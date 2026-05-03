/*
  MSP.h

  Copyright (c) 2017, Fabrizio Di Vittorio (fdivitto2013@gmail.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#pragma once

#include <Arduino.h>
#include <Stream.h>

// MSP2 header size (without payload)
#define MSP2_HEADER_SIZE 9

typedef struct {
    uint8_t permanentId;
    uint8_t boxId;
    const char *name;
} flight_mode_definition_t;

#define INAV_FLIGHT_MODE_ARM                0
#define INAV_FLIGHT_MODE_ANGLE              1
#define INAV_FLIGHT_MODE_HORIZON            2
#define INAV_FLIGHT_MODE_NAV_ALTHOLD        3
#define INAV_FLIGHT_MODE_HEADING_HOLD       5
#define INAV_FLIGHT_MODE_HEADFREE           6
#define INAV_FLIGHT_MODE_HEADADJ            7
#define INAV_FLIGHT_MODE_CAMSTAB            8
#define INAV_FLIGHT_MODE_NAV_RTH            10
#define INAV_FLIGHT_MODE_NAV_POSHOLD        11
#define INAV_FLIGHT_MODE_MANUAL             12
#define INAV_FLIGHT_MODE_BEEPER             13
#define INAV_FLIGHT_MODE_LEDS_OFF           15
#define INAV_FLIGHT_MODE_LIGHTS             16
#define INAV_FLIGHT_MODE_OSD_OFF            19
#define INAV_FLIGHT_MODE_TELEMETRY          20
#define INAV_FLIGHT_MODE_AUTO_TUNE          21
#define INAV_FLIGHT_MODE_BLACKBOX           26
#define INAV_FLIGHT_MODE_FAILSAFE           27
#define INAV_FLIGHT_MODE_NAV_WP             28
#define INAV_FLIGHT_MODE_AIR_MODE           29
#define INAV_FLIGHT_MODE_HOME_RESET         30
#define INAV_FLIGHT_MODE_GCS_NAV            31
#define INAV_FLIGHT_MODE_FPV_ANGLE_MIX      32
#define INAV_FLIGHT_MODE_SURFACE            33
#define INAV_FLIGHT_MODE_FLAPERON           34
#define INAV_FLIGHT_MODE_TURN_ASSIST        35
#define INAV_FLIGHT_MODE_NAV_LAUNCH         36
#define INAV_FLIGHT_MODE_SERVO_AUTOTRIM     37
#define INAV_FLIGHT_MODE_CAMERA_CONTROL_1   39
#define INAV_FLIGHT_MODE_CAMERA_CONTROL_2   40
#define INAV_FLIGHT_MODE_CAMERA_CONTROL_3   41
#define INAV_FLIGHT_MODE_OSD_ALT_1          42
#define INAV_FLIGHT_MODE_OSD_ALT_2          43
#define INAV_FLIGHT_MODE_OSD_ALT_3          44
#define INAV_FLIGHT_MODE_NAV_COURSE_HOLD    45
#define INAV_FLIGHT_MODE_MC_BRAKING         46
#define INAV_FLIGHT_MODE_USER1              47
#define INAV_FLIGHT_MODE_USER2              48
#define INAV_FLIGHT_MODE_USER3              57
#define INAV_FLIGHT_MODE_USER4              58
#define INAV_FLIGHT_MODE_LOITER_CHANGE      49
#define INAV_FLIGHT_MODE_MSP_RC_OVERRIDE    50
#define INAV_FLIGHT_MODE_PREARM             51
#define INAV_FLIGHT_MODE_TURTLE             52
#define INAV_FLIGHT_MODE_NAV_CRUISE         53
#define INAV_FLIGHT_MODE_AUTO_LEVEL_TRIM    54
#define INAV_FLIGHT_MODE_WP_PLANNER         55
#define INAV_FLIGHT_MODE_SOARING            56
#define INAV_FLIGHT_MODE_MISSION_CHANGE     59
#define INAV_FLIGHT_MODE_BEEPER_MUTE        60
#define INAV_FLIGHT_MODE_MULTI_FUNCTION     61
#define INAV_FLIGHT_MODE_MIXER_PROFILE_2    62
#define INAV_FLIGHT_MODE_MIXER_TRANSITION   63
#define INAV_FLIGHT_MODE_ANGLE_HOLD         64
#define INAV_FLIGHT_MODE_GIMBAL_LEVEL_TILT  65
#define INAV_FLIGHT_MODE_GIMBAL_LEVEL_ROLL  66
#define INAV_FLIGHT_MODE_GIMBAL_CENTER      67
#define INAV_FLIGHT_MODE_GIMBAL_HEADTRACKER 68

extern const flight_mode_definition_t INAV_MODE_DEFS[];
extern const uint8_t INAV_MODE_DEFS_COUNT;

class MSP {

  public:

    void begin(Stream & stream, uint32_t timeout = 500);
    void send(uint16_t messageID, void * payload, uint16_t size);
    bool recv(uint16_t *messageID, void * payload, uint16_t maxSize, uint16_t *recvSize);
    bool waitFor(uint16_t messageID, void * payload, uint16_t maxSize, uint16_t *recvSize = NULL);
    bool request(uint16_t messageID, void * payload, uint16_t maxSize, uint16_t *recvSize = NULL);
    bool command(uint16_t messageID, void * payload, uint16_t size, bool waitACK = true);
    void reset();
    bool getActiveModes(uint32_t * activeModes);
    static bool checkFlightMode(const flight_mode_definition_t *defs, uint8_t defCount, const uint8_t bitmap[8], uint8_t permanentId);
    
  private:
  
    Stream * _stream;
    uint32_t _timeout;
    
};

