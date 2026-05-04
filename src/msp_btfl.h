/*
  msp_btfl.h

  Betaflight-specific MSP frame IDs, constants, and payload structures.
  All names are prefixed with BTFL_ to distinguish them from generic MSP symbols.

  Flight mode bitmap extraction differs from INAV: Betaflight has no dedicated
  MSP_ACTIVEBOXES command. Instead, flight mode bits are packed into MSP_STATUS /
  MSP_STATUS_EX responses. Use btflExtractFlightModeBitmap() to pull the 8-byte
  bitmap out of the raw response buffer, then pass it to MSP::checkFlightMode()
  exactly as you would with INAV.

  MSP_BOXIDS (119) works identically in both firmwares.
*/

#pragma once

#include <Arduino.h>
#include <msp.h>

// ============================================================
// Betaflight MSP Frame IDs
// ============================================================

#define BTFL_MSP_STATUS                       101
#define BTFL_MSP_STATUS_EX                    150
#define BTFL_MSP_BOXIDS                       119
#define BTFL_MSP_BOXNAMES                     116

// ============================================================
// MSP_STATUS_EX response layout (Betaflight)
//
//  Offset  Size  Field
//  0-1     U16   cycleTime
//  2-3     U16   i2cErrorCounter
//  4-5     U16   sensors
//  6-9     U32   flightModeFlags[0..31]   <- first 32 mode bits
//  10      U8    configProfileIndex
//  11-12   U16   averageSystemLoadPercent
//  13      U8    pidProfileCount          (MSP_STATUS_EX only; MSP_STATUS writes U16 0 here)
//  14      U8    controlRateProfileIndex  (MSP_STATUS_EX only)
//  15      U8    extCount (lower 4 bits)  <- number of additional flight mode bytes
//  16+     bytes flightModeFlags[32..]   <- 0-15 additional bytes
//  ...     ...   armingDisableFlags, rebootRequired, coreTemp, etc.
//
// Use a raw buffer of at least 32 bytes to capture the whole fixed section plus
// any extension bytes.
// ============================================================

// Extract the 8-byte flight mode bitmap from a raw MSP_STATUS or MSP_STATUS_EX
// response buffer. Returns false if bufLen is too short to contain the header.
static inline bool btflExtractFlightModeBitmap(const uint8_t *buf, uint16_t bufLen, uint8_t bitmap[8])
{
    if (bufLen < 16) return false;

    memset(bitmap, 0, 8);
    memcpy(bitmap, buf + 6, 4);                 // first 32 bits at offset 6

    const uint8_t extCount = buf[15] & 0x0F;   // low nibble = extension byte count
    if (extCount > 0 && bufLen >= (uint16_t)(16 + extCount)) {
        // copy up to 4 more bytes (filling bitmap[4..7])
        const uint8_t copyBytes = extCount < 4 ? extCount : 4;
        memcpy(bitmap + 4, buf + 16, copyBytes);
    }
    return true;
}

// ============================================================
// Flight mode permanent IDs
// Source: btfl/src/main/msp/msp_box.c
// ============================================================

#define BTFL_FLIGHT_MODE_ARM                    0
#define BTFL_FLIGHT_MODE_ANGLE                  1
#define BTFL_FLIGHT_MODE_HORIZON                2
#define BTFL_FLIGHT_MODE_ALTHOLD                3
#define BTFL_FLIGHT_MODE_ANTI_GRAVITY           4
#define BTFL_FLIGHT_MODE_MAG                    5
#define BTFL_FLIGHT_MODE_HEADFREE               6
#define BTFL_FLIGHT_MODE_HEADADJ                7
#define BTFL_FLIGHT_MODE_CAMSTAB                8
#define BTFL_FLIGHT_MODE_POS_HOLD               11
#define BTFL_FLIGHT_MODE_PASSTHRU               12
#define BTFL_FLIGHT_MODE_BEEPER                 13
#define BTFL_FLIGHT_MODE_LEDLOW                 15
#define BTFL_FLIGHT_MODE_CALIB                  17
#define BTFL_FLIGHT_MODE_OSD_DISABLE            19
#define BTFL_FLIGHT_MODE_TELEMETRY              20
#define BTFL_FLIGHT_MODE_SERVO1                 23
#define BTFL_FLIGHT_MODE_SERVO2                 24
#define BTFL_FLIGHT_MODE_SERVO3                 25
#define BTFL_FLIGHT_MODE_BLACKBOX               26
#define BTFL_FLIGHT_MODE_FAILSAFE               27
#define BTFL_FLIGHT_MODE_AIR_MODE               28
#define BTFL_FLIGHT_MODE_3D_DISABLE             29
#define BTFL_FLIGHT_MODE_FPV_ANGLE_MIX          30
#define BTFL_FLIGHT_MODE_BLACKBOX_ERASE         31
#define BTFL_FLIGHT_MODE_CAMERA_CONTROL_1       32
#define BTFL_FLIGHT_MODE_CAMERA_CONTROL_2       33
#define BTFL_FLIGHT_MODE_CAMERA_CONTROL_3       34
#define BTFL_FLIGHT_MODE_FLIP_OVER_AFTER_CRASH  35
#define BTFL_FLIGHT_MODE_PREARM                 36
#define BTFL_FLIGHT_MODE_GPS_BEEP_SAT_COUNT     37
#define BTFL_FLIGHT_MODE_VTX_PIT_MODE           39
#define BTFL_FLIGHT_MODE_USER1                  40
#define BTFL_FLIGHT_MODE_USER2                  41
#define BTFL_FLIGHT_MODE_USER3                  42
#define BTFL_FLIGHT_MODE_USER4                  43
#define BTFL_FLIGHT_MODE_PID_AUDIO              44
#define BTFL_FLIGHT_MODE_PARALYZE               45
#define BTFL_FLIGHT_MODE_GPS_RESCUE             46
#define BTFL_FLIGHT_MODE_ACRO_TRAINER           47
#define BTFL_FLIGHT_MODE_VTX_CONTROL_DISABLE    48
#define BTFL_FLIGHT_MODE_LAUNCH_CONTROL         49
#define BTFL_FLIGHT_MODE_MSP_OVERRIDE           50
#define BTFL_FLIGHT_MODE_STICK_COMMANDS_DISABLE 51
#define BTFL_FLIGHT_MODE_BEEPER_MUTE            52
#define BTFL_FLIGHT_MODE_READY                  53
#define BTFL_FLIGHT_MODE_LAP_TIMER_RESET        54
#define BTFL_FLIGHT_MODE_CHIRP                  55
#define BTFL_FLIGHT_MODE_AUTOPILOT              56

// ============================================================
// Mode definition table
// boxId field is the Betaflight boxId_e value (not meaningful
// for mode checking; permanentId is used by MSP::checkFlightMode).
// ============================================================

const flight_mode_definition_t BTFL_MODE_DEFS[] = {
    {  0,  0, "ARM" },
    {  1,  1, "ANGLE" },
    {  2,  2, "HORIZON" },
    {  3,  3, "ALTHOLD" },
    {  4, 12, "ANTI GRAVITY" },
    {  5,  5, "MAG" },
    {  6,  6, "HEADFREE" },
    {  7,  7, "HEADADJ" },
    {  8,  8, "CAMSTAB" },
    { 11,  9, "POS HOLD" },
    { 12,  7, "PASSTHRU" },
    { 13, 13, "BEEPER" },
    { 15, 14, "LEDLOW" },
    { 17, 15, "CALIB" },
    { 19, 16, "OSD DISABLE" },
    { 20, 17, "TELEMETRY" },
    { 23, 18, "SERVO1" },
    { 24, 19, "SERVO2" },
    { 25, 20, "SERVO3" },
    { 26, 21, "BLACKBOX" },
    { 27, 22, "FAILSAFE" },
    { 28, 23, "AIR MODE" },
    { 29, 24, "3D DISABLE" },
    { 30, 25, "FPV ANGLE MIX" },
    { 31, 26, "BLACKBOX ERASE" },
    { 32, 27, "CAMERA CONTROL 1" },
    { 33, 28, "CAMERA CONTROL 2" },
    { 34, 29, "CAMERA CONTROL 3" },
    { 35, 30, "FLIP OVER AFTER CRASH" },
    { 36, 31, "PREARM" },
    { 37, 32, "GPS BEEP SATELLITE COUNT" },
    { 39, 33, "VTX PIT MODE" },
    { 40, 34, "USER1" },
    { 41, 35, "USER2" },
    { 42, 36, "USER3" },
    { 43, 37, "USER4" },
    { 44, 38, "PID AUDIO" },
    { 45, 39, "PARALYZE" },
    { 46, 40, "GPS RESCUE" },
    { 47, 41, "ACRO TRAINER" },
    { 48, 42, "VTX CONTROL DISABLE" },
    { 49, 43, "LAUNCH CONTROL" },
    { 50, 44, "MSP OVERRIDE" },
    { 51, 45, "STICK COMMANDS DISABLE" },
    { 52, 46, "BEEPER MUTE" },
    { 53, 47, "READY" },
    { 54, 48, "LAP TIMER RESET" },
    { 55, 49, "CHIRP" },
    { 56, 50, "AUTOPILOT" },
};

const uint8_t BTFL_MODE_DEFS_COUNT = sizeof(BTFL_MODE_DEFS) / sizeof(BTFL_MODE_DEFS[0]);

class MspBTFL : public MSP {
public:
    MspBTFL() : _boxIdCount(0), _boxIdsLoaded(false) {
        memset(_boxIdMap, 0, sizeof(_boxIdMap));
        memset(_bitmap,   0, sizeof(_bitmap));
    }

    bool loadBoxIds() {
        uint16_t recvSize = 0;
        if (!request(BTFL_MSP_BOXIDS, _boxIdMap, sizeof(_boxIdMap), &recvSize)) {
            _boxIdsLoaded = false;
            return false;
        }
        _boxIdCount   = recvSize < sizeof(_boxIdMap) ? (uint8_t)recvSize : (uint8_t)sizeof(_boxIdMap);
        _boxIdsLoaded = true;
        return true;
    }

    bool loadActiveFlightModes() {
        uint8_t rawBuf[32];
        uint16_t recvSize = 0;
        memset(rawBuf, 0, sizeof(rawBuf));
        if (!request(BTFL_MSP_STATUS_EX, rawBuf, sizeof(rawBuf), &recvSize)) return false;
        return btflExtractFlightModeBitmap(rawBuf, recvSize, _bitmap);
    }

    bool isFlightModeActive(uint8_t permanentId) const {
        if (!_boxIdsLoaded) return false;
        return checkFlightMode(_boxIdMap, _boxIdCount, _bitmap, permanentId);
    }

private:
    uint8_t _boxIdMap[64];
    uint8_t _boxIdCount;
    uint8_t _bitmap[8];
    bool    _boxIdsLoaded;
};
