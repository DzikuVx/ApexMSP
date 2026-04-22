/*
  btfl_msp.h

  Betaflight-specific MSP frame IDs, constants, and payload structures.
  All names are prefixed with BTFL_ to distinguish them from generic MSP symbols.

  Covers MSPv1 (IDs 1-254), MSPv2 Betaflight (0x3000+), and MSPv2 common (0x1000+).
*/

#pragma once

#include <Arduino.h>

// ============================================================
// MSPv1 Frame IDs
// ============================================================

// Info / Version
#define BTFL_MSP_API_VERSION              1
#define BTFL_MSP_FC_VARIANT               2
#define BTFL_MSP_FC_VERSION               3
#define BTFL_MSP_BOARD_INFO               4
#define BTFL_MSP_BUILD_INFO               5
#define BTFL_MSP_NAME                    10
#define BTFL_MSP_SET_NAME                11

// Battery / Power
#define BTFL_MSP_BATTERY_CONFIG          32
#define BTFL_MSP_SET_BATTERY_CONFIG      33

// Mode ranges / Config
#define BTFL_MSP_MODE_RANGES             34
#define BTFL_MSP_SET_MODE_RANGE          35
#define BTFL_MSP_FEATURE_CONFIG          36
#define BTFL_MSP_SET_FEATURE_CONFIG      37
#define BTFL_MSP_BOARD_ALIGNMENT_CONFIG  38
#define BTFL_MSP_SET_BOARD_ALIGNMENT_CONFIG 39
#define BTFL_MSP_CURRENT_METER_CONFIG    40
#define BTFL_MSP_SET_CURRENT_METER_CONFIG 41
#define BTFL_MSP_MIXER_CONFIG            42
#define BTFL_MSP_SET_MIXER_CONFIG        43
#define BTFL_MSP_RX_CONFIG               44
#define BTFL_MSP_SET_RX_CONFIG           45
#define BTFL_MSP_LED_COLORS              46
#define BTFL_MSP_SET_LED_COLORS          47
#define BTFL_MSP_LED_STRIP_CONFIG        48
#define BTFL_MSP_SET_LED_STRIP_CONFIG    49
#define BTFL_MSP_RSSI_CONFIG             50
#define BTFL_MSP_SET_RSSI_CONFIG         51
#define BTFL_MSP_ADJUSTMENT_RANGES       52
#define BTFL_MSP_SET_ADJUSTMENT_RANGE    53
#define BTFL_MSP_CF_SERIAL_CONFIG        54
#define BTFL_MSP_SET_CF_SERIAL_CONFIG    55
#define BTFL_MSP_VOLTAGE_METER_CONFIG    56
#define BTFL_MSP_SET_VOLTAGE_METER_CONFIG 57
#define BTFL_MSP_SONAR_ALTITUDE          58
#define BTFL_MSP_PID_CONTROLLER          59
#define BTFL_MSP_SET_PID_CONTROLLER      60
#define BTFL_MSP_ARMING_CONFIG           61
#define BTFL_MSP_SET_ARMING_CONFIG       62
#define BTFL_MSP_RX_MAP                  64
#define BTFL_MSP_SET_RX_MAP              65
#define BTFL_MSP_REBOOT                  68
#define BTFL_MSP_DATAFLASH_SUMMARY       70
#define BTFL_MSP_DATAFLASH_READ          71
#define BTFL_MSP_DATAFLASH_ERASE         72
#define BTFL_MSP_FAILSAFE_CONFIG         75
#define BTFL_MSP_SET_FAILSAFE_CONFIG     76
#define BTFL_MSP_RXFAIL_CONFIG           77
#define BTFL_MSP_SET_RXFAIL_CONFIG       78
#define BTFL_MSP_SDCARD_SUMMARY          79
#define BTFL_MSP_BLACKBOX_CONFIG         80
#define BTFL_MSP_SET_BLACKBOX_CONFIG     81
#define BTFL_MSP_TRANSPONDER_CONFIG      82
#define BTFL_MSP_SET_TRANSPONDER_CONFIG  83
#define BTFL_MSP_OSD_CONFIG              84
#define BTFL_MSP_SET_OSD_CONFIG          85
#define BTFL_MSP_OSD_CHAR_READ           86
#define BTFL_MSP_OSD_CHAR_WRITE          87
#define BTFL_MSP_VTX_CONFIG              88
#define BTFL_MSP_SET_VTX_CONFIG          89
#define BTFL_MSP_ADVANCED_CONFIG         90
#define BTFL_MSP_SET_ADVANCED_CONFIG     91
#define BTFL_MSP_FILTER_CONFIG           92
#define BTFL_MSP_SET_FILTER_CONFIG       93
#define BTFL_MSP_PID_ADVANCED            94
#define BTFL_MSP_SET_PID_ADVANCED        95
#define BTFL_MSP_SENSOR_CONFIG           96
#define BTFL_MSP_SET_SENSOR_CONFIG       97
#define BTFL_MSP_CAMERA_CONTROL          98
#define BTFL_MSP_SET_ARMING_DISABLED     99

// Telemetry / Status
#define BTFL_MSP_STATUS                 101
#define BTFL_MSP_RAW_IMU                102
#define BTFL_MSP_SERVO                  103
#define BTFL_MSP_MOTOR                  104
#define BTFL_MSP_RC                     105
#define BTFL_MSP_RAW_GPS                106
#define BTFL_MSP_COMP_GPS               107
#define BTFL_MSP_ATTITUDE               108
#define BTFL_MSP_ALTITUDE               109
#define BTFL_MSP_ANALOG                 110
#define BTFL_MSP_RC_TUNING              111
#define BTFL_MSP_PID                    112
#define BTFL_MSP_BOXNAMES               116
#define BTFL_MSP_PIDNAMES               117
#define BTFL_MSP_BOXIDS                 119
#define BTFL_MSP_SERVO_CONFIGURATIONS   120
#define BTFL_MSP_MOTOR_3D_CONFIG        124
#define BTFL_MSP_RC_DEADBAND            125
#define BTFL_MSP_SENSOR_ALIGNMENT       126
#define BTFL_MSP_LED_STRIP_MODECOLOR    127
#define BTFL_MSP_VOLTAGE_METERS         128
#define BTFL_MSP_CURRENT_METERS         129
#define BTFL_MSP_BATTERY_STATE          130
#define BTFL_MSP_MOTOR_CONFIG           131
#define BTFL_MSP_GPS_CONFIG             132
#define BTFL_MSP_COMPASS_CONFIG         133
#define BTFL_MSP_ESC_SENSOR_DATA        134
#define BTFL_MSP_GPS_RESCUE             135
#define BTFL_MSP_GPS_RESCUE_PIDS        136
#define BTFL_MSP_VTXTABLE_BAND          137
#define BTFL_MSP_VTXTABLE_POWERLEVEL    138
#define BTFL_MSP_MOTOR_TELEMETRY        139
#define BTFL_MSP_SIMPLIFIED_TUNING      140
#define BTFL_MSP_SET_SIMPLIFIED_TUNING  141
#define BTFL_MSP_CALCULATE_SIMPLIFIED_PID   142
#define BTFL_MSP_CALCULATE_SIMPLIFIED_GYRO  143
#define BTFL_MSP_CALCULATE_SIMPLIFIED_DTERM 144
#define BTFL_MSP_VALIDATE_SIMPLIFIED_TUNING 145
#define BTFL_MSP_STATUS_EX              150
#define BTFL_MSP_UID                    160
#define BTFL_MSP_GPSSVINFO              164
#define BTFL_MSP_GPSSTATISTICS          166
#define BTFL_MSP_ATTITUDE_QUATERNION    167
#define BTFL_MSP_OSD_VIDEO_CONFIG       180
#define BTFL_MSP_SET_OSD_VIDEO_CONFIG   181
#define BTFL_MSP_DISPLAYPORT            182
#define BTFL_MSP_COPY_PROFILE           183
#define BTFL_MSP_BEEPER_CONFIG          184
#define BTFL_MSP_SET_BEEPER_CONFIG      185
#define BTFL_MSP_SET_TX_INFO            186
#define BTFL_MSP_TX_INFO                187
#define BTFL_MSP_SET_OSD_CANVAS         188
#define BTFL_MSP_OSD_CANVAS             189

// Commands
#define BTFL_MSP_SET_RAW_RC             200
#define BTFL_MSP_SET_RAW_GPS            201
#define BTFL_MSP_SET_PID                202
#define BTFL_MSP_SET_RC_TUNING          204
#define BTFL_MSP_ACC_CALIBRATION        205
#define BTFL_MSP_MAG_CALIBRATION        206
#define BTFL_MSP_RESET_CONF             208
#define BTFL_MSP_SELECT_SETTING         210
#define BTFL_MSP_SET_HEADING            211
#define BTFL_MSP_SET_SERVO_CONFIGURATION 212
#define BTFL_MSP_SET_MOTOR              214
#define BTFL_MSP_SET_MOTOR_3D_CONFIG    217
#define BTFL_MSP_SET_RC_DEADBAND        218
#define BTFL_MSP_SET_RESET_CURR_PID     219
#define BTFL_MSP_SET_SENSOR_ALIGNMENT   220
#define BTFL_MSP_SET_LED_STRIP_MODECOLOR 221
#define BTFL_MSP_SET_MOTOR_CONFIG       222
#define BTFL_MSP_SET_GPS_CONFIG         223
#define BTFL_MSP_SET_COMPASS_CONFIG     224
#define BTFL_MSP_SET_GPS_RESCUE         225
#define BTFL_MSP_SET_GPS_RESCUE_PIDS    226
#define BTFL_MSP_SET_VTXTABLE_BAND      227
#define BTFL_MSP_SET_VTXTABLE_POWERLEVEL 228
#define BTFL_MSP_MULTIPLE_MSP           230
#define BTFL_MSP_MODE_RANGES_EXTRA      238
#define BTFL_MSP_SET_ACC_TRIM           239
#define BTFL_MSP_ACC_TRIM               240
#define BTFL_MSP_SERVO_MIX_RULES        241
#define BTFL_MSP_SET_SERVO_MIX_RULE     242
#define BTFL_MSP_SET_PASSTHROUGH        245
#define BTFL_MSP_SET_RTC                246
#define BTFL_MSP_RTC                    247
#define BTFL_MSP_SET_BOARD_INFO         248
#define BTFL_MSP_SET_SIGNATURE          249
#define BTFL_MSP_EEPROM_WRITE           250
#define BTFL_MSP_DEBUG                  254


// ============================================================
// MSPv2 Betaflight Frame IDs (0x3000+)
// ============================================================

#define BTFL_MSP2_BETAFLIGHT_BIND               0x3000
#define BTFL_MSP2_MOTOR_OUTPUT_REORDERING       0x3001
#define BTFL_MSP2_SET_MOTOR_OUTPUT_REORDERING   0x3002
#define BTFL_MSP2_SEND_DSHOT_COMMAND            0x3003
#define BTFL_MSP2_GET_VTX_DEVICE_STATUS         0x3004
#define BTFL_MSP2_GET_OSD_WARNINGS              0x3005
#define BTFL_MSP2_GET_TEXT                      0x3006
#define BTFL_MSP2_SET_TEXT                      0x3007
#define BTFL_MSP2_GET_LED_STRIP_CONFIG_VALUES   0x3008
#define BTFL_MSP2_SET_LED_STRIP_CONFIG_VALUES   0x3009
#define BTFL_MSP2_SENSOR_CONFIG_ACTIVE          0x300A
#define BTFL_MSP2_SENSOR_OPTICALFLOW            0x300B
#define BTFL_MSP2_MCU_INFO                      0x300C
#define BTFL_MSP2_GYRO_SENSOR_ACTIVE            0x300D
#define BTFL_MSP2_BATTERY_PROFILE               0x300E
#define BTFL_MSP2_SET_BATTERY_PROFILE           0x300F
#define BTFL_MSP2_CLI_SETTING                   0x3010
#define BTFL_MSP2_CLI_SETTING_INFO              0x3011


// ============================================================
// MSPv2 Common Frame IDs (0x1000+)
// ============================================================

#define BTFL_MSP2_COMMON_SERIAL_CONFIG          0x1009
#define BTFL_MSP2_COMMON_SET_SERIAL_CONFIG      0x100A
#define BTFL_MSP2_SENSOR_RANGEFINDER_LIDARMT    0x1F01
#define BTFL_MSP2_SENSOR_OPTICALFLOW_MT         0x1F02
#define BTFL_MSP2_SENSOR_GPS                    0x1F03


// ============================================================
// MSP2_GET_TEXT / MSP2_SET_TEXT text type values
// ============================================================

#define BTFL_MSP2_TEXT_PILOT_NAME           1
#define BTFL_MSP2_TEXT_CRAFT_NAME           2
#define BTFL_MSP2_TEXT_PID_PROFILE_NAME     3
#define BTFL_MSP2_TEXT_RATE_PROFILE_NAME    4
#define BTFL_MSP2_TEXT_BUILD_KEY            5
#define BTFL_MSP2_TEXT_RELEASE_NAME         6
#define BTFL_MSP2_TEXT_BATTERY_PROFILE_NAME 11


// ============================================================
// Reboot mode values (BTFL_msp_reboot_t.reboot_mode)
// ============================================================

#define BTFL_MSP_REBOOT_FIRMWARE      0
#define BTFL_MSP_REBOOT_BOOTLOADER    1
#define BTFL_MSP_REBOOT_MSC           2
#define BTFL_MSP_REBOOT_MSC_UTC       3
#define BTFL_MSP_REBOOT_BOOTLOADER_FLASH 4


// ============================================================
// Battery state values (BTFL_msp_battery_state_t.battery_state)
// ============================================================

#define BTFL_MSP_BATTERY_OK           0
#define BTFL_MSP_BATTERY_WARNING      1
#define BTFL_MSP_BATTERY_CRITICAL     2
#define BTFL_MSP_BATTERY_NOT_PRESENT  3
#define BTFL_MSP_BATTERY_INIT         4


// ============================================================
// Copy profile type values (BTFL_msp_copy_profile_t.profile_type)
// ============================================================

#define BTFL_MSP_PROFILE_TYPE_PID          0
#define BTFL_MSP_PROFILE_TYPE_CONTROL_RATE 1


// ============================================================
// Payload structures
// ============================================================

// BTFL_MSP_API_VERSION reply
struct BTFL_msp_api_version_t {
  uint8_t protocol_version;
  uint8_t api_version_major;
  uint8_t api_version_minor;
} __attribute__((packed));


// BTFL_MSP_FC_VARIANT reply
struct BTFL_msp_fc_variant_t {
  char flight_controller_identifier[4]; // e.g. "BTFL"
} __attribute__((packed));


// BTFL_MSP_FC_VERSION reply
struct BTFL_msp_fc_version_t {
  uint8_t fc_version_major;
  uint8_t fc_version_minor;
  uint8_t fc_version_patch_level;
} __attribute__((packed));


// BTFL_MSP_BUILD_INFO reply (fixed portion; API 1.46+ appends uint32_t build_info_flags)
struct BTFL_msp_build_info_t {
  char build_date[11];       // "MMM DD YYYY"
  char build_time[8];        // "HH:MM:SS"
  char git_short_revision[7];
} __attribute__((packed));


// BTFL_MSP_BATTERY_CONFIG reply
struct BTFL_msp_battery_config_t {
  uint8_t  vbat_min_cell_voltage_legacy;   // in 0.1V
  uint8_t  vbat_max_cell_voltage_legacy;
  uint8_t  vbat_warn_cell_voltage_legacy;
  uint16_t battery_capacity_mah;
  uint8_t  voltage_meter_source;
  uint8_t  current_meter_source;
  // API 1.39+:
  uint16_t vbat_min_cell_voltage;          // in 0.01V
  uint16_t vbat_max_cell_voltage;
  uint16_t vbat_warn_cell_voltage;
} __attribute__((packed));


// BTFL_MSP_SET_BATTERY_CONFIG command
typedef BTFL_msp_battery_config_t BTFL_msp_set_battery_config_t;


// BTFL_MSP_MODE_RANGES reply — one entry per mode activation condition
struct BTFL_msp_mode_range_entry_t {
  uint8_t box_permanent_id;
  uint8_t aux_channel_index;
  uint8_t range_start_step;
  uint8_t range_end_step;
} __attribute__((packed));


// BTFL_MSP_SET_MODE_RANGE command
struct BTFL_msp_set_mode_range_t {
  uint8_t mode_index;
  uint8_t box_permanent_id;
  uint8_t aux_channel_index;
  uint8_t range_start_step;
  uint8_t range_end_step;
  uint8_t mode_logic;               // optional extended field
  uint8_t linked_box_permanent_id;  // optional extended field
} __attribute__((packed));


// BTFL_MSP_FEATURE_CONFIG reply
struct BTFL_msp_feature_config_t {
  uint32_t enabled_features; // bitmask
} __attribute__((packed));


// BTFL_MSP_SET_FEATURE_CONFIG command
typedef BTFL_msp_feature_config_t BTFL_msp_set_feature_config_t;


// BTFL_MSP_BOARD_ALIGNMENT_CONFIG reply
struct BTFL_msp_board_alignment_config_t {
  int16_t roll_degrees;
  int16_t pitch_degrees;
  int16_t yaw_degrees;
} __attribute__((packed));


// BTFL_MSP_SET_BOARD_ALIGNMENT_CONFIG command
typedef BTFL_msp_board_alignment_config_t BTFL_msp_set_board_alignment_config_t;


// BTFL_MSP_SET_CURRENT_METER_CONFIG command
struct BTFL_msp_set_current_meter_config_t {
  uint8_t  meter_id;
  uint16_t scale;
  uint16_t offset;
} __attribute__((packed));


// BTFL_MSP_MIXER_CONFIG reply
struct BTFL_msp_mixer_config_t {
  uint8_t mixer_mode;
  uint8_t yaw_motors_reversed;
} __attribute__((packed));


// BTFL_MSP_SET_MIXER_CONFIG command
typedef BTFL_msp_mixer_config_t BTFL_msp_set_mixer_config_t;


// BTFL_MSP_RX_CONFIG reply (fixed portion; many optional fields follow)
struct BTFL_msp_rx_config_t {
  uint8_t  serialrx_provider;
  uint16_t maxcheck;
  uint16_t midrc;
  uint16_t mincheck;
  uint8_t  spektrum_sat_bind;
  uint16_t rx_min_usec;
  uint16_t rx_max_usec;
} __attribute__((packed));


// BTFL_MSP_LED_COLORS reply — one entry per configurable LED color
struct BTFL_msp_led_color_entry_t {
  uint16_t hue;
  uint8_t  saturation;
  uint8_t  value;
} __attribute__((packed));


// BTFL_MSP_RSSI_CONFIG reply
struct BTFL_msp_rssi_config_t {
  uint8_t rssi_channel;
} __attribute__((packed));


// BTFL_MSP_SET_RSSI_CONFIG command
typedef BTFL_msp_rssi_config_t BTFL_msp_set_rssi_config_t;


// BTFL_MSP_ADJUSTMENT_RANGES reply — one entry per adjustment range
struct BTFL_msp_adjustment_range_entry_t {
  uint8_t  adjustment_index;       // deprecated
  uint8_t  aux_channel_index;
  uint8_t  range_start_step;
  uint8_t  range_end_step;
  uint8_t  adjustment_config;
  uint8_t  aux_switch_channel_index;
  uint16_t adjustment_center;
  uint16_t adjustment_scale;
} __attribute__((packed));


// BTFL_MSP_SET_ADJUSTMENT_RANGE command
struct BTFL_msp_set_adjustment_range_t {
  uint8_t  range_index;
  uint8_t  adjustment_index;       // deprecated
  uint8_t  aux_channel_index;
  uint8_t  range_start_step;
  uint8_t  range_end_step;
  uint8_t  adjustment_config;
  uint8_t  aux_switch_channel_index;
  uint16_t adjustment_center;      // optional
  uint16_t adjustment_scale;       // optional
} __attribute__((packed));


// BTFL_MSP_CF_SERIAL_CONFIG reply — one entry per serial port
struct BTFL_msp_serial_port_entry_t {
  uint8_t  identifier;
  uint16_t function_mask;
  uint8_t  msp_baudrate_index;
  uint8_t  gps_baudrate_index;
  uint8_t  telemetry_baudrate_index;
  uint8_t  blackbox_baudrate_index;
} __attribute__((packed));


// BTFL_MSP_SET_VOLTAGE_METER_CONFIG command
struct BTFL_msp_set_voltage_meter_config_t {
  uint8_t sensor_id;
  uint8_t vbat_scale;
  uint8_t vbat_res_div_val;
  uint8_t vbat_res_div_multiplier;
} __attribute__((packed));


// BTFL_MSP_SONAR_ALTITUDE reply
struct BTFL_msp_sonar_altitude_t {
  int32_t altitude_cm;
} __attribute__((packed));


// BTFL_MSP_PID_CONTROLLER reply
struct BTFL_msp_pid_controller_t {
  uint8_t pid_controller_type;
} __attribute__((packed));


// BTFL_MSP_ARMING_CONFIG reply
struct BTFL_msp_arming_config_t {
  uint8_t auto_disarm_delay;
  uint8_t reserved;
  uint8_t small_angle;
  uint8_t gyro_cal_on_first_arm;
} __attribute__((packed));


// BTFL_MSP_SET_ARMING_CONFIG command
typedef BTFL_msp_arming_config_t BTFL_msp_set_arming_config_t;


// BTFL_MSP_REBOOT reply
struct BTFL_msp_reboot_t {
  uint8_t reboot_mode;         // BTFL_MSP_REBOOT_...
  uint8_t msc_filesystem_ready; // only when reboot_mode == BTFL_MSP_REBOOT_MSC
} __attribute__((packed));


// BTFL_MSP_DATAFLASH_SUMMARY reply
struct BTFL_msp_dataflash_summary_t {
  uint8_t  flags;        // bit 0: ready, bit 1: supported
  uint32_t sector_count;
  uint32_t total_size;
  uint32_t used_size;
} __attribute__((packed));


// BTFL_MSP_DATAFLASH_READ request
struct BTFL_msp_dataflash_read_request_t {
  uint32_t address;
  uint16_t read_length;       // optional, defaults to 128
  uint8_t  allow_compression; // optional
} __attribute__((packed));


// BTFL_MSP_DATAFLASH_READ reply (fixed portion; variable data[] follows)
struct BTFL_msp_dataflash_read_t {
  uint32_t address;
  uint16_t read_length;
  uint8_t  compression_method;
} __attribute__((packed));


// BTFL_MSP_FAILSAFE_CONFIG reply
struct BTFL_msp_failsafe_config_t {
  uint8_t  failsafe_delay;
  uint8_t  failsafe_landing_time;
  uint16_t failsafe_throttle;
  uint8_t  failsafe_switch_mode;
  uint16_t failsafe_throttle_low_delay;
  uint8_t  failsafe_procedure;
} __attribute__((packed));


// BTFL_MSP_SET_FAILSAFE_CONFIG command
typedef BTFL_msp_failsafe_config_t BTFL_msp_set_failsafe_config_t;


// BTFL_MSP_RXFAIL_CONFIG reply — one entry per RC channel
struct BTFL_msp_rxfail_channel_entry_t {
  uint8_t  mode;
  uint16_t step_value;
} __attribute__((packed));


// BTFL_MSP_SET_RXFAIL_CONFIG command
struct BTFL_msp_set_rxfail_config_t {
  uint8_t  channel_index;
  uint8_t  mode;
  uint16_t step_value;
} __attribute__((packed));


// BTFL_MSP_SDCARD_SUMMARY reply
struct BTFL_msp_sdcard_summary_t {
  uint8_t  flags;          // bit 0: supported
  uint8_t  state;          // 0=not present, 1=fatal, 2=card init, 3=fs init, 4=ready
  uint8_t  last_error;
  uint32_t free_space_kb;
  uint32_t total_space_kb;
} __attribute__((packed));


// BTFL_MSP_BLACKBOX_CONFIG reply
struct BTFL_msp_blackbox_config_t {
  uint8_t  blackbox_supported;
  uint8_t  device;
  uint8_t  rate_numerator;     // deprecated
  uint8_t  rate_denominator;
  uint16_t p_ratio;
  uint8_t  sample_rate;
  uint32_t fields_disabled_mask; // API 1.45+
} __attribute__((packed));


// BTFL_MSP_SET_BLACKBOX_CONFIG command
struct BTFL_msp_set_blackbox_config_t {
  uint8_t  device;
  uint8_t  rate_numerator;       // deprecated
  uint8_t  rate_denominator;     // deprecated
  uint16_t p_ratio;              // optional
  uint8_t  sample_rate;          // optional
  uint32_t fields_disabled_mask; // optional, API 1.45+
} __attribute__((packed));


// BTFL_MSP_VTX_CONFIG reply (fixed portion; optional table fields follow from API 1.42+)
struct BTFL_msp_vtx_config_t {
  uint8_t  vtx_type;
  uint8_t  band;
  uint8_t  channel;
  uint8_t  power;
  uint8_t  pit_mode;
  uint16_t frequency_mhz;
  uint8_t  device_ready;
  uint8_t  low_power_disarm;
  uint16_t pit_mode_frequency_mhz; // API 1.42+
  uint8_t  vtx_table_available;    // API 1.42+, if USE_VTX_TABLE
  uint8_t  vtx_table_bands;
  uint8_t  vtx_table_channels;
  uint8_t  vtx_table_power_levels;
} __attribute__((packed));


// BTFL_MSP_ADVANCED_CONFIG reply
struct BTFL_msp_advanced_config_t {
  uint8_t  deprecated_gyro_sync_denom;
  uint8_t  pid_process_denom;
  uint8_t  use_unsynced_pwm;
  uint8_t  motor_protocol;
  uint16_t motor_pwm_rate;
  uint16_t motor_idle_value;
  uint8_t  deprecated_gyro_use_32khz;
  uint8_t  motor_inversion;
  uint8_t  deprecated_gyro_to_use;
  uint8_t  gyro_high_fsr;
  uint8_t  gyro_movement_calibration_threshold;
  uint16_t gyro_calibration_duration;
  uint16_t gyro_offset_yaw;
  uint8_t  check_overflow;
  uint8_t  debug_mode;           // API 1.42+
  uint8_t  debug_value_count;    // API 1.42+
} __attribute__((packed));


// BTFL_MSP_FILTER_CONFIG reply (fixed portion; many conditional fields follow)
struct BTFL_msp_filter_config_t {
  uint8_t  gyro_lpf1_static_hz_legacy;
  uint16_t dterm_lpf1_static_hz;
  uint16_t yaw_lowpass_hz;
  uint16_t gyro_soft_notch_hz_1;
  uint16_t gyro_soft_notch_cutoff_1;
  uint16_t dterm_notch_hz;
  uint16_t dterm_notch_cutoff;
  uint16_t gyro_soft_notch_hz_2;
  uint16_t gyro_soft_notch_cutoff_2;
  uint8_t  dterm_lpf1_type;
  uint8_t  gyro_hardware_lpf;
  uint8_t  deprecated_gyro_32khz_hardware_lpf;
  uint16_t gyro_lpf1_static_hz;
  uint16_t gyro_lpf2_static_hz;
  uint8_t  gyro_lpf1_type;
  uint8_t  gyro_lpf2_type;
  uint16_t dterm_lpf2_static_hz;
} __attribute__((packed));


// BTFL_MSP_PID_ADVANCED reply (fixed portion; many conditional fields follow)
struct BTFL_msp_pid_advanced_t {
  uint16_t reserved_1;
  uint16_t reserved_2;
  uint16_t deprecated_yaw_p_limit;
  uint8_t  reserved_3;
  uint8_t  deprecated_vbat_pid_compensation;
  uint8_t  feedforward_transition;
  uint8_t  reserved_4;
  uint8_t  reserved_5;
  uint8_t  reserved_6;
  uint16_t rate_accel_limit;
  uint16_t yaw_rate_accel_limit;
  uint8_t  angle_limit;
  uint8_t  deprecated_level_sensitivity;
  uint16_t deprecated_iterm_throttle_threshold;
  uint16_t anti_gravity_gain;
  uint16_t deprecated_dterm_setpoint_weight;
  uint8_t  iterm_rotation;
  uint8_t  deprecated_smart_feedforward;
} __attribute__((packed));


// BTFL_MSP_SENSOR_CONFIG reply
struct BTFL_msp_sensor_config_t {
  uint8_t acc_hardware;
  uint8_t baro_hardware;
  uint8_t mag_hardware;
  uint8_t rangefinder_hardware; // API 1.46+
  uint8_t opticalflow_hardware; // API 1.46+
} __attribute__((packed));


// BTFL_MSP_SET_SENSOR_CONFIG command
typedef BTFL_msp_sensor_config_t BTFL_msp_set_sensor_config_t;


// BTFL_MSP_SET_ARMING_DISABLED command
struct BTFL_msp_set_arming_disabled_t {
  uint8_t command;                   // 0=enable arming, 1=disable arming
  uint8_t disable_runaway_takeoff;   // optional, if USE_RUNAWAY_TAKEOFF
} __attribute__((packed));


// BTFL_MSP_STATUS reply (fixed portion; variable flight_mode_flags_extended[] follows)
struct BTFL_msp_status_t {
  uint16_t cycle_time_us;
  uint16_t i2c_error_count;
  uint16_t sensors_present;              // bitmask
  uint32_t flight_mode_flags;
  uint8_t  current_pid_profile_index;
  uint16_t average_system_load_percent;
  uint16_t deprecated_gyro_cycle_time;
  uint8_t  flight_mode_flags_byte_count;
} __attribute__((packed));


// BTFL_MSP_RAW_IMU reply
struct BTFL_msp_raw_imu_t {
  int16_t accel_x;
  int16_t accel_y;
  int16_t accel_z;
  int16_t gyro_x_dps;
  int16_t gyro_y_dps;
  int16_t gyro_z_dps;
  int16_t mag_x;
  int16_t mag_y;
  int16_t mag_z;
} __attribute__((packed));


// BTFL_MSP_SERVO reply — always 8 entries
struct BTFL_msp_servo_t {
  uint16_t servo[8];
} __attribute__((packed));


// BTFL_MSP_MOTOR reply — always 8 entries; unused motors = 0
struct BTFL_msp_motor_t {
  uint16_t motor[8];
} __attribute__((packed));


// BTFL_MSP_SET_MOTOR command
struct BTFL_msp_set_motor_t {
  uint16_t motor[8]; // variable up to MAX_SUPPORTED_MOTORS; unused = 0
} __attribute__((packed));


// BTFL_MSP_RAW_GPS reply
struct BTFL_msp_raw_gps_t {
  uint8_t  gps_fix;
  uint8_t  num_satellites;
  int32_t  latitude;              // degrees * 1e7
  int32_t  longitude;             // degrees * 1e7
  int16_t  altitude_m;
  uint16_t ground_speed_cms;
  uint16_t ground_course_decidegrees;
  uint16_t pdop;                  // API 1.44+
} __attribute__((packed));


// BTFL_MSP_SET_RAW_GPS command
struct BTFL_msp_set_raw_gps_t {
  uint8_t  gps_fix;
  uint8_t  num_satellites;
  int32_t  latitude;
  int32_t  longitude;
  int16_t  altitude_m;
  uint16_t ground_speed_cms;
} __attribute__((packed));


// BTFL_MSP_COMP_GPS reply
struct BTFL_msp_comp_gps_t {
  uint16_t distance_to_home_m;
  uint16_t direction_to_home_degrees;
  uint8_t  gps_heartbeat;         // toggles 0/1 each update
} __attribute__((packed));


// BTFL_MSP_ATTITUDE reply
struct BTFL_msp_attitude_t {
  int16_t roll_decidegrees;
  int16_t pitch_decidegrees;
  int16_t yaw_degrees;
} __attribute__((packed));


// BTFL_MSP_ATTITUDE_QUATERNION reply
struct BTFL_msp_attitude_quaternion_t {
  int16_t w; // scaled by 0x7FFF
  int16_t x;
  int16_t y;
  int16_t z;
} __attribute__((packed));


// BTFL_MSP_ALTITUDE reply
struct BTFL_msp_altitude_t {
  int32_t altitude_cm;
  int16_t variometer_cms;
} __attribute__((packed));


// BTFL_MSP_ANALOG reply
struct BTFL_msp_analog_t {
  uint8_t  battery_voltage_legacy; // in 0.1V
  uint16_t mah_drawn;
  uint16_t rssi;                   // 0–1023
  int16_t  amperage_centiamps;
  uint16_t battery_voltage;        // in 0.01V
} __attribute__((packed));


// BTFL_MSP_VOLTAGE_METERS reply — one entry per active voltage meter
struct BTFL_msp_voltage_meter_entry_t {
  uint8_t meter_id;
  uint8_t voltage_scaled; // in 0.1V
} __attribute__((packed));


// BTFL_MSP_CURRENT_METERS reply — one entry per active current meter
struct BTFL_msp_current_meter_entry_t {
  uint8_t  meter_id;
  uint16_t mah_drawn;
  uint16_t amperage_centiamps;
} __attribute__((packed));


// BTFL_MSP_BATTERY_STATE reply
struct BTFL_msp_battery_state_t {
  uint8_t  cell_count;
  uint16_t battery_capacity_mah;
  uint8_t  battery_voltage_legacy; // in 0.1V
  uint16_t mah_drawn;
  int16_t  amperage_centiamps;
  uint8_t  battery_state;          // BTFL_MSP_BATTERY_...
  uint16_t battery_voltage;        // in 0.01V
} __attribute__((packed));


// BTFL_MSP_RC_TUNING reply (fixed portion; optional fields follow from API 1.41+)
struct BTFL_msp_rc_tuning_t {
  uint8_t  rc_rate_roll;
  uint8_t  rc_expo_roll;
  uint8_t  rate_roll;
  uint8_t  rate_pitch;
  uint8_t  rate_yaw;
  uint8_t  deprecated_tpa_rate;
  uint8_t  throttle_mid;
  uint8_t  throttle_expo;
  uint16_t deprecated_tpa_breakpoint;
  uint8_t  rc_expo_yaw;
  uint8_t  rc_rate_yaw;
  uint8_t  rc_rate_pitch;
  uint8_t  rc_expo_pitch;
} __attribute__((packed));


// BTFL_MSP_PID reply — one entry per PID axis
struct BTFL_msp_pid_entry_t {
  uint8_t p;
  uint8_t i;
  uint8_t d;
} __attribute__((packed));


// BTFL_MSP_SET_PID command — one entry per PID axis (mirrors BTFL_msp_pid_entry_t array)
typedef BTFL_msp_pid_entry_t BTFL_msp_set_pid_entry_t;


// BTFL_MSP_SET_RAW_RC command
struct BTFL_msp_set_raw_rc_t {
  uint16_t rc_channel[18]; // variable number of channels up to MAX_SUPPORTED_RC_CHANNEL_COUNT
} __attribute__((packed));


// BTFL_MSP_SERVO_CONFIGURATIONS reply — one entry per servo
struct BTFL_msp_servo_config_entry_t {
  uint16_t min;
  uint16_t max;
  uint16_t middle;
  uint8_t  rate;
  uint8_t  forward_from_channel;
  uint32_t reversed_sources;
} __attribute__((packed));


// BTFL_MSP_SET_SERVO_CONFIGURATION command
struct BTFL_msp_set_servo_configuration_t {
  uint8_t  servo_index;
  uint16_t min;
  uint16_t max;
  uint16_t middle;
  uint8_t  rate;
  uint8_t  forward_from_channel;
  uint32_t reversed_sources;
} __attribute__((packed));


// BTFL_MSP_SERVO_MIX_RULES reply — one entry per rule
struct BTFL_msp_servo_mix_rule_entry_t {
  uint8_t target_channel;
  uint8_t input_source;
  uint8_t rate;
  uint8_t speed;
  uint8_t min;
  uint8_t max;
  uint8_t box;
} __attribute__((packed));


// BTFL_MSP_SET_SERVO_MIX_RULE command
struct BTFL_msp_set_servo_mix_rule_t {
  uint8_t rule_index;
  uint8_t target_channel;
  uint8_t input_source;
  uint8_t rate;
  uint8_t speed;
  uint8_t min;
  uint8_t max;
  uint8_t box;
} __attribute__((packed));


// BTFL_MSP_MOTOR_TELEMETRY reply (fixed header; per-motor entries follow)
struct BTFL_msp_motor_telemetry_t {
  uint8_t motor_count;
  // Repeated motor_count times:
  // uint32_t rpm;
  // uint16_t invalid_percent;
  // uint8_t  esc_temperature_c;
  // uint16_t esc_voltage_mv;       // in 0.01V
  // uint16_t esc_current_ma;
  // uint16_t esc_consumption_mah;
} __attribute__((packed));


// BTFL_MSP_MOTOR_3D_CONFIG reply
struct BTFL_msp_motor_3d_config_t {
  uint16_t deadband3d_low;
  uint16_t deadband3d_high;
  uint16_t neutral3d;
} __attribute__((packed));


// BTFL_MSP_SET_MOTOR_3D_CONFIG command
typedef BTFL_msp_motor_3d_config_t BTFL_msp_set_motor_3d_config_t;


// BTFL_MSP_RC_DEADBAND reply
struct BTFL_msp_rc_deadband_t {
  uint8_t  deadband;
  uint8_t  yaw_deadband;
  uint8_t  pos_hold_deadband;    // if USE_POSITION_HOLD
  uint16_t deadband3d_throttle;
} __attribute__((packed));


// BTFL_MSP_SET_RC_DEADBAND command
typedef BTFL_msp_rc_deadband_t BTFL_msp_set_rc_deadband_t;


// BTFL_MSP_SENSOR_ALIGNMENT reply (fixed portion; optional mag custom align fields follow)
struct BTFL_msp_sensor_alignment_t {
  uint8_t gyro_alignment;
  uint8_t acc_alignment;
  uint8_t mag_alignment;            // if USE_MAG
  uint8_t gyro_detection_flags;     // API 1.41+
  uint8_t gyro_enabled_bitmask;     // API 1.41+
} __attribute__((packed));


// BTFL_MSP_MOTOR_CONFIG reply
struct BTFL_msp_motor_config_t {
  uint16_t deprecated_minthrottle;
  uint16_t maxthrottle;
  uint16_t mincommand;
  uint8_t  motor_count;            // API 1.42+
  uint8_t  motor_pole_count;       // API 1.42+
  uint8_t  use_dshot_telemetry;    // API 1.42+, if USE_DSHOT_TELEMETRY
  uint8_t  esc_sensor_available;   // API 1.42+, if USE_ESC_SENSOR
} __attribute__((packed));


// BTFL_MSP_GPS_CONFIG reply
struct BTFL_msp_gps_config_t {
  uint8_t provider;
  uint8_t sbas_mode;
  uint8_t auto_config;
  uint8_t auto_baud;
  uint8_t gps_set_home_once;       // API 1.43+
  uint8_t gps_ublox_use_galileo;   // API 1.43+
} __attribute__((packed));


// BTFL_MSP_SET_GPS_CONFIG command
typedef BTFL_msp_gps_config_t BTFL_msp_set_gps_config_t;


// BTFL_MSP_COMPASS_CONFIG reply
struct BTFL_msp_compass_config_t {
  int16_t mag_declination_decidegrees;
} __attribute__((packed));


// BTFL_MSP_SET_COMPASS_CONFIG command
typedef BTFL_msp_compass_config_t BTFL_msp_set_compass_config_t;


// BTFL_MSP_GPS_RESCUE reply (fixed portion; optional fields follow from API 1.43+)
struct BTFL_msp_gps_rescue_t {
  uint16_t max_rescue_angle_degrees;
  uint16_t return_altitude_m;
  uint16_t descent_distance_m;
  uint16_t ground_speed_cms;
  uint16_t throttle_min;
  uint16_t throttle_max;
  uint16_t hover_throttle;
  uint8_t  sanity_checks_enabled;
  uint8_t  min_satellites;
} __attribute__((packed));


// BTFL_MSP_GPS_RESCUE_PIDS reply
struct BTFL_msp_gps_rescue_pids_t {
  uint16_t altitude_p;
  uint16_t altitude_i;
  uint16_t altitude_d;
  uint16_t velocity_p;
  uint16_t velocity_i;
  uint16_t velocity_d;
  uint16_t yaw_p;
} __attribute__((packed));


// BTFL_MSP_SET_GPS_RESCUE_PIDS command
typedef BTFL_msp_gps_rescue_pids_t BTFL_msp_set_gps_rescue_pids_t;


// BTFL_MSP_SIMPLIFIED_TUNING reply
struct BTFL_msp_simplified_tuning_t {
  uint8_t simplified_pids_enabled;
  uint8_t simplified_master_multiplier;
  uint8_t simplified_i_gain;
  uint8_t simplified_d_gain;
  uint8_t simplified_pi_gain;
  uint8_t simplified_dmax_gain;
  uint8_t simplified_feedforward_gain;
  uint8_t simplified_pitch_pi_gain;
  uint8_t simplified_gyro_filter_enabled;
  uint8_t simplified_gyro_filter_multiplier;
  uint8_t simplified_dterm_filter_enabled;
  uint8_t simplified_dterm_filter_multiplier;
} __attribute__((packed));


// BTFL_MSP_SET_SIMPLIFIED_TUNING command
typedef BTFL_msp_simplified_tuning_t BTFL_msp_set_simplified_tuning_t;


// BTFL_MSP_VALIDATE_SIMPLIFIED_TUNING reply
struct BTFL_msp_validate_simplified_tuning_t {
  uint8_t pid_profile_valid;
  uint8_t gyro_filters_valid;
  uint8_t dterm_filters_valid;
} __attribute__((packed));


// BTFL_MSP_UID reply
struct BTFL_msp_uid_t {
  uint32_t uid_0;
  uint32_t uid_1;
  uint32_t uid_2;
} __attribute__((packed));


// BTFL_MSP_GPSSTATISTICS reply
struct BTFL_msp_gpsstatistics_t {
  uint16_t last_message_dt_ms;
  uint32_t errors;
  uint32_t timeouts;
  uint32_t packet_count;
  uint16_t hdop;
  uint16_t eph_cm;
  uint16_t epv_cm;
} __attribute__((packed));


// BTFL_MSP_OSD_VIDEO_CONFIG reply
struct BTFL_msp_osd_video_config_t {
  uint8_t video_system;
} __attribute__((packed));


// BTFL_MSP_SET_OSD_VIDEO_CONFIG command
typedef BTFL_msp_osd_video_config_t BTFL_msp_set_osd_video_config_t;


// BTFL_MSP_COPY_PROFILE command
struct BTFL_msp_copy_profile_t {
  uint8_t profile_type;      // BTFL_MSP_PROFILE_TYPE_...
  uint8_t dst_profile_index;
  uint8_t src_profile_index;
} __attribute__((packed));


// BTFL_MSP_BEEPER_CONFIG reply
struct BTFL_msp_beeper_config_t {
  uint32_t beeper_off_flags;
  uint8_t  dshot_beacon_tone;
  uint32_t dshot_beacon_off_flags;
} __attribute__((packed));


// BTFL_MSP_SET_BEEPER_CONFIG command
typedef BTFL_msp_beeper_config_t BTFL_msp_set_beeper_config_t;


// BTFL_MSP_TX_INFO reply
struct BTFL_msp_tx_info_t {
  uint8_t rssi_source;
  uint8_t rtc_date_time_is_set;
} __attribute__((packed));


// BTFL_MSP_OSD_CANVAS reply
struct BTFL_msp_osd_canvas_t {
  uint8_t canvas_cols;
  uint8_t canvas_rows;
} __attribute__((packed));


// BTFL_MSP_SET_OSD_CANVAS command
typedef BTFL_msp_osd_canvas_t BTFL_msp_set_osd_canvas_t;


// BTFL_MSP_RESET_CONF reply
struct BTFL_msp_reset_conf_t {
  uint8_t success; // API 1.42+
} __attribute__((packed));


// BTFL_MSP_ACC_TRIM reply
struct BTFL_msp_acc_trim_t {
  int16_t pitch_trim;
  int16_t roll_trim;
} __attribute__((packed));


// BTFL_MSP_SET_ACC_TRIM command
typedef BTFL_msp_acc_trim_t BTFL_msp_set_acc_trim_t;


// BTFL_MSP_SET_PASSTHROUGH reply
struct BTFL_msp_set_passthrough_t {
  uint8_t result; // 0=failed, 1=success
} __attribute__((packed));


// BTFL_MSP_SET_RTC command
struct BTFL_msp_set_rtc_t {
  uint32_t seconds;
  uint16_t millis;
} __attribute__((packed));


// BTFL_MSP_RTC reply
struct BTFL_msp_rtc_t {
  uint16_t year;
  uint8_t  month;
  uint8_t  day;
  uint8_t  hours;
  uint8_t  minutes;
  uint8_t  seconds;
  uint16_t millis;
} __attribute__((packed));


// BTFL_MSP_DEBUG reply
struct BTFL_msp_debug_t {
  int16_t debug_value[8]; // DEBUG16_VALUE_COUNT entries
} __attribute__((packed));


// BTFL_MSP_MODE_RANGES_EXTRA reply (fixed header; per-mode entries follow)
struct BTFL_msp_mode_ranges_extra_t {
  uint8_t mode_count;
  // Repeated mode_count times:
  // uint8_t box_permanent_id;
  // uint8_t mode_logic;
  // uint8_t linked_box_permanent_id;
} __attribute__((packed));


// ============================================================
// MSPv2 Betaflight payload structures
// ============================================================

// BTFL_MSP2_MOTOR_OUTPUT_REORDERING reply
struct BTFL_msp2_motor_output_reordering_t {
  uint8_t max_supported_motors;
  uint8_t reordering_index[8]; // MAX_SUPPORTED_MOTORS entries
} __attribute__((packed));


// BTFL_MSP2_SEND_DSHOT_COMMAND command (fixed portion; variable command[] follows)
struct BTFL_msp2_send_dshot_command_t {
  uint8_t command_type;  // 0=instant, 1=wait for motor stop
  uint8_t motor_index;   // 0xFF = all motors
  uint8_t command_count;
} __attribute__((packed));


// BTFL_MSP2_GET_OSD_WARNINGS reply (fixed portion; variable warning_text[] follows)
struct BTFL_msp2_get_osd_warnings_t {
  uint8_t display_attr;
  uint8_t warning_length;
} __attribute__((packed));


// BTFL_MSP2_GET_TEXT reply (fixed portion; variable text[] follows)
struct BTFL_msp2_get_text_t {
  uint8_t text_type;   // BTFL_MSP2_TEXT_...
  uint8_t text_length;
} __attribute__((packed));


// BTFL_MSP2_GET_LED_STRIP_CONFIG_VALUES reply
struct BTFL_msp2_led_strip_config_values_t {
  uint8_t  brightness;
  uint16_t rainbow_delta;
  uint16_t rainbow_freq;
} __attribute__((packed));


// BTFL_MSP2_SET_LED_STRIP_CONFIG_VALUES command
typedef BTFL_msp2_led_strip_config_values_t BTFL_msp2_set_led_strip_config_values_t;


// BTFL_MSP2_SENSOR_CONFIG_ACTIVE reply
struct BTFL_msp2_sensor_config_active_t {
  uint8_t detected_gyro;        // if USE_GYRO
  uint8_t detected_acc;         // if USE_ACC
  uint8_t detected_baro;        // if USE_BARO
  uint8_t detected_mag;         // if USE_MAG
  uint8_t detected_rangefinder; // if USE_RANGEFINDER
  uint8_t detected_opticalflow; // if USE_OPTICALFLOW
} __attribute__((packed));


// BTFL_MSP2_MCU_INFO reply (fixed portion; variable mcu_type_name[] follows)
struct BTFL_msp2_mcu_info_t {
  uint8_t mcu_type_id;
  uint8_t mcu_type_name_length;
} __attribute__((packed));


// BTFL_MSP2_BATTERY_PROFILE reply
struct BTFL_msp2_battery_profile_t {
  uint8_t  profile_index;
  uint16_t vbat_min_cell_voltage;          // in 0.01V
  uint16_t vbat_max_cell_voltage;
  uint16_t vbat_warn_cell_voltage;
  uint16_t vbat_full_cell_voltage;
  uint16_t battery_capacity_mah;
  uint8_t  force_battery_cell_count;
  uint8_t  consumption_warning_percentage;
} __attribute__((packed));


// BTFL_MSP2_SET_BATTERY_PROFILE command
typedef BTFL_msp2_battery_profile_t BTFL_msp2_set_battery_profile_t;


// BTFL_MSP2_SENSOR_GPS command (external GPS sensor push)
struct BTFL_msp2_sensor_gps_t {
  uint8_t  instance;
  uint16_t gps_week;
  uint32_t ms_tow;
  uint8_t  fix_type;
  uint8_t  satellites_in_view;
  uint16_t horizontal_pos_accuracy_cm;
  uint16_t vertical_pos_accuracy_cm;
  uint16_t horizontal_vel_accuracy_cm;
  uint16_t hdop;
  int32_t  longitude;                    // degrees * 1e7
  int32_t  latitude;                     // degrees * 1e7
  int32_t  altitude_mm;
  int32_t  ned_vel_north_cms;
  int32_t  ned_vel_east_cms;
  int32_t  ned_vel_down_cms;
  uint16_t true_course_centidegrees;
  uint16_t true_yaw_centidegrees;
  uint16_t year;
  uint8_t  month;
  uint8_t  day;
  uint8_t  hour;
  uint8_t  minute;
  uint8_t  second;
} __attribute__((packed));
