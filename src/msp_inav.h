/*
  msp_inav.h

  INAV-specific MSP frame IDs, constants, and payload structures.
  All names are prefixed with INAV_ to distinguish them from generic MSP symbols.
*/

#pragma once

#include <Arduino.h>

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
#define INAV_MSP_MISC                         114
#define INAV_MSP_BOXIDS                       119
#define INAV_MSP_SERVO_CONFIGURATIONS         120
#define INAV_MSP_NAV_STATUS                   121
#define INAV_MSP_SENSOR_ALIGNMENT             126
#define INAV_MSP_STATUS_EX                    150
#define INAV_MSP_SENSOR_STATUS                151
#define INAV_MSP_UID                          160
#define INAV_MSP_GPSSVINFO                    164
#define INAV_MSP_GPSSTATISTICS                166

// Commands
#define INAV_MSP_SET_RAW_RC                   200
#define INAV_MSP_SET_RAW_GPS                  201
#define INAV_MSP_SET_PID                      202
#define INAV_MSP_SET_WP                       209
#define INAV_MSP_SET_HEAD                     211

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
