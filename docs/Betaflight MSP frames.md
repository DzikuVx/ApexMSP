# MSP Frames From src/main/msp/msp.c

Generated from handlers in `src/main/msp/msp.c`.

For each MSP frame:
1. MSP frame name
2. MSP frame ID
3. C payload structure with semantically inferred field names

> Notes:
> - Field names are inferred from variable names, expressions, and inline comments in `msp.c`.
> - Some payloads are variable-length/conditional; conditions are noted inline.
> - API version guards are noted where applicable (e.g. "API 1.42+").
> - MSPv2 Betaflight-specific frames use IDs in the `0x3000` range.
> - MSPv2 common frames use IDs in the `0x1000` range.

---

## MSP_API_VERSION
- MSP frame name: `MSP_API_VERSION`
- MSP frame ID: `1 (0x01)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_api_version_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  protocol_version;
    uint8_t  api_version_major;
    uint8_t  api_version_minor;
} msp_api_version_response_t;
```

---

## MSP_FC_VARIANT
- MSP frame name: `MSP_FC_VARIANT`
- MSP frame ID: `2 (0x02)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_fc_variant_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    char flight_controller_identifier[4]; // e.g. "BTFL"
} msp_fc_variant_response_t;
```

---

## MSP_FC_VERSION
- MSP frame name: `MSP_FC_VERSION`
- MSP frame ID: `3 (0x03)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_fc_version_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  fc_version_major;
    uint8_t  fc_version_minor;
    uint8_t  fc_version_patch_level;
} msp_fc_version_response_t;
```

---

## MSP_BOARD_INFO
- MSP frame name: `MSP_BOARD_INFO`
- MSP frame ID: `4 (0x04)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_board_info_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    char     board_identifier[4];
    uint16_t hardware_revision;
    uint8_t  osd_support;                  // bit 0: OSD supported, bit 1: MAX7456
    uint8_t  target_capabilities;
    uint8_t  target_name_length;
    char     target_name[];                // variable, target_name_length bytes
    // if USE_BOARD_INFO:
    uint8_t  board_name_length;
    char     board_name[];
    uint8_t  manufacturer_id_length;
    char     manufacturer_id[];
    // if USE_SIGNATURE:
    uint8_t  signature[32];
    uint8_t  mcu_type_id;
    // API 1.42+:
    uint8_t  configuration_state;
    // API 1.43+:
    uint16_t gyro_sample_rate_hz;
    uint32_t configuration_problems;
    // API 1.44+, if USE_SPI:
    uint8_t  spi_device_count;
    // API 1.44+, if USE_I2C:
    uint8_t  i2c_device_count;
} msp_board_info_response_t;
```

---

## MSP_BUILD_INFO
- MSP frame name: `MSP_BUILD_INFO`
- MSP frame ID: `5 (0x05)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_build_info_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    char     build_date[11];        // "MMM DD YYYY"
    char     build_time[8];         // "HH:MM:SS"
    char     git_short_revision[7];
    // API 1.46+:
    uint32_t build_info_flags;
} msp_build_info_response_t;
```

---

## MSP_NAME
- MSP frame name: `MSP_NAME`
- MSP frame ID: `10 (0x0A)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_name_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    char craft_name[]; // null-terminated string, variable length
} msp_name_response_t;
```

---

## MSP_SET_NAME
- MSP frame name: `MSP_SET_NAME`
- MSP frame ID: `11 (0x0B)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    char craft_name[]; // variable length, up to MAX_NAME_LENGTH
} msp_set_name_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_set_name_response_t;
```

---

## MSP_BATTERY_CONFIG
- MSP frame name: `MSP_BATTERY_CONFIG`
- MSP frame ID: `32 (0x20)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_battery_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  vbat_min_cell_voltage_legacy;  // in units of 0.1V
    uint8_t  vbat_max_cell_voltage_legacy;
    uint8_t  vbat_warn_cell_voltage_legacy;
    uint16_t battery_capacity_mah;
    uint8_t  voltage_meter_source;
    uint8_t  current_meter_source;
    // API 1.39+:
    uint16_t vbat_min_cell_voltage;         // in units of 0.01V
    uint16_t vbat_max_cell_voltage;
    uint16_t vbat_warn_cell_voltage;
} msp_battery_config_response_t;
```

---

## MSP_SET_BATTERY_CONFIG
- MSP frame name: `MSP_SET_BATTERY_CONFIG`
- MSP frame ID: `33 (0x21)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  vbat_min_cell_voltage_legacy;
    uint8_t  vbat_max_cell_voltage_legacy;
    uint8_t  vbat_warn_cell_voltage_legacy;
    uint16_t battery_capacity_mah;
    uint8_t  voltage_meter_source;
    uint8_t  current_meter_source;
    // API 1.39+:
    uint16_t vbat_min_cell_voltage;
    uint16_t vbat_max_cell_voltage;
    uint16_t vbat_warn_cell_voltage;
} msp_set_battery_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_set_battery_config_response_t;
```

---

## MSP_MODE_RANGES
- MSP frame name: `MSP_MODE_RANGES`
- MSP frame ID: `34 (0x22)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_mode_ranges_request_t;
```

Response payload:
```c
// Repeated MAX_MODE_ACTIVATION_CONDITION_COUNT times:
typedef struct __attribute__((packed)) {
    uint8_t box_permanent_id;
    uint8_t aux_channel_index;
    uint8_t range_start_step;
    uint8_t range_end_step;
} msp_mode_range_entry_t;
```

---

## MSP_SET_MODE_RANGE
- MSP frame name: `MSP_SET_MODE_RANGE`
- MSP frame ID: `35 (0x23)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mode_index;
    uint8_t box_permanent_id;
    uint8_t aux_channel_index;
    uint8_t range_start_step;
    uint8_t range_end_step;
    // optional extended fields:
    uint8_t mode_logic;
    uint8_t linked_box_permanent_id;
} msp_set_mode_range_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_set_mode_range_response_t;
```

---

## MSP_FEATURE_CONFIG
- MSP frame name: `MSP_FEATURE_CONFIG`
- MSP frame ID: `36 (0x24)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_feature_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t enabled_features; // bitmask
} msp_feature_config_response_t;
```

---

## MSP_SET_FEATURE_CONFIG
- MSP frame name: `MSP_SET_FEATURE_CONFIG`
- MSP frame ID: `37 (0x25)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t enabled_features;
} msp_set_feature_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_set_feature_config_response_t;
```

---

## MSP_BOARD_ALIGNMENT_CONFIG
- MSP frame name: `MSP_BOARD_ALIGNMENT_CONFIG`
- MSP frame ID: `38 (0x26)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_board_alignment_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int16_t roll_degrees;
    int16_t pitch_degrees;
    int16_t yaw_degrees;
} msp_board_alignment_config_response_t;
```

---

## MSP_SET_BOARD_ALIGNMENT_CONFIG
- MSP frame name: `MSP_SET_BOARD_ALIGNMENT_CONFIG`
- MSP frame ID: `39 (0x27)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    int16_t roll_degrees;
    int16_t pitch_degrees;
    int16_t yaw_degrees;
} msp_set_board_alignment_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_set_board_alignment_config_response_t;
```

---

## MSP_CURRENT_METER_CONFIG
- MSP frame name: `MSP_CURRENT_METER_CONFIG`
- MSP frame ID: `40 (0x28)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_current_meter_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t meter_count;
    // Repeated meter_count times:
    // uint8_t  subframe_length;
    // uint8_t  meter_id;
    // uint8_t  sensor_type;
    // uint16_t scale;
    // uint16_t offset;
} msp_current_meter_config_response_t;
```

---

## MSP_SET_CURRENT_METER_CONFIG
- MSP frame name: `MSP_SET_CURRENT_METER_CONFIG`
- MSP frame ID: `41 (0x29)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  meter_id;
    uint16_t scale;
    uint16_t offset;
} msp_set_current_meter_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_set_current_meter_config_response_t;
```

---

## MSP_MIXER_CONFIG
- MSP frame name: `MSP_MIXER_CONFIG`
- MSP frame ID: `42 (0x2A)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_mixer_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mixer_mode;
    uint8_t yaw_motors_reversed;
} msp_mixer_config_response_t;
```

---

## MSP_SET_MIXER_CONFIG
- MSP frame name: `MSP_SET_MIXER_CONFIG`
- MSP frame ID: `43 (0x2B)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mixer_mode;
    uint8_t yaw_motors_reversed; // optional
} msp_set_mixer_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_set_mixer_config_response_t;
```

---

## MSP_RX_CONFIG
- MSP frame name: `MSP_RX_CONFIG`
- MSP frame ID: `44 (0x2C)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rx_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  serialrx_provider;
    uint16_t maxcheck;
    uint16_t midrc;
    uint16_t mincheck;
    uint8_t  spektrum_sat_bind;
    // API 1.39+:
    uint16_t rx_min_usec;
    uint16_t rx_max_usec;
    uint8_t  deprecated_rc_interpolation;
    uint8_t  deprecated_rc_interpolation_interval;
    uint16_t air_mode_activate_threshold;
    // if USE_RX_SPI, API 1.37+:
    uint8_t  rx_spi_protocol;
    uint32_t rx_spi_id;
    uint8_t  rx_spi_rf_channel_count;
    // API 1.39+:
    uint8_t  fpv_cam_angle_degrees;
    // API 1.40+, if USE_RC_SMOOTHING_FILTER:
    uint8_t  deprecated_rc_smoothing_channels;
    uint8_t  deprecated_rc_smoothing_type;
    uint8_t  rc_smoothing_setpoint_cutoff;
    uint8_t  rc_smoothing_throttle_cutoff;
    uint8_t  rc_smoothing_auto_factor_throttle;
    uint8_t  deprecated_rc_smoothing_derivative_type;
    // API 1.40+, if USE_USB_CDC_HID:
    uint8_t  usb_device_type;
    // API 1.42+, if USE_RC_SMOOTHING_FILTER:
    uint8_t  rc_smoothing_auto_factor_rpy;
    // API 1.44+:
    uint8_t  rc_smoothing_enabled;
    // API 1.45+, if USE_RX_EXPRESSLRS:
    uint8_t  rx_expresslrs_uid[6];
    // API 1.47+, if USE_RX_EXPRESSLRS:
    uint8_t  rx_expresslrs_model_id;
} msp_rx_config_response_t;
```

---

## MSP_SET_RX_CONFIG
- MSP frame name: `MSP_SET_RX_CONFIG`
- MSP frame ID: `45 (0x2D)`

Request payload: mirrors `MSP_RX_CONFIG` response with conditional optional tail fields.

---

## MSP_LED_COLORS
- MSP frame name: `MSP_LED_COLORS`
- MSP frame ID: `46 (0x2E)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_led_colors_request_t;
```

Response payload:
```c
// Repeated LED_CONFIGURABLE_COLOR_COUNT times:
typedef struct __attribute__((packed)) {
    uint16_t hue;
    uint8_t  saturation;
    uint8_t  value;
} msp_led_color_entry_t;
```

---

## MSP_SET_LED_COLORS
- MSP frame name: `MSP_SET_LED_COLORS`
- MSP frame ID: `47 (0x2F)`

Request payload:
```c
// Repeated LED_CONFIGURABLE_COLOR_COUNT times:
typedef struct __attribute__((packed)) {
    uint16_t hue;
    uint8_t  saturation;
    uint8_t  value;
} msp_set_led_color_entry_t;
```

---

## MSP_LED_STRIP_CONFIG
- MSP frame name: `MSP_LED_STRIP_CONFIG`
- MSP frame ID: `48 (0x30)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_led_strip_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t led_config[LED_STRIP_MAX_LENGTH]; // one uint32 per LED
    uint8_t  advanced_profile_support;
    uint8_t  selected_profile;
} msp_led_strip_config_response_t;
```

---

## MSP_SET_LED_STRIP_CONFIG
- MSP frame name: `MSP_SET_LED_STRIP_CONFIG`
- MSP frame ID: `49 (0x31)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  led_index;
    uint32_t led_config;
    // API 1.41+:
    uint8_t  ledstrip_profile; // optional
} msp_set_led_strip_config_request_t;
```

---

## MSP_RSSI_CONFIG
- MSP frame name: `MSP_RSSI_CONFIG`
- MSP frame ID: `50 (0x32)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rssi_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rssi_channel;
} msp_rssi_config_response_t;
```

---

## MSP_SET_RSSI_CONFIG
- MSP frame name: `MSP_SET_RSSI_CONFIG`
- MSP frame ID: `51 (0x33)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rssi_channel;
} msp_set_rssi_config_request_t;
```

---

## MSP_ADJUSTMENT_RANGES
- MSP frame name: `MSP_ADJUSTMENT_RANGES`
- MSP frame ID: `52 (0x34)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_adjustment_ranges_request_t;
```

Response payload:
```c
// Repeated MAX_ADJUSTMENT_RANGE_COUNT times:
typedef struct __attribute__((packed)) {
    uint8_t  adjustment_index;          // deprecated
    uint8_t  aux_channel_index;
    uint8_t  range_start_step;
    uint8_t  range_end_step;
    uint8_t  adjustment_config;
    uint8_t  aux_switch_channel_index;
    uint16_t adjustment_center;
    uint16_t adjustment_scale;
} msp_adjustment_range_entry_t;
```

---

## MSP_SET_ADJUSTMENT_RANGE
- MSP frame name: `MSP_SET_ADJUSTMENT_RANGE`
- MSP frame ID: `53 (0x35)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  range_index;
    uint8_t  adjustment_index;          // deprecated
    uint8_t  aux_channel_index;
    uint8_t  range_start_step;
    uint8_t  range_end_step;
    uint8_t  adjustment_config;
    uint8_t  aux_switch_channel_index;
    // optional:
    uint16_t adjustment_center;
    uint16_t adjustment_scale;
} msp_set_adjustment_range_request_t;
```

---

## MSP_CF_SERIAL_CONFIG
- MSP frame name: `MSP_CF_SERIAL_CONFIG`
- MSP frame ID: `54 (0x36)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_cf_serial_config_request_t;
```

Response payload:
```c
// Repeated per available serial port:
typedef struct __attribute__((packed)) {
    uint8_t  identifier;
    uint16_t function_mask;
    uint8_t  msp_baudrate_index;
    uint8_t  gps_baudrate_index;
    uint8_t  telemetry_baudrate_index;
    uint8_t  blackbox_baudrate_index;
} msp_serial_port_entry_t;
```

---

## MSP_SET_CF_SERIAL_CONFIG
- MSP frame name: `MSP_SET_CF_SERIAL_CONFIG`
- MSP frame ID: `55 (0x37)`

Request payload:
```c
// Variable number of port configs:
typedef struct __attribute__((packed)) {
    uint8_t  identifier;
    uint16_t function_mask;
    uint8_t  msp_baudrate_index;
    uint8_t  gps_baudrate_index;
    uint8_t  telemetry_baudrate_index;
    uint8_t  blackbox_baudrate_index;
} msp_set_serial_port_entry_t;
```

---

## MSP_VOLTAGE_METER_CONFIG
- MSP frame name: `MSP_VOLTAGE_METER_CONFIG`
- MSP frame ID: `56 (0x38)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_voltage_meter_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t adc_sensor_count;
    // Repeated adc_sensor_count times:
    // uint8_t subframe_length;
    // uint8_t sensor_id;
    // uint8_t sensor_type;
    // uint8_t vbat_scale;
    // uint8_t vbat_res_div_val;
    // uint8_t vbat_res_div_multiplier;
} msp_voltage_meter_config_response_t;
```

---

## MSP_SET_VOLTAGE_METER_CONFIG
- MSP frame name: `MSP_SET_VOLTAGE_METER_CONFIG`
- MSP frame ID: `57 (0x39)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sensor_id;
    uint8_t vbat_scale;
    uint8_t vbat_res_div_val;
    uint8_t vbat_res_div_multiplier;
} msp_set_voltage_meter_config_request_t;
```

---

## MSP_SONAR_ALTITUDE
- MSP frame name: `MSP_SONAR_ALTITUDE`
- MSP frame ID: `58 (0x3A)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_sonar_altitude_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int32_t altitude_cm; // if USE_RANGEFINDER, else 0
} msp_sonar_altitude_response_t;
```

---

## MSP_PID_CONTROLLER
- MSP frame name: `MSP_PID_CONTROLLER`
- MSP frame ID: `59 (0x3B)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_pid_controller_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t pid_controller_type;
} msp_pid_controller_response_t;
```

---

## MSP_SET_PID_CONTROLLER
- MSP frame name: `MSP_SET_PID_CONTROLLER`
- MSP frame ID: `60 (0x3C)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields processed */
} msp_set_pid_controller_request_t;
```

---

## MSP_ARMING_CONFIG
- MSP frame name: `MSP_ARMING_CONFIG`
- MSP frame ID: `61 (0x3D)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_arming_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t auto_disarm_delay;
    uint8_t reserved;
    uint8_t small_angle;
    uint8_t gyro_cal_on_first_arm;
} msp_arming_config_response_t;
```

---

## MSP_SET_ARMING_CONFIG
- MSP frame name: `MSP_SET_ARMING_CONFIG`
- MSP frame ID: `62 (0x3E)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t auto_disarm_delay;
    uint8_t reserved;
    uint8_t small_angle;           // optional
    uint8_t gyro_cal_on_first_arm; // optional
} msp_set_arming_config_request_t;
```

---

## MSP_RX_MAP
- MSP frame name: `MSP_RX_MAP`
- MSP frame ID: `64 (0x40)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rx_map_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t channel_map[RX_MAPPABLE_CHANNEL_COUNT];
} msp_rx_map_response_t;
```

---

## MSP_SET_RX_MAP
- MSP frame name: `MSP_SET_RX_MAP`
- MSP frame ID: `65 (0x41)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t channel_map[RX_MAPPABLE_CHANNEL_COUNT];
} msp_set_rx_map_request_t;
```

---

## MSP_REBOOT
- MSP frame name: `MSP_REBOOT`
- MSP frame ID: `68 (0x44)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t reboot_mode; // optional: 0=firmware, 1=bootloader ROM, 2=MSC, 3=MSC UTC, 4=bootloader flash
} msp_reboot_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t reboot_mode;
    // if USE_USB_MSC and mode == MSP_REBOOT_MSC:
    uint8_t msc_filesystem_ready;
} msp_reboot_response_t;
```

---

## MSP_DATAFLASH_SUMMARY
- MSP frame name: `MSP_DATAFLASH_SUMMARY`
- MSP frame ID: `70 (0x46)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_dataflash_summary_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  flags;           // bit 0: ready, bit 1: supported
    uint32_t sector_count;
    uint32_t total_size;
    uint32_t used_size;
} msp_dataflash_summary_response_t;
```

---

## MSP_DATAFLASH_READ
- MSP frame name: `MSP_DATAFLASH_READ`
- MSP frame ID: `71 (0x47)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t address;
    uint16_t read_length;          // optional, defaults to 128
    uint8_t  allow_compression;    // optional
} msp_dataflash_read_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t address;
    uint16_t read_length;
    uint8_t  compression_method;
    uint8_t  data[];               // variable length
} msp_dataflash_read_response_t;
```

---

## MSP_DATAFLASH_ERASE
- MSP frame name: `MSP_DATAFLASH_ERASE`
- MSP frame ID: `72 (0x48)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields — triggers erase */
} msp_dataflash_erase_request_t;
```

---

## MSP_FAILSAFE_CONFIG
- MSP frame name: `MSP_FAILSAFE_CONFIG`
- MSP frame ID: `75 (0x4B)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_failsafe_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  failsafe_delay;
    uint8_t  failsafe_landing_time;
    uint16_t failsafe_throttle;
    uint8_t  failsafe_switch_mode;
    uint16_t failsafe_throttle_low_delay;
    uint8_t  failsafe_procedure;
} msp_failsafe_config_response_t;
```

---

## MSP_SET_FAILSAFE_CONFIG
- MSP frame name: `MSP_SET_FAILSAFE_CONFIG`
- MSP frame ID: `76 (0x4C)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  failsafe_delay;
    uint8_t  failsafe_landing_time;
    uint16_t failsafe_throttle;
    uint8_t  failsafe_switch_mode;
    uint16_t failsafe_throttle_low_delay;
    uint8_t  failsafe_procedure;
} msp_set_failsafe_config_request_t;
```

---

## MSP_RXFAIL_CONFIG
- MSP frame name: `MSP_RXFAIL_CONFIG`
- MSP frame ID: `77 (0x4D)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rxfail_config_request_t;
```

Response payload:
```c
// Repeated MAX_SUPPORTED_RC_CHANNEL_COUNT times:
typedef struct __attribute__((packed)) {
    uint8_t  mode;
    uint16_t step_value;
} msp_rxfail_channel_entry_t;
```

---

## MSP_SET_RXFAIL_CONFIG
- MSP frame name: `MSP_SET_RXFAIL_CONFIG`
- MSP frame ID: `78 (0x4E)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  channel_index;
    uint8_t  mode;
    uint16_t step_value;
} msp_set_rxfail_config_request_t;
```

---

## MSP_SDCARD_SUMMARY
- MSP frame name: `MSP_SDCARD_SUMMARY`
- MSP frame ID: `79 (0x4F)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_sdcard_summary_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  flags;            // bit 0: supported
    uint8_t  state;            // 0=not present, 1=fatal, 2=card init, 3=fs init, 4=ready
    uint8_t  last_error;
    uint32_t free_space_kb;
    uint32_t total_space_kb;
} msp_sdcard_summary_response_t;
```

---

## MSP_BLACKBOX_CONFIG
- MSP frame name: `MSP_BLACKBOX_CONFIG`
- MSP frame ID: `80 (0x50)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_blackbox_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  blackbox_supported;
    uint8_t  device;
    uint8_t  rate_numerator;    // deprecated
    uint8_t  rate_denominator;
    uint16_t p_ratio;
    uint8_t  sample_rate;
    // API 1.45+:
    uint32_t fields_disabled_mask;
} msp_blackbox_config_response_t;
```

---

## MSP_SET_BLACKBOX_CONFIG
- MSP frame name: `MSP_SET_BLACKBOX_CONFIG`
- MSP frame ID: `81 (0x51)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  device;
    uint8_t  rate_numerator;        // deprecated
    uint8_t  rate_denominator;      // deprecated
    uint16_t p_ratio;               // optional
    uint8_t  sample_rate;           // optional
    uint32_t fields_disabled_mask;  // optional, API 1.45+
} msp_set_blackbox_config_request_t;
```

---

## MSP_TRANSPONDER_CONFIG
- MSP frame name: `MSP_TRANSPONDER_CONFIG`
- MSP frame ID: `82 (0x52)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_transponder_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t provider_count;
    // Repeated provider_count times:
    // uint8_t provider_type;
    // uint8_t data_length;
    uint8_t selected_provider;
    uint8_t provider_data[]; // variable, length per selected provider
} msp_transponder_config_response_t;
```

---

## MSP_SET_TRANSPONDER_CONFIG
- MSP frame name: `MSP_SET_TRANSPONDER_CONFIG`
- MSP frame ID: `83 (0x53)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t provider;
    uint8_t provider_data[]; // variable length based on provider
} msp_set_transponder_config_request_t;
```

---

## MSP_OSD_CONFIG
- MSP frame name: `MSP_OSD_CONFIG`
- MSP frame ID: `84 (0x54)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_osd_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  osd_flags;             // bit 0: OSD feature enabled
    uint8_t  video_system;
    uint8_t  units;
    uint8_t  rssi_alarm;
    uint16_t cap_alarm;
    uint8_t  timer_count_low_byte;  // legacy
    uint8_t  osd_item_count;        // legacy
    uint16_t alt_alarm;
    uint16_t item_pos[OSD_ITEM_COUNT];
    uint8_t  stat_count;
    uint8_t  stat_enabled[OSD_STAT_COUNT];
    uint8_t  timer_count;
    uint16_t timer_value[OSD_TIMER_COUNT];
    // API < 1.41:
    uint16_t enabled_warnings;
    // API 1.41+:
    uint8_t  warning_count;
    uint32_t enabled_warnings;
    // API 1.41+, if USE_OSD_PROFILES:
    uint8_t  osd_profile_count;
    uint8_t  selected_osd_profile;
    // API 1.41+, if USE_OSD_STICK_OVERLAY:
    uint8_t  overlay_radio_mode;
    // API 1.43+:
    uint8_t  camera_frame_width;
    uint8_t  camera_frame_height;
    // API 1.46+:
    uint16_t link_quality_alarm;
    // API 1.47+:
    uint16_t rssi_dbm_alarm;
} msp_osd_config_response_t;
```

---

## MSP_SET_OSD_CONFIG
- MSP frame name: `MSP_SET_OSD_CONFIG`
- MSP frame ID: `85 (0x55)`

Request payload:
```c
// First byte selects sub-command:
// addr == 0xFF (-1): set general OSD settings
// addr == 0xFE (-2): set a timer
// addr >= 0: set OSD item position
typedef struct __attribute__((packed)) {
    uint8_t address; // sub-command selector
    // if address == 0xFF:
    //   uint8_t  video_system;
    //   uint8_t  units;
    //   uint8_t  rssi_alarm;
    //   uint16_t cap_alarm;
    //   uint16_t timer_count_unused;
    //   uint16_t alt_alarm;
    //   uint16_t enabled_warnings;     (optional)
    //   uint32_t enabled_warnings_ext; (optional)
    //   uint8_t  selected_osd_profile; (optional)
    //   uint8_t  overlay_radio_mode;   (optional)
    //   uint8_t  camera_frame_width;   (optional)
    //   uint8_t  camera_frame_height;  (optional)
    //   uint16_t link_quality_alarm;   (optional)
    //   uint16_t rssi_dbm_alarm;       (optional)
    // if address == 0xFE:
    //   uint8_t  timer_index;
    //   uint16_t timer_value;
    // else:
    //   uint16_t item_value;
    //   uint8_t  screen; (optional)
} msp_set_osd_config_request_t;
```

---

## MSP_OSD_CHAR_READ
- MSP frame name: `MSP_OSD_CHAR_READ`
- MSP frame ID: `86 (0x56)`

Response payload: raw OSD character bitmap data (variable).

---

## MSP_OSD_CHAR_WRITE
- MSP frame name: `MSP_OSD_CHAR_WRITE`
- MSP frame ID: `87 (0x57)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    // uint8_t address  (if data_size <= 55)
    // uint16_t address (if data_size > 55)
    uint8_t  character_data[]; // variable
} msp_osd_char_write_request_t;
```

---

## MSP_VTX_CONFIG
- MSP frame name: `MSP_VTX_CONFIG`
- MSP frame ID: `88 (0x58)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_vtx_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  vtx_type;
    uint8_t  band;
    uint8_t  channel;
    uint8_t  power;
    uint8_t  pit_mode;
    uint16_t frequency_mhz;
    uint8_t  device_ready;
    uint8_t  low_power_disarm;
    // API 1.42+:
    uint16_t pit_mode_frequency_mhz;
    // API 1.42+, if USE_VTX_TABLE:
    uint8_t  vtx_table_available;
    uint8_t  vtx_table_bands;
    uint8_t  vtx_table_channels;
    uint8_t  vtx_table_power_levels;
} msp_vtx_config_response_t;
```

---

## MSP_SET_VTX_CONFIG
- MSP frame name: `MSP_SET_VTX_CONFIG`
- MSP frame ID: `89 (0x59)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t frequency_or_band_channel; // if < 5000: band/channel encoded, else frequency
    uint8_t  power;                     // optional
    uint8_t  pit_mode;                  // optional
    uint8_t  low_power_disarm;          // optional
    uint16_t pit_mode_frequency_mhz;    // optional
    // if remaining >= 4:
    uint8_t  band;
    uint8_t  channel;
    uint16_t frequency_mhz;
    uint8_t  vtx_table_band_count;
    uint8_t  vtx_table_channel_count;
    uint8_t  vtx_table_power_count;
    uint8_t  clear_vtx_table;
} msp_set_vtx_config_request_t;
```

---

## MSP_ADVANCED_CONFIG
- MSP frame name: `MSP_ADVANCED_CONFIG`
- MSP frame ID: `90 (0x5A)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_advanced_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
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
    // API 1.42+:
    uint8_t  debug_mode;
    uint8_t  debug_value_count;
} msp_advanced_config_response_t;
```

---

## MSP_SET_ADVANCED_CONFIG
- MSP frame name: `MSP_SET_ADVANCED_CONFIG`
- MSP frame ID: `91 (0x5B)`

Request payload: mirrors `MSP_ADVANCED_CONFIG` response with optional tail fields.

---

## MSP_FILTER_CONFIG
- MSP frame name: `MSP_FILTER_CONFIG`
- MSP frame ID: `92 (0x5C)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_filter_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  gyro_lpf1_static_hz_legacy;    // 1 byte legacy field
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
    // API 1.41+:
    uint8_t  dterm_lpf2_type;
    // API 1.41+, if USE_DYN_LPF:
    uint16_t gyro_lpf1_dyn_min_hz;
    uint16_t gyro_lpf1_dyn_max_hz;
    uint16_t dterm_lpf1_dyn_min_hz;
    uint16_t dterm_lpf1_dyn_max_hz;
    // API 1.42+:
    uint8_t  deprecated_dyn_notch_range;
    uint8_t  deprecated_dyn_notch_width_percent;
    // API 1.42+, if USE_DYN_NOTCH_FILTER:
    uint16_t dyn_notch_q;
    uint16_t dyn_notch_min_hz;
    // API 1.42+, if USE_RPM_FILTER:
    uint8_t  rpm_filter_harmonics;
    uint8_t  rpm_filter_min_hz;
    // API 1.43+, if USE_DYN_NOTCH_FILTER:
    uint16_t dyn_notch_max_hz;
    // API 1.44+, if USE_DYN_LPF:
    uint8_t  dterm_lpf1_dyn_expo;
    // API 1.44+, if USE_DYN_NOTCH_FILTER:
    uint8_t  dyn_notch_count;
} msp_filter_config_response_t;
```

---

## MSP_SET_FILTER_CONFIG
- MSP frame name: `MSP_SET_FILTER_CONFIG`
- MSP frame ID: `93 (0x5D)`

Request payload: mirrors `MSP_FILTER_CONFIG` response with conditional optional tail fields.

---

## MSP_PID_ADVANCED
- MSP frame name: `MSP_PID_ADVANCED`
- MSP frame ID: `94 (0x5E)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_pid_advanced_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t reserved_1;
    uint16_t reserved_2;
    uint16_t deprecated_yaw_p_limit;
    uint8_t  reserved_3;
    uint8_t  deprecated_vbat_pid_compensation;
    uint8_t  feedforward_transition;    // if USE_FEEDFORWARD
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
    // if USE_ITERM_RELAX:
    uint8_t  iterm_relax;
    uint8_t  iterm_relax_type;
    // if USE_ABSOLUTE_CONTROL:
    uint8_t  abs_control_gain;
    // if USE_THROTTLE_BOOST:
    uint8_t  throttle_boost;
    // if USE_ACRO_TRAINER:
    uint8_t  acro_trainer_angle_limit;
    uint16_t pid_roll_f;
    uint16_t pid_pitch_f;
    uint16_t pid_yaw_f;
    uint8_t  deprecated_anti_gravity_mode;
    // if USE_D_MAX:
    uint8_t  d_max_roll;
    uint8_t  d_max_pitch;
    uint8_t  d_max_yaw;
    uint8_t  d_max_gain;
    uint8_t  d_max_advance;
    // if USE_INTEGRATED_YAW_CONTROL:
    uint8_t  use_integrated_yaw;
    uint8_t  integrated_yaw_relax;
    // API 1.42+, if USE_ITERM_RELAX:
    uint8_t  iterm_relax_cutoff;
    // API 1.43+:
    uint8_t  motor_output_limit;
    uint8_t  auto_profile_cell_count;
    // API 1.43+, if USE_DYN_IDLE:
    uint8_t  dyn_idle_min_rpm;
    // API 1.44+, if USE_FEEDFORWARD:
    uint8_t  feedforward_averaging;
    uint8_t  feedforward_smooth_factor;
    uint8_t  feedforward_boost;
    uint8_t  feedforward_max_rate_limit;
    uint8_t  feedforward_jitter_factor;
    // API 1.44+, if USE_BATTERY_VOLTAGE_SAG_COMPENSATION:
    uint8_t  vbat_sag_compensation;
    // API 1.44+, if USE_THRUST_LINEARIZATION:
    uint8_t  thrust_linearization;
    // API 1.45+:
    uint8_t  tpa_mode;
    uint8_t  tpa_rate;
    uint16_t tpa_breakpoint;
} msp_pid_advanced_response_t;
```

---

## MSP_SET_PID_ADVANCED
- MSP frame name: `MSP_SET_PID_ADVANCED`
- MSP frame ID: `95 (0x5F)`

Request payload: mirrors `MSP_PID_ADVANCED` response with optional tail fields based on remaining byte count.

---

## MSP_SENSOR_CONFIG
- MSP frame name: `MSP_SENSOR_CONFIG`
- MSP frame ID: `96 (0x60)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_sensor_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t acc_hardware;
    uint8_t baro_hardware;
    uint8_t mag_hardware;
    // API 1.46+:
    uint8_t rangefinder_hardware;
    uint8_t opticalflow_hardware;
} msp_sensor_config_response_t;
```

---

## MSP_SET_SENSOR_CONFIG
- MSP frame name: `MSP_SET_SENSOR_CONFIG`
- MSP frame ID: `97 (0x61)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t acc_hardware;
    uint8_t baro_hardware;
    uint8_t mag_hardware;
    uint8_t rangefinder_hardware; // optional
    uint8_t opticalflow_hardware; // optional
} msp_set_sensor_config_request_t;
```

---

## MSP_CAMERA_CONTROL
- MSP frame name: `MSP_CAMERA_CONTROL`
- MSP frame ID: `98 (0x62)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t key_press;
} msp_camera_control_request_t;
```

---

## MSP_SET_ARMING_DISABLED
- MSP frame name: `MSP_SET_ARMING_DISABLED`
- MSP frame ID: `99 (0x63)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t command;                    // 0=enable arming, 1=disable arming
    uint8_t disable_runaway_takeoff;    // optional, if USE_RUNAWAY_TAKEOFF
} msp_set_arming_disabled_request_t;
```

---

## MSP_STATUS
- MSP frame name: `MSP_STATUS`
- MSP frame ID: `101 (0x65)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_status_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t cycle_time_us;
    uint16_t i2c_error_count;
    uint16_t sensors_present;              // bitmask
    uint32_t flight_mode_flags;
    uint8_t  current_pid_profile_index;
    uint16_t average_system_load_percent;
    uint16_t deprecated_gyro_cycle_time;
    uint8_t  flight_mode_flags_byte_count;
    uint8_t  flight_mode_flags_extended[]; // variable
    uint8_t  arming_disable_flags_count;
    uint32_t arming_disable_flags;
    uint8_t  config_state_flags;
    // API 1.46+, if USE_ADC_INTERNAL:
    uint16_t cpu_temp_celsius;
    // API 1.46+:
    uint8_t  control_rate_profile_count;
    // API 1.48+:
    uint8_t  battery_profile_count;
    uint8_t  current_battery_profile_index;
} msp_status_response_t;
```

---

## MSP_STATUS_EX
- MSP frame name: `MSP_STATUS_EX`
- MSP frame ID: `150 (0x96)`

Response payload: same as `MSP_STATUS` but with `pid_profile_count` and `current_control_rate_profile_index` in place of `deprecated_gyro_cycle_time`.

---

## MSP_RAW_IMU
- MSP frame name: `MSP_RAW_IMU`
- MSP frame ID: `102 (0x66)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_raw_imu_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int16_t  accel_x;
    int16_t  accel_y;
    int16_t  accel_z;
    int16_t  gyro_x_dps;
    int16_t  gyro_y_dps;
    int16_t  gyro_z_dps;
    int16_t  mag_x;
    int16_t  mag_y;
    int16_t  mag_z;
} msp_raw_imu_response_t;
```

---

## MSP_SERVO
- MSP frame name: `MSP_SERVO`
- MSP frame ID: `103 (0x67)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_servo_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t servo[MAX_SUPPORTED_SERVOS];
} msp_servo_response_t;
```

---

## MSP_SERVO_CONFIGURATIONS
- MSP frame name: `MSP_SERVO_CONFIGURATIONS`
- MSP frame ID: `120 (0x78)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_servo_configurations_request_t;
```

Response payload:
```c
// Repeated MAX_SUPPORTED_SERVOS times:
typedef struct __attribute__((packed)) {
    uint16_t min;
    uint16_t max;
    uint16_t middle;
    uint8_t  rate;
    uint8_t  forward_from_channel;
    uint32_t reversed_sources;
} msp_servo_config_entry_t;
```

---

## MSP_SET_SERVO_CONFIGURATION
- MSP frame name: `MSP_SET_SERVO_CONFIGURATION`
- MSP frame ID: `212 (0xD4)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  servo_index;
    uint16_t min;
    uint16_t max;
    uint16_t middle;
    uint8_t  rate;
    uint8_t  forward_from_channel;
    uint32_t reversed_sources;
} msp_set_servo_configuration_request_t;
```

---

## MSP_SERVO_MIX_RULES
- MSP frame name: `MSP_SERVO_MIX_RULES`
- MSP frame ID: `241 (0xF1)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_servo_mix_rules_request_t;
```

Response payload:
```c
// Repeated MAX_SERVO_RULES times:
typedef struct __attribute__((packed)) {
    uint8_t target_channel;
    uint8_t input_source;
    uint8_t rate;
    uint8_t speed;
    uint8_t min;
    uint8_t max;
    uint8_t box;
} msp_servo_mix_rule_entry_t;
```

---

## MSP_SET_SERVO_MIX_RULE
- MSP frame name: `MSP_SET_SERVO_MIX_RULE`
- MSP frame ID: `242 (0xF2)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rule_index;
    uint8_t target_channel;
    uint8_t input_source;
    uint8_t rate;
    uint8_t speed;
    uint8_t min;
    uint8_t max;
    uint8_t box;
} msp_set_servo_mix_rule_request_t;
```

---

## MSP_MOTOR
- MSP frame name: `MSP_MOTOR`
- MSP frame ID: `104 (0x68)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_motor_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t motor[8]; // always 8 entries; unused motors = 0
} msp_motor_response_t;
```

---

## MSP_SET_MOTOR
- MSP frame name: `MSP_SET_MOTOR`
- MSP frame ID: `214 (0xD6)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t motor[]; // variable, up to MAX_SUPPORTED_MOTORS
} msp_set_motor_request_t;
```

---

## MSP_MOTOR_TELEMETRY
- MSP frame name: `MSP_MOTOR_TELEMETRY`
- MSP frame ID: `139 (0x8B)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_motor_telemetry_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t motor_count;
    // Repeated motor_count times:
    // uint32_t rpm;
    // uint16_t invalid_percent;
    // uint8_t  esc_temperature_c;
    // uint16_t esc_voltage_mv;   // in 0.01V units
    // uint16_t esc_current_ma;
    // uint16_t esc_consumption_mah;
} msp_motor_telemetry_response_t;
```

---

## MSP_RC
- MSP frame name: `MSP_RC`
- MSP frame ID: `105 (0x69)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rc_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t rc_channel[]; // variable, rxRuntimeState.channelCount entries
} msp_rc_response_t;
```

---

## MSP_SET_RAW_RC
- MSP frame name: `MSP_SET_RAW_RC`
- MSP frame ID: `200 (0xC8)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t rc_channel[]; // variable number of channels
} msp_set_raw_rc_request_t;
```

---

## MSP_RAW_GPS
- MSP frame name: `MSP_RAW_GPS`
- MSP frame ID: `106 (0x6A)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_raw_gps_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  gps_fix;
    uint8_t  num_satellites;
    int32_t  latitude;          // in degrees * 1e7
    int32_t  longitude;         // in degrees * 1e7
    int16_t  altitude_m;
    uint16_t ground_speed_cms;
    uint16_t ground_course_decidegrees;
    // API 1.44+:
    uint16_t pdop;
} msp_raw_gps_response_t;
```

---

## MSP_SET_RAW_GPS
- MSP frame name: `MSP_SET_RAW_GPS`
- MSP frame ID: `201 (0xC9)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  gps_fix;
    uint8_t  num_satellites;
    int32_t  latitude;
    int32_t  longitude;
    int16_t  altitude_m;
    uint16_t ground_speed_cms;
} msp_set_raw_gps_request_t;
```

---

## MSP_COMP_GPS
- MSP frame name: `MSP_COMP_GPS`
- MSP frame ID: `107 (0x6B)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_comp_gps_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t distance_to_home_m;
    uint16_t direction_to_home_degrees;
    uint8_t  gps_heartbeat;
} msp_comp_gps_response_t;
```

---

## MSP_ATTITUDE
- MSP frame name: `MSP_ATTITUDE`
- MSP frame ID: `108 (0x6C)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_attitude_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int16_t roll_decidegrees;
    int16_t pitch_decidegrees;
    int16_t yaw_degrees;
} msp_attitude_response_t;
```

---

## MSP_ATTITUDE_QUATERNION
- MSP frame name: `MSP_ATTITUDE_QUATERNION`
- MSP frame ID: `167 (0xA7)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_attitude_quaternion_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int16_t w; // scaled by 0x7FFF
    int16_t x;
    int16_t y;
    int16_t z;
} msp_attitude_quaternion_response_t;
```

---

## MSP_ALTITUDE
- MSP frame name: `MSP_ALTITUDE`
- MSP frame ID: `109 (0x6D)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_altitude_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int32_t  altitude_cm;
    int16_t  variometer_cms;
} msp_altitude_response_t;
```

---

## MSP_ANALOG
- MSP frame name: `MSP_ANALOG`
- MSP frame ID: `110 (0x6E)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_analog_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  battery_voltage_legacy; // in 0.1V units
    uint16_t mah_drawn;
    uint16_t rssi;                   // 0–1023
    int16_t  amperage_centiamps;
    uint16_t battery_voltage;        // in 0.01V units
} msp_analog_response_t;
```

---

## MSP_VOLTAGE_METERS
- MSP frame name: `MSP_VOLTAGE_METERS`
- MSP frame ID: `128 (0x80)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_voltage_meters_request_t;
```

Response payload:
```c
// Repeated per active voltage meter:
typedef struct __attribute__((packed)) {
    uint8_t meter_id;
    uint8_t voltage_scaled; // in 0.1V units
} msp_voltage_meter_entry_t;
```

---

## MSP_CURRENT_METERS
- MSP frame name: `MSP_CURRENT_METERS`
- MSP frame ID: `129 (0x81)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_current_meters_request_t;
```

Response payload:
```c
// Repeated per active current meter:
typedef struct __attribute__((packed)) {
    uint8_t  meter_id;
    uint16_t mah_drawn;
    uint16_t amperage_centiamps;
} msp_current_meter_entry_t;
```

---

## MSP_BATTERY_STATE
- MSP frame name: `MSP_BATTERY_STATE`
- MSP frame ID: `130 (0x82)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_battery_state_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  cell_count;
    uint16_t battery_capacity_mah;
    uint8_t  battery_voltage_legacy; // in 0.1V
    uint16_t mah_drawn;
    int16_t  amperage_centiamps;
    uint8_t  battery_state;           // 0=ok, 1=warning, 2=critical, 3=not present, 4=init
    uint16_t battery_voltage;         // in 0.01V
} msp_battery_state_response_t;
```

---

## MSP_RC_TUNING
- MSP frame name: `MSP_RC_TUNING`
- MSP frame ID: `111 (0x6F)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rc_tuning_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
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
    // API 1.41+:
    uint8_t  throttle_limit_type;
    uint8_t  throttle_limit_percent;
    // API 1.42+:
    uint16_t rate_limit_roll;
    uint16_t rate_limit_pitch;
    uint16_t rate_limit_yaw;
    // API 1.43+:
    uint8_t  rates_type;
    // API 1.47+:
    uint8_t  throttle_hover;
} msp_rc_tuning_response_t;
```

---

## MSP_SET_RC_TUNING
- MSP frame name: `MSP_SET_RC_TUNING`
- MSP frame ID: `204 (0xCC)`

Request payload: mirrors `MSP_RC_TUNING` response with optional tail fields based on remaining byte count.

---

## MSP_PID
- MSP frame name: `MSP_PID`
- MSP frame ID: `112 (0x70)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_pid_request_t;
```

Response payload:
```c
// Repeated PID_ITEM_COUNT times:
typedef struct __attribute__((packed)) {
    uint8_t p;
    uint8_t i;
    uint8_t d;
} msp_pid_entry_t;
```

---

## MSP_SET_PID
- MSP frame name: `MSP_SET_PID`
- MSP frame ID: `202 (0xCA)`

Request payload:
```c
// Repeated PID_ITEM_COUNT times:
typedef struct __attribute__((packed)) {
    uint8_t p;
    uint8_t i;
    uint8_t d;
} msp_set_pid_entry_t;
```

---

## MSP_PIDNAMES
- MSP frame name: `MSP_PIDNAMES`
- MSP frame ID: `117 (0x75)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_pidnames_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    char pid_names[]; // semicolon-separated PID axis names, variable length
} msp_pidnames_response_t;
```

---

## MSP_BOXNAMES
- MSP frame name: `MSP_BOXNAMES`
- MSP frame ID: `116 (0x74)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t page; // optional, defaults to 0
} msp_boxnames_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    char box_names[]; // semicolon-separated box names for the requested page
} msp_boxnames_response_t;
```

---

## MSP_BOXIDS
- MSP frame name: `MSP_BOXIDS`
- MSP frame ID: `119 (0x77)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t page; // optional, defaults to 0
} msp_boxids_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t permanent_id[]; // one byte per active box
} msp_boxids_response_t;
```

---

## MSP_MODE_RANGES_EXTRA
- MSP frame name: `MSP_MODE_RANGES_EXTRA`
- MSP frame ID: `238 (0xEE)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_mode_ranges_extra_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mode_count;
    // Repeated mode_count times:
    // uint8_t box_permanent_id;
    // uint8_t mode_logic;
    // uint8_t linked_box_permanent_id;
} msp_mode_ranges_extra_response_t;
```

---

## MSP_MOTOR_CONFIG
- MSP frame name: `MSP_MOTOR_CONFIG`
- MSP frame ID: `131 (0x83)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_motor_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t deprecated_minthrottle;
    uint16_t maxthrottle;
    uint16_t mincommand;
    // API 1.42+:
    uint8_t  motor_count;
    uint8_t  motor_pole_count;
    // API 1.42+, if USE_DSHOT_TELEMETRY:
    uint8_t  use_dshot_telemetry;
    // API 1.42+, if USE_ESC_SENSOR:
    uint8_t  esc_sensor_available;
} msp_motor_config_response_t;
```

---

## MSP_SET_MOTOR_CONFIG
- MSP frame name: `MSP_SET_MOTOR_CONFIG`
- MSP frame ID: `222 (0xDE)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t deprecated_minthrottle;
    uint16_t maxthrottle;
    uint16_t mincommand;
    // optional:
    uint8_t  motor_pole_count;
    uint8_t  use_dshot_telemetry; // if USE_DSHOT_TELEMETRY
} msp_set_motor_config_request_t;
```

---

## MSP_MOTOR_3D_CONFIG
- MSP frame name: `MSP_MOTOR_3D_CONFIG`
- MSP frame ID: `124 (0x7C)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_motor_3d_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t deadband3d_low;
    uint16_t deadband3d_high;
    uint16_t neutral3d;
} msp_motor_3d_config_response_t;
```

---

## MSP_SET_MOTOR_3D_CONFIG
- MSP frame name: `MSP_SET_MOTOR_3D_CONFIG`
- MSP frame ID: `217 (0xD9)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t deadband3d_low;
    uint16_t deadband3d_high;
    uint16_t neutral3d;
} msp_set_motor_3d_config_request_t;
```

---

## MSP_RC_DEADBAND
- MSP frame name: `MSP_RC_DEADBAND`
- MSP frame ID: `125 (0x7D)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rc_deadband_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  deadband;
    uint8_t  yaw_deadband;
    uint8_t  pos_hold_deadband;     // if USE_POSITION_HOLD
    uint16_t deadband3d_throttle;
} msp_rc_deadband_response_t;
```

---

## MSP_SET_RC_DEADBAND
- MSP frame name: `MSP_SET_RC_DEADBAND`
- MSP frame ID: `218 (0xDA)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  deadband;
    uint8_t  yaw_deadband;
    uint8_t  pos_hold_deadband;     // if USE_POSITION_HOLD
    uint16_t deadband3d_throttle;
} msp_set_rc_deadband_request_t;
```

---

## MSP_SENSOR_ALIGNMENT
- MSP frame name: `MSP_SENSOR_ALIGNMENT`
- MSP frame ID: `126 (0x7E)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_sensor_alignment_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  gyro_alignment;
    uint8_t  acc_alignment;
    uint8_t  mag_alignment;             // if USE_MAG
    // API 1.41+:
    uint8_t  gyro_detection_flags;
    uint8_t  gyro_enabled_bitmask;
    // API 1.41+, if USE_MAG:
    uint16_t mag_custom_align_roll;
    uint16_t mag_custom_align_pitch;
    uint16_t mag_custom_align_yaw;
} msp_sensor_alignment_response_t;
```

---

## MSP_SET_SENSOR_ALIGNMENT
- MSP frame name: `MSP_SET_SENSOR_ALIGNMENT`
- MSP frame ID: `220 (0xDC)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  deprecated_gyro_alignment;
    uint8_t  deprecated_acc_alignment;
    uint8_t  mag_alignment;             // if USE_MAG
    uint8_t  gyro_enabled_bitmask;
    // optional, if USE_MAG and remaining >= 6:
    uint16_t mag_custom_align_roll;
    uint16_t mag_custom_align_pitch;
    uint16_t mag_custom_align_yaw;
} msp_set_sensor_alignment_request_t;
```

---

## MSP_LED_STRIP_MODECOLOR
- MSP frame name: `MSP_LED_STRIP_MODECOLOR`
- MSP frame ID: `127 (0x7F)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_led_strip_modecolor_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    // LED_MODE_COUNT × LED_DIRECTION_COUNT entries:
    // uint8_t mode_index;
    // uint8_t direction_index;
    // uint8_t color_index;
    // LED_SPECIAL_COLOR_COUNT entries:
    // uint8_t special_mode;
    // uint8_t direction_index;
    // uint8_t color_index;
    uint8_t aux_channel;
    uint8_t reserved;
    uint8_t aux_channel_value;
} msp_led_strip_modecolor_response_t;
```

---

## MSP_SET_LED_STRIP_MODECOLOR
- MSP frame name: `MSP_SET_LED_STRIP_MODECOLOR`
- MSP frame ID: `221 (0xDD)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mode_index;
    uint8_t direction_index;
    uint8_t color_index;
} msp_set_led_strip_modecolor_request_t;
```

---

## MSP_GPS_CONFIG
- MSP frame name: `MSP_GPS_CONFIG`
- MSP frame ID: `132 (0x84)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_gps_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t provider;
    uint8_t sbas_mode;
    uint8_t auto_config;
    uint8_t auto_baud;
    // API 1.43+:
    uint8_t gps_set_home_once;
    uint8_t gps_ublox_use_galileo;
} msp_gps_config_response_t;
```

---

## MSP_SET_GPS_CONFIG
- MSP frame name: `MSP_SET_GPS_CONFIG`
- MSP frame ID: `223 (0xDF)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t provider;
    uint8_t sbas_mode;
    uint8_t auto_config;
    uint8_t auto_baud;
    // optional:
    uint8_t gps_set_home_once;
    uint8_t gps_ublox_use_galileo;
} msp_set_gps_config_request_t;
```

---

## MSP_COMPASS_CONFIG
- MSP frame name: `MSP_COMPASS_CONFIG`
- MSP frame ID: `133 (0x85)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_compass_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int16_t mag_declination_decidegrees;
} msp_compass_config_response_t;
```

---

## MSP_SET_COMPASS_CONFIG
- MSP frame name: `MSP_SET_COMPASS_CONFIG`
- MSP frame ID: `224 (0xE0)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    int16_t mag_declination_decidegrees;
} msp_set_compass_config_request_t;
```

---

## MSP_ESC_SENSOR_DATA
- MSP frame name: `MSP_ESC_SENSOR_DATA`
- MSP frame ID: `134 (0x86)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_esc_sensor_data_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t motor_count; // if USE_ESC_SENSOR or USE_DSHOT_TELEMETRY
    // Repeated motor_count times:
    // uint8_t  esc_temperature_c;
    // uint16_t esc_rpm;
} msp_esc_sensor_data_response_t;
```

---

## MSP_GPS_RESCUE
- MSP frame name: `MSP_GPS_RESCUE`
- MSP frame ID: `135 (0x87)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_gps_rescue_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t max_rescue_angle_degrees;
    uint16_t return_altitude_m;
    uint16_t descent_distance_m;
    uint16_t ground_speed_cms;
    uint16_t throttle_min;
    uint16_t throttle_max;
    uint16_t hover_throttle;
    uint8_t  sanity_checks_enabled;
    uint8_t  min_satellites;
    // API 1.43+:
    uint16_t ascend_rate_cms;
    uint16_t descend_rate_cms;
    uint8_t  allow_arming_without_fix;
    uint8_t  altitude_mode;
    // API 1.44+:
    uint16_t min_start_dist_m;
    // API 1.46+:
    uint16_t initial_climb_m;
} msp_gps_rescue_response_t;
```

---

## MSP_SET_GPS_RESCUE
- MSP frame name: `MSP_SET_GPS_RESCUE`
- MSP frame ID: `225 (0xE1)`

Request payload: mirrors `MSP_GPS_RESCUE` response with optional tail fields.

---

## MSP_GPS_RESCUE_PIDS
- MSP frame name: `MSP_GPS_RESCUE_PIDS`
- MSP frame ID: `136 (0x88)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_gps_rescue_pids_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t altitude_p;
    uint16_t altitude_i;
    uint16_t altitude_d;
    uint16_t velocity_p;
    uint16_t velocity_i;
    uint16_t velocity_d;
    uint16_t yaw_p;
} msp_gps_rescue_pids_response_t;
```

---

## MSP_SET_GPS_RESCUE_PIDS
- MSP frame name: `MSP_SET_GPS_RESCUE_PIDS`
- MSP frame ID: `226 (0xE2)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t altitude_p;
    uint16_t altitude_i;
    uint16_t altitude_d;
    uint16_t velocity_p;
    uint16_t velocity_i;
    uint16_t velocity_d;
    uint16_t yaw_p;
} msp_set_gps_rescue_pids_request_t;
```

---

## MSP_VTXTABLE_BAND
- MSP frame name: `MSP_VTXTABLE_BAND`
- MSP frame ID: `137 (0x89)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t band_index; // optional, defaults to 0
} msp_vtxtable_band_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  band_index;
    uint8_t  band_name_length;
    char     band_name[];
    char     band_letter;
    uint8_t  is_factory_band;
    uint8_t  channel_count;
    uint16_t channel_freq_mhz[]; // channel_count entries
} msp_vtxtable_band_response_t;
```

---

## MSP_SET_VTXTABLE_BAND
- MSP frame name: `MSP_SET_VTXTABLE_BAND`
- MSP frame ID: `227 (0xE3)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  band_index;
    uint8_t  band_name_length;
    char     band_name[];
    char     band_letter;
    uint8_t  is_factory_band;
    uint8_t  channel_count;
    uint16_t channel_freq_mhz[]; // channel_count entries
} msp_set_vtxtable_band_request_t;
```

---

## MSP_VTXTABLE_POWERLEVEL
- MSP frame name: `MSP_VTXTABLE_POWERLEVEL`
- MSP frame ID: `138 (0x8A)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t power_level_index; // optional, defaults to 0
} msp_vtxtable_powerlevel_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  power_level_index;
    uint16_t power_value_mw;
    uint8_t  label_length;
    char     label[];
} msp_vtxtable_powerlevel_response_t;
```

---

## MSP_SET_VTXTABLE_POWERLEVEL
- MSP frame name: `MSP_SET_VTXTABLE_POWERLEVEL`
- MSP frame ID: `228 (0xE4)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  power_level_index;
    uint16_t power_value_mw;
    uint8_t  label_length;
    char     label[];
} msp_set_vtxtable_powerlevel_request_t;
```

---

## MSP_SIMPLIFIED_TUNING
- MSP frame name: `MSP_SIMPLIFIED_TUNING`
- MSP frame ID: `140 (0x8C)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_simplified_tuning_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  simplified_pids_enabled;
    uint8_t  simplified_master_multiplier;
    uint8_t  simplified_i_gain;
    uint8_t  simplified_d_gain;
    uint8_t  simplified_pi_gain;
    uint8_t  simplified_dmax_gain;
    uint8_t  simplified_feedforward_gain;
    uint8_t  simplified_pitch_pi_gain;
    uint8_t  simplified_gyro_filter_enabled;
    uint8_t  simplified_gyro_filter_multiplier;
    uint8_t  simplified_dterm_filter_enabled;
    uint8_t  simplified_dterm_filter_multiplier;
} msp_simplified_tuning_response_t;
```

---

## MSP_SET_SIMPLIFIED_TUNING
- MSP frame name: `MSP_SET_SIMPLIFIED_TUNING`
- MSP frame ID: `141 (0x8D)`

Request payload: mirrors `MSP_SIMPLIFIED_TUNING` response.

---

## MSP_CALCULATE_SIMPLIFIED_PID
- MSP frame name: `MSP_CALCULATE_SIMPLIFIED_PID`
- MSP frame ID: `142 (0x8E)`

Request payload: simplified PID tuning input values (mirrors `MSP_SIMPLIFIED_TUNING` response subset).

Response payload:
```c
// Repeated per PID axis (roll, pitch, yaw):
typedef struct __attribute__((packed)) {
    uint8_t  p;
    uint8_t  i;
    uint8_t  d;
    uint8_t  d_max;
    uint16_t f;
} msp_calculate_simplified_pid_axis_t;
```

---

## MSP_CALCULATE_SIMPLIFIED_GYRO
- MSP frame name: `MSP_CALCULATE_SIMPLIFIED_GYRO`
- MSP frame ID: `143 (0x8F)`

Request payload: simplified gyro filter input values.

Response payload: calculated gyro filter values.

---

## MSP_CALCULATE_SIMPLIFIED_DTERM
- MSP frame name: `MSP_CALCULATE_SIMPLIFIED_DTERM`
- MSP frame ID: `144 (0x90)`

Request payload: simplified D-term filter input values.

Response payload: calculated D-term filter values.

---

## MSP_VALIDATE_SIMPLIFIED_TUNING
- MSP frame name: `MSP_VALIDATE_SIMPLIFIED_TUNING`
- MSP frame ID: `145 (0x91)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_validate_simplified_tuning_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t pid_profile_valid;
    uint8_t gyro_filters_valid;
    uint8_t dterm_filters_valid;
} msp_validate_simplified_tuning_response_t;
```

---

## MSP_UID
- MSP frame name: `MSP_UID`
- MSP frame ID: `160 (0xA0)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_uid_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t uid_0;
    uint32_t uid_1;
    uint32_t uid_2;
} msp_uid_response_t;
```

---

## MSP_GPSSVINFO
- MSP frame name: `MSP_GPSSVINFO`
- MSP frame ID: `164 (0xA4)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_gpssvinfo_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t channel_count;
    // Repeated channel_count times:
    // uint8_t channel;
    // uint8_t svid;
    // uint8_t quality_indicator;
    // uint8_t cno_dbhz;
} msp_gpssvinfo_response_t;
```

---

## MSP_GPSSTATISTICS
- MSP frame name: `MSP_GPSSTATISTICS`
- MSP frame ID: `166 (0xA6)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_gpsstatistics_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t last_message_dt_ms;
    uint32_t errors;
    uint32_t timeouts;
    uint32_t packet_count;
    uint16_t hdop;
    uint16_t eph_cm;
    uint16_t epv_cm;
} msp_gpsstatistics_response_t;
```

---

## MSP_OSD_VIDEO_CONFIG
- MSP frame name: `MSP_OSD_VIDEO_CONFIG`
- MSP frame ID: `180 (0xB4)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_osd_video_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t video_system;
} msp_osd_video_config_response_t;
```

---

## MSP_SET_OSD_VIDEO_CONFIG
- MSP frame name: `MSP_SET_OSD_VIDEO_CONFIG`
- MSP frame ID: `181 (0xB5)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t video_system;
} msp_set_osd_video_config_request_t;
```

---

## MSP_DISPLAYPORT
- MSP frame name: `MSP_DISPLAYPORT`
- MSP frame ID: `182 (0xB6)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sub_command; // 0=heartbeat, 1=release, 2=clear screen, 3=write string, 4=draw screen, 5=set options
    // sub_command 3:
    // uint8_t row;
    // uint8_t col;
    // uint8_t attr;
    // char    string[];
    // sub_command 5:
    // uint8_t font_selection;
    // uint8_t background_type;
} msp_displayport_request_t;
```

---

## MSP_COPY_PROFILE
- MSP frame name: `MSP_COPY_PROFILE`
- MSP frame ID: `183 (0xB7)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t profile_type;       // 0=PID profile, 1=control rate profile
    uint8_t dst_profile_index;
    uint8_t src_profile_index;
} msp_copy_profile_request_t;
```

---

## MSP_BEEPER_CONFIG
- MSP frame name: `MSP_BEEPER_CONFIG`
- MSP frame ID: `184 (0xB8)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_beeper_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t beeper_off_flags;
    uint8_t  dshot_beacon_tone;
    uint32_t dshot_beacon_off_flags;
} msp_beeper_config_response_t;
```

---

## MSP_SET_BEEPER_CONFIG
- MSP frame name: `MSP_SET_BEEPER_CONFIG`
- MSP frame ID: `185 (0xB9)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t beeper_off_flags;
    uint8_t  dshot_beacon_tone;         // optional
    uint32_t dshot_beacon_off_flags;    // optional
} msp_set_beeper_config_request_t;
```

---

## MSP_SET_TX_INFO
- MSP frame name: `MSP_SET_TX_INFO`
- MSP frame ID: `186 (0xBA)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rssi_source;
} msp_set_tx_info_request_t;
```

---

## MSP_TX_INFO
- MSP frame name: `MSP_TX_INFO`
- MSP frame ID: `187 (0xBB)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_tx_info_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rssi_source;
    uint8_t rtc_date_time_is_set;
} msp_tx_info_response_t;
```

---

## MSP_SET_OSD_CANVAS
- MSP frame name: `MSP_SET_OSD_CANVAS`
- MSP frame ID: `188 (0xBC)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t canvas_cols;
    uint8_t canvas_rows;
} msp_set_osd_canvas_request_t;
```

---

## MSP_OSD_CANVAS
- MSP frame name: `MSP_OSD_CANVAS`
- MSP frame ID: `189 (0xBD)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_osd_canvas_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t canvas_cols; // if USE_OSD
    uint8_t canvas_rows;
} msp_osd_canvas_response_t;
```

---

## MSP_SET_RAW_GPS (alias: MSP_SET_RAW_GPS)
See [MSP_SET_RAW_GPS](#msp_set_raw_gps) above (ID 201).

---

## MSP_ACC_CALIBRATION
- MSP frame name: `MSP_ACC_CALIBRATION`
- MSP frame ID: `205 (0xCD)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields — triggers accelerometer calibration */
} msp_acc_calibration_request_t;
```

---

## MSP_MAG_CALIBRATION
- MSP frame name: `MSP_MAG_CALIBRATION`
- MSP frame ID: `206 (0xCE)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields — triggers magnetometer calibration */
} msp_mag_calibration_request_t;
```

---

## MSP_RESET_CONF
- MSP frame name: `MSP_RESET_CONF`
- MSP frame ID: `208 (0xD0)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t reset_type; // optional, API 1.42+
} msp_reset_conf_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t success; // API 1.42+
} msp_reset_conf_response_t;
```

---

## MSP_SELECT_SETTING
- MSP frame name: `MSP_SELECT_SETTING`
- MSP frame ID: `210 (0xD2)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t profile_index; // 0-based PID profile index
} msp_select_setting_request_t;
```

---

## MSP_SET_HEADING
- MSP frame name: `MSP_SET_HEADING`
- MSP frame ID: `211 (0xD3)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    int16_t heading_degrees;
} msp_set_heading_request_t;
```

---

## MSP_SET_RESET_CURR_PID
- MSP frame name: `MSP_SET_RESET_CURR_PID`
- MSP frame ID: `219 (0xDB)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields — resets current PID profile to defaults */
} msp_set_reset_curr_pid_request_t;
```

---

## MSP_ACC_TRIM
- MSP frame name: `MSP_ACC_TRIM`
- MSP frame ID: `240 (0xF0)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_acc_trim_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int16_t pitch_trim;
    int16_t roll_trim;
} msp_acc_trim_response_t;
```

---

## MSP_SET_ACC_TRIM
- MSP frame name: `MSP_SET_ACC_TRIM`
- MSP frame ID: `239 (0xEF)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    int16_t pitch_trim;
    int16_t roll_trim;
} msp_set_acc_trim_request_t;
```

---

## MSP_SET_PASSTHROUGH
- MSP frame name: `MSP_SET_PASSTHROUGH`
- MSP frame ID: `245 (0xF5)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t passthrough_mode;     // optional: 0=ESC 4-way, 1=serial, 2=VTX
    uint8_t passthrough_argument; // optional: port/device index
} msp_set_passthrough_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t result; // 0=failed, 1=success
} msp_set_passthrough_response_t;
```

---

## MSP_SET_RTC
- MSP frame name: `MSP_SET_RTC`
- MSP frame ID: `246 (0xF6)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t seconds;
    uint16_t millis;
} msp_set_rtc_request_t;
```

---

## MSP_RTC
- MSP frame name: `MSP_RTC`
- MSP frame ID: `247 (0xF7)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_rtc_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t year;
    uint8_t  month;
    uint8_t  day;
    uint8_t  hours;
    uint8_t  minutes;
    uint8_t  seconds;
    uint16_t millis;
} msp_rtc_response_t;
```

---

## MSP_SET_BOARD_INFO
- MSP frame name: `MSP_SET_BOARD_INFO`
- MSP frame ID: `248 (0xF8)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t board_name_length;
    char    board_name[];
    uint8_t manufacturer_id_length;
    char    manufacturer_id[];
} msp_set_board_info_request_t;
```

---

## MSP_SET_SIGNATURE
- MSP frame name: `MSP_SET_SIGNATURE`
- MSP frame ID: `249 (0xF9)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t signature[SIGNATURE_LENGTH]; // 32 bytes
} msp_set_signature_request_t;
```

---

## MSP_EEPROM_WRITE
- MSP frame name: `MSP_EEPROM_WRITE`
- MSP frame ID: `250 (0xFA)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields — triggers EEPROM save */
} msp_eeprom_write_request_t;
```

---

## MSP_MULTIPLE_MSP
- MSP frame name: `MSP_MULTIPLE_MSP`
- MSP frame ID: `230 (0xE6)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t msp_command_ids[]; // list of MSP command IDs to batch
} msp_multiple_msp_request_t;
```

Response payload:
```c
// Concatenated responses for each requested command:
// uint8_t  reply_size;
// uint8_t  reply_data[reply_size];
```

---

## MSP_DEBUG
- MSP frame name: `MSP_DEBUG`
- MSP frame ID: `254 (0xFE)`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp_debug_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    int16_t debug_value[DEBUG16_VALUE_COUNT];
} msp_debug_response_t;
```

---

# MSPv2 Betaflight Frames

## MSP2_BETAFLIGHT_BIND
- MSP frame name: `MSP2_BETAFLIGHT_BIND`
- MSP frame ID: `0x3000`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields — triggers RX bind if supported */
} msp2_betaflight_bind_request_t;
```

---

## MSP2_MOTOR_OUTPUT_REORDERING
- MSP frame name: `MSP2_MOTOR_OUTPUT_REORDERING`
- MSP frame ID: `0x3001`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_motor_output_reordering_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t max_supported_motors;
    uint8_t reordering_index[MAX_SUPPORTED_MOTORS];
} msp2_motor_output_reordering_response_t;
```

---

## MSP2_SET_MOTOR_OUTPUT_REORDERING
- MSP frame name: `MSP2_SET_MOTOR_OUTPUT_REORDERING`
- MSP frame ID: `0x3002`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t array_size;
    uint8_t reordering_index[]; // array_size entries (up to MAX_SUPPORTED_MOTORS)
} msp2_set_motor_output_reordering_request_t;
```

---

## MSP2_SEND_DSHOT_COMMAND
- MSP frame name: `MSP2_SEND_DSHOT_COMMAND`
- MSP frame ID: `0x3003`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t command_type;    // 0=instant, 1=wait for motor stop
    uint8_t motor_index;     // 0xFF = all motors
    uint8_t command_count;
    uint8_t command[];       // command_count command IDs
} msp2_send_dshot_command_request_t;
```

---

## MSP2_GET_VTX_DEVICE_STATUS
- MSP frame name: `MSP2_GET_VTX_DEVICE_STATUS`
- MSP frame ID: `0x3004`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_get_vtx_device_status_request_t;
```

Response payload: VTX device status serialized by `vtxCommonSerializeDeviceStatus()` (device-type dependent).

---

## MSP2_GET_OSD_WARNINGS
- MSP frame name: `MSP2_GET_OSD_WARNINGS`
- MSP frame ID: `0x3005`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_get_osd_warnings_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t display_attr;       // text display attribute flags
    uint8_t warning_length;
    char    warning_text[];     // active OSD warning string
} msp2_get_osd_warnings_response_t;
```

---

## MSP2_GET_TEXT
- MSP frame name: `MSP2_GET_TEXT`
- MSP frame ID: `0x3006`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t text_type; // 1=pilot name, 2=craft name, 3=PID profile name, 4=rate profile name,
                       // 5=build key, 6=release name, 7-10=custom messages, 11=battery profile name
} msp2_get_text_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t text_type;
    uint8_t text_length;
    char    text[];
} msp2_get_text_response_t;
```

---

## MSP2_SET_TEXT
- MSP frame name: `MSP2_SET_TEXT`
- MSP frame ID: `0x3007`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t text_type;
    uint8_t text_length;
    char    text[];
} msp2_set_text_request_t;
```

---

## MSP2_GET_LED_STRIP_CONFIG_VALUES
- MSP frame name: `MSP2_GET_LED_STRIP_CONFIG_VALUES`
- MSP frame ID: `0x3008`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_get_led_strip_config_values_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  brightness;
    uint16_t rainbow_delta;
    uint16_t rainbow_freq;
} msp2_get_led_strip_config_values_response_t;
```

---

## MSP2_SET_LED_STRIP_CONFIG_VALUES
- MSP frame name: `MSP2_SET_LED_STRIP_CONFIG_VALUES`
- MSP frame ID: `0x3009`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  brightness;
    uint16_t rainbow_delta;
    uint16_t rainbow_freq;
} msp2_set_led_strip_config_values_request_t;
```

---

## MSP2_SENSOR_CONFIG_ACTIVE
- MSP frame name: `MSP2_SENSOR_CONFIG_ACTIVE`
- MSP frame ID: `0x300A`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_sensor_config_active_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t detected_gyro;          // if USE_GYRO
    uint8_t detected_acc;           // if USE_ACC
    uint8_t detected_baro;          // if USE_BARO
    uint8_t detected_mag;           // if USE_MAG
    uint8_t detected_rangefinder;   // if USE_RANGEFINDER
    uint8_t detected_opticalflow;   // if USE_OPTICALFLOW
} msp2_sensor_config_active_response_t;
```

---

## MSP2_SENSOR_OPTICALFLOW
- MSP frame name: `MSP2_SENSOR_OPTICALFLOW`
- MSP frame ID: `0x300B`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* optical flow sensor data (MSP sensor input) */
} msp2_sensor_opticalflow_request_t;
```

---

## MSP2_MCU_INFO
- MSP frame name: `MSP2_MCU_INFO`
- MSP frame ID: `0x300C`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_mcu_info_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mcu_type_id;
    uint8_t mcu_type_name_length;
    char    mcu_type_name[];
} msp2_mcu_info_response_t;
```

---

## MSP2_GYRO_SENSOR_ACTIVE
- MSP frame name: `MSP2_GYRO_SENSOR_ACTIVE`
- MSP frame ID: `0x300D`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_gyro_sensor_active_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t gyro_count; // if USE_GYRO
    uint8_t detected_gyro[GYRO_COUNT];
} msp2_gyro_sensor_active_response_t;
```

---

## MSP2_BATTERY_PROFILE
- MSP frame name: `MSP2_BATTERY_PROFILE`
- MSP frame ID: `0x300E`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t profile_index; // optional
} msp2_battery_profile_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t  profile_index;
    uint16_t vbat_min_cell_voltage;         // in 0.01V
    uint16_t vbat_max_cell_voltage;
    uint16_t vbat_warn_cell_voltage;
    uint16_t vbat_full_cell_voltage;
    uint16_t battery_capacity_mah;
    uint8_t  force_battery_cell_count;
    uint8_t  consumption_warning_percentage;
} msp2_battery_profile_response_t;
```

---

## MSP2_SET_BATTERY_PROFILE
- MSP frame name: `MSP2_SET_BATTERY_PROFILE`
- MSP frame ID: `0x300F`

Request payload: mirrors `MSP2_BATTERY_PROFILE` response.

---

## MSP2_CLI_SETTING
- MSP frame name: `MSP2_CLI_SETTING`
- MSP frame ID: `0x3010`

Request payload:
```c
typedef struct __attribute__((packed)) {
    char setting_command[]; // CLI set command string, e.g. "pid_roll_p=45"
} msp2_cli_setting_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    char response[]; // CLI response string
} msp2_cli_setting_response_t;
```

---

## MSP2_CLI_SETTING_INFO
- MSP frame name: `MSP2_CLI_SETTING_INFO`
- MSP frame ID: `0x3011`

Request payload:
```c
typedef struct __attribute__((packed)) {
    char     setting_name[];
    uint16_t offset;  // optional chunk offset
} msp2_cli_setting_info_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t total_length;
    uint8_t  setting_info[]; // JSON or structured setting descriptor
} msp2_cli_setting_info_response_t;
```

---

# MSPv2 Common Frames

## MSP2_COMMON_SERIAL_CONFIG
- MSP frame name: `MSP2_COMMON_SERIAL_CONFIG`
- MSP frame ID: `0x1009`

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no fields */
} msp2_common_serial_config_request_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t port_count;
    // Repeated port_count times:
    // uint8_t  identifier;
    // uint32_t function_mask;
    // uint8_t  msp_baudrate_index;
    // uint8_t  gps_baudrate_index;
    // uint8_t  telemetry_baudrate_index;
    // uint8_t  blackbox_baudrate_index;
} msp2_common_serial_config_response_t;
```

---

## MSP2_COMMON_SET_SERIAL_CONFIG
- MSP frame name: `MSP2_COMMON_SET_SERIAL_CONFIG`
- MSP frame ID: `0x100A`

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t port_count;
    // Repeated port_count times:
    // uint8_t  identifier;
    // uint32_t function_mask;
    // uint8_t  msp_baudrate_index;
    // uint8_t  gps_baudrate_index;
    // uint8_t  telemetry_baudrate_index;
    // uint8_t  blackbox_baudrate_index;
} msp2_common_set_serial_config_request_t;
```

---

## MSP2_SENSOR_GPS
- MSP frame name: `MSP2_SENSOR_GPS`
- MSP frame ID: `0x1F03`

Request payload (sensor push from external GPS module):
```c
typedef struct __attribute__((packed)) {
    uint8_t  instance;
    uint16_t gps_week;
    uint32_t ms_tow;
    uint8_t  fix_type;
    uint8_t  satellites_in_view;
    uint16_t horizontal_pos_accuracy_cm;
    uint16_t vertical_pos_accuracy_cm;
    uint16_t horizontal_vel_accuracy_cm;
    uint16_t hdop;
    int32_t  longitude;         // degrees * 1e7
    int32_t  latitude;          // degrees * 1e7
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
} msp2_sensor_gps_request_t;
```

---

## MSP2_SENSOR_RANGEFINDER_LIDARMT
- MSP frame name: `MSP2_SENSOR_RANGEFINDER_LIDARMT`
- MSP frame ID: `0x1F01`

Request payload: rangefinder sensor data (push from external sensor).

---

## MSP2_SENSOR_OPTICALFLOW_MT
- MSP frame name: `MSP2_SENSOR_OPTICALFLOW_MT`
- MSP frame ID: `0x1F02`

Request payload: optical flow sensor data (push from external sensor).
