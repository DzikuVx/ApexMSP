#include <unity.h>
#include <vector>
#include <cstdint>
#include <cstring>

#include "msp.h"
#include "crc.h"

// Single definition of the mock clock (declared extern in Arduino.h).
uint32_t g_mock_millis = 0;

// ---------------------------------------------------------------------------
// MockStream
//
// Two independent buffers:
//   written   – bytes MSP pushed via write()
//   readable  – bytes the test pre-fills for MSP to read()
//
// advance_on_available: if non-zero, every available() call adds this value
// to g_mock_millis, letting tests drive timeout code paths without threads.
// ---------------------------------------------------------------------------
class MockStream : public Stream {
public:
    std::vector<uint8_t> written;
    std::vector<uint8_t> readable;
    size_t   read_pos            = 0;
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

    size_t write(uint8_t b) override {
        written.push_back(b);
        return 1;
    }

    size_t write(const uint8_t* buf, size_t sz) override {
        for (size_t i = 0; i < sz; i++) written.push_back(buf[i]);
        return sz;
    }

    // flush() in real Arduino flushes the TX buffer; it does NOT drain RX.
    // MSP::reset() calls flush() then reads remaining bytes in a loop.
    void flush() override {}
};

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------

static const uint32_t TIMEOUT_MS = 1000;
static MockStream     mockStream;
static MSP            msp;

// Build a valid MSPv2 response frame (direction byte '>').
static std::vector<uint8_t> buildResponseFrame(uint16_t id,
                                               const uint8_t* payload,
                                               uint16_t size)
{
    std::vector<uint8_t> f;
    f.push_back('$');
    f.push_back('X');
    f.push_back('>');

    uint8_t flag = 0, crc = 0;
    crc = crc8_dvb_s2(crc, flag);
    f.push_back(flag);

    uint8_t id_lo = id & 0xFF, id_hi = (id >> 8) & 0xFF;
    crc = crc8_dvb_s2(crc, id_lo);
    crc = crc8_dvb_s2(crc, id_hi);
    f.push_back(id_lo);
    f.push_back(id_hi);

    uint8_t sz_lo = size & 0xFF, sz_hi = (size >> 8) & 0xFF;
    crc = crc8_dvb_s2(crc, sz_lo);
    crc = crc8_dvb_s2(crc, sz_hi);
    f.push_back(sz_lo);
    f.push_back(sz_hi);

    for (uint16_t i = 0; i < size; i++) {
        crc = crc8_dvb_s2(crc, payload[i]);
        f.push_back(payload[i]);
    }
    f.push_back(crc);
    return f;
}

// ---------------------------------------------------------------------------
// Test lifecycle
// ---------------------------------------------------------------------------

void setUp() {
    mockStream.reset();
    g_mock_millis = 0;
    msp.begin(mockStream, TIMEOUT_MS);
}

void tearDown() {}

// ===========================================================================
// send() tests
// ===========================================================================

void test_send_writes_mspv2_header() {
    msp.send(0x0001, nullptr, 0);
    TEST_ASSERT_EQUAL_UINT8('$', mockStream.written[0]);
    TEST_ASSERT_EQUAL_UINT8('X', mockStream.written[1]);
    TEST_ASSERT_EQUAL_UINT8('<', mockStream.written[2]);
}

void test_send_empty_payload_is_nine_bytes() {
    msp.send(0x0001, nullptr, 0);
    // $X< + flag(1) + id(2) + size(2) + crc(1) = 9 bytes
    TEST_ASSERT_EQUAL(9, (int)mockStream.written.size());
}

void test_send_message_id_little_endian() {
    msp.send(0x0102, nullptr, 0);
    TEST_ASSERT_EQUAL_UINT8(0x02, mockStream.written[4]); // low byte
    TEST_ASSERT_EQUAL_UINT8(0x01, mockStream.written[5]); // high byte
}

void test_send_size_field_is_zero_for_empty_payload() {
    msp.send(0x0001, nullptr, 0);
    TEST_ASSERT_EQUAL_UINT8(0x00, mockStream.written[6]);
    TEST_ASSERT_EQUAL_UINT8(0x00, mockStream.written[7]);
}

void test_send_size_field_reflects_payload_length() {
    uint8_t payload[] = {0x01, 0x02, 0x03};
    msp.send(0x0001, payload, 3);
    TEST_ASSERT_EQUAL_UINT8(0x03, mockStream.written[6]);
    TEST_ASSERT_EQUAL_UINT8(0x00, mockStream.written[7]);
}

void test_send_payload_bytes_present_in_output() {
    uint8_t payload[] = {0xAA, 0xBB, 0xCC};
    msp.send(0x0001, payload, 3);
    TEST_ASSERT_EQUAL_UINT8(0xAA, mockStream.written[8]);
    TEST_ASSERT_EQUAL_UINT8(0xBB, mockStream.written[9]);
    TEST_ASSERT_EQUAL_UINT8(0xCC, mockStream.written[10]);
}

void test_send_total_size_accounts_for_payload() {
    uint8_t payload[] = {0x01, 0x02};
    msp.send(0x0001, payload, 2);
    TEST_ASSERT_EQUAL(11, (int)mockStream.written.size()); // 9 + 2
}

void test_send_crc_correct_empty_payload() {
    uint8_t crc = 0;
    crc = crc8_dvb_s2(crc, 0x00); // flag
    crc = crc8_dvb_s2(crc, 0x01); // id low
    crc = crc8_dvb_s2(crc, 0x00); // id high
    crc = crc8_dvb_s2(crc, 0x00); // size low
    crc = crc8_dvb_s2(crc, 0x00); // size high

    msp.send(0x0001, nullptr, 0);
    TEST_ASSERT_EQUAL_UINT8(crc, mockStream.written[8]);
}

void test_send_crc_correct_with_payload() {
    uint8_t payload[] = {0xAB, 0xCD};
    uint8_t crc = 0;
    crc = crc8_dvb_s2(crc, 0x00); // flag
    crc = crc8_dvb_s2(crc, 0x05); // id low
    crc = crc8_dvb_s2(crc, 0x00); // id high
    crc = crc8_dvb_s2(crc, 0x02); // size low
    crc = crc8_dvb_s2(crc, 0x00); // size high
    crc = crc8_dvb_s2(crc, 0xAB); // payload[0]
    crc = crc8_dvb_s2(crc, 0xCD); // payload[1]

    msp.send(0x0005, payload, 2);
    TEST_ASSERT_EQUAL_UINT8(crc, mockStream.written[10]);
}

// ===========================================================================
// recv() tests
// ===========================================================================

void test_recv_returns_true_for_valid_empty_frame() {
    auto frame = buildResponseFrame(0x0042, nullptr, 0);
    mockStream.feed(frame.data(), frame.size());

    uint16_t msgID = 0, recvSize = 0;
    TEST_ASSERT_TRUE(msp.recv(&msgID, nullptr, 0, &recvSize));
}

void test_recv_decodes_message_id() {
    auto frame = buildResponseFrame(0x0042, nullptr, 0);
    mockStream.feed(frame.data(), frame.size());

    uint16_t msgID = 0, recvSize = 0;
    msp.recv(&msgID, nullptr, 0, &recvSize);
    TEST_ASSERT_EQUAL_UINT16(0x0042, msgID);
}

void test_recv_decodes_payload_and_size() {
    uint8_t payload[] = {0x11, 0x22, 0x33};
    auto frame = buildResponseFrame(0x0010, payload, 3);
    mockStream.feed(frame.data(), frame.size());

    uint16_t msgID = 0, recvSize = 0;
    uint8_t buf[8] = {0};
    msp.recv(&msgID, buf, sizeof(buf), &recvSize);

    TEST_ASSERT_EQUAL_UINT16(3, recvSize);
    TEST_ASSERT_EQUAL_UINT8(0x11, buf[0]);
    TEST_ASSERT_EQUAL_UINT8(0x22, buf[1]);
    TEST_ASSERT_EQUAL_UINT8(0x33, buf[2]);
}

void test_recv_zero_pads_buffer_when_payload_smaller_than_max() {
    uint8_t payload[] = {0xAA, 0xBB};
    auto frame = buildResponseFrame(0x0001, payload, 2);
    mockStream.feed(frame.data(), frame.size());

    uint16_t msgID = 0, recvSize = 0;
    uint8_t buf[4] = {0xFF, 0xFF, 0xFF, 0xFF};
    msp.recv(&msgID, buf, sizeof(buf), &recvSize);

    TEST_ASSERT_EQUAL_UINT8(0xAA, buf[0]);
    TEST_ASSERT_EQUAL_UINT8(0xBB, buf[1]);
    TEST_ASSERT_EQUAL_UINT8(0x00, buf[2]);
    TEST_ASSERT_EQUAL_UINT8(0x00, buf[3]);
}

void test_recv_truncates_payload_to_max_size_but_reports_full_size() {
    uint8_t payload[] = {0x11, 0x22, 0x33, 0x44};
    auto frame = buildResponseFrame(0x0001, payload, 4);
    mockStream.feed(frame.data(), frame.size());

    uint16_t msgID = 0, recvSize = 0;
    uint8_t buf[2] = {0};
    msp.recv(&msgID, buf, sizeof(buf), &recvSize);

    TEST_ASSERT_EQUAL_UINT16(4, recvSize); // full size from frame header
    TEST_ASSERT_EQUAL_UINT8(0x11, buf[0]);
    TEST_ASSERT_EQUAL_UINT8(0x22, buf[1]);
}

void test_recv_returns_false_on_timeout_with_no_data() {
    // Each available() call advances the clock past the timeout.
    mockStream.advance_on_available = TIMEOUT_MS + 1;

    uint16_t msgID = 0, recvSize = 0;
    TEST_ASSERT_FALSE(msp.recv(&msgID, nullptr, 0, &recvSize));
}

void test_recv_returns_false_on_bad_checksum() {
    // Build a valid frame then corrupt its CRC byte.
    auto frame = buildResponseFrame(0x0001, nullptr, 0);
    frame.back() ^= 0xFF;
    mockStream.feed(frame.data(), frame.size());
    // After consuming the corrupted frame recv loops waiting for more data;
    // advance_on_available drives it to timeout.
    mockStream.advance_on_available = TIMEOUT_MS + 1;

    uint16_t msgID = 0, recvSize = 0;
    TEST_ASSERT_FALSE(msp.recv(&msgID, nullptr, 0, &recvSize));
}

// ===========================================================================
// reset() tests
// ===========================================================================

void test_reset_drains_all_pending_data() {
    uint8_t junk[] = {0x01, 0x02, 0x03};
    mockStream.feed(junk, sizeof(junk));
    TEST_ASSERT_EQUAL(3, mockStream.available());

    msp.reset();
    TEST_ASSERT_EQUAL(0, mockStream.available());
}

// ===========================================================================
// command() tests
// ===========================================================================

void test_command_without_ack_returns_true_immediately() {
    uint8_t payload[] = {0x01};
    TEST_ASSERT_TRUE(msp.command(0x0001, payload, 1, false));
}

void test_command_without_ack_sends_valid_mspv2_frame() {
    uint8_t payload[] = {0x42};
    msp.command(0x0001, payload, 1, false);
    TEST_ASSERT_EQUAL_UINT8('$', mockStream.written[0]);
    TEST_ASSERT_EQUAL_UINT8('X', mockStream.written[1]);
    TEST_ASSERT_EQUAL_UINT8('<', mockStream.written[2]);
}

void test_command_with_ack_returns_true_when_response_arrives() {
    auto ack = buildResponseFrame(0x0001, nullptr, 0);
    mockStream.feed(ack.data(), ack.size());
    TEST_ASSERT_TRUE(msp.command(0x0001, nullptr, 0, true));
}

// ===========================================================================
// waitFor() tests
// ===========================================================================

void test_waitFor_returns_true_when_matching_frame_arrives() {
    auto frame = buildResponseFrame(0x00FF, nullptr, 0);
    mockStream.feed(frame.data(), frame.size());
    TEST_ASSERT_TRUE(msp.waitFor(0x00FF, nullptr, 0, nullptr));
}

void test_waitFor_returns_false_on_timeout() {
    mockStream.advance_on_available = TIMEOUT_MS + 1;
    TEST_ASSERT_FALSE(msp.waitFor(0x00FF, nullptr, 0, nullptr));
}

// ===========================================================================
// request() tests
// ===========================================================================

void test_request_returns_true_and_delivers_payload() {
    uint8_t payload[] = {0xDE, 0xAD};
    auto frame = buildResponseFrame(0x0005, payload, 2);
    mockStream.feed(frame.data(), frame.size());

    uint8_t buf[8] = {0};
    uint16_t recvSize = 0;
    TEST_ASSERT_TRUE(msp.request(0x0005, buf, sizeof(buf), &recvSize));
    TEST_ASSERT_EQUAL_UINT16(2, recvSize);
    TEST_ASSERT_EQUAL_UINT8(0xDE, buf[0]);
    TEST_ASSERT_EQUAL_UINT8(0xAD, buf[1]);
}

void test_request_sends_frame_before_reading_response() {
    auto frame = buildResponseFrame(0x0005, nullptr, 0);
    mockStream.feed(frame.data(), frame.size());

    msp.request(0x0005, nullptr, 0, nullptr);

    // The request frame must have been written before the response was read.
    TEST_ASSERT_GREATER_THAN(0, (int)mockStream.written.size());
    TEST_ASSERT_EQUAL_UINT8('$', mockStream.written[0]);
    TEST_ASSERT_EQUAL_UINT8('X', mockStream.written[1]);
    TEST_ASSERT_EQUAL_UINT8('<', mockStream.written[2]);
}

// ===========================================================================
// Entry point
// ===========================================================================

int main(int argc, char** argv)
{
    UNITY_BEGIN();

    // send()
    RUN_TEST(test_send_writes_mspv2_header);
    RUN_TEST(test_send_empty_payload_is_nine_bytes);
    RUN_TEST(test_send_message_id_little_endian);
    RUN_TEST(test_send_size_field_is_zero_for_empty_payload);
    RUN_TEST(test_send_size_field_reflects_payload_length);
    RUN_TEST(test_send_payload_bytes_present_in_output);
    RUN_TEST(test_send_total_size_accounts_for_payload);
    RUN_TEST(test_send_crc_correct_empty_payload);
    RUN_TEST(test_send_crc_correct_with_payload);

    // recv()
    RUN_TEST(test_recv_returns_true_for_valid_empty_frame);
    RUN_TEST(test_recv_decodes_message_id);
    RUN_TEST(test_recv_decodes_payload_and_size);
    RUN_TEST(test_recv_zero_pads_buffer_when_payload_smaller_than_max);
    RUN_TEST(test_recv_truncates_payload_to_max_size_but_reports_full_size);
    RUN_TEST(test_recv_returns_false_on_timeout_with_no_data);
    RUN_TEST(test_recv_returns_false_on_bad_checksum);

    // reset()
    RUN_TEST(test_reset_drains_all_pending_data);

    // command()
    RUN_TEST(test_command_without_ack_returns_true_immediately);
    RUN_TEST(test_command_without_ack_sends_valid_mspv2_frame);
    RUN_TEST(test_command_with_ack_returns_true_when_response_arrives);

    // waitFor()
    RUN_TEST(test_waitFor_returns_true_when_matching_frame_arrives);
    RUN_TEST(test_waitFor_returns_false_on_timeout);

    // request()
    RUN_TEST(test_request_returns_true_and_delivers_payload);
    RUN_TEST(test_request_sends_frame_before_reading_response);

    return UNITY_END();
}
