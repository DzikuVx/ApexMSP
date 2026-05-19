/*
  msp_inav.h

  INAV-specific MSP frame IDs, constants, and payload structures.
  All names are prefixed with INAV_ to distinguish them from generic MSP symbols.
*/

#pragma once

#include <Arduino.h>
#include "msp.h"

// ============================================================
// INAV MSP Frame IDs
// ============================================================

// Info / Version
#define INAV_MSP_API_VERSION                    1
#define INAV_MSP_FC_VARIANT                     2
#define INAV_MSP_FC_VERSION                     3
#define INAV_MSP_BOARD_INFO                     4
#define INAV_MSP_BUILD_INFO                     5
#define INAV_MSP_INAV_PID                       6
#define INAV_MSP_SET_INAV_PID                   7
#define INAV_MSP_NAME                          10
#define INAV_MSP_SET_NAME                      11
#define INAV_MSP_NAV_POSHOLD                   12
#define INAV_MSP_SET_NAV_POSHOLD               13
#define INAV_MSP_CALIBRATION_DATA              14
#define INAV_MSP_SET_CALIBRATION_DATA          15
#define INAV_MSP_POSITION_ESTIMATION_CONFIG    16
#define INAV_MSP_SET_POSITION_ESTIMATION_CONFIG 17
#define INAV_MSP_WP_MISSION_LOAD               18
#define INAV_MSP_WP_MISSION_SAVE               19
#define INAV_MSP_WP_GETINFO                    20
#define INAV_MSP_RTH_AND_LAND_CONFIG           21
#define INAV_MSP_SET_RTH_AND_LAND_CONFIG       22
#define INAV_MSP_FW_CONFIG                     23
#define INAV_MSP_SET_FW_CONFIG                 24

// Mode ranges / Config
#define INAV_MSP_MODE_RANGES                   34
#define INAV_MSP_SET_MODE_RANGE                35
#define INAV_MSP_FEATURE                       36
#define INAV_MSP_SET_FEATURE                   37
#define INAV_MSP_BOARD_ALIGNMENT               38
#define INAV_MSP_SET_BOARD_ALIGNMENT           39
#define INAV_MSP_CURRENT_METER_CONFIG          40
#define INAV_MSP_SET_CURRENT_METER_CONFIG      41
#define INAV_MSP_MIXER                         42
#define INAV_MSP_SET_MIXER                     43
#define INAV_MSP_RX_CONFIG                     44
#define INAV_MSP_SET_RX_CONFIG                 45
#define INAV_MSP_LED_COLORS                    46
#define INAV_MSP_SET_LED_COLORS                47
#define INAV_MSP_LED_STRIP_CONFIG              48
#define INAV_MSP_SET_LED_STRIP_CONFIG          49
#define INAV_MSP_RSSI_CONFIG                   50
#define INAV_MSP_SET_RSSI_CONFIG               51
#define INAV_MSP_ADJUSTMENT_RANGES             52
#define INAV_MSP_SET_ADJUSTMENT_RANGE          53
#define INAV_MSP_VOLTAGE_METER_CONFIG          56
#define INAV_MSP_SET_VOLTAGE_METER_CONFIG      57
#define INAV_MSP_SONAR_ALTITUDE                58
#define INAV_MSP_ARMING_CONFIG                 61
#define INAV_MSP_RX_MAP                        64
#define INAV_MSP_SET_RX_MAP                    65
#define INAV_MSP_DATAFLASH_SUMMARY             70
#define INAV_MSP_DATAFLASH_READ                71
#define INAV_MSP_DATAFLASH_ERASE               72
#define INAV_MSP_LOOP_TIME                     73
#define INAV_MSP_SET_LOOP_TIME                 74
#define INAV_MSP_FAILSAFE_CONFIG               75
#define INAV_MSP_SET_FAILSAFE_CONFIG           76
#define INAV_MSP_SDCARD_SUMMARY                79
#define INAV_MSP_BLACKBOX_CONFIG               80
#define INAV_MSP_OSD_CONFIG                    84
#define INAV_MSP_SET_OSD_CONFIG                85
#define INAV_MSP_OSD_CHAR_WRITE                87
#define INAV_MSP_VTX_CONFIG                    88
#define INAV_MSP_SET_VTX_CONFIG                89
#define INAV_MSP_ADVANCED_CONFIG               90
#define INAV_MSP_SET_ADVANCED_CONFIG           91
#define INAV_MSP_FILTER_CONFIG                 92
#define INAV_MSP_SET_FILTER_CONFIG             93
#define INAV_MSP_PID_ADVANCED                  94
#define INAV_MSP_SET_PID_ADVANCED              95
#define INAV_MSP_SENSOR_CONFIG                 96
#define INAV_MSP_SET_SENSOR_CONFIG             97

// Telemetry / Status
#define INAV_MSP_STATUS                       101
#define INAV_MSP_RAW_IMU                      102
#define INAV_MSP_SERVO                        103
#define INAV_MSP_MOTOR                        104
#define INAV_MSP_RC                           105
#define INAV_MSP_RAW_GPS                      106
#define INAV_MSP_COMP_GPS                     107
#define INAV_MSP_ATTITUDE                     108
#define INAV_MSP_ALTITUDE                     109
#define INAV_MSP_ANALOG                       110
#define INAV_MSP_RC_TUNING                    111
#define INAV_MSP_PID                          112
#define INAV_MSP_ACTIVEBOXES                  113
#define INAV_MSP_MISC                         114
#define INAV_MSP_BOXNAMES                     116
#define INAV_MSP_PIDNAMES                     117
#define INAV_MSP_WP                           118
#define INAV_MSP_BOXIDS                       119
#define INAV_MSP_SERVO_CONFIGURATIONS         120
#define INAV_MSP_NAV_STATUS                   121
#define INAV_MSP_3D                           124
#define INAV_MSP_RC_DEADBAND                  125
#define INAV_MSP_SENSOR_ALIGNMENT             126
#define INAV_MSP_LED_STRIP_MODECOLOR          127
#define INAV_MSP_BATTERY_STATE                130
#define INAV_MSP_VTXTABLE_POWERLEVEL          138
#define INAV_MSP_STATUS_EX                    150
#define INAV_MSP_SENSOR_STATUS                151
#define INAV_MSP_UID                          160
#define INAV_MSP_GPSSVINFO                    164
#define INAV_MSP_GPSSTATISTICS                166
#define INAV_MSP_SET_TX_INFO                  186
#define INAV_MSP_TX_INFO                      187

// MSP2 INAV frames
#define INAV_MSP2_INAV_STATUS              0x2000

// MSP2 Common frames
#define INAV_MSP2_COMMON_TZ                0x1001
#define INAV_MSP2_COMMON_SET_TZ            0x1002
#define INAV_MSP2_COMMON_SETTING           0x1003
#define INAV_MSP2_COMMON_SET_SETTING       0x1004
#define INAV_MSP2_COMMON_MOTOR_MIXER       0x1005
#define INAV_MSP2_COMMON_SET_MOTOR_MIXER   0x1006
#define INAV_MSP2_COMMON_SETTING_INFO      0x1007
#define INAV_MSP2_COMMON_PG_LIST           0x1008
#define INAV_MSP2_COMMON_SERIAL_CONFIG     0x1009
#define INAV_MSP2_COMMON_SET_SERIAL_CONFIG 0x100A
#define INAV_MSP2_COMMON_SET_RADAR_POS     0x100B
#define INAV_MSP2_COMMON_SET_MSP_RC_LINK_STATS 0x100D
#define INAV_MSP2_COMMON_SET_MSP_RC_INFO   0x100E
#define INAV_MSP2_COMMON_GET_RADAR_GPS     0x100F

// MSP2 Sensor frames
#define INAV_MSP2_SENSOR_RANGEFINDER       0x1F01
#define INAV_MSP2_SENSOR_OPTIC_FLOW        0x1F02
#define INAV_MSP2_SENSOR_GPS               0x1F03
#define INAV_MSP2_SENSOR_COMPASS           0x1F04
#define INAV_MSP2_SENSOR_BAROMETER         0x1F05
#define INAV_MSP2_SENSOR_AIRSPEED          0x1F06
#define INAV_MSP2_SENSOR_HEADTRACKER       0x1F07

// MSP2 INAV extended frames
#define INAV_MSP2_INAV_OPTICAL_FLOW           0x2001
#define INAV_MSP2_INAV_ANALOG                 0x2002
#define INAV_MSP2_INAV_MISC                   0x2003
#define INAV_MSP2_INAV_SET_MISC               0x2004
#define INAV_MSP2_INAV_BATTERY_CONFIG         0x2005
#define INAV_MSP2_INAV_SET_BATTERY_CONFIG     0x2006
#define INAV_MSP2_INAV_RATE_PROFILE           0x2007
#define INAV_MSP2_INAV_SET_RATE_PROFILE       0x2008
#define INAV_MSP2_INAV_AIR_SPEED              0x2009
#define INAV_MSP2_INAV_OUTPUT_MAPPING         0x200A
#define INAV_MSP2_INAV_MC_BRAKING             0x200B
#define INAV_MSP2_INAV_SET_MC_BRAKING         0x200C
#define INAV_MSP2_INAV_OUTPUT_MAPPING_EXT     0x200D
#define INAV_MSP2_INAV_TIMER_OUTPUT_MODE      0x200E
#define INAV_MSP2_INAV_SET_TIMER_OUTPUT_MODE  0x200F
#define INAV_MSP2_INAV_MIXER                  0x2010
#define INAV_MSP2_INAV_SET_MIXER              0x2011
#define INAV_MSP2_INAV_OSD_LAYOUTS            0x2012
#define INAV_MSP2_INAV_OSD_SET_LAYOUT_ITEM    0x2013
#define INAV_MSP2_INAV_OSD_ALARMS             0x2014
#define INAV_MSP2_INAV_OSD_SET_ALARMS         0x2015
#define INAV_MSP2_INAV_OSD_PREFERENCES        0x2016
#define INAV_MSP2_INAV_OSD_SET_PREFERENCES    0x2017
#define INAV_MSP2_INAV_SELECT_BATTERY_PROFILE 0x2018
#define INAV_MSP2_INAV_DEBUG                  0x2019
#define INAV_MSP2_BLACKBOX_CONFIG             0x201A
#define INAV_MSP2_SET_BLACKBOX_CONFIG         0x201B
#define INAV_MSP2_INAV_TEMP_SENSOR_CONFIG     0x201C
#define INAV_MSP2_INAV_SET_TEMP_SENSOR_CONFIG 0x201D
#define INAV_MSP2_INAV_TEMPERATURES           0x201E
#define INAV_MSP2_INAV_SIMULATOR              0x201F
#define INAV_MSP2_INAV_SERVO_MIXER            0x2020
#define INAV_MSP2_INAV_SET_SERVO_MIXER        0x2021
#define INAV_MSP2_INAV_LOGIC_CONDITIONS       0x2022
#define INAV_MSP2_INAV_SET_LOGIC_CONDITIONS   0x2023
#define INAV_MSP2_INAV_LOGIC_CONDITIONS_STATUS 0x2026
#define INAV_MSP2_INAV_GVAR_STATUS            0x2027
#define INAV_MSP2_INAV_PROGRAMMING_PID        0x2028
#define INAV_MSP2_INAV_SET_PROGRAMMING_PID    0x2029
#define INAV_MSP2_INAV_PROGRAMMING_PID_STATUS 0x202A
#define INAV_MSP2_PID                         0x2030
#define INAV_MSP2_SET_PID                     0x2031
#define INAV_MSP2_INAV_OPFLOW_CALIBRATION     0x2032
#define INAV_MSP2_INAV_FWUPDT_PREPARE        0x2033
#define INAV_MSP2_INAV_FWUPDT_STORE          0x2034
#define INAV_MSP2_INAV_FWUPDT_EXEC           0x2035
#define INAV_MSP2_INAV_FWUPDT_ROLLBACK_PREPARE 0x2036
#define INAV_MSP2_INAV_FWUPDT_ROLLBACK_EXEC  0x2037
#define INAV_MSP2_INAV_SAFEHOME               0x2038
#define INAV_MSP2_INAV_SET_SAFEHOME           0x2039
#define INAV_MSP2_INAV_MISC2                  0x203A
#define INAV_MSP2_INAV_LOGIC_CONDITIONS_SINGLE 0x203B
#define INAV_MSP2_INAV_LOGIC_CONDITIONS_CONFIGURED 0x203C
#define INAV_MSP2_INAV_ESC_RPM                0x2040
#define INAV_MSP2_INAV_ESC_TELEM             0x2041
#define INAV_MSP2_INAV_LED_STRIP_CONFIG_EX    0x2048
#define INAV_MSP2_INAV_SET_LED_STRIP_CONFIG_EX 0x2049
#define INAV_MSP2_INAV_FW_APPROACH            0x204A
#define INAV_MSP2_INAV_SET_FW_APPROACH        0x204B
#define INAV_MSP2_INAV_GPS_UBLOX_COMMAND      0x2050
#define INAV_MSP2_INAV_RATE_DYNAMICS          0x2060
#define INAV_MSP2_INAV_SET_RATE_DYNAMICS      0x2061
#define INAV_MSP2_INAV_EZ_TUNE               0x2070
#define INAV_MSP2_INAV_EZ_TUNE_SET           0x2071
#define INAV_MSP2_INAV_SELECT_MIXER_PROFILE   0x2080
#define INAV_MSP2_ADSB_VEHICLE_LIST           0x2090
#define INAV_MSP2_INAV_CUSTOM_OSD_ELEMENTS    0x2100
#define INAV_MSP2_INAV_CUSTOM_OSD_ELEMENT     0x2101
#define INAV_MSP2_INAV_SET_CUSTOM_OSD_ELEMENTS 0x2102
#define INAV_MSP2_INAV_OUTPUT_MAPPING_EXT2    0x210D
#define INAV_MSP2_INAV_OSD_UPDATE_POSITION    0x2118
#define INAV_MSP2_INAV_SERVO_CONFIG           0x2200
#define INAV_MSP2_INAV_SET_SERVO_CONFIG       0x2201
#define INAV_MSP2_INAV_GEOZONE                0x2210
#define INAV_MSP2_INAV_SET_GEOZONE            0x2211
#define INAV_MSP2_INAV_GEOZONE_VERTEX         0x2212
#define INAV_MSP2_INAV_SET_GEOZONE_VERTEX     0x2213
#define INAV_MSP2_INAV_SET_GVAR               0x2214
#define INAV_MSP2_INAV_SET_ALT_TARGET         0x2215
#define INAV_MSP2_INAV_FLIGHT_AXIS_ANGLE_OVERRIDE 0x2216
#define INAV_MSP2_INAV_FLIGHT_AXIS_RATE_OVERRIDE  0x2217
#define INAV_MSP2_INAV_SET_LOCAL_TARGET       0x2218
#define INAV_MSP2_INAV_LOCAL_TARGET           0x2219
#define INAV_MSP2_INAV_SET_GLOBAL_TARGET      0x221A
#define INAV_MSP2_INAV_NAV_TARGET             0x221B
#define INAV_MSP2_INAV_FULL_LOCAL_POSE        0x2220
#define INAV_MSP2_BETAFLIGHT_BIND             0x3000

// Commands
#define INAV_MSP_SET_RAW_RC                   200
#define INAV_MSP_SET_RAW_GPS                  201
#define INAV_MSP_SET_PID                      202
#define INAV_MSP_SET_RC_TUNING                204
#define INAV_MSP_ACC_CALIBRATION              205
#define INAV_MSP_MAG_CALIBRATION              206
#define INAV_MSP_SET_MISC                     207
#define INAV_MSP_RESET_CONF                   208
#define INAV_MSP_SET_WP                       209
#define INAV_MSP_SELECT_SETTING               210
#define INAV_MSP_SET_HEAD                     211
#define INAV_MSP_SET_SERVO_CONFIGURATION      212
#define INAV_MSP_SET_MOTOR                    214
#define INAV_MSP_SET_3D                       217
#define INAV_MSP_SET_RC_DEADBAND              218
#define INAV_MSP_SET_RESET_CURR_PID           219
#define INAV_MSP_SET_SENSOR_ALIGNMENT         220
#define INAV_MSP_SET_LED_STRIP_MODECOLOR      221
#define INAV_MSP_SERVO_MIX_RULES             241
#define INAV_MSP_SET_SERVO_MIX_RULE          242
#define INAV_MSP_RTC                          246
#define INAV_MSP_SET_RTC                      247
#define INAV_MSP_EEPROM_WRITE                 250
#define INAV_MSP_DEBUG                        254

// ============================================================
// Status sensor flags (INAV_msp_status_t.sensor / INAV_msp_status_ex_t.sensor)
// ============================================================

#define INAV_MSP_STATUS_SENSOR_ACC    1
#define INAV_MSP_STATUS_SENSOR_BARO   2
#define INAV_MSP_STATUS_SENSOR_MAG    4
#define INAV_MSP_STATUS_SENSOR_GPS    8
#define INAV_MSP_STATUS_SENSOR_SONAR 16


// ============================================================
// Feature mask bits (INAV_msp_feature_t.featureMask)
// ============================================================

#define INAV_MSP_FEATURE_RX_PPM              (1 <<  0)
#define INAV_MSP_FEATURE_VBAT                (1 <<  1)
#define INAV_MSP_FEATURE_UNUSED_1            (1 <<  2)
#define INAV_MSP_FEATURE_RX_SERIAL           (1 <<  3)
#define INAV_MSP_FEATURE_MOTOR_STOP          (1 <<  4)
#define INAV_MSP_FEATURE_SERVO_TILT          (1 <<  5)
#define INAV_MSP_FEATURE_SOFTSERIAL          (1 <<  6)
#define INAV_MSP_FEATURE_GPS                 (1 <<  7)
#define INAV_MSP_FEATURE_UNUSED_3            (1 <<  8)
#define INAV_MSP_FEATURE_UNUSED_4            (1 <<  9)
#define INAV_MSP_FEATURE_TELEMETRY           (1 << 10)
#define INAV_MSP_FEATURE_CURRENT_METER       (1 << 11)
#define INAV_MSP_FEATURE_3D                  (1 << 12)
#define INAV_MSP_FEATURE_RX_PARALLEL_PWM     (1 << 13)
#define INAV_MSP_FEATURE_RX_MSP              (1 << 14)
#define INAV_MSP_FEATURE_RSSI_ADC            (1 << 15)
#define INAV_MSP_FEATURE_LED_STRIP           (1 << 16)
#define INAV_MSP_FEATURE_DASHBOARD           (1 << 17)
#define INAV_MSP_FEATURE_UNUSED_2            (1 << 18)
#define INAV_MSP_FEATURE_BLACKBOX            (1 << 19)
#define INAV_MSP_FEATURE_CHANNEL_FORWARDING  (1 << 20)
#define INAV_MSP_FEATURE_TRANSPONDER         (1 << 21)
#define INAV_MSP_FEATURE_AIRMODE             (1 << 22)
#define INAV_MSP_FEATURE_SUPEREXPO_RATES     (1 << 23)
#define INAV_MSP_FEATURE_VTX                 (1 << 24)
#define INAV_MSP_FEATURE_RX_SPI              (1 << 25)
#define INAV_MSP_FEATURE_SOFTSPI             (1 << 26)
#define INAV_MSP_FEATURE_PWM_SERVO_DRIVER    (1 << 27)
#define INAV_MSP_FEATURE_PWM_OUTPUT_ENABLE   (1 << 28)
#define INAV_MSP_FEATURE_OSD                 (1 << 29)


// ============================================================
// GPS fix types (INAV_msp_raw_gps_t.fixType)
// ============================================================

#define INAV_MSP_GPS_NO_FIX 0
#define INAV_MSP_GPS_FIX_2D 1
#define INAV_MSP_GPS_FIX_3D 2


// ============================================================
// Sensor alignment values (INAV_msp_sensor_alignment_t fields)
// ============================================================

#define INAV_MSP_SENSOR_ALIGN_CW0_DEG        1
#define INAV_MSP_SENSOR_ALIGN_CW90_DEG       2
#define INAV_MSP_SENSOR_ALIGN_CW180_DEG      3
#define INAV_MSP_SENSOR_ALIGN_CW270_DEG      4
#define INAV_MSP_SENSOR_ALIGN_CW0_DEG_FLIP   5
#define INAV_MSP_SENSOR_ALIGN_CW90_DEG_FLIP  6
#define INAV_MSP_SENSOR_ALIGN_CW180_DEG_FLIP 7
#define INAV_MSP_SENSOR_ALIGN_CW270_DEG_FLIP 8


// ============================================================
// Current meter types (INAV_msp_current_meter_config_t.currentMeterType)
// ============================================================

#define INAV_MSP_CURRENT_SENSOR_NONE    0
#define INAV_MSP_CURRENT_SENSOR_ADC     1
#define INAV_MSP_CURRENT_SENSOR_VIRTUAL 2


// ============================================================
// Serial RX provider values (INAV_msp_rx_config_t.serialrx_provider)
// ============================================================

#define INAV_MSP_SERIALRX_SPEKTRUM1024      0
#define INAV_MSP_SERIALRX_SPEKTRUM2048      1
#define INAV_MSP_SERIALRX_SBUS              2
#define INAV_MSP_SERIALRX_SUMD              3
#define INAV_MSP_SERIALRX_SUMH              4
#define INAV_MSP_SERIALRX_XBUS_MODE_B       5
#define INAV_MSP_SERIALRX_XBUS_MODE_B_RJ01  6
#define INAV_MSP_SERIALRX_IBUS              7
#define INAV_MSP_SERIALRX_JETIEXBUS         8
#define INAV_MSP_SERIALRX_CRSF              9


// ============================================================
// RX SPI protocol values (INAV_msp_rx_config_t.rx_spi_protocol)
// ============================================================

#define INAV_MSP_SPI_PROT_NRF24RX_V202_250K 0
#define INAV_MSP_SPI_PROT_NRF24RX_V202_1M   1
#define INAV_MSP_SPI_PROT_NRF24RX_SYMA_X    2
#define INAV_MSP_SPI_PROT_NRF24RX_SYMA_X5C  3
#define INAV_MSP_SPI_PROT_NRF24RX_CX10      4
#define INAV_MSP_SPI_PROT_NRF24RX_CX10A     5
#define INAV_MSP_SPI_PROT_NRF24RX_H8_3D     6
#define INAV_MSP_SPI_PROT_NRF24RX_INAV      7


// ============================================================
// Nav status constants
// ============================================================

// INAV_msp_nav_status_t.mode values
#define INAV_MSP_NAV_STATUS_MODE_NONE   0
#define INAV_MSP_NAV_STATUS_MODE_HOLD   1
#define INAV_MSP_NAV_STATUS_MODE_RTH    2
#define INAV_MSP_NAV_STATUS_MODE_NAV    3
#define INAV_MSP_NAV_STATUS_MODE_EMERG 15

// INAV_msp_nav_status_t.state values
#define INAV_MSP_NAV_STATUS_STATE_NONE                0
#define INAV_MSP_NAV_STATUS_STATE_RTH_START           1
#define INAV_MSP_NAV_STATUS_STATE_RTH_ENROUTE         2
#define INAV_MSP_NAV_STATUS_STATE_HOLD_INFINIT        3
#define INAV_MSP_NAV_STATUS_STATE_HOLD_TIMED          4
#define INAV_MSP_NAV_STATUS_STATE_WP_ENROUTE          5
#define INAV_MSP_NAV_STATUS_STATE_PROCESS_NEXT        6
#define INAV_MSP_NAV_STATUS_STATE_DO_JUMP             7
#define INAV_MSP_NAV_STATUS_STATE_LAND_START          8
#define INAV_MSP_NAV_STATUS_STATE_LAND_IN_PROGRESS    9
#define INAV_MSP_NAV_STATUS_STATE_LANDED             10
#define INAV_MSP_NAV_STATUS_STATE_LAND_SETTLE        11
#define INAV_MSP_NAV_STATUS_STATE_LAND_START_DESCENT 12

// INAV_msp_nav_status_t.activeWpAction / INAV_msp_set_wp_t.action values
#define INAV_MSP_NAV_STATUS_WAYPOINT_ACTION_WAYPOINT 0x01
#define INAV_MSP_NAV_STATUS_WAYPOINT_ACTION_RTH      0x04

// INAV_msp_nav_status_t.error values
#define INAV_MSP_NAV_STATUS_ERROR_NONE               0
#define INAV_MSP_NAV_STATUS_ERROR_TOOFAR             1
#define INAV_MSP_NAV_STATUS_ERROR_SPOILED_GPS        2
#define INAV_MSP_NAV_STATUS_ERROR_WP_CRC             3
#define INAV_MSP_NAV_STATUS_ERROR_FINISH             4
#define INAV_MSP_NAV_STATUS_ERROR_TIMEWAIT           5
#define INAV_MSP_NAV_STATUS_ERROR_INVALID_JUMP       6
#define INAV_MSP_NAV_STATUS_ERROR_INVALID_DATA       7
#define INAV_MSP_NAV_STATUS_ERROR_WAIT_FOR_RTH_ALT   8
#define INAV_MSP_NAV_STATUS_ERROR_GPS_FIX_LOST       9
#define INAV_MSP_NAV_STATUS_ERROR_DISARMED          10
#define INAV_MSP_NAV_STATUS_ERROR_LANDING           11


// ============================================================
// Array size constants
// ============================================================

#define INAV_MSP_MAX_SUPPORTED_SERVOS   8
#define INAV_MSP_MAX_SERVO_RULES       16
#define INAV_MSP_MAX_SUPPORTED_MOTORS   8
#define INAV_MSP_MAX_SUPPORTED_CHANNELS 16
#define INAV_MSP_MAX_MAPPABLE_RX_INPUTS 8


// ============================================================
// Payload structures
// ============================================================

// INAV_MSP_API_VERSION reply
struct INAV_msp_api_version_t {
  uint8_t protocolVersion;
  uint8_t APIMajor;
  uint8_t APIMinor;
} __attribute__((packed));


// INAV_MSP_FC_VARIANT reply
struct INAV_msp_fc_variant_t {
  char flightControlIdentifier[32];
} __attribute__((packed));


// INAV_MSP_FC_VERSION reply
struct INAV_msp_fc_version_t {
  uint8_t versionMajor;
  uint8_t versionMinor;
  uint8_t versionPatchLevel;
} __attribute__((packed));


// INAV_MSP_BOARD_INFO reply
struct INAV_msp_board_info_t {
  char     boardIdentifier[4];
  uint16_t hardwareRevision;
} __attribute__((packed));


// INAV_MSP_BUILD_INFO reply
struct INAV_msp_build_info_t {
  char buildDate[11];
  char buildTime[8];
  char shortGitRevision[7];
} __attribute__((packed));


// INAV_MSP_INAV_PID reply
struct INAV_msp_inav_pid_t {
  uint8_t asyncMode;
  uint16_t rateTaskFrequency;
  uint16_t attitudeTaskFrequency;
  uint16_t velocityTaskFrequency;
  uint8_t  magHoldRateLimit;
  uint8_t  magHoldErrorLimitYaw;
  uint16_t yawJumpPreventionLimit;
  uint8_t  gyroLpf;
  uint8_t  accSoftLpfHz;
  uint8_t  reserved0;
  uint8_t  reserved1;
  uint8_t  reserved2;
  uint8_t  reserved3;
} __attribute__((packed));


// INAV_MSP_NAV_POSHOLD reply
struct INAV_msp_nav_poshold_t {
  uint8_t  userControlMode;
  uint16_t maxSpeed;           // cm/s
  uint16_t maxClimbRate;       // cm/s
  uint16_t maxManualSpeed;     // cm/s
  uint16_t maxManualClimbRate; // cm/s
  uint8_t  maxBankAngle;       // deg
  uint8_t  usePosHoldMode;
  uint16_t hoverThrottle;
} __attribute__((packed));


// INAV_MSP_POSITION_ESTIMATION_CONFIG reply
struct INAV_msp_position_estimation_config_t {
  uint16_t wZBaroP;       // scaled x100
  uint16_t wZGpsP;        // scaled x100
  uint16_t wZGpsV;        // scaled x100
  uint16_t wXYGpsP;       // scaled x100
  uint16_t wXYGpsV;       // scaled x100
  uint8_t  gpsMinSats;
  uint8_t  useGpsVelNed;
} __attribute__((packed));


// INAV_MSP_WP_GETINFO reply
struct INAV_msp_wp_getinfo_t {
  uint8_t  reserved;
  uint8_t  capabilities;
  uint8_t  maxWaypoints;
  uint8_t  waypointCount;
} __attribute__((packed));


// INAV_MSP_RTH_AND_LAND_CONFIG reply
struct INAV_msp_rth_and_land_config_t {
  uint16_t minRthDistance;          // m
  uint8_t  rthClimbFirst;
  uint8_t  rthClimbIgnoreEmergency;
  uint8_t  rthTailFirst;
  uint8_t  rthAllowLanding;
  uint8_t  rthAltControlMode;
  uint16_t rthAbortThreshold;       // cm/s
  uint16_t rthAltitude;             // cm
  uint16_t landDescentRate;         // cm/s
  uint16_t landSlowdownMinAlt;      // cm
  uint16_t landSlowdownMaxAlt;      // cm
  uint16_t emergDescentRate;        // cm/s
} __attribute__((packed));


// INAV_MSP_FW_CONFIG reply
struct INAV_msp_fw_config_t {
  uint16_t cruiseThrottle;
  uint16_t minThrottle;
  uint16_t maxThrottle;
  uint8_t  maxBankAngle;    // deg
  uint8_t  maxClimbAngle;   // deg
  uint8_t  maxDiveAngle;    // deg
  uint8_t  pitchToThrottle;
  uint16_t loiterRadius;    // cm
} __attribute__((packed));


// INAV_MSP_RAW_IMU reply
struct INAV_msp_raw_imu_t {
  int16_t acc[3];   // x, y, z
  int16_t gyro[3];  // x, y, z
  int16_t mag[3];   // x, y, z
} __attribute__((packed));


// INAV_MSP_STATUS reply
struct INAV_msp_status_t {
  uint16_t cycleTime;
  uint16_t i2cErrorCounter;
  uint16_t sensor;           // INAV_MSP_STATUS_SENSOR_...
  uint32_t flightModeFlags;  // see INAV_MSP_MODE_...
  uint8_t  configProfileIndex;
} __attribute__((packed));


// INAV_MSP2_INAV_STATUS reply
struct INAV_msp2_inav_status_t {
  uint16_t cycleTime;
  uint16_t i2cErrorCounter;
  uint16_t sensorStatus;
  uint16_t averageSystemLoadPercent;
  uint8_t  configProfileIndex;
  uint32_t armingFlags;
  uint8_t  msp_box_mode_flags_bytes[8];
  uint8_t  configMixerProfile;
} __attribute__((packed));


// INAV_MSP_STATUS_EX reply
struct INAV_msp_status_ex_t {
  uint16_t cycleTime;
  uint16_t i2cErrorCounter;
  uint16_t sensor;                   // INAV_MSP_STATUS_SENSOR_...
  uint32_t flightModeFlags;          // see INAV_MSP_MODE_...
  uint8_t  configProfileIndex;
  uint16_t averageSystemLoadPercent; // 0...100
  uint16_t armingFlags;
  uint8_t  accCalibrationAxisFlags;
} __attribute__((packed));


// INAV_MSP_SENSOR_STATUS reply
struct INAV_msp_sensor_status_t {
  uint8_t isHardwareHealthy;
  uint8_t hwGyroStatus;
  uint8_t hwAccelerometerStatus;
  uint8_t hwCompassStatus;
  uint8_t hwBarometerStatus;
  uint8_t hwGPSStatus;
  uint8_t hwRangefinderStatus;
  uint8_t hwPitotmeterStatus;
  uint8_t hwOpticalFlowStatus;
} __attribute__((packed));


// INAV_MSP_SERVO reply
struct INAV_msp_servo_t {
  uint16_t servo[INAV_MSP_MAX_SUPPORTED_SERVOS];
} __attribute__((packed));


// INAV_MSP_SERVO_CONFIGURATIONS reply
struct INAV_msp_servo_configurations_t {
  __attribute__((packed)) struct {
    uint16_t min;
    uint16_t max;
    uint16_t middle;
    uint8_t  rate;
    uint8_t  angleAtMin;
    uint8_t  angleAtMax;
    uint8_t  forwardFromChannel;
    uint32_t reversedSources;
  } conf[INAV_MSP_MAX_SUPPORTED_SERVOS];
} __attribute__((packed));


// INAV_MSP_SERVO_MIX_RULES reply (not a frame ID in the list above, used internally)
struct INAV_msp_servo_mix_rules_t {
  struct __attribute__((packed)) {
    uint8_t targetChannel;
    uint8_t inputSource;
    uint8_t rate;
    uint8_t speed;
    uint8_t min;
    uint8_t max;
  } mixRule[INAV_MSP_MAX_SERVO_RULES];
} __attribute__((packed));


// INAV_MSP_MOTOR reply
struct INAV_msp_motor_t {
  uint16_t motor[INAV_MSP_MAX_SUPPORTED_MOTORS];
} __attribute__((packed));


// INAV_MSP_RC reply
struct INAV_msp_rc_t {
  uint16_t channelValue[INAV_MSP_MAX_SUPPORTED_CHANNELS];
} __attribute__((packed));


// INAV_MSP_ATTITUDE reply
struct INAV_msp_attitude_t {
  int16_t roll;
  int16_t pitch;
  int16_t yaw;
} __attribute__((packed));


// INAV_MSP_ALTITUDE reply
struct INAV_msp_altitude_t {
  int32_t estimatedActualPosition;  // cm
  int16_t estimatedActualVelocity;  // cm/s
  int32_t baroLatestAltitude;
} __attribute__((packed));


// INAV_MSP_SONAR_ALTITUDE reply
struct INAV_msp_sonar_altitude_t {
  int32_t altitude;
} __attribute__((packed));


// INAV_MSP_ANALOG reply
struct INAV_msp_analog_t {
  uint8_t  vbat;       // 0...255
  uint16_t mAhDrawn;   // milliamp hours drawn from battery
  uint16_t rssi;       // 0..1023
  int16_t  amperage;   // 0.01 A steps, range -320A to 320A
} __attribute__((packed));


// INAV_MSP_ARMING_CONFIG reply
struct INAV_msp_arming_config_t {
  uint8_t auto_disarm_delay;
  uint8_t disarm_kill_switch;
} __attribute__((packed));


// INAV_MSP_LOOP_TIME reply
struct INAV_msp_loop_time_t {
  uint16_t looptime;
} __attribute__((packed));


// INAV_MSP_RC_TUNING reply
struct INAV_msp_rc_tuning_t {
  uint8_t  rcRate8;       // no longer used
  uint8_t  rcExpo8;
  uint8_t  rates[3];      // R, P, Y
  uint8_t  dynThrPID;
  uint8_t  thrMid8;
  uint8_t  thrExpo8;
  uint16_t tpa_breakpoint;
  uint8_t  rcYawExpo8;
} __attribute__((packed));


// INAV_MSP_PID reply
struct INAV_msp_pid_t {
  uint8_t roll[3];     // 0=P, 1=I, 2=D
  uint8_t pitch[3];    // 0=P, 1=I, 2=D
  uint8_t yaw[3];      // 0=P, 1=I, 2=D
  uint8_t pos_z[3];    // 0=P, 1=I, 2=D
  uint8_t pos_xy[3];   // 0=P, 1=I, 2=D
  uint8_t vel_xy[3];   // 0=P, 1=I, 2=D
  uint8_t surface[3];  // 0=P, 1=I, 2=D
  uint8_t level[3];    // 0=P, 1=I, 2=D
  uint8_t heading[3];  // 0=P, 1=I, 2=D
  uint8_t vel_z[3];    // 0=P, 1=I, 2=D
} __attribute__((packed));


// INAV_MSP_ACTIVEBOXES reply — variable-length; one bit per box, LSB first.
// Byte count = ceil(number_of_boxes / 8). Use INAV_MSP_BOXIDS to map bit
// positions to box IDs.
struct INAV_msp_activeboxes_t {
  uint8_t flags[8];  // up to 64 boxes; actual length determined by frame size
} __attribute__((packed));


// INAV_MSP_MISC reply
struct INAV_msp_misc_t {
  uint16_t midrc;
  uint16_t minthrottle;
  uint16_t maxthrottle;
  uint16_t mincommand;
  uint16_t failsafe_throttle;
  uint8_t  gps_provider;
  uint8_t  gps_baudrate;
  uint8_t  gps_ubx_sbas;
  uint8_t  multiwiiCurrentMeterOutput;
  uint8_t  rssi_channel;
  uint8_t  dummy;
  uint16_t mag_declination;
  uint8_t  vbatscale;
  uint8_t  vbatmincellvoltage;
  uint8_t  vbatmaxcellvoltage;
  uint8_t  vbatwarningcellvoltage;
} __attribute__((packed));


// INAV_MSP_RAW_GPS reply
struct INAV_msp_raw_gps_t {
  uint8_t  fixType;       // INAV_MSP_GPS_NO_FIX / FIX_2D / FIX_3D
  uint8_t  numSat;
  int32_t  lat;           // 1 / 10000000 deg
  int32_t  lon;           // 1 / 10000000 deg
  int16_t  alt;           // meters
  int16_t  groundSpeed;   // cm/s
  int16_t  groundCourse;  // degree x 10
  uint16_t hdop;
} __attribute__((packed));


// INAV_MSP_COMP_GPS reply
struct INAV_msp_comp_gps_t {
  int16_t distanceToHome;   // meters
  int16_t directionToHome;  // degrees
  uint8_t heartbeat;        // toggles 0/1 each change
} __attribute__((packed));


// INAV_MSP_NAV_STATUS reply
struct INAV_msp_nav_status_t {
  uint8_t mode;            // INAV_MSP_NAV_STATUS_MODE_...
  uint8_t state;           // INAV_MSP_NAV_STATUS_STATE_...
  uint8_t activeWpAction;  // INAV_MSP_NAV_STATUS_WAYPOINT_ACTION_...
  uint8_t activeWpNumber;
  uint8_t error;           // INAV_MSP_NAV_STATUS_ERROR_...
  int16_t magHoldHeading;
} __attribute__((packed));


// INAV_MSP_GPSSVINFO reply
struct INAV_msp_gpssvinfo_t {
  uint8_t dummy1;
  uint8_t dummy2;
  uint8_t dummy3;
  uint8_t dummy4;
  uint8_t HDOP;
} __attribute__((packed));


// INAV_MSP_GPSSTATISTICS reply
struct INAV_msp_gpsstatistics_t {
  uint16_t lastMessageDt;
  uint32_t errors;
  uint32_t timeouts;
  uint32_t packetCount;
  uint16_t hdop;
  uint16_t eph;
  uint16_t epv;
} __attribute__((packed));


// INAV_MSP_UID reply
struct INAV_msp_uid_t {
  uint32_t uid0;
  uint32_t uid1;
  uint32_t uid2;
} __attribute__((packed));


// INAV_MSP_FEATURE reply
struct INAV_msp_feature_t {
  uint32_t featureMask;  // INAV_MSP_FEATURE_...
} __attribute__((packed));


// INAV_MSP_BOARD_ALIGNMENT reply
struct INAV_msp_board_alignment_t {
  int16_t rollDeciDegrees;
  int16_t pitchDeciDegrees;
  int16_t yawDeciDegrees;
} __attribute__((packed));


// INAV_MSP_CURRENT_METER_CONFIG reply
struct INAV_msp_current_meter_config_t {
  int16_t  currentMeterScale;
  int16_t  currentMeterOffset;
  uint8_t  currentMeterType;  // INAV_MSP_CURRENT_SENSOR_...
  uint16_t batteryCapacity;
} __attribute__((packed));


// INAV_MSP_RX_CONFIG reply
struct INAV_msp_rx_config_t {
  uint8_t  serialrx_provider;       // INAV_MSP_SERIALRX_...
  uint16_t maxcheck;
  uint16_t midrc;
  uint16_t mincheck;
  uint8_t  spektrum_sat_bind;
  uint16_t rx_min_usec;
  uint16_t rx_max_usec;
  uint8_t  dummy1;
  uint8_t  dummy2;
  uint16_t dummy3;
  uint8_t  rx_spi_protocol;         // INAV_MSP_SPI_PROT_...
  uint32_t rx_spi_id;
  uint8_t  rx_spi_rf_channel_count;
} __attribute__((packed));


// INAV_MSP_RX_MAP reply
struct INAV_msp_rx_map_t {
  uint8_t rxmap[INAV_MSP_MAX_MAPPABLE_RX_INPUTS];
} __attribute__((packed));


// INAV_MSP_SENSOR_ALIGNMENT reply
struct INAV_msp_sensor_alignment_t {
  uint8_t gyro_align;  // INAV_MSP_SENSOR_ALIGN_...
  uint8_t acc_align;   // INAV_MSP_SENSOR_ALIGN_...
  uint8_t mag_align;   // INAV_MSP_SENSOR_ALIGN_...
} __attribute__((packed));


// INAV_MSP_CALIBRATION_DATA reply
struct INAV_msp_calibration_data_t {
  int16_t accZeroX;
  int16_t accZeroY;
  int16_t accZeroZ;
  int16_t accGainX;
  int16_t accGainY;
  int16_t accGainZ;
  int16_t magZeroX;
  int16_t magZeroY;
  int16_t magZeroZ;
} __attribute__((packed));


// INAV_MSP_SET_HEAD command
struct INAV_msp_set_head_t {
  int16_t magHoldHeading;  // degrees
} __attribute__((packed));


// INAV_MSP_SET_RAW_RC command
struct INAV_msp_set_raw_rc_t {
  uint16_t channel[INAV_MSP_MAX_SUPPORTED_CHANNELS];
} __attribute__((packed));


// INAV_MSP_SET_PID command
typedef INAV_msp_pid_t INAV_msp_set_pid_t;


// INAV_MSP_SET_RAW_GPS command
struct INAV_msp_set_raw_gps_t {
  uint8_t fixType;      // INAV_MSP_GPS_NO_FIX / FIX_2D / FIX_3D
  uint8_t numSat;
  int32_t lat;          // 1 / 10000000 deg
  int32_t lon;          // 1 / 10000000 deg
  int16_t alt;          // meters
  int16_t groundSpeed;  // cm/s
} __attribute__((packed));


// INAV_MSP_FILTER_CONFIG reply
struct INAV_msp_filter_config_t {
  uint8_t  gyroMainLpfHz;
  uint16_t dtermLpfHz;
  uint16_t yawLpfHz;
  uint16_t gyroNotchHz1;
  uint16_t gyroNotchCutoff1;
  uint16_t dtermNotchHz;
  uint16_t dtermNotchCutoff;
  uint16_t gyroNotchHz2;
  uint16_t gyroNotchCutoff2;
  uint16_t accNotchHz;
  uint16_t accNotchCutoff;
  uint16_t gyroStage2LpfHz;
} __attribute__((packed));


// INAV_MSP_SET_FILTER_CONFIG command
typedef INAV_msp_filter_config_t INAV_msp_set_filter_config_t;


// INAV_MSP_PID_ADVANCED reply
struct INAV_msp_pid_advanced_t {
  uint16_t rollPitchItermIgnoreRate;
  uint16_t yawItermIgnoreRate;
  uint16_t yawPLimit;
  uint8_t  deltaMethod;
  uint8_t  vbatPidCompensation;
  uint8_t  setpointRelaxRatio;
  uint8_t  reserved0;
  uint16_t pidSumLimit;
  uint8_t  itermThrottleGain;
  uint16_t axisAccelerationLimitRollPitch;
  uint16_t axisAccelerationLimitYaw;
} __attribute__((packed));


// INAV_MSP_SET_PID_ADVANCED command
typedef INAV_msp_pid_advanced_t INAV_msp_set_pid_advanced_t;


// INAV_MSP_SENSOR_CONFIG reply
struct INAV_msp_sensor_config_t {
  uint8_t accHardware;
  uint8_t baroHardware;
  uint8_t reserved0;
  uint8_t magHardware;
  uint8_t reserved1;
  uint8_t pitotHardware;
  uint8_t reserved2;
  uint8_t rangefinderHardware;
  uint8_t reserved3;
  uint8_t opflowHardware;
  uint8_t reserved4;
} __attribute__((packed));


// INAV_MSP_SET_SENSOR_CONFIG command
typedef INAV_msp_sensor_config_t INAV_msp_set_sensor_config_t;


// INAV_MSP_3D reply
struct INAV_msp_3d_t {
  uint16_t deadband3dLow;
  uint16_t deadband3dHigh;
  uint16_t neutral3d;
} __attribute__((packed));


// INAV_MSP_RC_DEADBAND reply
struct INAV_msp_rc_deadband_t {
  uint8_t  deadband;
  uint8_t  yawDeadband;
  uint8_t  altHoldDeadband;
  uint16_t midThrottleDeadband;
} __attribute__((packed));


// INAV_MSP_LED_STRIP_MODECOLOR reply — variable-length repeated entries
struct INAV_msp_led_strip_modecolor_entry_t {
  uint8_t modeIdx;
  uint8_t funIdx;
  uint8_t color;
} __attribute__((packed));


// INAV_MSP_BATTERY_STATE reply
struct INAV_msp_battery_state_t {
  uint8_t  cellCount;
  uint16_t capacity;          // mAh
  uint8_t  voltage;           // 0.1 V steps
  uint16_t mAhDrawn;
  uint16_t amperage;          // 0.01 A steps
  uint8_t  batteryState;
  uint16_t batteryVoltage;    // 0.01 V steps
} __attribute__((packed));


// INAV_MSP_VTXTABLE_POWERLEVEL reply
struct INAV_msp_vtxtable_powerlevel_t {
  uint8_t  powerLevel;
  uint16_t powerValue;
  uint8_t  labelLength;
  uint8_t  label;             // first byte; actual label is labelLength bytes long
} __attribute__((packed));


// INAV_MSP_TX_INFO reply
struct INAV_msp_tx_info_t {
  uint8_t rssiSource;
  uint8_t rtcDateTimeIsSet;
} __attribute__((packed));


// INAV_MSP_SET_TX_INFO command
struct INAV_msp_set_tx_info_t {
  uint8_t rssiValue;
} __attribute__((packed));


// INAV_MSP_SET_RC_TUNING command
struct INAV_msp_set_rc_tuning_t {
  uint8_t  rcRate8;
  uint8_t  rcExpo8;
  uint8_t  rollRate;
  uint8_t  pitchRate;
  uint8_t  yawRate;
  uint8_t  dynThrPID;
  uint8_t  thrMid8;
  uint8_t  thrExpo8;
  uint16_t tpaBreakpoint;
  uint8_t  rcYawExpo8;
} __attribute__((packed));


// INAV_MSP_SET_MISC command
struct INAV_msp_set_misc_t {
  uint16_t midrc;
  uint16_t wasMinThrottle;
  uint16_t wasMaxThrottle;
  uint16_t mincommand;
  uint16_t failsafeThrottle;
  uint8_t  gpsProvider;
  uint8_t  gpsBaudrate;
  uint8_t  gpsSbasMode;
  uint8_t  gpsType;
  uint8_t  gpsBaudrate2;
  uint8_t  gpsUbxSbas;
  uint8_t  multiwiiCurrentMeterOutput;
  uint8_t  rssiChannel;
  uint8_t  reserved0;
  uint16_t magDeclination;
  uint16_t reserved1;
  uint8_t  vbatscale;
  uint8_t  vbatmincellvoltage;
  uint8_t  vbatmaxcellvoltage;
  uint8_t  vbatwarningcellvoltage;
  uint8_t  reserved2;
  uint8_t  reserved3;
  uint8_t  reserved4;
  uint8_t  reserved5;
} __attribute__((packed));


// INAV_MSP_SELECT_SETTING command
struct INAV_msp_select_setting_t {
  uint8_t profileIndex;
} __attribute__((packed));


// INAV_MSP_SET_SERVO_CONFIGURATION command
struct INAV_msp_set_servo_configuration_t {
  uint8_t  servoIndex;
  uint16_t min;
  uint16_t max;
  uint16_t middle;
  uint8_t  rate;
  uint8_t  reserved0;
  uint8_t  reserved1;
  uint8_t  reserved2;
  uint32_t reversedSources;
} __attribute__((packed));


// INAV_MSP_SET_3D command
struct INAV_msp_set_3d_t {
  uint16_t deadband3dLow;
  uint16_t deadband3dHigh;
  uint16_t neutral3d;
} __attribute__((packed));


// INAV_MSP_SET_RC_DEADBAND command
struct INAV_msp_set_rc_deadband_t {
  uint8_t  deadband;
  uint8_t  yawDeadband;
  uint8_t  altHoldDeadband;
  uint16_t midThrottleDeadband;
} __attribute__((packed));


// INAV_MSP_SET_SENSOR_ALIGNMENT command
struct INAV_msp_set_sensor_alignment_t {
  uint8_t gyroAlign;
  uint8_t accAlign;
  uint8_t magAlign;
  uint8_t reserved0;
  uint8_t opflowAlign;
  uint8_t reserved1;
} __attribute__((packed));


// INAV_MSP_SET_LED_STRIP_MODECOLOR command
struct INAV_msp_set_led_strip_modecolor_t {
  uint8_t modeIdx;
  uint8_t funIdx;
  uint8_t color;
} __attribute__((packed));


// INAV_MSP_SET_SERVO_MIX_RULE command — per-rule entry (one at a time)
struct INAV_msp_set_servo_mix_rule_t {
  uint8_t  mixerIndex;
  uint8_t  targetChannel;
  uint8_t  inputSource;
  uint16_t rate;
  uint8_t  speed;
  uint16_t minMax;    // written but ignored by firmware
  uint8_t  reserved0;
} __attribute__((packed));


// INAV_MSP_RTC reply
struct INAV_msp_rtc_t {
  uint32_t seconds;
  uint16_t millis;
} __attribute__((packed));


// INAV_MSP_SET_RTC command
struct INAV_msp_set_rtc_t {
  uint32_t seconds;
  uint16_t millis;
} __attribute__((packed));


// INAV_MSP_DEBUG reply (4 debug values, each uint16_t)
struct INAV_msp_debug_t {
  uint16_t debugValues[4];
} __attribute__((packed));


// ============================================================
// MSP2 Common payload structures
// ============================================================

// INAV_MSP2_COMMON_TZ reply
struct INAV_msp2_common_tz_t {
  int16_t tzOffset;
  uint8_t tzAutomaticDst;
} __attribute__((packed));


// INAV_MSP2_COMMON_SET_TZ command
struct INAV_msp2_common_set_tz_t {
  int16_t tzOffset;
  int16_t tzOffset2;
  uint8_t tzAutomaticDst;
} __attribute__((packed));


// INAV_MSP2_COMMON_MOTOR_MIXER reply — per-motor entry (variable number)
struct INAV_msp2_common_motor_mixer_entry_t {
  uint16_t throttle;  // float mapped to 0..1000
  uint16_t roll;
  uint16_t pitch;
  uint16_t yaw;
} __attribute__((packed));


// INAV_MSP2_COMMON_SET_MOTOR_MIXER command
struct INAV_msp2_common_set_motor_mixer_t {
  uint8_t  motorIndex;
  uint16_t throttle;
  uint16_t roll;
  uint16_t pitch;
  uint16_t yaw;
} __attribute__((packed));


// INAV_MSP2_COMMON_SERIAL_CONFIG reply — per-port entry
struct INAV_msp2_common_serial_config_entry_t {
  uint8_t  identifier;
  uint32_t functionMask;
  uint8_t  mspBaudrateIndex;
  uint8_t  gpsBaudrateIndex;
  uint8_t  telemetryBaudrateIndex;
  uint8_t  peripheralBaudrateIndex;
} __attribute__((packed));


// INAV_MSP2_COMMON_SET_SERIAL_CONFIG command
typedef INAV_msp2_common_serial_config_entry_t INAV_msp2_common_set_serial_config_t;


// INAV_MSP2_COMMON_SET_RADAR_POS command
struct INAV_msp2_common_set_radar_pos_t {
  uint8_t  radarNo;
  uint8_t  state;
  uint32_t lat;       // 1/10000000 deg
  uint32_t lon;
  uint32_t alt;       // cm
  uint16_t heading;
  uint16_t speed;     // cm/s
  uint8_t  lq;
} __attribute__((packed));


// INAV_MSP2_COMMON_SET_MSP_RC_LINK_STATS command
struct INAV_msp2_common_set_msp_rc_link_stats_t {
  uint8_t sublinkId;
  uint8_t reserved0;
  uint8_t rssiFromMspRc;
  uint8_t uplinkRssi;
  uint8_t downlinkLq;
  uint8_t uplinkLq;
} __attribute__((packed));


// INAV_MSP2_COMMON_SET_MSP_RC_INFO command
struct INAV_msp2_common_set_msp_rc_info_t {
  uint8_t  sublinkId;
  uint16_t uplinkTxPower;
  uint16_t downlinkTxPower;
  uint8_t  band;
  uint8_t  mode;
} __attribute__((packed));


// ============================================================
// MSP2 INAV payload structures
// ============================================================

// INAV_MSP2_INAV_OPTICAL_FLOW reply
struct INAV_msp2_inav_optical_flow_t {
  uint8_t  rawQuality;
  uint16_t flowRateX;    // deg/s scaled
  uint16_t flowRateY;
  uint16_t bodyRateX;
  uint16_t bodyRateY;
  uint8_t  reserved0;
  uint16_t reserved1;
  uint16_t reserved2;
  uint16_t reserved3;
  uint16_t reserved4;
} __attribute__((packed));


// INAV_MSP2_INAV_ANALOG reply
struct INAV_msp2_inav_analog_t {
  uint8_t  batteryWasFullWhenPluggedIn;
  uint16_t batteryVoltage;         // 0.01 V steps
  uint16_t amperage;               // 0.01 A steps
  uint32_t power;                  // mW
  uint32_t mAhDrawn;
  uint32_t mWhDrawn;
  uint32_t batteryRemainingCapacity;
  uint8_t  batteryPercentage;
  uint16_t rssi;
} __attribute__((packed));


// INAV_MSP2_INAV_MISC reply
struct INAV_msp2_inav_misc_t {
  uint16_t midrc;
  uint16_t reserved0;
  uint16_t maxThrottle;
  uint16_t mincommand;
  uint16_t failsafeThrottle;
  uint8_t  gpsProvider;
  uint8_t  reserved1;
  uint8_t  gpsSbasMode;
  uint8_t  reserved2;
  uint8_t  reserved3;
  uint8_t  reserved4;
  uint8_t  rssiChannel;
  uint16_t magDeclinationDeciDeg;
  uint16_t reserved5;
  uint16_t voltageScale;
  uint8_t  voltageSource;
  uint8_t  cellCount;
  uint16_t voltageCellDetect;    // 0.01 V
  uint16_t voltageCellMin;
  uint16_t voltageCellMax;
  uint16_t voltageCellWarning;
  uint16_t reserved6;
  uint8_t  reserved7;
  uint8_t  reserved8;
  uint16_t reserved9;
  uint16_t reserved10;
  uint16_t reserved11;
  uint16_t reserved12;
  uint32_t capacityValue;        // mAh or mWh
  uint32_t capacityWarning;
  uint32_t capacityCritical;
  uint8_t  capacityUnit;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_MISC command
struct INAV_msp2_inav_set_misc_t {
  uint16_t midrc;
  uint16_t wasMinThrottle;
  uint16_t wasMaxThrottle;
  uint16_t mincommand;
  uint16_t failsafeThrottle;
  uint8_t  gpsProvider;
  uint8_t  gpsBaudrate;
  uint8_t  gpsSbasMode;
  uint8_t  gpsType;
  uint8_t  gpsBaudrate2;
  uint8_t  gpsUbxSbas;
  uint8_t  reserved0;
  uint16_t magDeclination;
  uint16_t reserved1;
  uint16_t voltageScale;
  uint8_t  voltageSource;
  uint8_t  cellCount;
  uint16_t voltageCellDetect;
  uint16_t voltageCellMin;
  uint16_t voltageCellMax;
  uint16_t voltageCellWarning;
  uint16_t reserved2;
  uint8_t  reserved3;
  uint8_t  reserved4;
  uint16_t reserved5;
  uint16_t reserved6;
  uint16_t reserved7;
  uint16_t reserved8;
  uint32_t capacityValue;
  uint32_t capacityWarning;
  uint32_t capacityCritical;
  uint8_t  capacityUnit;
} __attribute__((packed));


// INAV_MSP2_INAV_BATTERY_CONFIG reply
struct INAV_msp2_inav_battery_config_t {
  uint16_t voltageScale;
  uint8_t  voltageSource;
  uint8_t  cellCount;
  uint16_t voltageCellDetect;
  uint16_t voltageCellMin;
  uint16_t voltageCellMax;
  uint16_t voltageCellWarning;
  uint16_t reserved0;
  uint8_t  reserved1;
  uint8_t  reserved2;
  uint16_t reserved3;
  uint16_t reserved4;
  uint16_t reserved5;
  uint16_t reserved6;
  uint16_t currentOffset;
  uint16_t currentScale;
  uint32_t capacityValue;
  uint32_t capacityWarning;
  uint32_t capacityCritical;
  uint8_t  capacityUnit;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_BATTERY_CONFIG command
struct INAV_msp2_inav_set_battery_config_t {
  uint16_t voltageScale;
  uint8_t  voltageSource;
  uint8_t  cellCount;
  uint16_t voltageCellDetect;
  uint16_t voltageCellMin;
  uint16_t voltageCellMax;
  uint16_t voltageCellWarning;
  uint16_t reserved0;
  uint8_t  reserved1;
  uint8_t  reserved2;
  uint16_t reserved3;
  uint16_t reserved4;
  uint16_t reserved5;
  uint16_t reserved6;
  uint16_t currentOffset;
  uint16_t currentScale;
  uint32_t capacityValue;
  uint32_t capacityWarning;
  uint32_t capacityCritical;
  uint8_t  capacityUnit;
} __attribute__((packed));


// INAV_MSP2_INAV_RATE_PROFILE reply
struct INAV_msp2_inav_rate_profile_t {
  uint8_t  throttleRcMid8;
  uint8_t  throttleRcExpo8;
  uint8_t  throttleDynPID;
  uint16_t throttlePaBreakpoint;
  uint8_t  stabilizedRcExpo8;
  uint8_t  stabilizedRcYawExpo8;
  uint8_t  stabilizedRates;    // roll=pitch
  uint8_t  manualRcExpo8;
  uint8_t  manualRcYawExpo8;
  uint8_t  manualRates;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_RATE_PROFILE command
struct INAV_msp2_inav_set_rate_profile_t {
  uint8_t  throttleRcMid8;
  uint8_t  throttleRcExpo8;
  uint8_t  throttleDynPID;
  uint16_t throttlePaBreakpoint;
  uint8_t  stabilizedRcExpo8;
  uint8_t  stabilizedRcYawExpo8;
  uint8_t  stabilizedRates;
  uint8_t  manualRcExpo8;
  uint8_t  manualRcYawExpo8;
  uint8_t  manualRates;
} __attribute__((packed));


// INAV_MSP2_INAV_AIR_SPEED reply
struct INAV_msp2_inav_air_speed_t {
  uint32_t airspeedEstimate;   // cm/s
  uint32_t reserved0;
} __attribute__((packed));


// INAV_MSP2_INAV_OUTPUT_MAPPING reply — variable-length; one byte per output
struct INAV_msp2_inav_output_mapping_entry_t {
  uint8_t usageFlags;
} __attribute__((packed));


// INAV_MSP2_INAV_MC_BRAKING reply
struct INAV_msp2_inav_mc_braking_t {
  uint16_t speedThreshold;
  uint16_t disengageSpeed;
  uint16_t timeout;
  uint8_t  boostFactor;
  uint16_t boostTimeout;
  uint16_t boostSpeedThreshold;
  uint16_t boostDisengageSpeed;
  uint8_t  bankAngle;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_MC_BRAKING command
typedef INAV_msp2_inav_mc_braking_t INAV_msp2_inav_set_mc_braking_t;


// INAV_MSP2_INAV_OUTPUT_MAPPING_EXT reply — variable-length; one entry per output
struct INAV_msp2_inav_output_mapping_ext_entry_t {
  uint8_t  reserved0;
  uint8_t  timerId;
  uint8_t  usageFlags;
} __attribute__((packed));


// INAV_MSP2_INAV_TIMER_OUTPUT_MODE reply
struct INAV_msp2_inav_timer_output_mode_t {
  uint8_t reserved0;
  uint8_t outputMode;
  uint8_t timer;
  uint8_t timerOutputMode;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_TIMER_OUTPUT_MODE command
struct INAV_msp2_inav_set_timer_output_mode_t {
  uint8_t timer;
  uint8_t outputMode;
} __attribute__((packed));


// INAV_MSP2_INAV_MIXER reply
struct INAV_msp2_inav_mixer_t {
  uint8_t  motorDirectionInverted;
  uint8_t  reserved0;
  uint8_t  motorstopOnLow;
  uint8_t  platformType;
  uint8_t  hasFlaps;
  uint16_t appliedMixerPreset;
  uint8_t  maxSupportedMotors;
  uint8_t  maxSupportedServos;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_MIXER command
struct INAV_msp2_inav_set_mixer_t {
  uint8_t  motorDirectionInverted;
  uint8_t  reserved0;
  uint8_t  motorstopOnLow;
  uint8_t  platformType;
  uint8_t  hasFlaps;
  uint16_t appliedMixerPreset;
  uint8_t  reserved1;
  uint8_t  reserved2;
} __attribute__((packed));


// INAV_MSP2_INAV_OSD_LAYOUTS reply
struct INAV_msp2_inav_osd_layouts_t {
  uint16_t itemPos;
  uint16_t itemPosAlt;
  uint8_t  layoutCount;
  uint8_t  itemCount;
} __attribute__((packed));


// INAV_MSP2_INAV_OSD_SET_LAYOUT_ITEM command
struct INAV_msp2_inav_osd_set_layout_item_t {
  uint8_t  layoutIdx;
  uint8_t  itemIdx;
  uint16_t pos;
} __attribute__((packed));


// INAV_MSP2_INAV_OSD_ALARMS reply
struct INAV_msp2_inav_osd_alarms_t {
  uint8_t  rssiAlarm;
  uint16_t timeAlarm;
  uint16_t altAlarm;
  uint16_t distAlarm;
  uint16_t negAltAlarm;
  uint16_t gforceAlarm;
  uint16_t gforceAxisAlarmMin;
  uint16_t gforceAxisAlarmMax;
  uint8_t  currentAlarm;
  int16_t  imuTempAlarmMin;
  int16_t  imuTempAlarmMax;
  int16_t  baroTempAlarmMin;
  int16_t  baroTempAlarmMax;
  uint16_t reserved0;
  uint16_t reserved1;
  uint16_t adsbDistanceWarning;
  uint16_t adsbDistanceAlert;
  uint16_t reserved2;
  uint16_t reserved3;
} __attribute__((packed));


// INAV_MSP2_INAV_OSD_SET_ALARMS command
struct INAV_msp2_inav_osd_set_alarms_t {
  uint8_t  rssiAlarm;
  uint16_t timeAlarm;
  uint16_t altAlarm;
  uint16_t distAlarm;
  uint16_t negAltAlarm;
  uint16_t reserved0;
  uint16_t reserved1;
  uint16_t reserved2;
  uint8_t  currentAlarm;
  int16_t  imuTempAlarmMin;
  int16_t  imuTempAlarmMax;
  int16_t  baroTempAlarmMin;
  int16_t  baroTempAlarmMax;
} __attribute__((packed));


// INAV_MSP2_INAV_OSD_PREFERENCES reply
struct INAV_msp2_inav_osd_preferences_t {
  uint8_t videoSystem;
  uint8_t mainVoltageDecimals;
  uint8_t ahiReverseRoll;
  uint8_t crosshairsStyle;
  uint8_t leftSidebarScroll;
  uint8_t rightSidebarScroll;
  uint8_t sidebarScrollArrows;
  uint8_t units;
  uint8_t statsEnergyUnit;
  uint8_t adsbWarningStyle;
  uint8_t reserved0;
} __attribute__((packed));


// INAV_MSP2_INAV_OSD_SET_PREFERENCES command
struct INAV_msp2_inav_osd_set_preferences_t {
  uint8_t videoSystem;
  uint8_t mainVoltageDecimals;
  uint8_t ahiReverseRoll;
  uint8_t crosshairsStyle;
  uint8_t leftSidebarScroll;
  uint8_t rightSidebarScroll;
  uint8_t sidebarScrollArrows;
  uint8_t units;
  uint8_t statsEnergyUnit;
  uint8_t adsbWarningStyle;
} __attribute__((packed));


// INAV_MSP2_INAV_SELECT_BATTERY_PROFILE command
struct INAV_msp2_inav_select_battery_profile_t {
  uint8_t profileIndex;
} __attribute__((packed));


// INAV_MSP2_INAV_DEBUG reply (8 x uint32_t debug values)
struct INAV_msp2_inav_debug_t {
  uint32_t debugValues[8];
} __attribute__((packed));


// INAV_MSP2_BLACKBOX_CONFIG reply
struct INAV_msp2_blackbox_config_t {
  uint8_t  reserved0;
  uint8_t  device;
  uint16_t rateNum;
  uint16_t rateDenom;
  uint32_t includeFlags;
  uint8_t  reserved1;
  uint8_t  reserved2;
  uint16_t reserved3;
  uint16_t reserved4;
} __attribute__((packed));


// INAV_MSP2_SET_BLACKBOX_CONFIG command
struct INAV_msp2_set_blackbox_config_t {
  uint8_t  device;
  uint16_t rateNum;
  uint16_t rateDenom;
  uint32_t includeFlags;
} __attribute__((packed));


// INAV_MSP2_INAV_TEMP_SENSOR_CONFIG reply — variable-length; one entry per sensor
struct INAV_msp2_inav_temp_sensor_config_entry_t {
  uint8_t  type;
  uint8_t  address;
  int16_t  alarmMin;
  int16_t  alarmMax;
  uint8_t  osdSymbol;
  uint8_t  label;      // first byte of label; actual label is 4 bytes long
} __attribute__((packed));


// INAV_MSP2_INAV_SET_TEMP_SENSOR_CONFIG command — one sensor at a time
typedef INAV_msp2_inav_temp_sensor_config_entry_t INAV_msp2_inav_set_temp_sensor_config_t;


// INAV_MSP2_INAV_TEMPERATURES reply — variable-length; one int16_t per sensor (decidegrees C, 0x7FFF = invalid)
struct INAV_msp2_inav_temperatures_entry_t {
  int16_t temperature;
} __attribute__((packed));


// INAV_MSP2_INAV_SERVO_MIXER reply — per-entry (two profiles interleaved)
struct INAV_msp2_inav_servo_mixer_entry_t {
  uint8_t  targetChannel;
  uint8_t  inputSource;
  uint16_t rate;
  uint8_t  speed;
  uint8_t  conditionId;
  uint8_t  reserved0;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_SERVO_MIXER command
struct INAV_msp2_inav_set_servo_mixer_t {
  uint8_t  mixerIndex;
  uint8_t  targetChannel;
  uint8_t  inputSource;
  uint16_t rate;
  uint8_t  speed;
  uint8_t  conditionId;
  uint8_t  reserved0;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_LOGIC_CONDITIONS command
struct INAV_msp2_inav_set_logic_conditions_t {
  uint8_t  conditionIndex;
  uint8_t  enabled;
  uint8_t  activatorId;
  uint8_t  operation;
  uint8_t  operandAType;
  uint32_t operandAValue;
  uint8_t  operandBType;
  uint32_t operandBValue;
  uint8_t  flags;
} __attribute__((packed));


// INAV_MSP2_INAV_LOGIC_CONDITIONS_STATUS reply — one uint32_t per active logic condition
struct INAV_msp2_inav_logic_conditions_status_entry_t {
  uint32_t value;
} __attribute__((packed));


// INAV_MSP2_INAV_GVAR_STATUS reply — one uint32_t per global variable
struct INAV_msp2_inav_gvar_status_entry_t {
  uint32_t value;
} __attribute__((packed));


// INAV_MSP2_INAV_PROGRAMMING_PID reply — per-programming-PID entry
struct INAV_msp2_inav_programming_pid_entry_t {
  uint8_t  enabled;
  uint8_t  setpointType;
  uint32_t setpointValue;
  uint8_t  measurementType;
  uint32_t measurementValue;
  uint16_t gainsP;
  uint16_t gainsI;
  uint16_t gainsD;
  uint16_t gainsFF;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_PROGRAMMING_PID command
struct INAV_msp2_inav_set_programming_pid_t {
  uint8_t  pidIndex;
  uint8_t  enabled;
  uint8_t  setpointType;
  uint32_t setpointValue;
  uint8_t  measurementType;
  uint32_t measurementValue;
  uint16_t gainsP;
  uint16_t gainsI;
  uint16_t gainsD;
  uint16_t gainsFF;
} __attribute__((packed));


// INAV_MSP2_INAV_PROGRAMMING_PID_STATUS reply — one int32_t per programming PID output
struct INAV_msp2_inav_programming_pid_status_entry_t {
  int32_t output;
} __attribute__((packed));


// INAV_MSP2_PID reply — per-PID entry (4 bytes: P, I, D, FF)
struct INAV_msp2_pid_entry_t {
  uint8_t p;
  uint8_t i;
  uint8_t d;
  uint8_t ff;
} __attribute__((packed));


// INAV_MSP2_SET_PID command
typedef INAV_msp2_pid_entry_t INAV_msp2_set_pid_entry_t;


// INAV_MSP2_INAV_FWUPDT_PREPARE command
struct INAV_msp2_inav_fwupdt_prepare_t {
  uint32_t firmwareSize;
} __attribute__((packed));


// INAV_MSP2_INAV_FWUPDT_EXEC command
struct INAV_msp2_inav_fwupdt_exec_t {
  uint8_t execFlag;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_SAFEHOME command
struct INAV_msp2_inav_set_safehome_t {
  uint8_t  safehomeIndex;
  uint8_t  enabled;
  uint32_t lat;   // 1/10000000 deg
  uint32_t lon;
} __attribute__((packed));


// INAV_MSP2_INAV_MISC2 reply
struct INAV_msp2_inav_misc2_t {
  uint32_t micros;
  uint32_t flightTime;           // seconds
  uint8_t  throttlePercent;
  uint8_t  navigationIsControllingThrottle;
} __attribute__((packed));


// INAV_MSP2_INAV_LOGIC_CONDITIONS_CONFIGURED reply
struct INAV_msp2_inav_logic_conditions_configured_t {
  uint32_t configuredMask0;
  uint32_t configuredMask1;
} __attribute__((packed));


// INAV_MSP2_INAV_ESC_RPM reply — variable-length; one uint32_t per motor
struct INAV_msp2_inav_esc_rpm_entry_t {
  uint32_t rpm;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_LED_STRIP_CONFIG_EX command
struct INAV_msp2_inav_set_led_strip_config_ex_t {
  uint8_t ledIndex;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_FW_APPROACH command
struct INAV_msp2_inav_set_fw_approach_t {
  uint8_t  index;
  uint32_t approachAlt;       // cm
  uint32_t landAlt;           // cm
  uint8_t  approachDirection;
  uint8_t  isSeaLevelRef;
} __attribute__((packed));


// INAV_MSP2_INAV_RATE_DYNAMICS reply
struct INAV_msp2_inav_rate_dynamics_t {
  uint8_t sensitivityCenter;
  uint8_t sensitivityEnd;
  uint8_t correctionCenter;
  uint8_t correctionEnd;
  uint8_t weightCenter;
  uint8_t weightEnd;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_RATE_DYNAMICS command
typedef INAV_msp2_inav_rate_dynamics_t INAV_msp2_inav_set_rate_dynamics_t;


// INAV_MSP2_INAV_EZ_TUNE reply
struct INAV_msp2_inav_ez_tune_t {
  uint8_t  enabled;
  uint16_t filterHz;
  uint8_t  axisRatio;
  uint8_t  response;
  uint8_t  damping;
  uint8_t  stability;
  uint8_t  aggressiveness;
  uint8_t  rate;
  uint8_t  expo;
  uint8_t  snappiness;
} __attribute__((packed));


// INAV_MSP2_INAV_EZ_TUNE_SET command
typedef INAV_msp2_inav_ez_tune_t INAV_msp2_inav_ez_tune_set_t;


// INAV_MSP2_INAV_SELECT_MIXER_PROFILE command
struct INAV_msp2_inav_select_mixer_profile_t {
  uint8_t profileIndex;
} __attribute__((packed));


// INAV_MSP2_ADSB_VEHICLE_LIST reply — header followed by vehicle entries
struct INAV_msp2_adsb_vehicle_list_header_t {
  uint8_t  maxVehicles;
  uint8_t  callsignMaxLength;
  uint32_t messagesTotalVehicle;
  uint32_t messagesTotalHeartbeat;
} __attribute__((packed));

struct INAV_msp2_adsb_vehicle_entry_t {
  uint8_t  callsignFirstByte;  // callsign is callsignMaxLength bytes long
  uint32_t icao;
  uint32_t lat;                // 1/10000000 deg
  uint32_t lon;
  uint32_t alt;                // cm
  uint16_t heading;            // deg
  uint8_t  tslc;
  uint8_t  emitterType;
  uint8_t  ttl;
  uint8_t  reserved0;
  uint8_t  reserved1;
  uint32_t reserved2;
  uint32_t reserved3;
} __attribute__((packed));


// INAV_MSP2_INAV_CUSTOM_OSD_ELEMENTS reply
struct INAV_msp2_inav_custom_osd_elements_t {
  uint8_t maxCustomElements;
  uint8_t textSize;
  uint8_t partsPerElement;
} __attribute__((packed));


// INAV_MSP2_INAV_CUSTOM_OSD_ELEMENT request
struct INAV_msp2_inav_custom_osd_element_req_t {
  uint8_t elementIndex;
} __attribute__((packed));


// INAV_MSP2_INAV_CUSTOM_OSD_ELEMENT reply — variable structure per element
struct INAV_msp2_inav_custom_osd_element_part_t {
  uint8_t  type;
  uint16_t value;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_CUSTOM_OSD_ELEMENTS command
struct INAV_msp2_inav_set_custom_osd_elements_t {
  uint8_t  elementIndex;
  uint8_t  part0Type;
  uint16_t part0Value;
  uint8_t  part1Type;
  uint16_t part1Value;
  uint8_t  textFirstByte;  // full text follows; length = textSize
} __attribute__((packed));


// INAV_MSP2_INAV_OUTPUT_MAPPING_EXT2 reply — per output
struct INAV_msp2_inav_output_mapping_ext2_entry_t {
  uint8_t  reserved0;
  uint8_t  timerId;
  uint32_t usageFlags;
  uint8_t  reserved1;
  uint8_t  pinLabel;
} __attribute__((packed));


// INAV_MSP2_INAV_OSD_UPDATE_POSITION command
struct INAV_msp2_inav_osd_update_position_t {
  uint8_t  itemIndex;
  uint16_t pos;
} __attribute__((packed));


// INAV_MSP2_INAV_SERVO_CONFIG reply — per servo entry
struct INAV_msp2_inav_servo_config_entry_t {
  uint16_t min;
  uint16_t max;
  uint16_t middle;
  uint8_t  rate;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_SERVO_CONFIG command
struct INAV_msp2_inav_set_servo_config_t {
  uint8_t  servoIndex;
  uint16_t min;
  uint16_t max;
  uint16_t middle;
  uint8_t  rate;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_GEOZONE command
struct INAV_msp2_inav_set_geozone_t {
  uint8_t  zoneIndex;
  uint8_t  type;
  uint8_t  shape;
  uint32_t minAltitude;   // cm
  uint32_t maxAltitude;
  uint8_t  isSeaLevelRef;
  uint8_t  fenceAction;
  uint8_t  vertexCount;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_GEOZONE_VERTEX command
struct INAV_msp2_inav_set_geozone_vertex_t {
  uint8_t  zoneIndex;
  uint8_t  vertexId;
  uint32_t lat;    // 1/10000000 deg
  uint32_t lon;
  uint32_t reserved0;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_GVAR command
struct INAV_msp2_inav_set_gvar_t {
  uint8_t  gvarIndex;
  uint32_t value;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_ALT_TARGET command
struct INAV_msp2_inav_set_alt_target_t {
  uint8_t  flag;
  uint32_t altCm;
} __attribute__((packed));


// INAV_MSP2_INAV_FLIGHT_AXIS_ANGLE_OVERRIDE command
struct INAV_msp2_inav_flight_axis_angle_override_t {
  uint8_t  overrideMask;
  uint16_t rollTarget;    // decidegrees
  uint16_t pitchTarget;
  uint16_t yawTarget;
} __attribute__((packed));


// INAV_MSP2_INAV_FLIGHT_AXIS_RATE_OVERRIDE command
struct INAV_msp2_inav_flight_axis_rate_override_t {
  uint8_t  overrideMask;
  uint16_t rollRate;      // decidegrees/s
  uint16_t pitchRate;
  uint16_t yawRate;
} __attribute__((packed));


// INAV_MSP2_INAV_SET_LOCAL_TARGET command
struct INAV_msp2_inav_set_local_target_t {
  uint32_t offsetBodyX;   // cm
  uint32_t offsetBodyY;
  uint32_t offsetBodyZ;
} __attribute__((packed));


// INAV_MSP2_INAV_LOCAL_TARGET reply
struct INAV_msp2_inav_local_target_t {
  uint32_t posX;                    // cm
  uint32_t posY;
  uint32_t posZ;
  uint16_t velX;                    // cm/s
  uint16_t velY;
  uint16_t velZ;
  uint32_t desiredYaw;              // decidegrees
  uint16_t desiredClimbRateDemand;  // cm/s
} __attribute__((packed));


// INAV_MSP2_INAV_SET_GLOBAL_TARGET command
struct INAV_msp2_inav_set_global_target_t {
  uint32_t lat;        // 1/10000000 deg
  uint32_t lon;
  uint32_t alt;        // cm
  uint8_t  datumFlag;
} __attribute__((packed));


// INAV_MSP2_INAV_NAV_TARGET reply
struct INAV_msp2_inav_nav_target_t {
  uint32_t targetLat;              // 1/10000000 deg
  uint32_t targetLon;
  uint32_t posZ;                   // cm
  uint16_t headingTarget;          // decidegrees
  uint16_t desiredClimbRateDemand; // cm/s
} __attribute__((packed));


// INAV_MSP2_INAV_FULL_LOCAL_POSE reply — repeated per axis
struct INAV_msp2_inav_full_local_pose_t {
  uint16_t roll;          // decidegrees
  uint16_t pitch;
  uint16_t yaw;
  uint32_t posV;          // cm (axis)
  uint16_t velV;          // cm/s
} __attribute__((packed));


// INAV_MSP_SET_WP command
// Special waypoints: 0 = RTH position, 255 = POSHOLD position
struct INAV_msp_set_wp_t {
  uint8_t waypointNumber;
  uint8_t action;   // INAV_MSP_NAV_STATUS_WAYPOINT_ACTION_...
  int32_t lat;      // decimal degrees latitude * 10000000
  int32_t lon;      // decimal degrees longitude * 10000000
  int32_t alt;      // altitude (cm)
  int16_t p1;       // speed (cm/s) for WAYPOINT, or land flag for RTH
  int16_t p2;
  int16_t p3;
  uint8_t flag;     // 0xa5 = last waypoint, otherwise 0
} __attribute__((packed));

const flight_mode_definition_t INAV_MODE_DEFS[] = {
    {  0,  0, "ARM" },
    {  1,  1, "ANGLE" },
    {  2,  2, "HORIZON" },
    {  3,  3, "NAV ALTHOLD" },
    {  5,  4, "HEADING HOLD" },
    {  6,  5, "HEADFREE" },
    {  7,  6, "HEADADJ" },
    {  8,  7, "CAMSTAB" },
    { 10,  8, "NAV RTH" },
    { 11,  9, "NAV POSHOLD" },
    { 12, 10, "MANUAL" },
    { 13, 11, "BEEPER" },
    { 15, 12, "LEDS OFF" },
    { 16, 13, "LIGHTS" },
    { 19, 15, "OSD OFF" },
    { 20, 16, "TELEMETRY" },
    { 21, 28, "AUTO TUNE" },
    { 26, 17, "BLACKBOX" },
    { 27, 18, "FAILSAFE" },
    { 28, 19, "NAV WP" },
    { 29, 20, "AIR MODE" },
    { 30, 21, "HOME RESET" },
    { 31, 22, "GCS NAV" },
    { 32, 39, "FPV ANGLE MIX" },
    { 33, 24, "SURFACE" },
    { 34, 25, "FLAPERON" },
    { 35, 26, "TURN ASSIST" },
    { 36, 14, "NAV LAUNCH" },
    { 37, 27, "SERVO AUTOTRIM" },
    { 39, 29, "CAMERA CONTROL 1" },
    { 40, 30, "CAMERA CONTROL 2" },
    { 41, 31, "CAMERA CONTROL 3" },
    { 42, 32, "OSD ALT 1" },
    { 43, 33, "OSD ALT 2" },
    { 44, 34, "OSD ALT 3" },
    { 45, 35, "NAV COURSE HOLD" },
    { 46, 36, "MC BRAKING" },
    { 47, 37, "USER1" },
    { 48, 38, "USER2" },
    { 57, 48, "USER3" },
    { 58, 49, "USER4" },
    { 49, 40, "LOITER CHANGE" },
    { 50, 41, "MSP RC OVERRIDE" },
    { 51, 42, "PREARM" },
    { 52, 43, "TURTLE" },
    { 53, 44, "NAV CRUISE" },
    { 54, 45, "AUTO LEVEL TRIM" },
    { 55, 46, "WP PLANNER" },
    { 56, 47, "SOARING" },
    { 59, 50, "MISSION CHANGE" },
    { 60, 51, "BEEPER MUTE" },
    { 61, 52, "MULTI FUNCTION" },
    { 62, 53, "MIXER PROFILE 2" },
    { 63, 54, "MIXER TRANSITION" },
    { 64, 55, "ANGLE HOLD" },
    { 65, 56, "GIMBAL LEVEL TILT" },
    { 66, 57, "GIMBAL LEVEL ROLL" },
    { 67, 58, "GIMBAL CENTER" },
    { 68, 59, "GIMBAL HEADTRACKER" }
};

const uint8_t INAV_MODE_DEFS_COUNT = sizeof(INAV_MODE_DEFS) / sizeof(INAV_MODE_DEFS[0]);

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

class MspINAV : public MSP {
public:
    MspINAV() : _boxIdCount(0), _boxIdsLoaded(false) {
        memset(_boxIdMap, 0, sizeof(_boxIdMap));
        memset(_bitmap,   0, sizeof(_bitmap));
    }

    bool loadBoxIds() {
        uint16_t recvSize = 0;
        if (!request(INAV_MSP_BOXIDS, _boxIdMap, sizeof(_boxIdMap), &recvSize)) {
            _boxIdsLoaded = false;
            return false;
        }
        _boxIdCount   = recvSize < sizeof(_boxIdMap) ? (uint8_t)recvSize : (uint8_t)sizeof(_boxIdMap);
        _boxIdsLoaded = true;
        return true;
    }

    bool loadActiveFlightModes() {
        INAV_msp_activeboxes_t boxes;
        memset(&boxes, 0, sizeof(boxes));
        if (!request(INAV_MSP_ACTIVEBOXES, &boxes, sizeof(boxes))) return false;
        memcpy(_bitmap, boxes.flags, sizeof(_bitmap));
        return true;
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