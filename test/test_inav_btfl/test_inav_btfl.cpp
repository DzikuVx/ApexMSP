#include <unity.h>
#include <vector>
#include <cstdint>
#include <cstring>

#include "msp.h"
#include "msp_inav.h"
#include "msp_btfl.h"
#include "crc.h"

uint32_t g_mock_millis = 0;

// ---------------------------------------------------------------------------
// MockStream — same contract as in test_msp.cpp
// ---------------------------------------------------------------------------
class MockStream : public Stream {
public:
    std::vector<uint8_t> written;
    std::vector<uint8_t> readable;
    size_t   read_pos             = 0;
    uint32_t advance_on_available = 0;

    void reset() {
        written.clear();
        readable.clear();
        read_pos             = 0;
        advance_on_available = 0;
    }

    void feed(const uint8_t* data, size_t len) {
        for (size_t i = 0; i < len; i++) readable.push_back(data[i]);
    }

    int available() override {
        g_mock_millis += advance_on_available;
        return (int)(readable.size() - read_pos);
    }
    int read() override {
        if (read_pos >= readable.size()) return -1;
        return readable[read_pos++];
    }
    size_t readBytes(char* buf, size_t len) override {
        size_t n = 0;
        while (n < len && read_pos < readable.size())
            buf[n++] = (char)readable[read_pos++];
        return n;
    }
    size_t write(uint8_t b) override { written.push_back(b); return 1; }
    size_t write(const uint8_t* buf, size_t sz) override {
        for (size_t i = 0; i < sz; i++) written.push_back(buf[i]);
        return sz;
    }
    void flush() override {}
};

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static const uint32_t TIMEOUT_MS = 1000;
static MockStream mockStream;

static std::vector<uint8_t> buildResponseFrame(uint16_t id,
                                               const uint8_t* payload,
                                               uint16_t size)
{
    std::vector<uint8_t> f;
    f.push_back('$'); f.push_back('X'); f.push_back('>');

    uint8_t flag = 0, crc = 0;
    crc = crc8_dvb_s2(crc, flag);
    f.push_back(flag);

    uint8_t id_lo = id & 0xFF, id_hi = (id >> 8) & 0xFF;
    crc = crc8_dvb_s2(crc, id_lo); crc = crc8_dvb_s2(crc, id_hi);
    f.push_back(id_lo); f.push_back(id_hi);

    uint8_t sz_lo = size & 0xFF, sz_hi = (size >> 8) & 0xFF;
    crc = crc8_dvb_s2(crc, sz_lo); crc = crc8_dvb_s2(crc, sz_hi);
    f.push_back(sz_lo); f.push_back(sz_hi);

    for (uint16_t i = 0; i < size; i++) {
        crc = crc8_dvb_s2(crc, payload[i]);
        f.push_back(payload[i]);
    }
    f.push_back(crc);
    return f;
}

// Feed a BOXIDS response and call loadBoxIds() on the given INAV instance.
static void feedINAVBoxIds(MspINAV& msp, const uint8_t* ids, uint8_t count) {
    auto f = buildResponseFrame(INAV_MSP_BOXIDS, ids, count);
    mockStream.feed(f.data(), f.size());
    msp.loadBoxIds();
}

// Feed an ACTIVEBOXES response and call loadActiveFlightModes().
static void feedINAVActiveModes(MspINAV& msp, const uint8_t bitmap[8]) {
    auto f = buildResponseFrame(INAV_MSP_ACTIVEBOXES, bitmap, 8);
    mockStream.feed(f.data(), f.size());
    msp.loadActiveFlightModes();
}

// Feed a BOXIDS response and call loadBoxIds() on the given BTFL instance.
static void feedBTFLBoxIds(MspBTFL& msp, const uint8_t* ids, uint8_t count) {
    auto f = buildResponseFrame(BTFL_MSP_BOXIDS, ids, count);
    mockStream.feed(f.data(), f.size());
    msp.loadBoxIds();
}

// Build a STATUS_EX payload (>=16 bytes).
//   modeBase  – 32-bit flight mode flags packed in bytes 6-9
//   extCount  – number of extension bytes (byte 15 lower nibble)
//   extBytes  – optional pointer to extCount bytes placed at byte 16+
static std::vector<uint8_t> makeStatusExPayload(uint32_t modeBase,
                                                uint8_t  extCount  = 0,
                                                const uint8_t* extBytes = nullptr)
{
    std::vector<uint8_t> buf(16 + extCount, 0);
    buf[6]  = (modeBase >>  0) & 0xFF;
    buf[7]  = (modeBase >>  8) & 0xFF;
    buf[8]  = (modeBase >> 16) & 0xFF;
    buf[9]  = (modeBase >> 24) & 0xFF;
    buf[15] = extCount & 0x0F;
    for (uint8_t i = 0; i < extCount; i++)
        buf[16 + i] = extBytes ? extBytes[i] : 0;
    return buf;
}

void setUp() {
    mockStream.reset();
    g_mock_millis = 0;
}

void tearDown() {}

// ===========================================================================
// MspINAV – loadBoxIds()
// ===========================================================================

void test_inav_loadBoxIds_returns_true_on_valid_response() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    uint8_t boxIds[] = { 0, 1, 2 };
    auto f = buildResponseFrame(INAV_MSP_BOXIDS, boxIds, sizeof(boxIds));
    mockStream.feed(f.data(), f.size());
    TEST_ASSERT_TRUE(msp.loadBoxIds());
}

void test_inav_loadBoxIds_returns_false_on_timeout() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    mockStream.advance_on_available = TIMEOUT_MS + 1;
    TEST_ASSERT_FALSE(msp.loadBoxIds());
}

// ===========================================================================
// MspINAV – isFlightModeActive() guard: requires loadBoxIds() to succeed
// ===========================================================================

void test_inav_isFlightModeActive_returns_false_before_loadBoxIds() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    TEST_ASSERT_FALSE(msp.isFlightModeActive(INAV_FLIGHT_MODE_ARM));
}

void test_inav_isFlightModeActive_returns_false_after_failed_loadBoxIds() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    mockStream.advance_on_available = TIMEOUT_MS + 1;
    msp.loadBoxIds();   // fails — _boxIdsLoaded stays false

    // Reset clock/stream, then successfully load active modes
    mockStream.reset();
    g_mock_millis = 0;
    uint8_t bitmap[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    auto f = buildResponseFrame(INAV_MSP_ACTIVEBOXES, bitmap, sizeof(bitmap));
    mockStream.feed(f.data(), f.size());
    msp.loadActiveFlightModes();

    // Still false: box ID map was never loaded
    TEST_ASSERT_FALSE(msp.isFlightModeActive(INAV_FLIGHT_MODE_ARM));
}

// ===========================================================================
// MspINAV – loadActiveFlightModes()
// ===========================================================================

void test_inav_loadActiveFlightModes_returns_true_on_valid_response() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    uint8_t bitmap[8] = { 0x01, 0, 0, 0, 0, 0, 0, 0 };
    auto f = buildResponseFrame(INAV_MSP_ACTIVEBOXES, bitmap, sizeof(bitmap));
    mockStream.feed(f.data(), f.size());
    TEST_ASSERT_TRUE(msp.loadActiveFlightModes());
}

void test_inav_loadActiveFlightModes_returns_false_on_timeout() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    mockStream.advance_on_available = TIMEOUT_MS + 1;
    TEST_ASSERT_FALSE(msp.loadActiveFlightModes());
}

// ===========================================================================
// MspINAV – isFlightModeActive() after full load
// ===========================================================================

void test_inav_isFlightModeActive_returns_true_for_active_mode() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    // boxIdMap: [ARM(0), ANGLE(1), HORIZON(2)]
    uint8_t boxIds[] = {
        INAV_FLIGHT_MODE_ARM,
        INAV_FLIGHT_MODE_ANGLE,
        INAV_FLIGHT_MODE_HORIZON
    };
    feedINAVBoxIds(msp, boxIds, sizeof(boxIds));
    // bit 0 set → ARM active
    uint8_t bitmap[8] = { 0x01, 0, 0, 0, 0, 0, 0, 0 };
    feedINAVActiveModes(msp, bitmap);
    TEST_ASSERT_TRUE(msp.isFlightModeActive(INAV_FLIGHT_MODE_ARM));
}

void test_inav_isFlightModeActive_returns_false_for_inactive_mode() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    uint8_t boxIds[] = {
        INAV_FLIGHT_MODE_ARM,
        INAV_FLIGHT_MODE_ANGLE,
        INAV_FLIGHT_MODE_HORIZON
    };
    feedINAVBoxIds(msp, boxIds, sizeof(boxIds));
    // Only bit 0 (ARM) set; ANGLE at position 1 is not
    uint8_t bitmap[8] = { 0x01, 0, 0, 0, 0, 0, 0, 0 };
    feedINAVActiveModes(msp, bitmap);
    TEST_ASSERT_FALSE(msp.isFlightModeActive(INAV_FLIGHT_MODE_ANGLE));
}

void test_inav_isFlightModeActive_returns_false_for_mode_not_in_map() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    uint8_t boxIds[] = { INAV_FLIGHT_MODE_ARM, INAV_FLIGHT_MODE_ANGLE };
    feedINAVBoxIds(msp, boxIds, sizeof(boxIds));
    // All bits set — but HORIZON is absent from boxIdMap
    uint8_t bitmap[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    feedINAVActiveModes(msp, bitmap);
    TEST_ASSERT_FALSE(msp.isFlightModeActive(INAV_FLIGHT_MODE_HORIZON));
}

void test_inav_isFlightModeActive_works_across_byte_boundary() {
    MspINAV msp;
    msp.begin(mockStream, TIMEOUT_MS);
    // 9 modes; position 8 → bit 8 → bitmap[1] & 0x01
    uint8_t boxIds[9] = {
        INAV_FLIGHT_MODE_ARM,           // pos 0
        INAV_FLIGHT_MODE_ANGLE,         // pos 1
        INAV_FLIGHT_MODE_HORIZON,       // pos 2
        INAV_FLIGHT_MODE_NAV_ALTHOLD,   // pos 3
        INAV_FLIGHT_MODE_HEADING_HOLD,  // pos 4
        INAV_FLIGHT_MODE_HEADFREE,      // pos 5
        INAV_FLIGHT_MODE_HEADADJ,       // pos 6
        INAV_FLIGHT_MODE_CAMSTAB,       // pos 7
        INAV_FLIGHT_MODE_NAV_RTH,       // pos 8
    };
    feedINAVBoxIds(msp, boxIds, sizeof(boxIds));
    // Set only bit 8 (second byte of bitmap, bit 0)
    uint8_t bitmap[8] = { 0x00, 0x01, 0, 0, 0, 0, 0, 0 };
    feedINAVActiveModes(msp, bitmap);
    TEST_ASSERT_TRUE(msp.isFlightModeActive(INAV_FLIGHT_MODE_NAV_RTH));
    TEST_ASSERT_FALSE(msp.isFlightModeActive(INAV_FLIGHT_MODE_ARM));
}

// ===========================================================================
// MspBTFL – loadBoxIds()
// ===========================================================================

void test_btfl_loadBoxIds_returns_true_on_valid_response() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    uint8_t boxIds[] = { BTFL_FLIGHT_MODE_ARM, BTFL_FLIGHT_MODE_ANGLE };
    auto f = buildResponseFrame(BTFL_MSP_BOXIDS, boxIds, sizeof(boxIds));
    mockStream.feed(f.data(), f.size());
    TEST_ASSERT_TRUE(msp.loadBoxIds());
}

void test_btfl_loadBoxIds_returns_false_on_timeout() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    mockStream.advance_on_available = TIMEOUT_MS + 1;
    TEST_ASSERT_FALSE(msp.loadBoxIds());
}

// ===========================================================================
// MspBTFL – isFlightModeActive() guard
// ===========================================================================

void test_btfl_isFlightModeActive_returns_false_before_loadBoxIds() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    TEST_ASSERT_FALSE(msp.isFlightModeActive(BTFL_FLIGHT_MODE_ARM));
}

// ===========================================================================
// MspBTFL – loadActiveFlightModes()
// ===========================================================================

void test_btfl_loadActiveFlightModes_returns_true_on_valid_response() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    auto payload = makeStatusExPayload(0);
    auto f = buildResponseFrame(BTFL_MSP_STATUS_EX, payload.data(), (uint16_t)payload.size());
    mockStream.feed(f.data(), f.size());
    TEST_ASSERT_TRUE(msp.loadActiveFlightModes());
}

void test_btfl_loadActiveFlightModes_returns_false_on_timeout() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    mockStream.advance_on_available = TIMEOUT_MS + 1;
    TEST_ASSERT_FALSE(msp.loadActiveFlightModes());
}

void test_btfl_loadActiveFlightModes_returns_false_for_short_response() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    // Response shorter than the required 16 bytes
    uint8_t shortBuf[15] = {};
    auto f = buildResponseFrame(BTFL_MSP_STATUS_EX, shortBuf, sizeof(shortBuf));
    mockStream.feed(f.data(), f.size());
    TEST_ASSERT_FALSE(msp.loadActiveFlightModes());
}

// ===========================================================================
// MspBTFL – isFlightModeActive() after full load
// ===========================================================================

void test_btfl_isFlightModeActive_returns_true_for_active_mode() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    // boxIdMap[0]=ARM(0), [1]=ANGLE(1)
    uint8_t boxIds[] = { BTFL_FLIGHT_MODE_ARM, BTFL_FLIGHT_MODE_ANGLE };
    feedBTFLBoxIds(msp, boxIds, sizeof(boxIds));
    // Bit 0 set in flightModeFlags → _bitmap[0] & 1 = 1 → ARM active
    auto payload = makeStatusExPayload(0x00000001);
    auto f = buildResponseFrame(BTFL_MSP_STATUS_EX, payload.data(), (uint16_t)payload.size());
    mockStream.feed(f.data(), f.size());
    msp.loadActiveFlightModes();
    TEST_ASSERT_TRUE(msp.isFlightModeActive(BTFL_FLIGHT_MODE_ARM));
}

void test_btfl_isFlightModeActive_returns_false_for_inactive_mode() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    uint8_t boxIds[] = { BTFL_FLIGHT_MODE_ARM, BTFL_FLIGHT_MODE_ANGLE };
    feedBTFLBoxIds(msp, boxIds, sizeof(boxIds));
    // Only bit 0 set → only ARM active; ANGLE at position 1 is not
    auto payload = makeStatusExPayload(0x00000001);
    auto f = buildResponseFrame(BTFL_MSP_STATUS_EX, payload.data(), (uint16_t)payload.size());
    mockStream.feed(f.data(), f.size());
    msp.loadActiveFlightModes();
    TEST_ASSERT_FALSE(msp.isFlightModeActive(BTFL_FLIGHT_MODE_ANGLE));
}

void test_btfl_isFlightModeActive_returns_false_for_mode_not_in_map() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    uint8_t boxIds[] = { BTFL_FLIGHT_MODE_ARM };
    feedBTFLBoxIds(msp, boxIds, sizeof(boxIds));
    // All 32 base bits set — but ANGLE not in boxIdMap
    auto payload = makeStatusExPayload(0xFFFFFFFF);
    auto f = buildResponseFrame(BTFL_MSP_STATUS_EX, payload.data(), (uint16_t)payload.size());
    mockStream.feed(f.data(), f.size());
    msp.loadActiveFlightModes();
    TEST_ASSERT_FALSE(msp.isFlightModeActive(BTFL_FLIGHT_MODE_ANGLE));
}

void test_btfl_loadActiveFlightModes_reads_ext_bytes() {
    MspBTFL msp;
    msp.begin(mockStream, TIMEOUT_MS);
    // 33 entries: positions 0–31 map to permanentIds 0–31;
    // position 32 maps to FLIP_OVER_AFTER_CRASH (35).
    // bit 32 lives in _bitmap[4] & 0x01, which comes from rawBuf[16] (first ext byte).
    uint8_t boxIds[33];
    for (uint8_t i = 0; i < 32; i++) boxIds[i] = i;
    boxIds[32] = BTFL_FLIGHT_MODE_FLIP_OVER_AFTER_CRASH;
    feedBTFLBoxIds(msp, boxIds, sizeof(boxIds));

    uint8_t extBytes[] = { 0x01 };  // bit 0 of ext → bit 32 overall
    auto payload = makeStatusExPayload(0x00000000, 1, extBytes);
    auto f = buildResponseFrame(BTFL_MSP_STATUS_EX, payload.data(), (uint16_t)payload.size());
    mockStream.feed(f.data(), f.size());
    msp.loadActiveFlightModes();

    TEST_ASSERT_TRUE(msp.isFlightModeActive(BTFL_FLIGHT_MODE_FLIP_OVER_AFTER_CRASH));
    TEST_ASSERT_FALSE(msp.isFlightModeActive(BTFL_FLIGHT_MODE_ARM)); // no base bits set
}

// ===========================================================================
// Entry point
// ===========================================================================

int main(int argc, char** argv)
{
    UNITY_BEGIN();

    // MspINAV – loadBoxIds()
    RUN_TEST(test_inav_loadBoxIds_returns_true_on_valid_response);
    RUN_TEST(test_inav_loadBoxIds_returns_false_on_timeout);

    // MspINAV – isFlightModeActive() guard
    RUN_TEST(test_inav_isFlightModeActive_returns_false_before_loadBoxIds);
    RUN_TEST(test_inav_isFlightModeActive_returns_false_after_failed_loadBoxIds);

    // MspINAV – loadActiveFlightModes()
    RUN_TEST(test_inav_loadActiveFlightModes_returns_true_on_valid_response);
    RUN_TEST(test_inav_loadActiveFlightModes_returns_false_on_timeout);

    // MspINAV – isFlightModeActive() after full load
    RUN_TEST(test_inav_isFlightModeActive_returns_true_for_active_mode);
    RUN_TEST(test_inav_isFlightModeActive_returns_false_for_inactive_mode);
    RUN_TEST(test_inav_isFlightModeActive_returns_false_for_mode_not_in_map);
    RUN_TEST(test_inav_isFlightModeActive_works_across_byte_boundary);

    // MspBTFL – loadBoxIds()
    RUN_TEST(test_btfl_loadBoxIds_returns_true_on_valid_response);
    RUN_TEST(test_btfl_loadBoxIds_returns_false_on_timeout);

    // MspBTFL – isFlightModeActive() guard
    RUN_TEST(test_btfl_isFlightModeActive_returns_false_before_loadBoxIds);

    // MspBTFL – loadActiveFlightModes()
    RUN_TEST(test_btfl_loadActiveFlightModes_returns_true_on_valid_response);
    RUN_TEST(test_btfl_loadActiveFlightModes_returns_false_on_timeout);
    RUN_TEST(test_btfl_loadActiveFlightModes_returns_false_for_short_response);

    // MspBTFL – isFlightModeActive() after full load
    RUN_TEST(test_btfl_isFlightModeActive_returns_true_for_active_mode);
    RUN_TEST(test_btfl_isFlightModeActive_returns_false_for_inactive_mode);
    RUN_TEST(test_btfl_isFlightModeActive_returns_false_for_mode_not_in_map);
    RUN_TEST(test_btfl_loadActiveFlightModes_reads_ext_bytes);

    return UNITY_END();
}
