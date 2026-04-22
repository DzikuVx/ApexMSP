# MSP Frames From src/main/fc/fc_msp.c

Generated from handlers in `src/main/fc/fc_msp.c`.

For each MSP frame:
1. MSP frame name
2. MSP frame ID
3. C payload structure with semantically inferred field names

> Notes:
> - Field names are inferred from variable names, expressions, and inline comments in `fc_msp.c`.
> - Some payloads are variable-length/conditional or delegated to helpers and therefore stay partially generic.

## MSP_API_VERSION
- MSP frame name: `MSP_API_VERSION`
- MSP frame ID: `1 (0x1)`
- Occurrences in file: line(s) 392

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_api_version_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t msp_protocol_version;
    uint8_t api_version_major;
    uint8_t api_version_minor;
} msp_api_version_response_payload_t;
```

## MSP_FC_VARIANT
- MSP frame name: `MSP_FC_VARIANT`
- MSP frame ID: `2 (0x2)`
- Occurrences in file: line(s) 398

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_fc_variant_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t flight_controller_identifier_bytes[];
} msp_fc_variant_response_payload_t;
```

## MSP_FC_VERSION
- MSP frame name: `MSP_FC_VERSION`
- MSP frame ID: `3 (0x3)`
- Occurrences in file: line(s) 402

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_fc_version_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t fc_version_major;
    uint8_t fc_version_minor;
    uint8_t fc_version_patch_level;
} msp_fc_version_response_payload_t;
```

## MSP_BOARD_INFO
- MSP frame name: `MSP_BOARD_INFO`
- MSP frame ID: `4 (0x4)`
- Occurrences in file: line(s) 408

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_board_info_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t board_identifier_bytes[];
    uint16_t hardware_revision;
    uint16_t field;
    uint8_t field_2;
    uint8_t field_3;
    uint8_t comm_capabilities;
    uint8_t target_name;
    uint8_t target_name_bytes[];
} msp_board_info_response_payload_t;
```

## MSP_BUILD_INFO
- MSP frame name: `MSP_BUILD_INFO`
- MSP frame ID: `5 (0x5)`
- Occurrences in file: line(s) 442

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_build_info_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t build_date_bytes[];
    uint8_t build_time_bytes[];
    uint8_t short_git_revision_bytes[];
} msp_build_info_response_payload_t;
```

## MSP_INAV_PID
- MSP frame name: `MSP_INAV_PID`
- MSP frame ID: `6 (0x6)`
- Occurrences in file: line(s) 1363

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_inav_pid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint16_t field_2;
    uint16_t field_3;
    uint8_t pid_profile_heading_hold_rate_limit;
    uint8_t heading_hold_error_lpf_freq;
    uint16_t field_4;
    uint8_t gyro_lpf_256_hz;
    uint8_t accelerometer_config_acc_lpf_hz;
    uint8_t field_5;
    uint8_t field_6;
    uint8_t field_7;
    uint8_t field_8;
} msp_inav_pid_response_payload_t;
```

## MSP_SET_INAV_PID
- MSP frame name: `MSP_SET_INAV_PID`
- MSP frame ID: `7 (0x7)`
- Occurrences in file: line(s) 2579

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8;
    uint16_t sbuf_read_u16;
    uint16_t sbuf_read_u16_2;
    uint8_t heading_hold_rate_limit;
    uint8_t heading_hold_error_lpf_freq;
    uint16_t legacy_yaw_jump_prevention_limit;
    uint8_t was_gyro_lpf;
    uint8_t acc_lpf_hz;
    uint8_t reserved;
    uint8_t reserved_2;
    uint8_t reserved_3;
    uint8_t reserved_4;
} msp_set_inav_pid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_inav_pid_response_payload_t;
```

## MSP_NAME
- MSP frame name: `MSP_NAME`
- MSP frame ID: `10 (0xA)`
- Occurrences in file: line(s) 1571

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_name_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t name;
} msp_name_response_payload_t;
```

## MSP_SET_NAME
- MSP frame name: `MSP_SET_NAME`
- MSP frame ID: `11 (0xB)`
- Occurrences in file: line(s) 3338

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t payload_bytes[];
} msp_set_name_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_name_response_payload_t;
```

## MSP_NAV_POSHOLD
- MSP frame name: `MSP_NAV_POSHOLD`
- MSP frame ID: `12 (0xC)`
- Occurrences in file: line(s) 1407

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_nav_poshold_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t flags_user_control_mode;
    uint16_t general_max_auto_speed;
    uint16_t mc_max_auto_climb_rate;
    uint16_t general_max_manual_speed;
    uint16_t mc_max_manual_climb_rate;
    uint8_t mc_max_bank_angle;
    uint8_t mc_althold_throttle_type;
    uint16_t mc_hover_throttle;
} msp_nav_poshold_response_payload_t;
```

## MSP_SET_NAV_POSHOLD
- MSP frame name: `MSP_SET_NAV_POSHOLD`
- MSP frame ID: `13 (0xD)`
- Occurrences in file: line(s) 2629

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t user_control_mode;
    uint16_t max_auto_speed;
    uint16_t max_auto_climb_rate;
    uint16_t max_auto_climb_rate_2;
    uint16_t max_manual_speed;
    uint16_t max_manual_climb_rate;
    uint16_t max_manual_climb_rate_2;
    uint8_t max_bank_angle;
    uint8_t althold_throttle_type;
    uint16_t hover_throttle;
} msp_set_nav_poshold_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_nav_poshold_response_payload_t;
```

## MSP_CALIBRATION_DATA
- MSP frame name: `MSP_CALIBRATION_DATA`
- MSP frame ID: `14 (0xE)`
- Occurrences in file: line(s) 1445

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_calibration_data_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t acc_get_calibration_axis_flags;
    uint16_t acc_zero_raw_x;
    uint16_t acc_zero_raw_y;
    uint16_t acc_zero_raw_z;
    uint16_t acc_gain_raw_x;
    uint16_t acc_gain_raw_y;
    uint16_t acc_gain_raw_z;
    uint16_t mag_zero_raw_x;
    uint16_t mag_zero_raw_y;
    uint16_t mag_zero_raw_z;
    uint16_t field;
    uint16_t field_2;
    uint16_t field_3;
    uint16_t optical_flow_config_opflow_scale_256;
    uint16_t field_4;
    uint16_t compass_config_mag_gain_x;
    uint16_t compass_config_mag_gain_y;
    uint16_t compass_config_mag_gain_z;
    uint16_t field_5;
    uint16_t field_6;
    uint16_t field_7;
} msp_calibration_data_response_payload_t;
```

## MSP_SET_CALIBRATION_DATA
- MSP frame name: `MSP_SET_CALIBRATION_DATA`
- MSP frame ID: `15 (0xF)`
- Occurrences in file: line(s) 2684

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t acc_zero_raw_x_sbuf_read_u16_src;
    uint16_t acc_zero_raw_y_sbuf_read_u16_src;
    uint16_t acc_zero_raw_z_sbuf_read_u16_src;
    uint16_t acc_gain_raw_x_sbuf_read_u16_src;
    uint16_t acc_gain_raw_y_sbuf_read_u16_src;
    uint16_t acc_gain_raw_z_sbuf_read_u16_src;
    uint16_t mag_zero_raw_x_sbuf_read_u16_src;
    uint16_t mag_zero_raw_y_sbuf_read_u16_src;
    uint16_t mag_zero_raw_z_sbuf_read_u16_src;
    uint16_t sbuf_read_u16;
    uint16_t sbuf_read_u16_2;
    uint16_t sbuf_read_u16_3;
    uint16_t opflow_scale;
    uint16_t compass_config_mutable_mag_gain_x_sbuf_read_u16_src;
    uint16_t compass_config_mutable_mag_gain_y_sbuf_read_u16_src;
    uint16_t compass_config_mutable_mag_gain_z_sbuf_read_u16_src;
    uint16_t sbuf_read_u16_4;
    uint16_t sbuf_read_u16_5;
    uint16_t sbuf_read_u16_6;
} msp_set_calibration_data_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_calibration_data_response_payload_t;
```

## MSP_POSITION_ESTIMATION_CONFIG
- MSP frame name: `MSP_POSITION_ESTIMATION_CONFIG`
- MSP frame ID: `16 (0x10)`
- Occurrences in file: line(s) 1482

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_position_estimation_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t position_estimation_config_w_z_baro_p_100;
    uint16_t position_estimation_config_w_z_gps_p_100;
    uint16_t position_estimation_config_w_z_gps_v_100;
    uint16_t position_estimation_config_w_xy_gps_p_100;
    uint16_t position_estimation_config_w_xy_gps_v_100;
    uint8_t gps_config_mutable_gps_min_sats;
    uint8_t field;
} msp_position_estimation_config_response_payload_t;
```

## MSP_SET_POSITION_ESTIMATION_CONFIG
- MSP frame name: `MSP_SET_POSITION_ESTIMATION_CONFIG`
- MSP frame ID: `17 (0x11)`
- Occurrences in file: line(s) 2724

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t w_z_baro_p;
    uint16_t w_z_gps_p;
    uint16_t w_z_gps_v;
    uint16_t w_xy_gps_p;
    uint16_t w_xy_gps_v;
    uint8_t gps_min_sats;
    uint8_t sbuf_read_u8_src_was_position_estimation_config_mutable_use_gps_velned;
} msp_set_position_estimation_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_position_estimation_config_response_payload_t;
```

## MSP_WP_MISSION_LOAD
- MSP frame name: `MSP_WP_MISSION_LOAD`
- MSP frame ID: `18 (0x12)`
- Occurrences in file: line(s) 3300

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
} msp_wp_mission_load_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_wp_mission_load_response_payload_t;
```

## MSP_WP_MISSION_SAVE
- MSP frame name: `MSP_WP_MISSION_SAVE`
- MSP frame ID: `19 (0x13)`
- Occurrences in file: line(s) 3306

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
} msp_wp_mission_save_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_wp_mission_save_response_payload_t;
```

## MSP_WP_GETINFO
- MSP frame name: `MSP_WP_GETINFO`
- MSP frame ID: `20 (0x14)`
- Occurrences in file: line(s) 1494

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_wp_getinfo_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t nav_max_waypoints;
    uint8_t waypoint_list_valid;
    uint8_t waypoint_count;
} msp_wp_getinfo_response_payload_t;
```

## MSP_RTH_AND_LAND_CONFIG
- MSP frame name: `MSP_RTH_AND_LAND_CONFIG`
- MSP frame ID: `21 (0x15)`
- Occurrences in file: line(s) 1418

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rth_and_land_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t general_min_rth_distance;
    uint8_t flags_rth_climb_first;
    uint8_t flags_rth_climb_ignore_emerg;
    uint8_t flags_rth_tail_first;
    uint8_t flags_rth_allow_landing;
    uint8_t flags_rth_alt_control_mode;
    uint16_t general_rth_abort_threshold;
    uint16_t general_rth_altitude;
    uint16_t general_land_minalt_vspd;
    uint16_t general_land_maxalt_vspd;
    uint16_t general_land_slowdown_minalt;
    uint16_t general_land_slowdown_maxalt;
    uint16_t general_emerg_descent_rate;
} msp_rth_and_land_config_response_payload_t;
```

## MSP_SET_RTH_AND_LAND_CONFIG
- MSP frame name: `MSP_SET_RTH_AND_LAND_CONFIG`
- MSP frame ID: `22 (0x16)`
- Occurrences in file: line(s) 2651

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t min_rth_distance;
    uint8_t rth_climb_first;
    uint8_t rth_climb_ignore_emerg;
    uint8_t rth_tail_first;
    uint8_t rth_allow_landing;
    uint8_t rth_alt_control_mode;
    uint16_t rth_abort_threshold;
    uint16_t rth_altitude;
    uint16_t land_minalt_vspd;
    uint16_t land_maxalt_vspd;
    uint16_t land_slowdown_minalt;
    uint16_t land_slowdown_maxalt;
    uint16_t emerg_descent_rate;
} msp_set_rth_and_land_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_rth_and_land_config_response_payload_t;
```

## MSP_FW_CONFIG
- MSP frame name: `MSP_FW_CONFIG`
- MSP frame ID: `23 (0x17)`
- Occurrences in file: line(s) 1434

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_fw_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t fw_cruise_throttle;
    uint16_t fw_min_throttle;
    uint16_t fw_max_throttle;
    uint8_t fw_max_bank_angle;
    uint8_t fw_max_climb_angle;
    uint8_t fw_max_dive_angle;
    uint8_t fw_pitch_to_throttle;
    uint16_t fw_loiter_radius;
} msp_fw_config_response_payload_t;
```

## MSP_SET_FW_CONFIG
- MSP frame name: `MSP_SET_FW_CONFIG`
- MSP frame ID: `24 (0x18)`
- Occurrences in file: line(s) 2670

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t cruise_throttle;
    uint16_t min_throttle;
    uint16_t max_throttle;
    uint8_t max_bank_angle;
    uint8_t max_climb_angle;
    uint8_t max_dive_angle;
    uint8_t pitch_to_throttle;
    uint16_t loiter_radius;
} msp_set_fw_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_fw_config_response_payload_t;
```

## MSP_MODE_RANGES
- MSP frame name: `MSP_MODE_RANGES`
- MSP frame ID: `34 (0x22)`
- Occurrences in file: line(s) 803

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_mode_ranges_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t box_box_permanent_id_0;
    uint8_t mac_aux_channel_index;
    uint8_t range_start_step;
    uint8_t range_end_step;
} msp_mode_ranges_response_payload_t;
```

## MSP_SET_MODE_RANGE
- MSP frame name: `MSP_SET_MODE_RANGE`
- MSP frame ID: `35 (0x23)`
- Occurrences in file: line(s) 2022

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t tmp_u8;
    uint8_t aux_channel_index;
    uint8_t start_step;
    uint8_t end_step;
} msp_set_mode_range_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_mode_range_response_payload_t;
```

## MSP_FEATURE
- MSP frame name: `MSP_FEATURE`
- MSP frame ID: `36 (0x24)`
- Occurrences in file: line(s) 1068

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_feature_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t feature_mask;
} msp_feature_response_payload_t;
```

## MSP_SET_FEATURE
- MSP frame name: `MSP_SET_FEATURE`
- MSP frame ID: `37 (0x25)`
- Occurrences in file: line(s) 3047

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t features_bitmap;
} msp_set_feature_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_feature_response_payload_t;
```

## MSP_BOARD_ALIGNMENT
- MSP frame name: `MSP_BOARD_ALIGNMENT`
- MSP frame ID: `38 (0x26)`
- Occurrences in file: line(s) 1072

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_board_alignment_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t board_alignment_roll_deci_degrees;
    uint16_t board_alignment_pitch_deci_degrees;
    uint16_t board_alignment_yaw_deci_degrees;
} msp_board_alignment_response_payload_t;
```

## MSP_SET_BOARD_ALIGNMENT
- MSP frame name: `MSP_SET_BOARD_ALIGNMENT`
- MSP frame ID: `39 (0x27)`
- Occurrences in file: line(s) 3056

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t roll_deci_degrees;
    uint16_t pitch_deci_degrees;
    uint16_t yaw_deci_degrees;
} msp_set_board_alignment_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_board_alignment_response_payload_t;
```

## MSP_CURRENT_METER_CONFIG
- MSP frame name: `MSP_CURRENT_METER_CONFIG`
- MSP frame ID: `40 (0x28)`
- Occurrences in file: line(s) 1092

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_current_meter_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t current_scale;
    uint16_t current_offset;
    uint8_t current_type;
    uint16_t capacity_value_0_0x_ffff;
} msp_current_meter_config_response_payload_t;
```

## MSP_SET_CURRENT_METER_CONFIG
- MSP frame name: `MSP_SET_CURRENT_METER_CONFIG`
- MSP frame ID: `41 (0x29)`
- Occurrences in file: line(s) 3082

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t scale;
    uint16_t offset;
    uint8_t type;
    uint16_t value;
} msp_set_current_meter_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_current_meter_config_response_payload_t;
```

## MSP_MIXER
- MSP frame name: `MSP_MIXER`
- MSP frame ID: `42 (0x2A)`
- Occurrences in file: line(s) 1099

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
} msp_mixer_response_payload_t;
```

## MSP_SET_MIXER
- MSP frame name: `MSP_SET_MIXER`
- MSP frame ID: `43 (0x2B)`
- Occurrences in file: line(s) 3092

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8;
} msp_set_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_mixer_response_payload_t;
```

## MSP_RX_CONFIG
- MSP frame name: `MSP_RX_CONFIG`
- MSP frame ID: `44 (0x2C)`
- Occurrences in file: line(s) 1104

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rx_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rx_config_serialrx_provider;
    uint16_t rx_config_maxcheck;
    uint16_t pwm_range_middle;
    uint16_t rx_config_mincheck;
    uint8_t rx_config_spektrum_sat_bind;
    uint8_t field;
    uint16_t rx_config_rx_min_usec;
    uint16_t rx_config_rx_max_usec;
    uint8_t field_2;
    uint8_t field_3;
    uint16_t field_4;
    uint8_t field_5;
    uint32_t field_6;
    uint8_t field_7;
    uint8_t field_8;
    uint8_t rx_config_receiver_type;
} msp_rx_config_response_payload_t;
```

## MSP_SET_RX_CONFIG
- MSP frame name: `MSP_SET_RX_CONFIG`
- MSP frame ID: `45 (0x2D)`
- Occurrences in file: line(s) 3100

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t serialrx_provider;
    uint16_t maxcheck;
    uint16_t midrc;
    uint16_t mincheck;
    uint8_t spektrum_sat_bind;
    uint8_t sbuf_read_u8;
    uint16_t rx_min_usec;
    uint16_t rx_max_usec;
    uint8_t sbuf_read_u8_2;
    uint8_t sbuf_read_u8_3;
    uint16_t sbuf_read_u16;
    uint8_t sbuf_read_u8_4;
    uint32_t sbuf_read_u32;
    uint8_t sbuf_read_u8_5;
    uint8_t sbuf_read_u8_6;
    uint8_t receiver_type;
} msp_set_rx_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_rx_config_response_payload_t;
```

## MSP_LED_COLORS
- MSP frame name: `MSP_LED_COLORS`
- MSP frame ID: `46 (0x2E)`
- Occurrences in file: line(s) 1165

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_led_colors_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t color_h;
    uint8_t color_s;
    uint8_t color_v;
} msp_led_colors_response_payload_t;
```

## MSP_SET_LED_COLORS
- MSP frame name: `MSP_SET_LED_COLORS`
- MSP frame ID: `47 (0x2F)`
- Occurrences in file: line(s) 3239

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t h;
    uint8_t s;
    uint8_t v;
} msp_set_led_colors_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_led_colors_response_payload_t;
```

## MSP_LED_STRIP_CONFIG
- MSP frame name: `MSP_LED_STRIP_CONFIG`
- MSP frame ID: `48 (0x30)`
- Occurrences in file: line(s) 1174

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_led_strip_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t legacy_led_config;
} msp_led_strip_config_response_payload_t;
```

## MSP_SET_LED_STRIP_CONFIG
- MSP frame name: `MSP_SET_LED_STRIP_CONFIG`
- MSP frame ID: `49 (0x31)`
- Occurrences in file: line(s) 3251

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t tmp_u8;
    uint32_t legacy_config;
} msp_set_led_strip_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_led_strip_config_response_payload_t;
```

## MSP_RSSI_CONFIG
- MSP frame name: `MSP_RSSI_CONFIG`
- MSP frame ID: `50 (0x32)`
- Occurrences in file: line(s) 1142

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rssi_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rx_config_rssi_channel;
} msp_rssi_config_response_payload_t;
```

## MSP_SET_RSSI_CONFIG
- MSP frame name: `MSP_SET_RSSI_CONFIG`
- MSP frame ID: `51 (0x33)`
- Occurrences in file: line(s) 3191

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
} msp_set_rssi_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_rssi_config_response_payload_t;
```

## MSP_ADJUSTMENT_RANGES
- MSP frame name: `MSP_ADJUSTMENT_RANGES`
- MSP frame ID: `52 (0x34)`
- Occurrences in file: line(s) 814

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_adjustment_ranges_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t adj_range_adjustment_index;
    uint8_t adj_range_aux_channel_index;
    uint8_t range_start_step;
    uint8_t range_end_step;
    uint8_t adj_range_adjustment_function;
    uint8_t adj_range_aux_switch_channel_index;
} msp_adjustment_ranges_response_payload_t;
```

## MSP_SET_ADJUSTMENT_RANGE
- MSP frame name: `MSP_SET_ADJUSTMENT_RANGE`
- MSP frame ID: `53 (0x35)`
- Occurrences in file: line(s) 2043

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t tmp_u8;
    uint8_t aux_channel_index;
    uint8_t start_step;
    uint8_t end_step;
    uint8_t adjustment_function;
    uint8_t aux_switch_channel_index;
} msp_set_adjustment_range_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_adjustment_range_response_payload_t;
```

## MSP_VOLTAGE_METER_CONFIG
- MSP frame name: `MSP_VOLTAGE_METER_CONFIG`
- MSP frame ID: `56 (0x38)`
- Occurrences in file: line(s) 1078

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_voltage_meter_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t voltage_scale_10;
    uint8_t voltage_cell_min_10;
    uint8_t voltage_cell_max_10;
    uint8_t voltage_cell_warning_10;
    uint8_t field;
    uint8_t field_2;
    uint8_t field_3;
    uint8_t field_4;
} msp_voltage_meter_config_response_payload_t;
```

## MSP_SET_VOLTAGE_METER_CONFIG
- MSP frame name: `MSP_SET_VOLTAGE_METER_CONFIG`
- MSP frame ID: `57 (0x39)`
- Occurrences in file: line(s) 3065

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t scale;
    uint8_t cell_min;
    uint8_t cell_max;
    uint8_t cell_warning;
    uint8_t sbuf_read_u8;
    uint8_t sbuf_read_u8_2;
    uint8_t sbuf_read_u8_3;
    uint8_t sbuf_read_u8_4;
} msp_set_voltage_meter_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_voltage_meter_config_response_payload_t;
```

## MSP_SONAR_ALTITUDE
- MSP frame name: `MSP_SONAR_ALTITUDE`
- MSP frame ID: `58 (0x3A)`
- Occurrences in file: line(s) 702

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_sonar_altitude_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t rangefinder_get_latest_altitude;
    uint32_t field;
} msp_sonar_altitude_response_payload_t;
```

## MSP_RX_MAP
- MSP frame name: `MSP_RX_MAP`
- MSP frame ID: `64 (0x40)`
- Occurrences in file: line(s) 1146

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rx_map_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rx_config_rcmap_bytes[];
} msp_rx_map_response_payload_t;
```

## MSP_SET_RX_MAP
- MSP frame name: `MSP_SET_RX_MAP`
- MSP frame ID: `65 (0x41)`
- Occurrences in file: line(s) 3201

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rx_config_mutable_rcmap_i_sbuf_read_u8_src;
} msp_set_rx_map_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_rx_map_response_payload_t;
```

## MSP_DATAFLASH_SUMMARY
- MSP frame name: `MSP_DATAFLASH_SUMMARY`
- MSP frame ID: `70 (0x46)`
- Occurrences in file: line(s) 1219

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_dataflash_summary_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_dataflash_summary_response_payload_t;
```

## MSP_DATAFLASH_READ
- MSP frame name: `MSP_DATAFLASH_READ`
- MSP frame ID: `71 (0x47)`
- Occurrences in file: line(s) 4126

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_dataflash_read_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_dataflash_read_response_payload_t;
```

## MSP_DATAFLASH_ERASE
- MSP frame name: `MSP_DATAFLASH_ERASE`
- MSP frame ID: `72 (0x48)`
- Occurrences in file: line(s) 2961

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_dataflash_erase_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_dataflash_erase_response_payload_t;
```

## MSP_LOOP_TIME
- MSP frame name: `MSP_LOOP_TIME`
- MSP frame ID: `73 (0x49)`
- Occurrences in file: line(s) 746

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_loop_time_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t gyro_config_looptime;
} msp_loop_time_response_payload_t;
```

## MSP_SET_LOOP_TIME
- MSP frame name: `MSP_SET_LOOP_TIME`
- MSP frame ID: `74 (0x4A)`
- Occurrences in file: line(s) 2001

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t if;
} msp_set_loop_time_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_loop_time_response_payload_t;
```

## MSP_FAILSAFE_CONFIG
- MSP frame name: `MSP_FAILSAFE_CONFIG`
- MSP frame ID: `75 (0x4B)`
- Occurrences in file: line(s) 1126

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_failsafe_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t failsafe_config_failsafe_delay;
    uint8_t failsafe_config_failsafe_off_delay;
    uint16_t current_battery_profile_failsafe_throttle;
    uint8_t field;
    uint16_t failsafe_config_failsafe_throttle_low_delay;
    uint8_t failsafe_config_failsafe_procedure;
    uint8_t failsafe_config_failsafe_recovery_delay;
    uint16_t failsafe_config_failsafe_fw_roll_angle;
    uint16_t failsafe_config_failsafe_fw_pitch_angle;
    uint16_t failsafe_config_failsafe_fw_yaw_rate;
    uint16_t failsafe_config_failsafe_stick_motion_threshold;
    uint16_t failsafe_config_failsafe_min_distance;
    uint8_t failsafe_config_failsafe_min_distance_procedure;
} msp_failsafe_config_response_payload_t;
```

## MSP_SET_FAILSAFE_CONFIG
- MSP frame name: `MSP_SET_FAILSAFE_CONFIG`
- MSP frame ID: `76 (0x4C)`
- Occurrences in file: line(s) 3172

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t failsafe_delay;
    uint8_t failsafe_off_delay;
    uint16_t failsafe_throttle;
    uint8_t was_failsafe_kill_switch;
    uint16_t failsafe_throttle_low_delay;
    uint8_t failsafe_procedure;
    uint8_t failsafe_recovery_delay;
    uint16_t failsafe_fw_roll_angle;
    uint16_t failsafe_fw_pitch_angle;
    uint16_t failsafe_fw_yaw_rate;
    uint16_t failsafe_stick_motion_threshold;
    uint16_t failsafe_min_distance;
    uint8_t failsafe_min_distance_procedure;
} msp_set_failsafe_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_failsafe_config_response_payload_t;
```

## MSP_SDCARD_SUMMARY
- MSP frame name: `MSP_SDCARD_SUMMARY`
- MSP frame ID: `79 (0x4F)`
- Occurrences in file: line(s) 1245

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_sdcard_summary_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_sdcard_summary_response_payload_t;
```

## MSP_BLACKBOX_CONFIG
- MSP frame name: `MSP_BLACKBOX_CONFIG`
- MSP frame ID: `80 (0x50)`
- Occurrences in file: line(s) 1223

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_blackbox_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t field_2;
    uint8_t field_3;
    uint8_t field_4;
} msp_blackbox_config_response_payload_t;
```

## MSP_OSD_CONFIG
- MSP frame name: `MSP_OSD_CONFIG`
- MSP frame ID: `84 (0x54)`
- Occurrences in file: line(s) 1268

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_osd_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t osd_driver_max7456;
    uint8_t osd_config_video_system;
    uint8_t osd_config_units;
    uint8_t osd_config_rssi_alarm;
    uint16_t capacity_warning;
    uint16_t osd_config_time_alarm;
    uint16_t osd_config_alt_alarm;
    uint16_t osd_config_dist_alarm;
    uint16_t osd_config_neg_alt_alarm;
    uint16_t osd_layouts_config_item_pos_0_i;
    uint8_t osd_driver_none;
} msp_osd_config_response_payload_t;
```

## MSP_SET_OSD_CONFIG
- MSP frame name: `MSP_SET_OSD_CONFIG`
- MSP frame ID: `85 (0x55)`
- Occurrences in file: line(s) 2795

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t video_system;
    uint8_t units;
    uint8_t rssi_alarm;
    uint16_t warning;
    uint16_t time_alarm;
    uint16_t alt_alarm;
    uint16_t sbuf_read_u16_safe_osd_config_mutable_dist_alarm_src;
    uint16_t sbuf_read_u16_safe_osd_config_mutable_neg_alt_alarm_src;
    uint16_t osd_layouts_config_mutable_item_pos_0_tmp_u8_sbuf_read_u16_src;
} msp_set_osd_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_osd_config_response_payload_t;
```

## MSP_OSD_CHAR_WRITE
- MSP frame name: `MSP_OSD_CHAR_WRITE`
- MSP frame ID: `87 (0x57)`
- Occurrences in file: line(s) 2849

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t addr;
    uint8_t addr_2;
    uint16_t addr_3;
    uint8_t addr_4;
    uint8_t chr_data_ii_sbuf_read_u8_src;
} msp_osd_char_write_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_osd_char_write_response_payload_t;
```

## MSP_VTX_CONFIG
- MSP frame name: `MSP_VTX_CONFIG`
- MSP frame ID: `88 (0x58)`
- Occurrences in file: line(s) 1525

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_vtx_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t device_type;
    uint8_t vtx_settings_config_band;
    uint8_t vtx_settings_config_channel;
    uint8_t vtx_settings_config_power;
    uint8_t pitmode;
    uint8_t vtx_common_device_is_ready;
    uint8_t vtx_settings_config_low_power_disarm;
    uint8_t field;
    uint8_t capability_band_count;
    uint8_t capability_channel_count;
    uint8_t capability_power_count;
    uint8_t min_power_index;
    uint8_t vtxdev_unknown;
    uint8_t vtxdev_unknown_2;
} msp_vtx_config_response_payload_t;
```

## MSP_SET_VTX_CONFIG
- MSP frame name: `MSP_SET_VTX_CONFIG`
- MSP frame ID: `89 (0x59)`
- Occurrences in file: line(s) 2887

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t new_frequency;
    uint8_t new_power;
    uint8_t new_pitmode;
    uint8_t low_power_disarm;
    uint16_t skip_pit_mode_freq;
    uint8_t new_band;
    uint8_t new_channel;
    uint16_t freq;
    uint8_t band_count;
    uint8_t channel_count;
    uint8_t new_power_count;
} msp_set_vtx_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_vtx_config_response_payload_t;
```

## MSP_ADVANCED_CONFIG
- MSP frame name: `MSP_ADVANCED_CONFIG`
- MSP frame ID: `90 (0x5A)`
- Occurrences in file: line(s) 1316

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_advanced_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t field_2;
    uint8_t field_3;
    uint8_t motor_config_motor_pwm_protocol;
    uint16_t motor_config_motor_pwm_rate;
    uint16_t servo_config_servo_pwm_rate;
    uint8_t field_4;
} msp_advanced_config_response_payload_t;
```

## MSP_SET_ADVANCED_CONFIG
- MSP frame name: `MSP_SET_ADVANCED_CONFIG`
- MSP frame ID: `91 (0x5B)`
- Occurrences in file: line(s) 2502

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_src_gyro_config_gyro_sync_denominator;
    uint8_t sbuf_read_u8_src_bf_master_config_pid_process_denom;
    uint8_t sbuf_read_u8_src_bf_motor_config_use_unsynced_pwm;
    uint8_t motor_pwm_protocol;
    uint16_t motor_pwm_rate;
    uint16_t servo_pwm_rate;
    uint8_t was_gyro_sync;
} msp_set_advanced_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_advanced_config_response_payload_t;
```

## MSP_FILTER_CONFIG
- MSP frame name: `MSP_FILTER_CONFIG`
- MSP frame ID: `92 (0x5C)`
- Occurrences in file: line(s) 1326

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_filter_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t gyro_config_gyro_main_lpf_hz;
    uint16_t pid_profile_dterm_lpf_hz;
    uint16_t pid_profile_yaw_lpf_hz;
    uint16_t field;
    uint16_t field_2;
    uint16_t field_3;
    uint16_t field_4;
    uint16_t field_5;
    uint16_t field_6;
    uint16_t accelerometer_config_acc_notch_hz;
    uint16_t accelerometer_config_acc_notch_cutoff;
    uint16_t field_7;
} msp_filter_config_response_payload_t;
```

## MSP_SET_FILTER_CONFIG
- MSP frame name: `MSP_SET_FILTER_CONFIG`
- MSP frame ID: `93 (0x5D)`
- Occurrences in file: line(s) 2515

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t gyro_main_lpf_hz;
    uint16_t dterm_lpf_hz;
    uint16_t yaw_lpf_hz;
    uint16_t sbuf_read_u16_src_was_gyro_config_mutable_gyro_notch_hz;
    uint16_t sbuf_read_u16_src_was_gyro_config_mutable_gyro_notch_cutoff;
    uint16_t sbuf_read_u16;
    uint16_t sbuf_read_u16_2;
    uint16_t sbuf_read_u16_src_was_gyro_config_mutable_gyro_soft_notch_hz_2;
    uint16_t sbuf_read_u16_src_was_gyro_config_mutable_gyro_soft_notch_cutoff_2;
    uint16_t acc_notch_hz;
    uint16_t acc_notch_cutoff;
    uint16_t was_gyro_stage2_lowpass_hz;
} msp_set_filter_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_filter_config_response_payload_t;
```

## MSP_PID_ADVANCED
- MSP frame name: `MSP_PID_ADVANCED`
- MSP frame ID: `94 (0x5E)`
- Occurrences in file: line(s) 1344

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_pid_advanced_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t field;
    uint16_t field_2;
    uint16_t field_3;
    uint8_t field_4;
    uint8_t field_5;
    uint8_t field_6;
    uint8_t field_7;
    uint16_t field_8;
    uint8_t field_9;
    uint16_t constrain_pid_profile_axis_acceleration_limit_roll_pitch_10_0_65535;
    uint16_t constrain_pid_profile_axis_acceleration_limit_yaw_10_0_65535;
} msp_pid_advanced_response_payload_t;
```

## MSP_SET_PID_ADVANCED
- MSP frame name: `MSP_SET_PID_ADVANCED`
- MSP frame ID: `95 (0x5F)`
- Occurrences in file: line(s) 2556

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t sbuf_read_u16_src_pid_profile_mutable_roll_pitch_iterm_ignore_rate;
    uint16_t sbuf_read_u16_src_pid_profile_mutable_yaw_iterm_ignore_rate;
    uint16_t sbuf_read_u16_src_pid_profile_yaw_p_limit;
    uint8_t sbuf_read_u8_src_bf_pid_profile_mutable_delta_method;
    uint8_t sbuf_read_u8_src_bf_pid_profile_mutable_vbat_pid_compensation;
    uint8_t sbuf_read_u8_src_bf_pid_profile_mutable_setpoint_relax_ratio;
    uint8_t sbuf_read_u8;
    uint16_t was_pidsum_limit;
    uint8_t sbuf_read_u8_src_bf_pid_profile_mutable_iterm_throttle_gain;
    uint16_t axis_acceleration_limit_roll_pitch;
    uint16_t axis_acceleration_limit_yaw;
} msp_set_pid_advanced_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_pid_advanced_response_payload_t;
```

## MSP_SENSOR_CONFIG
- MSP frame name: `MSP_SENSOR_CONFIG`
- MSP frame ID: `96 (0x60)`
- Occurrences in file: line(s) 1378

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_sensor_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t accelerometer_config_acc_hardware;
    uint8_t barometer_config_baro_hardware;
    uint8_t field;
    uint8_t compass_config_mag_hardware;
    uint8_t field_2;
    uint8_t pitotmeter_config_pitot_hardware;
    uint8_t field_3;
    uint8_t rangefinder_config_rangefinder_hardware;
    uint8_t field_4;
    uint8_t optical_flow_config_opflow_hardware;
    uint8_t field_5;
} msp_sensor_config_response_payload_t;
```

## MSP_SET_SENSOR_CONFIG
- MSP frame name: `MSP_SET_SENSOR_CONFIG`
- MSP frame ID: `97 (0x61)`
- Occurrences in file: line(s) 2597

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t acc_hardware;
    uint8_t baro_hardware;
    uint8_t sbuf_read_u8;
    uint8_t mag_hardware;
    uint8_t sbuf_read_u8_2;
    uint8_t pitot_hardware;
    uint8_t sbuf_read_u8_3;
    uint8_t rangefinder_hardware;
    uint8_t rangefinder_hardware_2;
    uint8_t opflow_hardware;
    uint8_t optical_flow_hardware;
} msp_set_sensor_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_sensor_config_response_payload_t;
```

## MSP_STATUS
- MSP frame name: `MSP_STATUS`
- MSP frame ID: `101 (0x65)`
- Occurrences in file: line(s) 471

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_status_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t cycle_time;
    uint16_t i2c_get_error_counter;
    uint16_t field;
    uint16_t sensor_status;
    uint8_t msp_box_mode_flags_bytes[];
    uint8_t config_profile;
    uint16_t average_system_load_percent;
    uint16_t arming_flags;
    uint8_t acc_get_calibration_axis_flags;
} msp_status_response_payload_t;
```

## MSP_RAW_IMU
- MSP frame name: `MSP_RAW_IMU`
- MSP frame ID: `102 (0x66)`
- Occurrences in file: line(s) 515

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_raw_imu_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t lrintf_acc_acc_ad_cf_i_512;
    uint16_t gyro_rate_dps;
    uint16_t lrintf_mag_mag_adc_i;
    uint16_t field;
} msp_raw_imu_response_payload_t;
```

## MSP_SERVO
- MSP frame name: `MSP_SERVO`
- MSP frame ID: `103 (0x67)`
- Occurrences in file: line(s) 533

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_servo_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t servo_bytes[];
} msp_servo_response_payload_t;
```

## MSP_MOTOR
- MSP frame name: `MSP_MOTOR`
- MSP frame ID: `104 (0x68)`
- Occurrences in file: line(s) 663

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_motor_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t motor;
} msp_motor_response_payload_t;
```

## MSP_RC
- MSP frame name: `MSP_RC`
- MSP frame ID: `105 (0x69)`
- Occurrences in file: line(s) 669

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t rx_get_channel_value;
} msp_rc_response_payload_t;
```

## MSP_RAW_GPS
- MSP frame name: `MSP_RAW_GPS`
- MSP frame ID: `106 (0x6A)`
- Occurrences in file: line(s) 967

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_raw_gps_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t gps_sol_fix_type;
    uint8_t gps_sol_num_sat;
    uint32_t llh_lat;
    uint32_t llh_lon;
    uint16_t llh_alt_100;
    uint16_t gps_sol_ground_speed;
    uint16_t gps_sol_ground_course;
    uint16_t gps_sol_hdop;
} msp_raw_gps_response_payload_t;
```

## MSP_COMP_GPS
- MSP frame name: `MSP_COMP_GPS`
- MSP frame ID: `107 (0x6B)`
- Occurrences in file: line(s) 978

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_comp_gps_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t gps_distance_to_home;
    uint16_t gps_direction_to_home;
    uint8_t flags_gps_heartbeat_1_0;
} msp_comp_gps_response_payload_t;
```

## MSP_ATTITUDE
- MSP frame name: `MSP_ATTITUDE`
- MSP frame ID: `108 (0x6C)`
- Occurrences in file: line(s) 675

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_attitude_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t values_roll;
    uint16_t values_pitch;
    uint16_t values_yaw;
} msp_attitude_response_payload_t;
```

## MSP_ALTITUDE
- MSP frame name: `MSP_ALTITUDE`
- MSP frame ID: `109 (0x6D)`
- Occurrences in file: line(s) 681

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_altitude_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t get_estimated_actual_position;
    uint16_t get_estimated_actual_velocity;
    uint32_t baro_get_latest_altitude;
    uint32_t field;
} msp_altitude_response_payload_t;
```

## MSP_ANALOG
- MSP frame name: `MSP_ANALOG`
- MSP frame ID: `110 (0x6E)`
- Occurrences in file: line(s) 726

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_analog_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t get_battery_voltage;
    uint16_t x_ffff;
    uint16_t rssi;
    uint16_t x7_fff;
} msp_analog_response_payload_t;
```

## MSP_RC_TUNING
- MSP frame name: `MSP_RC_TUNING`
- MSP frame ID: `111 (0x6F)`
- Occurrences in file: line(s) 750

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rc_tuning_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t stabilized_rc_expo8;
    uint8_t stabilized_rates_i;
    uint8_t throttle_dyn_pid;
    uint8_t throttle_rc_mid8;
    uint8_t throttle_rc_expo8;
    uint16_t throttle_pa_breakpoint;
    uint8_t stabilized_rc_yaw_expo8;
} msp_rc_tuning_response_payload_t;
```

## MSP_ACTIVEBOXES
- MSP frame name: `MSP_ACTIVEBOXES`
- MSP frame ID: `113 (0x71)`
- Occurrences in file: line(s) 462

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_activeboxes_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t msp_box_mode_flags_bytes[];
} msp_activeboxes_response_payload_t;
```

## MSP_MISC
- MSP frame name: `MSP_MISC`
- MSP frame ID: `114 (0x72)`
- Occurrences in file: line(s) 836

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_misc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t pwm_range_middle;
    uint16_t field;
    uint16_t max_throttle;
    uint16_t motor_config_mincommand;
    uint16_t current_battery_profile_failsafe_throttle;
    uint8_t gps_config_provider;
    uint8_t field_2;
    uint8_t gps_config_sbas_mode;
    uint8_t field_3;
    uint8_t field_4;
    uint8_t field_5;
    uint8_t field_6;
    uint8_t rx_config_rssi_channel;
    uint8_t field_7;
    uint16_t compass_config_mag_declination_10;
    uint16_t field_8;
    uint8_t voltage_scale_10;
    uint8_t voltage_cell_min_10;
    uint8_t voltage_cell_max_10;
    uint8_t voltage_cell_warning_10;
    uint8_t field_9;
    uint8_t field_10;
    uint8_t field_11;
    uint8_t field_12;
} msp_misc_response_payload_t;
```

## MSP_BOXNAMES
- MSP frame name: `MSP_BOXNAMES`
- MSP frame ID: `116 (0x74)`
- Occurrences in file: line(s) 826

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_boxnames_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_boxnames_response_payload_t;
```

## MSP_PIDNAMES
- MSP frame name: `MSP_PIDNAMES`
- MSP frame ID: `117 (0x75)`
- Occurrences in file: line(s) 797

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_pidnames_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t c;
} msp_pidnames_response_payload_t;
```

## MSP_WP
- MSP frame name: `MSP_WP`
- MSP frame ID: `118 (0x76)`
- Occurrences in file: line(s) 4120

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_wp_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_wp_response_payload_t;
```

## MSP_BOXIDS
- MSP frame name: `MSP_BOXIDS`
- MSP frame ID: `119 (0x77)`
- Occurrences in file: line(s) 832

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_boxids_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_boxids_response_payload_t;
```

## MSP_SERVO_CONFIGURATIONS
- MSP frame name: `MSP_SERVO_CONFIGURATIONS`
- MSP frame ID: `120 (0x78)`
- Occurrences in file: line(s) 536

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_servo_configurations_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t servo_params_i;
    uint16_t servo_params_i_2;
    uint16_t servo_params_i_middle;
    uint8_t servo_params_i_rate;
    uint8_t field;
    uint8_t field_2;
    uint8_t field_3;
    uint32_t field_4;
} msp_servo_configurations_response_payload_t;
```

## MSP_NAV_STATUS
- MSP frame name: `MSP_NAV_STATUS`
- MSP frame ID: `121 (0x79)`
- Occurrences in file: line(s) 983

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_nav_status_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t nav_status_mode;
    uint8_t nav_status_state;
    uint8_t nav_status_active_wp_action;
    uint8_t nav_status_active_wp_number;
    uint8_t nav_status_error;
    uint16_t heading_hold_target;
} msp_nav_status_response_payload_t;
```

## MSP_3D
- MSP frame name: `MSP_3D`
- MSP frame ID: `124 (0x7C)`
- Occurrences in file: line(s) 1288

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_3d_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t reversible_motors_config_deadband_low;
    uint16_t reversible_motors_config_deadband_high;
    uint16_t reversible_motors_config_neutral;
} msp_3d_response_payload_t;
```

## MSP_RC_DEADBAND
- MSP frame name: `MSP_RC_DEADBAND`
- MSP frame ID: `125 (0x7D)`
- Occurrences in file: line(s) 1294

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rc_deadband_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rc_controls_config_deadband;
    uint8_t rc_controls_config_yaw_deadband;
    uint8_t rc_controls_config_alt_hold_deadband;
    uint16_t rc_controls_config_mid_throttle_deadband;
} msp_rc_deadband_response_payload_t;
```

## MSP_SENSOR_ALIGNMENT
- MSP frame name: `MSP_SENSOR_ALIGNMENT`
- MSP frame ID: `126 (0x7E)`
- Occurrences in file: line(s) 1301

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_sensor_alignment_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t field_2;
    uint8_t compass_config_mag_align;
    uint8_t field_3;
    uint8_t optical_flow_config_opflow_align;
    uint8_t field_4;
} msp_sensor_alignment_response_payload_t;
```

## MSP_LED_STRIP_MODECOLOR
- MSP frame name: `MSP_LED_STRIP_MODECOLOR`
- MSP frame ID: `127 (0x7F)`
- Occurrences in file: line(s) 1202

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_led_strip_modecolor_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t field_2;
    uint8_t mode_colors_i_color_j;
    uint8_t led_mode_count;
    uint8_t field_3;
    uint8_t special_colors_color_j;
} msp_led_strip_modecolor_response_payload_t;
```

## MSP_BATTERY_STATE
- MSP frame name: `MSP_BATTERY_STATE`
- MSP frame ID: `130 (0x82)`
- Occurrences in file: line(s) 1250

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_battery_state_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t get_battery_cell_count;
    uint16_t capacity_value;
    uint8_t get_battery_voltage;
    uint16_t x_ffff;
    uint16_t x7_fff;
    uint8_t battery_state;
    uint16_t battery_voltage;
} msp_battery_state_response_payload_t;
```

## MSP_VTXTABLE_POWERLEVEL
- MSP frame name: `MSP_VTXTABLE_POWERLEVEL`
- MSP frame ID: `138 (0x8A)`
- Occurrences in file: line(s) 4555

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t power_level;
} msp_vtxtable_powerlevel_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t power_level;
    uint16_t field;
    uint8_t str_len;
    uint8_t str;
} msp_vtxtable_powerlevel_response_payload_t;
```

## MSP_STATUS_EX
- MSP frame name: `MSP_STATUS_EX`
- MSP frame ID: `150 (0x96)`
- Occurrences in file: line(s) 470

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_status_ex_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_status_ex_response_payload_t;
```

## MSP_SENSOR_STATUS
- MSP frame name: `MSP_SENSOR_STATUS`
- MSP frame ID: `151 (0x97)`
- Occurrences in file: line(s) 448

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_sensor_status_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t hardware_healthy;
    uint8_t hw_gyro_status;
    uint8_t hw_accelerometer_status;
    uint8_t hw_compass_status;
    uint8_t hw_barometer_status;
    uint8_t hw_gps_status;
    uint8_t hw_rangefinder_status;
    uint8_t hw_pitotmeter_status;
    uint8_t hw_optical_flow_status;
} msp_sensor_status_response_payload_t;
```

## MSP_UID
- MSP frame name: `MSP_UID`
- MSP frame ID: `160 (0xA0)`
- Occurrences in file: line(s) 1062

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_uid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t u_id_0;
    uint32_t u_id_1;
    uint32_t u_id_2;
} msp_uid_response_payload_t;
```

## MSP_GPSSVINFO
- MSP frame name: `MSP_GPSSVINFO`
- MSP frame ID: `164 (0xA4)`
- Occurrences in file: line(s) 994

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_gpssvinfo_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t hdop;
    uint8_t field_2;
    uint8_t gps_sol_hdop_100;
    uint8_t gps_sol_hdop_100_2;
} msp_gpssvinfo_response_payload_t;
```

## MSP_GPSSTATISTICS
- MSP frame name: `MSP_GPSSTATISTICS`
- MSP frame ID: `166 (0xA6)`
- Occurrences in file: line(s) 1005

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_gpsstatistics_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t gps_stats_last_message_dt;
    uint32_t gps_stats_errors;
    uint32_t gps_stats_timeouts;
    uint32_t gps_stats_packet_count;
    uint16_t gps_sol_hdop;
    uint16_t gps_sol_eph;
    uint16_t gps_sol_epv;
    uint32_t gps_state_hw_version;
} msp_gpsstatistics_response_payload_t;
```

## MSP_SET_TX_INFO
- MSP frame name: `MSP_SET_TX_INFO`
- MSP frame ID: `186 (0xBA)`
- Occurrences in file: line(s) 3326

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
} msp_set_tx_info_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_tx_info_response_payload_t;
```

## MSP_TX_INFO
- MSP frame name: `MSP_TX_INFO`
- MSP frame ID: `187 (0xBB)`
- Occurrences in file: line(s) 1501

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_tx_info_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rssi_source;
    uint8_t rtc_date_time_is_set;
} msp_tx_info_response_payload_t;
```

## MSP_SET_RAW_RC
- MSP frame name: `MSP_SET_RAW_RC`
- MSP frame ID: `200 (0xC8)`
- Occurrences in file: line(s) 1985

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t sbuf_read_u16;
} msp_set_raw_rc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_raw_rc_response_payload_t;
```

## MSP_SET_RAW_GPS
- MSP frame name: `MSP_SET_RAW_GPS`
- MSP frame ID: `201 (0xC9)`
- Occurrences in file: line(s) 2971

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t fix_type;
    uint8_t num_sat;
    uint32_t lat;
    uint32_t lon;
    uint16_t alt;
    uint16_t ground_speed;
} msp_set_raw_gps_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_raw_gps_response_payload_t;
```

## MSP_SET_RC_TUNING
- MSP frame name: `MSP_SET_RC_TUNING`
- MSP frame ID: `204 (0xCC)`
- Occurrences in file: line(s) 2063

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8;
    uint8_t rc_expo8;
    uint8_t tmp_u8;
    uint8_t tmp_u8_2;
    uint8_t rc_mid8;
    uint8_t rc_expo8_2;
    uint16_t pa_breakpoint;
    uint8_t rc_yaw_expo8;
} msp_set_rc_tuning_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_rc_tuning_response_payload_t;
```

## MSP_ACC_CALIBRATION
- MSP frame name: `MSP_ACC_CALIBRATION`
- MSP frame ID: `205 (0xCD)`
- Occurrences in file: line(s) 2748

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_acc_calibration_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_acc_calibration_response_payload_t;
```

## MSP_MAG_CALIBRATION
- MSP frame name: `MSP_MAG_CALIBRATION`
- MSP frame ID: `206 (0xCE)`
- Occurrences in file: line(s) 2755

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_mag_calibration_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_mag_calibration_response_payload_t;
```

## MSP_SET_MISC
- MSP frame name: `MSP_SET_MISC`
- MSP frame ID: `207 (0xCF)`
- Occurrences in file: line(s) 2131

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t midrc;
    uint16_t was_min_throttle;
    uint16_t was_max_throttle;
    uint16_t mincommand;
    uint16_t failsafe_throttle;
    uint8_t provider;
    uint8_t gps_baudrate;
    uint8_t sbas_mode;
    uint8_t gps_type;
    uint8_t gps_baudrate_2;
    uint8_t gps_ubx_sbas;
    uint8_t multiwii_current_meter_output;
    uint8_t tmp_u8;
    uint8_t sbuf_read_u8;
    uint16_t mag_declination;
    uint16_t sbuf_read_u16;
    uint8_t scale;
    uint8_t cell_min;
    uint8_t cell_max;
    uint8_t cell_warning;
    uint8_t sbuf_read_u8_2;
    uint8_t sbuf_read_u8_3;
    uint8_t sbuf_read_u8_4;
    uint8_t sbuf_read_u8_5;
} msp_set_misc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_misc_response_payload_t;
```

## MSP_RESET_CONF
- MSP frame name: `MSP_RESET_CONF`
- MSP frame ID: `208 (0xD0)`
- Occurrences in file: line(s) 2737

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_reset_conf_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_reset_conf_response_payload_t;
```

## MSP_SET_WP
- MSP frame name: `MSP_SET_WP`
- MSP frame ID: `209 (0xD1)`
- Occurrences in file: line(s) 3001

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t msp_wp_no;
    uint8_t action;
    uint32_t lat;
    uint32_t lon;
    uint32_t alt;
    uint16_t p1;
    uint16_t p2;
    uint16_t p3;
    uint8_t flag;
} msp_set_wp_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_wp_response_payload_t;
```

## MSP_SELECT_SETTING
- MSP frame name: `MSP_SELECT_SETTING`
- MSP frame ID: `210 (0xD2)`
- Occurrences in file: line(s) 1963

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
} msp_select_setting_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_select_setting_response_payload_t;
```

## MSP_SET_HEAD
- MSP frame name: `MSP_SET_HEAD`
- MSP frame ID: `211 (0xD3)`
- Occurrences in file: line(s) 1970

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t if;
} msp_set_head_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_head_response_payload_t;
```

## MSP_SET_SERVO_CONFIGURATION
- MSP frame name: `MSP_SET_SERVO_CONFIGURATION`
- MSP frame ID: `212 (0xD4)`
- Occurrences in file: line(s) 2308

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t tmp_u8;
    uint16_t min;
    uint16_t max;
    uint16_t middle;
    uint8_t rate;
    uint8_t sbuf_read_u8;
    uint8_t sbuf_read_u8_2;
    uint8_t sbuf_read_u8_3;
    uint32_t used_to_be_reversed_sources;
} msp_set_servo_configuration_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_servo_configuration_response_payload_t;
```

## MSP_SET_MOTOR
- MSP frame name: `MSP_SET_MOTOR`
- MSP frame ID: `214 (0xD6)`
- Occurrences in file: line(s) 2296

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t disarmed;
} msp_set_motor_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_motor_response_payload_t;
```

## MSP_SET_3D
- MSP frame name: `MSP_SET_3D`
- MSP frame ID: `217 (0xD9)`
- Occurrences in file: line(s) 2461

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t deadband_low;
    uint16_t deadband_high;
    uint16_t neutral;
} msp_set_3d_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_3d_response_payload_t;
```

## MSP_SET_RC_DEADBAND
- MSP frame name: `MSP_SET_RC_DEADBAND`
- MSP frame ID: `218 (0xDA)`
- Occurrences in file: line(s) 2470

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t deadband;
    uint8_t yaw_deadband;
    uint8_t alt_hold_deadband;
    uint16_t mid_throttle_deadband;
} msp_set_rc_deadband_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_rc_deadband_response_payload_t;
```

## MSP_SET_RESET_CURR_PID
- MSP frame name: `MSP_SET_RESET_CURR_PID`
- MSP frame ID: `219 (0xDB)`
- Occurrences in file: line(s) 2480

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_reset_curr_pid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_reset_curr_pid_response_payload_t;
```

## MSP_SET_SENSOR_ALIGNMENT
- MSP frame name: `MSP_SET_SENSOR_ALIGNMENT`
- MSP frame ID: `220 (0xDC)`
- Occurrences in file: line(s) 2484

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_src_was_gyro_config_mutable_gyro_align;
    uint8_t sbuf_read_u8_src_was_accelerometer_config_mutable_acc_align;
    uint8_t mag_align;
    uint8_t sbuf_read_u8;
    uint8_t opflow_align;
    uint8_t sbuf_read_u8_2;
} msp_set_sensor_alignment_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_sensor_alignment_response_payload_t;
```

## MSP_SET_LED_STRIP_MODECOLOR
- MSP frame name: `MSP_SET_LED_STRIP_MODECOLOR`
- MSP frame ID: `221 (0xDD)`
- Occurrences in file: line(s) 3286

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mode_idx;
    uint8_t fun_idx;
    uint8_t color;
} msp_set_led_strip_modecolor_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_led_strip_modecolor_response_payload_t;
```

## MSP_SERVO_MIX_RULES
- MSP frame name: `MSP_SERVO_MIX_RULES`
- MSP frame ID: `241 (0xF1)`
- Occurrences in file: line(s) 556

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_servo_mix_rules_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t custom_servo_mixers_i_target_channel;
    uint8_t custom_servo_mixers_i_input_source;
    uint16_t custom_servo_mixers_i_rate;
    uint8_t custom_servo_mixers_i_speed;
    uint8_t field;
    uint8_t field_2;
    uint8_t field_3;
} msp_servo_mix_rules_response_payload_t;
```

## MSP_SET_SERVO_MIX_RULE
- MSP frame name: `MSP_SET_SERVO_MIX_RULE`
- MSP frame ID: `242 (0xF2)`
- Occurrences in file: line(s) 2344

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t target_channel;
    uint8_t input_source;
    uint16_t rate;
    uint8_t speed;
    uint16_t read_2bytes_for_min_max_and_ignore_it;
    uint8_t sbuf_read_u8;
} msp_set_servo_mix_rule_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_servo_mix_rule_response_payload_t;
```

## MSP_RTC
- MSP frame name: `MSP_RTC`
- MSP frame ID: `246 (0xF6)`
- Occurrences in file: line(s) 1511

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_rtc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t seconds;
    uint16_t millis;
} msp_rtc_response_payload_t;
```

## MSP_SET_RTC
- MSP frame name: `MSP_SET_RTC`
- MSP frame ID: `247 (0xF7)`
- Occurrences in file: line(s) 3313

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t secs;
    uint16_t millis;
} msp_set_rtc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_set_rtc_response_payload_t;
```

## MSP_EEPROM_WRITE
- MSP frame name: `MSP_EEPROM_WRITE`
- MSP frame ID: `250 (0xFA)`
- Occurrences in file: line(s) 2771

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_eeprom_write_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_eeprom_write_response_payload_t;
```

## MSP_DEBUG
- MSP frame name: `MSP_DEBUG`
- MSP frame ID: `254 (0xFE)`
- Occurrences in file: line(s) 1047

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp_debug_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t debug;
} msp_debug_response_payload_t;
```

## MSP2_COMMON_TZ
- MSP frame name: `MSP2_COMMON_TZ`
- MSP frame ID: `4097 (0x1001)`
- Occurrences in file: line(s) 1580

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_tz_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t time_config_tz_offset;
    uint8_t time_config_tz_automatic_dst;
} msp2_common_tz_response_payload_t;
```

## MSP2_COMMON_SET_TZ
- MSP frame name: `MSP2_COMMON_SET_TZ`
- MSP frame ID: `4098 (0x1002)`
- Occurrences in file: line(s) 3348

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t tz_offset;
    uint16_t tz_offset_2;
    uint8_t tz_automatic_dst;
} msp2_common_set_tz_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_tz_response_payload_t;
```

## MSP2_COMMON_SETTING
- MSP frame name: `MSP2_COMMON_SETTING`
- MSP frame ID: `4099 (0x1003)`
- Occurrences in file: line(s) 4132

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_setting_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_setting_response_payload_t;
```

## MSP2_COMMON_SET_SETTING
- MSP frame name: `MSP2_COMMON_SET_SETTING`
- MSP frame ID: `4100 (0x1004)`
- Occurrences in file: line(s) 4136

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_setting_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_setting_response_payload_t;
```

## MSP2_COMMON_MOTOR_MIXER
- MSP frame name: `MSP2_COMMON_MOTOR_MIXER`
- MSP frame ID: `4101 (0x1005)`
- Occurrences in file: line(s) 647

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_motor_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t f_0f_4_0f_1000;
    uint16_t f_0f_4_0f_1000_2;
    uint16_t f_0f_4_0f_1000_3;
    uint16_t f_0f_4_0f_1000_4;
    uint16_t f_0f_4_0f_1000_5;
    uint16_t f_0f_4_0f_1000_6;
    uint16_t f_0f_4_0f_1000_7;
    uint16_t f_0f_4_0f_1000_8;
} msp2_common_motor_mixer_response_payload_t;
```

## MSP2_COMMON_SET_MOTOR_MIXER
- MSP frame name: `MSP2_COMMON_SET_MOTOR_MIXER`
- MSP frame ID: `4102 (0x1006)`
- Occurrences in file: line(s) 2450

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint16_t throttle;
    uint16_t roll;
    uint16_t pitch;
    uint16_t yaw;
} msp2_common_set_motor_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_motor_mixer_response_payload_t;
```

## MSP2_COMMON_SETTING_INFO
- MSP frame name: `MSP2_COMMON_SETTING_INFO`
- MSP frame ID: `4103 (0x1007)`
- Occurrences in file: line(s) 4140

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_setting_info_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_setting_info_response_payload_t;
```

## MSP2_COMMON_PG_LIST
- MSP frame name: `MSP2_COMMON_PG_LIST`
- MSP frame ID: `4104 (0x1008)`
- Occurrences in file: line(s) 4144

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_pg_list_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_pg_list_response_payload_t;
```

## MSP2_COMMON_SERIAL_CONFIG
- MSP frame name: `MSP2_COMMON_SERIAL_CONFIG`
- MSP frame ID: `4105 (0x1009)`
- Occurrences in file: line(s) 1150

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_serial_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t port_configs_i_identifier;
    uint32_t port_configs_i_function_mask;
    uint8_t port_configs_i_msp_baudrate_index;
    uint8_t port_configs_i_gps_baudrate_index;
    uint8_t port_configs_i_telemetry_baudrate_index;
    uint8_t port_configs_i_peripheral_baudrate_index;
} msp2_common_serial_config_response_payload_t;
```

## MSP2_COMMON_SET_SERIAL_CONFIG
- MSP frame name: `MSP2_COMMON_SET_SERIAL_CONFIG`
- MSP frame ID: `4106 (0x100A)`
- Occurrences in file: line(s) 3210

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t identifier;
    uint32_t function_mask;
    uint8_t msp_baudrate_index;
    uint8_t gps_baudrate_index;
    uint8_t telemetry_baudrate_index;
    uint8_t peripheral_baudrate_index;
} msp2_common_set_serial_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_serial_config_response_payload_t;
```

## MSP2_COMMON_SET_RADAR_POS
- MSP frame name: `MSP2_COMMON_SET_RADAR_POS`
- MSP frame ID: `4107 (0x100B)`
- Occurrences in file: line(s) 3033

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t msp_radar_no;
    uint8_t state;
    uint32_t lat;
    uint32_t lon;
    uint32_t alt;
    uint16_t heading;
    uint16_t speed;
    uint8_t lq;
} msp2_common_set_radar_pos_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_radar_pos_response_payload_t;
```

## MSP2_COMMON_SET_MSP_RC_LINK_STATS
- MSP frame name: `MSP2_COMMON_SET_MSP_RC_LINK_STATS`
- MSP frame ID: `4109 (0x100D)`
- Occurrences in file: line(s) 3126

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sublink_id;
    uint8_t sbuf_read_u8;
    uint8_t rssi_from_msp_rc;
    uint8_t uplink_rssi;
    uint8_t downlink_lq;
    uint8_t uplink_lq;
} msp2_common_set_msp_rc_link_stats_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_msp_rc_link_stats_response_payload_t;
```

## MSP2_COMMON_SET_MSP_RC_INFO
- MSP frame name: `MSP2_COMMON_SET_MSP_RC_INFO`
- MSP frame ID: `4110 (0x100E)`
- Occurrences in file: line(s) 3144

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sublink_id;
    uint16_t uplink_tx_power;
    uint16_t downlink_tx_power;
    uint8_t rx_link_statistics_band_i_sbuf_read_u8_src;
    uint8_t rx_link_statistics_mode_i_sbuf_read_u8_src;
} msp2_common_set_msp_rc_info_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_set_msp_rc_info_response_payload_t;
```

## MSP2_COMMON_GET_RADAR_GPS
- MSP frame name: `MSP2_COMMON_GET_RADAR_GPS`
- MSP frame ID: `4111 (0x100F)`
- Occurrences in file: line(s) 1804

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_common_get_radar_gps_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field_bytes[];
} msp2_common_get_radar_gps_response_payload_t;
```

## MSP2_SENSOR_RANGEFINDER
- MSP frame name: `MSP2_SENSOR_RANGEFINDER`
- MSP frame ID: `7937 (0x1F01)`
- Occurrences in file: line(s) 4591

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_rangefinder_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_rangefinder_response_payload_t;
```

## MSP2_SENSOR_OPTIC_FLOW
- MSP frame name: `MSP2_SENSOR_OPTIC_FLOW`
- MSP frame ID: `7938 (0x1F02)`
- Occurrences in file: line(s) 4597

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_optic_flow_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_optic_flow_response_payload_t;
```

## MSP2_SENSOR_GPS
- MSP frame name: `MSP2_SENSOR_GPS`
- MSP frame ID: `7939 (0x1F03)`
- Occurrences in file: line(s) 4603

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_gps_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_gps_response_payload_t;
```

## MSP2_SENSOR_COMPASS
- MSP frame name: `MSP2_SENSOR_COMPASS`
- MSP frame ID: `7940 (0x1F04)`
- Occurrences in file: line(s) 4609

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_compass_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_compass_response_payload_t;
```

## MSP2_SENSOR_BAROMETER
- MSP frame name: `MSP2_SENSOR_BAROMETER`
- MSP frame ID: `7941 (0x1F05)`
- Occurrences in file: line(s) 4615

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_barometer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_barometer_response_payload_t;
```

## MSP2_SENSOR_AIRSPEED
- MSP frame name: `MSP2_SENSOR_AIRSPEED`
- MSP frame ID: `7942 (0x1F06)`
- Occurrences in file: line(s) 4621

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_airspeed_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_airspeed_response_payload_t;
```

## MSP2_SENSOR_HEADTRACKER
- MSP frame name: `MSP2_SENSOR_HEADTRACKER`
- MSP frame ID: `7943 (0x1F07)`
- Occurrences in file: line(s) 4627

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_headtracker_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_sensor_headtracker_response_payload_t;
```

## MSP2_INAV_STATUS
- MSP frame name: `MSP2_INAV_STATUS`
- MSP frame ID: `8192 (0x2000)`
- Occurrences in file: line(s) 494

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_status_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t cycle_time;
    uint16_t i2c_get_error_counter;
    uint16_t field;
    uint16_t sensor_status;
    uint16_t average_system_load_percent;
    uint8_t get_config_profile;
    uint32_t arming_flags;
    uint8_t msp_box_mode_flags_bytes[];
    uint8_t config_mixer_profile;
} msp2_inav_status_response_payload_t;
```

## MSP2_INAV_OPTICAL_FLOW
- MSP frame name: `MSP2_INAV_OPTICAL_FLOW`
- MSP frame ID: `8193 (0x2001)`
- Occurrences in file: line(s) 710

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_optical_flow_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t opflow_raw_quality;
    uint16_t radians_to_degrees_opflow_flow_rate_x;
    uint16_t radians_to_degrees_opflow_flow_rate_y;
    uint16_t radians_to_degrees_opflow_body_rate_x;
    uint16_t radians_to_degrees_opflow_body_rate_y;
    uint8_t field;
    uint16_t field_2;
    uint16_t field_3;
    uint16_t field_4;
    uint16_t field_5;
} msp2_inav_optical_flow_response_payload_t;
```

## MSP2_INAV_ANALOG
- MSP frame name: `MSP2_INAV_ANALOG`
- MSP frame ID: `8194 (0x2002)`
- Occurrences in file: line(s) 733

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_analog_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t battery_was_full_when_plugged_in;
    uint16_t battery_voltage;
    uint16_t amperage;
    uint32_t power;
    uint32_t m_ah_drawn;
    uint32_t m_wh_drawn;
    uint32_t battery_remaining_capacity;
    uint8_t battery_percentage;
    uint16_t rssi;
} msp2_inav_analog_response_payload_t;
```

## MSP2_INAV_MISC
- MSP frame name: `MSP2_INAV_MISC`
- MSP frame ID: `8195 (0x2003)`
- Occurrences in file: line(s) 877

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_misc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t pwm_range_middle;
    uint16_t field;
    uint16_t max_throttle;
    uint16_t motor_config_mincommand;
    uint16_t current_battery_profile_failsafe_throttle;
    uint8_t gps_config_provider;
    uint8_t field_2;
    uint8_t gps_config_sbas_mode;
    uint8_t field_3;
    uint8_t field_4;
    uint8_t field_5;
    uint8_t rx_config_rssi_channel;
    uint16_t compass_config_mag_declination_10;
    uint16_t field_6;
    uint16_t voltage_scale;
    uint8_t battery_meters_config_voltage_source;
    uint8_t current_battery_profile_cells;
    uint16_t voltage_cell_detect;
    uint16_t voltage_cell_min;
    uint16_t voltage_cell_max;
    uint16_t voltage_cell_warning;
    uint16_t field_7;
    uint8_t field_8;
    uint8_t field_9;
    uint16_t field_10;
    uint16_t field_11;
    uint16_t field_12;
    uint16_t field_13;
    uint32_t capacity_value;
    uint32_t capacity_warning;
    uint32_t capacity_critical;
    uint8_t battery_meters_config_capacity_unit;
} msp2_inav_misc_response_payload_t;
```

## MSP2_INAV_SET_MISC
- MSP frame name: `MSP2_INAV_SET_MISC`
- MSP frame ID: `8196 (0x2004)`
- Occurrences in file: line(s) 2179

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t midrc;
    uint16_t was_min_throttle;
    uint16_t was_max_throttle;
    uint16_t mincommand;
    uint16_t failsafe_throttle;
    uint8_t provider;
    uint8_t gps_baudrate;
    uint8_t sbas_mode;
    uint8_t gps_type;
    uint8_t gps_baudrate_2;
    uint8_t gps_ubx_sbas;
    uint8_t tmp_u8;
    uint16_t mag_declination;
    uint16_t sbuf_read_u16;
    uint16_t scale;
    uint8_t voltage_source;
    uint8_t cells;
    uint16_t cell_detect;
    uint16_t cell_min;
    uint16_t cell_max;
    uint16_t cell_warning;
    uint16_t sbuf_read_u16_2;
    uint8_t sbuf_read_u8;
    uint8_t sbuf_read_u8_2;
    uint16_t sbuf_read_u16_3;
    uint16_t sbuf_read_u16_4;
    uint16_t sbuf_read_u16_5;
    uint16_t sbuf_read_u16_6;
    uint32_t value;
    uint32_t warning;
    uint32_t critical;
    uint8_t capacity_unit;
} msp2_inav_set_misc_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_misc_response_payload_t;
```

## MSP2_INAV_BATTERY_CONFIG
- MSP frame name: `MSP2_INAV_BATTERY_CONFIG`
- MSP frame ID: `8197 (0x2005)`
- Occurrences in file: line(s) 938

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_battery_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t voltage_scale;
    uint8_t battery_meters_config_voltage_source;
    uint8_t current_battery_profile_cells;
    uint16_t voltage_cell_detect;
    uint16_t voltage_cell_min;
    uint16_t voltage_cell_max;
    uint16_t voltage_cell_warning;
    uint16_t field;
    uint8_t field_2;
    uint8_t field_3;
    uint16_t field_4;
    uint16_t field_5;
    uint16_t field_6;
    uint16_t field_7;
    uint16_t current_offset;
    uint16_t current_scale;
    uint32_t capacity_value;
    uint32_t capacity_warning;
    uint32_t capacity_critical;
    uint8_t battery_meters_config_capacity_unit;
} msp2_inav_battery_config_response_payload_t;
```

## MSP2_INAV_SET_BATTERY_CONFIG
- MSP frame name: `MSP2_INAV_SET_BATTERY_CONFIG`
- MSP frame ID: `8198 (0x2006)`
- Occurrences in file: line(s) 2250

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t scale;
    uint8_t voltage_source;
    uint8_t cells;
    uint16_t cell_detect;
    uint16_t cell_min;
    uint16_t cell_max;
    uint16_t cell_warning;
    uint16_t sbuf_read_u16;
    uint8_t sbuf_read_u8;
    uint8_t sbuf_read_u8_2;
    uint16_t sbuf_read_u16_2;
    uint16_t sbuf_read_u16_3;
    uint16_t sbuf_read_u16_4;
    uint16_t sbuf_read_u16_5;
    uint16_t offset;
    uint16_t scale_2;
    uint32_t value;
    uint32_t warning;
    uint32_t critical;
    uint8_t capacity_unit;
} msp2_inav_set_battery_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_battery_config_response_payload_t;
```

## MSP2_INAV_RATE_PROFILE
- MSP frame name: `MSP2_INAV_RATE_PROFILE`
- MSP frame ID: `8199 (0x2007)`
- Occurrences in file: line(s) 763

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_rate_profile_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t throttle_rc_mid8;
    uint8_t throttle_rc_expo8;
    uint8_t throttle_dyn_pid;
    uint16_t throttle_pa_breakpoint;
    uint8_t stabilized_rc_expo8;
    uint8_t stabilized_rc_yaw_expo8;
    uint8_t stabilized_rates_i;
    uint8_t manual_rc_expo8;
    uint8_t manual_rc_yaw_expo8;
    uint8_t manual_rates_i;
} msp2_inav_rate_profile_response_payload_t;
```

## MSP2_INAV_SET_RATE_PROFILE
- MSP frame name: `MSP2_INAV_SET_RATE_PROFILE`
- MSP frame ID: `8200 (0x2008)`
- Occurrences in file: line(s) 2092

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rc_mid8;
    uint8_t rc_expo8;
    uint8_t dyn_pid;
    uint16_t pa_breakpoint;
    uint8_t rc_expo8_2;
    uint8_t rc_yaw_expo8;
    uint8_t tmp_u8;
    uint8_t rc_expo8_3;
    uint8_t rc_yaw_expo8_2;
    uint8_t tmp_u8_2;
} msp2_inav_set_rate_profile_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_rate_profile_response_payload_t;
```

## MSP2_INAV_AIR_SPEED
- MSP frame name: `MSP2_INAV_AIR_SPEED`
- MSP frame ID: `8201 (0x2009)`
- Occurrences in file: line(s) 1585

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_air_speed_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t airspeed_estimate;
    uint32_t field;
} msp2_inav_air_speed_response_payload_t;
```

## MSP2_INAV_OUTPUT_MAPPING
- MSP frame name: `MSP2_INAV_OUTPUT_MAPPING`
- MSP frame ID: `8202 (0x200A)`
- Occurrences in file: line(s) 1652

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_output_mapping_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t timer_hardware_i_usage_flags;
} msp2_inav_output_mapping_response_payload_t;
```

## MSP2_INAV_MC_BRAKING
- MSP frame name: `MSP2_INAV_MC_BRAKING`
- MSP frame ID: `8203 (0x200B)`
- Occurrences in file: line(s) 1698

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_mc_braking_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t mc_braking_speed_threshold;
    uint16_t mc_braking_disengage_speed;
    uint16_t mc_braking_timeout;
    uint8_t mc_braking_boost_factor;
    uint16_t mc_braking_boost_timeout;
    uint16_t mc_braking_boost_speed_threshold;
    uint16_t mc_braking_boost_disengage_speed;
    uint8_t mc_braking_bank_angle;
} msp2_inav_mc_braking_response_payload_t;
```

## MSP2_INAV_SET_MC_BRAKING
- MSP frame name: `MSP2_INAV_SET_MC_BRAKING`
- MSP frame ID: `8204 (0x200C)`
- Occurrences in file: line(s) 3458

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t braking_speed_threshold;
    uint16_t braking_disengage_speed;
    uint16_t braking_timeout;
    uint8_t braking_boost_factor;
    uint16_t braking_boost_timeout;
    uint16_t braking_boost_speed_threshold;
    uint16_t braking_boost_disengage_speed;
    uint8_t braking_bank_angle;
} msp2_inav_set_mc_braking_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_mc_braking_response_payload_t;
```

## MSP2_INAV_OUTPUT_MAPPING_EXT
- MSP frame name: `MSP2_INAV_OUTPUT_MAPPING_EXT`
- MSP frame ID: `8205 (0x200D)`
- Occurrences in file: line(s) 1660

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_output_mapping_ext_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t timer2id_timer_hardware_i_tim;
    uint8_t timer_hardware_i_usage_flags;
} msp2_inav_output_mapping_ext_response_payload_t;
```

## MSP2_INAV_TIMER_OUTPUT_MODE
- MSP frame name: `MSP2_INAV_TIMER_OUTPUT_MODE`
- MSP frame ID: `8206 (0x200E)`
- Occurrences in file: line(s) 4519

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t timer;
} msp2_inav_timer_output_mode_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t timer_overrides_i_output_mode;
    uint8_t timer;
    uint8_t timer_overrides_timer_output_mode;
} msp2_inav_timer_output_mode_response_payload_t;
```

## MSP2_INAV_SET_TIMER_OUTPUT_MODE
- MSP frame name: `MSP2_INAV_SET_TIMER_OUTPUT_MODE`
- MSP frame ID: `8207 (0x200F)`
- Occurrences in file: line(s) 4539

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t timer;
    uint8_t output_mode;
} msp2_inav_set_timer_output_mode_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_timer_output_mode_response_payload_t;
```

## MSP2_INAV_MIXER
- MSP frame name: `MSP2_INAV_MIXER`
- MSP frame ID: `8208 (0x2010)`
- Occurrences in file: line(s) 1593

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t mixer_config_motor_direction_inverted;
    uint8_t field;
    uint8_t mixer_config_motorstop_on_low;
    uint8_t mixer_config_platform_type;
    uint8_t mixer_config_has_flaps;
    uint16_t mixer_config_applied_mixer_preset;
    uint8_t max_supported_motors;
    uint8_t max_supported_servos;
} msp2_inav_mixer_response_payload_t;
```

## MSP2_INAV_SET_MIXER
- MSP frame name: `MSP2_INAV_SET_MIXER`
- MSP frame ID: `8209 (0x2011)`
- Occurrences in file: line(s) 3358

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t motor_direction_inverted;
    uint8_t was_yaw_jump_prevention_limit;
    uint8_t motorstop_on_low;
    uint8_t platform_type;
    uint8_t has_flaps;
    uint16_t applied_mixer_preset;
    uint8_t read_and_ignore_max_supported_motors;
    uint8_t read_and_ignore_max_supported_servos;
} msp2_inav_set_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_mixer_response_payload_t;
```

## MSP2_INAV_OSD_LAYOUTS
- MSP frame name: `MSP2_INAV_OSD_LAYOUTS`
- MSP frame ID: `8210 (0x2012)`
- Occurrences in file: line(s) 4149

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t layout;
    uint16_t item;
} msp2_inav_osd_layouts_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t osd_layouts_config_item_pos_layout_item;
    uint16_t osd_layouts_config_item_pos_layout_ii;
    uint8_t osd_layout_count;
    uint8_t osd_item_count;
} msp2_inav_osd_layouts_response_payload_t;
```

## MSP2_INAV_OSD_SET_LAYOUT_ITEM
- MSP frame name: `MSP2_INAV_OSD_SET_LAYOUT_ITEM`
- MSP frame ID: `8211 (0x2013)`
- Occurrences in file: line(s) 3374

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
    uint8_t if_2;
    uint16_t if_sbuf_read_u16_safe_osd_layouts_config_mutable_item_pos_layout_item_src;
} msp2_inav_osd_set_layout_item_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_osd_set_layout_item_response_payload_t;
```

## MSP2_INAV_OSD_ALARMS
- MSP frame name: `MSP2_INAV_OSD_ALARMS`
- MSP frame ID: `8212 (0x2014)`
- Occurrences in file: line(s) 1605

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_osd_alarms_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t osd_config_rssi_alarm;
    uint16_t osd_config_time_alarm;
    uint16_t osd_config_alt_alarm;
    uint16_t osd_config_dist_alarm;
    uint16_t osd_config_neg_alt_alarm;
    uint16_t osd_config_gforce_alarm_1000;
    uint16_t osd_config_gforce_axis_alarm_min_1000;
    uint16_t osd_config_gforce_axis_alarm_max_1000;
    uint8_t osd_config_current_alarm;
    uint16_t osd_config_imu_temp_alarm_min;
    uint16_t osd_config_imu_temp_alarm_max;
    uint16_t osd_config_baro_temp_alarm_min;
    uint16_t osd_config_baro_temp_alarm_max;
    uint16_t field;
    uint16_t field_2;
    uint16_t osd_config_adsb_distance_warning;
    uint16_t osd_config_adsb_distance_alert;
    uint16_t field_3;
    uint16_t field_4;
} msp2_inav_osd_alarms_response_payload_t;
```

## MSP2_INAV_OSD_SET_ALARMS
- MSP frame name: `MSP2_INAV_OSD_SET_ALARMS`
- MSP frame ID: `8213 (0x2015)`
- Occurrences in file: line(s) 3401

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rssi_alarm;
    uint16_t time_alarm;
    uint16_t alt_alarm;
    uint16_t dist_alarm;
    uint16_t neg_alt_alarm;
    uint16_t tmp_u16;
    uint16_t tmp_u16_2;
    uint16_t tmp_u16_3;
    uint8_t current_alarm;
    uint16_t imu_temp_alarm_min;
    uint16_t imu_temp_alarm_max;
    uint16_t baro_temp_alarm_min;
    uint16_t baro_temp_alarm_max;
} msp2_inav_osd_set_alarms_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_osd_set_alarms_response_payload_t;
```

## MSP2_INAV_OSD_PREFERENCES
- MSP frame name: `MSP2_INAV_OSD_PREFERENCES`
- MSP frame ID: `8214 (0x2016)`
- Occurrences in file: line(s) 1633

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_osd_preferences_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t osd_config_video_system;
    uint8_t osd_config_main_voltage_decimals;
    uint8_t osd_config_ahi_reverse_roll;
    uint8_t osd_config_crosshairs_style;
    uint8_t osd_config_left_sidebar_scroll;
    uint8_t osd_config_right_sidebar_scroll;
    uint8_t osd_config_sidebar_scroll_arrows;
    uint8_t osd_config_units;
    uint8_t osd_config_stats_energy_unit;
    uint8_t osd_config_adsb_warning_style;
    uint8_t field;
} msp2_inav_osd_preferences_response_payload_t;
```

## MSP2_INAV_OSD_SET_PREFERENCES
- MSP frame name: `MSP2_INAV_OSD_SET_PREFERENCES`
- MSP frame ID: `8215 (0x2017)`
- Occurrences in file: line(s) 3428

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t video_system;
    uint8_t main_voltage_decimals;
    uint8_t ahi_reverse_roll;
    uint8_t crosshairs_style;
    uint8_t left_sidebar_scroll;
    uint8_t right_sidebar_scroll;
    uint8_t sidebar_scroll_arrows;
    uint8_t units;
    uint8_t stats_energy_unit;
    uint8_t adsb_warning_style;
} msp2_inav_osd_set_preferences_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_osd_set_preferences_response_payload_t;
```

## MSP2_INAV_SELECT_BATTERY_PROFILE
- MSP frame name: `MSP2_INAV_SELECT_BATTERY_PROFILE`
- MSP frame ID: `8216 (0x2018)`
- Occurrences in file: line(s) 3474

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
} msp2_inav_select_battery_profile_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_select_battery_profile_response_payload_t;
```

## MSP2_INAV_DEBUG
- MSP frame name: `MSP2_INAV_DEBUG`
- MSP frame ID: `8217 (0x2019)`
- Occurrences in file: line(s) 1056

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_debug_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t debug;
} msp2_inav_debug_response_payload_t;
```

## MSP2_BLACKBOX_CONFIG
- MSP frame name: `MSP2_BLACKBOX_CONFIG`
- MSP frame ID: `8218 (0x201A)`
- Occurrences in file: line(s) 1230

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_blackbox_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t blackbox_config_device;
    uint16_t blackbox_config_rate_num;
    uint16_t blackbox_config_rate_denom;
    uint32_t blackbox_config_include_flags;
    uint8_t field_2;
    uint8_t field_3;
    uint16_t field_4;
    uint16_t field_5;
} msp2_blackbox_config_response_payload_t;
```

## MSP2_SET_BLACKBOX_CONFIG
- MSP frame name: `MSP2_SET_BLACKBOX_CONFIG`
- MSP frame ID: `8219 (0x201B)`
- Occurrences in file: line(s) 2782

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t device;
    uint16_t rate_num;
    uint16_t rate_denom;
    uint32_t include_flags;
} msp2_set_blackbox_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_set_blackbox_config_response_payload_t;
```

## MSP2_INAV_TEMP_SENSOR_CONFIG
- MSP frame name: `MSP2_INAV_TEMP_SENSOR_CONFIG`
- MSP frame ID: `8220 (0x201C)`
- Occurrences in file: line(s) 1712

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_temp_sensor_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sensor_config_type;
    uint8_t uint8_t_sensor_config_address_addr_index;
    uint16_t sensor_config_alarm_min;
    uint16_t sensor_config_alarm_max;
    uint8_t sensor_config_osd_symbol;
    uint8_t sensor_config_label_label_index;
} msp2_inav_temp_sensor_config_response_payload_t;
```

## MSP2_INAV_SET_TEMP_SENSOR_CONFIG
- MSP frame name: `MSP2_INAV_SET_TEMP_SENSOR_CONFIG`
- MSP frame ID: `8221 (0x201D)`
- Occurrences in file: line(s) 3491

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t type;
    uint8_t uint8_t_sensor_config_address_addr_index_sbuf_read_u8_src;
    uint16_t alarm_min;
    uint16_t alarm_max;
    uint8_t tmp_u8;
    uint8_t sensor_config_label_label_index_toupper_sbuf_read_u8_src;
} msp2_inav_set_temp_sensor_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_temp_sensor_config_response_payload_t;
```

## MSP2_INAV_TEMPERATURES
- MSP frame name: `MSP2_INAV_TEMPERATURES`
- MSP frame ID: `8222 (0x201E)`
- Occurrences in file: line(s) 1728

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_temperatures_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t temperature;
} msp2_inav_temperatures_response_payload_t;
```

## MSP_SIMULATOR
- MSP frame name: `MSP_SIMULATOR`
- MSP frame ID: `8223 (0x201F)`
- Occurrences in file: line(s) 4342

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t tmp_u8;
    uint8_t flags;
    uint8_t fix_type;
    uint8_t num_sat;
    uint32_t lat;
    uint32_t lon;
    uint32_t alt;
    uint16_t ground_speed;
    uint16_t ground_course;
    uint16_t gps_sol_drv_vel_ned_x_int16_t_sbuf_read_u16_src;
    uint16_t gps_sol_drv_vel_ned_y_int16_t_sbuf_read_u16_src;
    uint16_t gps_sol_drv_vel_ned_z_int16_t_sbuf_read_u16_src;
    uint16_t roll;
    uint16_t pitch;
    uint16_t yaw;
    uint16_t acc_ad_cf_x_int16_t_sbuf_read_u16_src_1000_0f;
    uint16_t acc_ad_cf_y_int16_t_sbuf_read_u16_src_1000_0f;
    uint16_t acc_ad_cf_z_int16_t_sbuf_read_u16_src_1000_0f;
    uint16_t gyro_ad_cf_x_int16_t_sbuf_read_u16_src_16_0f;
    uint16_t gyro_ad_cf_y_int16_t_sbuf_read_u16_src_16_0f;
    uint16_t gyro_ad_cf_z_int16_t_sbuf_read_u16_src_16_0f;
    uint32_t baro_pressure;
    uint16_t mag_mag_adc_x_int16_t_sbuf_read_u16_src_20_16000_20_800u_t;
    uint16_t note_that_mag_failure_is_simulated_by_setting_all_readings_to_zero;
    uint16_t mag_mag_adc_z_int16_t_sbuf_read_u16_src_20;
    uint8_t vbat;
    uint16_t air_speed;
    uint16_t sbuf_read_u16;
    uint8_t simulator_data_flags_uint16_t_sbuf_read_u8_src_8;
} msp_simulator_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t simulator_data_input_input_stabilized_roll;
    uint16_t simulator_data_input_input_stabilized_pitch;
    uint16_t simulator_data_input_input_stabilized_yaw;
    uint16_t arming_flag_armed_simulator_data_input_input_stabilized_throttle_500;
    uint8_t tmp_u8;
    uint32_t debug_simulator_data_debug_index;
    uint16_t values_roll;
    uint16_t values_pitch;
    uint16_t values_yaw;
} msp_simulator_response_payload_t;
```

## MSP2_INAV_SERVO_MIXER
- MSP frame name: `MSP2_INAV_SERVO_MIXER`
- MSP frame ID: `8224 (0x2020)`
- Occurrences in file: line(s) 567

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_servo_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t custom_servo_mixers_i_target_channel;
    uint8_t custom_servo_mixers_i_input_source;
    uint16_t custom_servo_mixers_i_rate;
    uint8_t custom_servo_mixers_i_speed;
    uint8_t custom_servo_mixers_i_condition_id;
    uint8_t field;
    uint8_t mixer_servo_mixers_by_index_next_mixer_profile_index_i_target_channel;
    uint8_t mixer_servo_mixers_by_index_next_mixer_profile_index_i_input_source;
    uint16_t mixer_servo_mixers_by_index_next_mixer_profile_index_i_rate;
    uint8_t mixer_servo_mixers_by_index_next_mixer_profile_index_i_speed;
    uint8_t mixer_servo_mixers_by_index_next_mixer_profile_index_i_condition_id;
    uint8_t field_2;
} msp2_inav_servo_mixer_response_payload_t;
```

## MSP2_INAV_SET_SERVO_MIXER
- MSP frame name: `MSP2_INAV_SET_SERVO_MIXER`
- MSP frame ID: `8225 (0x2021)`
- Occurrences in file: line(s) 2358

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t target_channel;
    uint8_t input_source;
    uint16_t rate;
    uint8_t speed;
    uint8_t condition_id;
    uint8_t sbuf_read_u8;
} msp2_inav_set_servo_mixer_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_servo_mixer_response_payload_t;
```

## MSP2_INAV_LOGIC_CONDITIONS
- MSP frame name: `MSP2_INAV_LOGIC_CONDITIONS`
- MSP frame ID: `8226 (0x2022)`
- Occurrences in file: line(s) 593

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_logic_conditions_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_logic_conditions_response_payload_t;
```

## MSP2_INAV_SET_LOGIC_CONDITIONS
- MSP frame name: `MSP2_INAV_SET_LOGIC_CONDITIONS`
- MSP frame ID: `8227 (0x2023)`
- Occurrences in file: line(s) 2375

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t enabled;
    uint8_t activator_id;
    uint8_t operation;
    uint8_t type;
    uint32_t value;
    uint8_t type_2;
    uint32_t value_2;
    uint8_t flags;
} msp2_inav_set_logic_conditions_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_logic_conditions_response_payload_t;
```

## MSP2_INAV_LOGIC_CONDITIONS_STATUS
- MSP frame name: `MSP2_INAV_LOGIC_CONDITIONS_STATUS`
- MSP frame ID: `8230 (0x2026)`
- Occurrences in file: line(s) 595

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_logic_conditions_status_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t logic_condition_get_value;
} msp2_inav_logic_conditions_status_response_payload_t;
```

## MSP2_INAV_GVAR_STATUS
- MSP frame name: `MSP2_INAV_GVAR_STATUS`
- MSP frame ID: `8231 (0x2027)`
- Occurrences in file: line(s) 623

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_gvar_status_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t gv_get;
} msp2_inav_gvar_status_response_payload_t;
```

## MSP2_INAV_PROGRAMMING_PID
- MSP frame name: `MSP2_INAV_PROGRAMMING_PID`
- MSP frame ID: `8232 (0x2028)`
- Occurrences in file: line(s) 628

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_programming_pid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t programming_pids_i_enabled;
    uint8_t setpoint_type;
    uint32_t setpoint_value;
    uint8_t measurement_type;
    uint32_t measurement_value;
    uint16_t gains_p;
    uint16_t gains_i;
    uint16_t gains_d;
    uint16_t gains_ff;
} msp2_inav_programming_pid_response_payload_t;
```

## MSP2_INAV_SET_PROGRAMMING_PID
- MSP frame name: `MSP2_INAV_SET_PROGRAMMING_PID`
- MSP frame ID: `8233 (0x2029)`
- Occurrences in file: line(s) 2390

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t enabled;
    uint8_t type;
    uint32_t value;
    uint8_t type_2;
    uint32_t value_2;
    uint16_t p;
    uint16_t i;
    uint16_t d;
    uint16_t ff;
} msp2_inav_set_programming_pid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_programming_pid_response_payload_t;
```

## MSP2_INAV_PROGRAMMING_PID_STATUS
- MSP frame name: `MSP2_INAV_PROGRAMMING_PID_STATUS`
- MSP frame ID: `8234 (0x202A)`
- Occurrences in file: line(s) 641

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_programming_pid_status_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t programming_pid_get_output;
} msp2_inav_programming_pid_status_response_payload_t;
```

## MSP2_PID
- MSP frame name: `MSP2_PID`
- MSP frame ID: `8240 (0x2030)`
- Occurrences in file: line(s) 785

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_pid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t pid_i_p_0_255;
    uint8_t pid_i_i_0_255;
    uint8_t pid_i_d_0_255;
    uint8_t pid_i_ff_0_255;
} msp2_pid_response_payload_t;
```

## MSP2_SET_PID
- MSP frame name: `MSP2_SET_PID`
- MSP frame ID: `8241 (0x2031)`
- Occurrences in file: line(s) 2008

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t p;
    uint8_t i;
    uint8_t d;
    uint8_t ff;
} msp2_set_pid_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_set_pid_response_payload_t;
```

## MSP2_INAV_OPFLOW_CALIBRATION
- MSP frame name: `MSP2_INAV_OPFLOW_CALIBRATION`
- MSP frame ID: `8242 (0x2032)`
- Occurrences in file: line(s) 2763

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_opflow_calibration_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_opflow_calibration_response_payload_t;
```

## MSP2_INAV_FWUPDT_PREPARE
- MSP frame name: `MSP2_INAV_FWUPDT_PREPARE`
- MSP frame ID: `8243 (0x2033)`
- Occurrences in file: line(s) 3511

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t if;
} msp2_inav_fwupdt_prepare_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_prepare_response_payload_t;
```

## MSP2_INAV_FWUPDT_STORE
- MSP frame name: `MSP2_INAV_FWUPDT_STORE`
- MSP frame ID: `8244 (0x2034)`
- Occurrences in file: line(s) 3516

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_store_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_store_response_payload_t;
```

## MSP2_INAV_FWUPDT_EXEC
- MSP frame name: `MSP2_INAV_FWUPDT_EXEC`
- MSP frame ID: `8245 (0x2035)`
- Occurrences in file: line(s) 3521

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t firmware_update_exec;
} msp2_inav_fwupdt_exec_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_exec_response_payload_t;
```

## MSP2_INAV_FWUPDT_ROLLBACK_PREPARE
- MSP frame name: `MSP2_INAV_FWUPDT_ROLLBACK_PREPARE`
- MSP frame ID: `8246 (0x2036)`
- Occurrences in file: line(s) 3525

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_rollback_prepare_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_rollback_prepare_response_payload_t;
```

## MSP2_INAV_FWUPDT_ROLLBACK_EXEC
- MSP frame name: `MSP2_INAV_FWUPDT_ROLLBACK_EXEC`
- MSP frame ID: `8247 (0x2037)`
- Occurrences in file: line(s) 3530

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_rollback_exec_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fwupdt_rollback_exec_response_payload_t;
```

## MSP2_INAV_SAFEHOME
- MSP frame name: `MSP2_INAV_SAFEHOME`
- MSP frame ID: `8248 (0x2038)`
- Occurrences in file: line(s) 4203

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_safehome_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_safehome_response_payload_t;
```

## MSP2_INAV_SET_SAFEHOME
- MSP frame name: `MSP2_INAV_SET_SAFEHOME`
- MSP frame ID: `8249 (0x2039)`
- Occurrences in file: line(s) 3536

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
    uint8_t enabled;
    uint32_t lat;
    uint32_t lon;
} msp2_inav_set_safehome_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_safehome_response_payload_t;
```

## MSP2_INAV_MISC2
- MSP frame name: `MSP2_INAV_MISC2`
- MSP frame ID: `8250 (0x203A)`
- Occurrences in file: line(s) 927

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_misc2_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t micros;
    uint32_t flight_time;
    uint8_t throttle_percent;
    uint8_t navigation_is_controlling_throttle;
} msp2_inav_misc2_response_payload_t;
```

## MSP2_INAV_LOGIC_CONDITIONS_SINGLE
- MSP frame name: `MSP2_INAV_LOGIC_CONDITIONS_SINGLE`
- MSP frame ID: `8251 (0x203B)`
- Occurrences in file: line(s) 4180

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_logic_conditions_single_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_logic_conditions_single_response_payload_t;
```

## MSP2_INAV_LOGIC_CONDITIONS_CONFIGURED
- MSP frame name: `MSP2_INAV_LOGIC_CONDITIONS_CONFIGURED`
- MSP frame ID: `8252 (0x203C)`
- Occurrences in file: line(s) 600

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_logic_conditions_configured_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t x_ffffffff;
    uint32_t x_ffffffff_2;
} msp2_inav_logic_conditions_configured_response_payload_t;
```

## MSP2_INAV_ESC_RPM
- MSP frame name: `MSP2_INAV_ESC_RPM`
- MSP frame ID: `8256 (0x2040)`
- Occurrences in file: line(s) 1738

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_esc_rpm_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t esc_state_rpm;
} msp2_inav_esc_rpm_response_payload_t;
```

## MSP2_INAV_ESC_TELEM
- MSP frame name: `MSP2_INAV_ESC_TELEM`
- MSP frame ID: `8257 (0x2041)`
- Occurrences in file: line(s) 1749

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_esc_telem_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t motor_count;
    uint8_t field_bytes[];
} msp2_inav_esc_telem_response_payload_t;
```

## MSP2_INAV_LED_STRIP_CONFIG_EX
- MSP frame name: `MSP2_INAV_LED_STRIP_CONFIG_EX`
- MSP frame ID: `8264 (0x2048)`
- Occurrences in file: line(s) 1194

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_led_strip_config_ex_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field_bytes[];
} msp2_inav_led_strip_config_ex_response_payload_t;
```

## MSP2_INAV_SET_LED_STRIP_CONFIG_EX
- MSP frame name: `MSP2_INAV_SET_LED_STRIP_CONFIG_EX`
- MSP frame ID: `8265 (0x2049)`
- Occurrences in file: line(s) 3273

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t tmp_u8;
} msp2_inav_set_led_strip_config_ex_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_led_strip_config_ex_response_payload_t;
```

## MSP2_INAV_FW_APPROACH
- MSP frame name: `MSP2_INAV_FW_APPROACH`
- MSP frame ID: `8266 (0x204A)`
- Occurrences in file: line(s) 4208

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fw_approach_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_fw_approach_response_payload_t;
```

## MSP2_INAV_SET_FW_APPROACH
- MSP frame name: `MSP2_INAV_SET_FW_APPROACH`
- MSP frame ID: `8267 (0x204B)`
- Occurrences in file: line(s) 3555

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
    uint32_t approach_alt;
    uint32_t land_alt;
    uint8_t approach_direction;
    uint8_t is_sea_level_ref;
} msp2_inav_set_fw_approach_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_fw_approach_response_payload_t;
```

## MSP2_INAV_GPS_UBLOX_COMMAND
- MSP frame name: `MSP2_INAV_GPS_UBLOX_COMMAND`
- MSP frame ID: `8272 (0x2050)`
- Occurrences in file: line(s) 3578

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_gps_ublox_command_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_gps_ublox_command_response_payload_t;
```

## MSP2_INAV_RATE_DYNAMICS
- MSP frame name: `MSP2_INAV_RATE_DYNAMICS`
- MSP frame ID: `8288 (0x2060)`
- Occurrences in file: line(s) 1782

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_rate_dynamics_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t rate_dynamics_sensitivity_center;
    uint8_t rate_dynamics_sensitivity_end;
    uint8_t rate_dynamics_correction_center;
    uint8_t rate_dynamics_correction_end;
    uint8_t rate_dynamics_weight_center;
    uint8_t rate_dynamics_weight_end;
} msp2_inav_rate_dynamics_response_payload_t;
```

## MSP2_INAV_SET_RATE_DYNAMICS
- MSP frame name: `MSP2_INAV_SET_RATE_DYNAMICS`
- MSP frame ID: `8289 (0x2061)`
- Occurrences in file: line(s) 3660

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sensitivity_center;
    uint8_t sensitivity_end;
    uint8_t correction_center;
    uint8_t correction_end;
    uint8_t weight_center;
    uint8_t weight_end;
} msp2_inav_set_rate_dynamics_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_rate_dynamics_response_payload_t;
```

## MSP2_INAV_EZ_TUNE
- MSP frame name: `MSP2_INAV_EZ_TUNE`
- MSP frame ID: `8304 (0x2070)`
- Occurrences in file: line(s) 1764

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_ez_tune_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t ez_tune_enabled;
    uint16_t ez_tune_filter_hz;
    uint8_t ez_tune_axis_ratio;
    uint8_t ez_tune_response;
    uint8_t ez_tune_damping;
    uint8_t ez_tune_stability;
    uint8_t ez_tune_aggressiveness;
    uint8_t ez_tune_rate;
    uint8_t ez_tune_expo;
    uint8_t ez_tune_snappiness;
} msp2_inav_ez_tune_response_payload_t;
```

## MSP2_INAV_EZ_TUNE_SET
- MSP frame name: `MSP2_INAV_EZ_TUNE_SET`
- MSP frame ID: `8305 (0x2071)`
- Occurrences in file: line(s) 3632

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t enabled;
    uint16_t filter_hz;
    uint8_t axis_ratio;
    uint8_t response;
    uint8_t damping;
    uint8_t stability;
    uint8_t aggressiveness;
    uint8_t rate;
    uint8_t expo;
    uint8_t snappiness;
} msp2_inav_ez_tune_set_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_ez_tune_set_response_payload_t;
```

## MSP2_INAV_SELECT_MIXER_PROFILE
- MSP frame name: `MSP2_INAV_SELECT_MIXER_PROFILE`
- MSP frame ID: `8320 (0x2080)`
- Occurrences in file: line(s) 3482

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
} msp2_inav_select_mixer_profile_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_select_mixer_profile_response_payload_t;
```

## MSP2_ADSB_VEHICLE_LIST
- MSP frame name: `MSP2_ADSB_VEHICLE_LIST`
- MSP frame ID: `8336 (0x2090)`
- Occurrences in file: line(s) 1016

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_adsb_vehicle_list_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t max_adsb_vehicles;
    uint8_t adsb_call_sign_max_length;
    uint32_t get_adsb_status_vehicles_messages_total;
    uint32_t get_adsb_status_heartbeat_messages_total;
    uint8_t vehicle_values_callsign_ii;
    uint32_t vehicle_values_icao;
    uint32_t gps_lat;
    uint32_t gps_lon;
    uint32_t vehicle_values_alt;
    uint16_t vehicle_values_heading;
    uint8_t vehicle_values_tslc;
    uint8_t vehicle_values_emitter_type;
    uint8_t adsb_vehicle_ttl;
    uint8_t field;
    uint8_t field_2;
    uint32_t field_3;
    uint32_t field_4;
} msp2_adsb_vehicle_list_response_payload_t;
```

## MSP2_INAV_CUSTOM_OSD_ELEMENTS
- MSP frame name: `MSP2_INAV_CUSTOM_OSD_ELEMENTS`
- MSP frame ID: `8448 (0x2100)`
- Occurrences in file: line(s) 1795

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_custom_osd_elements_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t max_custom_elements;
    uint8_t osd_custom_element_text_size;
    uint8_t custom_elements_parts;
} msp2_inav_custom_osd_elements_response_payload_t;
```

## MSP2_INAV_CUSTOM_OSD_ELEMENT
- MSP frame name: `MSP2_INAV_CUSTOM_OSD_ELEMENT`
- MSP frame ID: `8449 (0x2101)`
- Occurrences in file: line(s) 4183

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t idx;
} msp2_inav_custom_osd_element_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t part_ii_type;
    uint16_t part_ii_value;
    uint8_t visibility_type;
    uint16_t visibility_value;
    uint8_t custom_element_osd_custom_element_text_ii;
} msp2_inav_custom_osd_element_response_payload_t;
```

## MSP2_INAV_SET_CUSTOM_OSD_ELEMENTS
- MSP frame name: `MSP2_INAV_SET_CUSTOM_OSD_ELEMENTS`
- MSP frame ID: `8450 (0x2102)`
- Occurrences in file: line(s) 3678

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint8_t type;
    uint16_t value;
    uint8_t type_2;
    uint16_t value_2;
    uint8_t osd_custom_elements_mutable_tmp_u8_osd_custom_element_text_i_sbuf_read_u8_src;
} msp2_inav_set_custom_osd_elements_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_custom_osd_elements_response_payload_t;
```

## MSP2_INAV_OUTPUT_MAPPING_EXT2
- MSP frame name: `MSP2_INAV_OUTPUT_MAPPING_EXT2`
- MSP frame ID: `8461 (0x210D)`
- Occurrences in file: line(s) 1672

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_output_mapping_ext2_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t field;
    uint8_t timer2id_timer_hardware_i_tim;
    uint32_t timer_hardware_i_usage_flags;
    uint8_t field_2;
    uint8_t timer_hardware_i_tag_led_tag_pin_label_led_pin_label_none;
} msp2_inav_output_mapping_ext2_response_payload_t;
```

## MSP2_INAV_OSD_UPDATE_POSITION
- MSP frame name: `MSP2_INAV_OSD_UPDATE_POSITION`
- MSP frame ID: `8472 (0x2118)`
- Occurrences in file: line(s) 2825

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t sbuf_read_u8_safe;
    uint16_t pos;
} msp2_inav_osd_update_position_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_osd_update_position_response_payload_t;
```

## MSP2_INAV_SERVO_CONFIG
- MSP frame name: `MSP2_INAV_SERVO_CONFIG`
- MSP frame ID: `8704 (0x2200)`
- Occurrences in file: line(s) 548

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_servo_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t servo_params_i;
    uint16_t servo_params_i_2;
    uint16_t servo_params_i_middle;
    uint8_t servo_params_i_rate;
} msp2_inav_servo_config_response_payload_t;
```

## MSP2_INAV_SET_SERVO_CONFIG
- MSP frame name: `MSP2_INAV_SET_SERVO_CONFIG`
- MSP frame ID: `8705 (0x2201)`
- Occurrences in file: line(s) 2328

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t tmp_u8;
    uint16_t min;
    uint16_t max;
    uint16_t middle;
    uint8_t rate;
} msp2_inav_set_servo_config_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_servo_config_response_payload_t;
```

## MSP2_INAV_GEOZONE
- MSP frame name: `MSP2_INAV_GEOZONE`
- MSP frame ID: `8720 (0x2210)`
- Occurrences in file: line(s) 4213

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_geozone_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_geozone_response_payload_t;
```

## MSP2_INAV_SET_GEOZONE
- MSP frame name: `MSP2_INAV_SET_GEOZONE`
- MSP frame ID: `8721 (0x2211)`
- Occurrences in file: line(s) 3587

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
    uint8_t type;
    uint8_t shape;
    uint32_t min_altitude;
    uint32_t max_altitude;
    uint8_t is_sealevel_ref;
    uint8_t fence_action;
    uint8_t vertex_count;
} msp2_inav_set_geozone_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_geozone_response_payload_t;
```

## MSP2_INAV_GEOZONE_VERTEX
- MSP frame name: `MSP2_INAV_GEOZONE_VERTEX`
- MSP frame ID: `8722 (0x2212)`
- Occurrences in file: line(s) 4216

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_geozone_vertex_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_geozone_vertex_response_payload_t;
```

## MSP2_INAV_SET_GEOZONE_VERTEX
- MSP frame name: `MSP2_INAV_SET_GEOZONE_VERTEX`
- MSP frame ID: `8723 (0x2213)`
- Occurrences in file: line(s) 3606

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
    uint8_t vertex_id;
    uint32_t lat;
    uint32_t lon;
    uint32_t if_2;
} msp2_inav_set_geozone_vertex_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_geozone_vertex_response_payload_t;
```

## MSP2_INAV_SET_GVAR
- MSP frame name: `MSP2_INAV_SET_GVAR`
- MSP frame ID: `8724 (0x2214)`
- Occurrences in file: line(s) 2406

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
    uint32_t gvar_value;
} msp2_inav_set_gvar_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_gvar_response_payload_t;
```

## MSP2_INAV_SET_ALT_TARGET
- MSP frame name: `MSP2_INAV_SET_ALT_TARGET`
- MSP frame ID: `8725 (0x2215)`
- Occurrences in file: line(s) 4222

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t if;
    uint32_t if_2;
} msp2_inav_set_alt_target_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_alt_target_response_payload_t;
```

## MSP2_INAV_FLIGHT_AXIS_ANGLE_OVERRIDE
- MSP frame name: `MSP2_INAV_FLIGHT_AXIS_ANGLE_OVERRIDE`
- MSP frame ID: `8726 (0x2216)`
- Occurrences in file: line(s) 2424

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t override_mask;
    uint16_t roll_target;
    uint16_t pitch_target;
    uint16_t yaw_target;
} msp2_inav_flight_axis_angle_override_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_flight_axis_angle_override_response_payload_t;
```

## MSP2_INAV_FLIGHT_AXIS_RATE_OVERRIDE
- MSP frame name: `MSP2_INAV_FLIGHT_AXIS_RATE_OVERRIDE`
- MSP frame ID: `8727 (0x2217)`
- Occurrences in file: line(s) 2437

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint8_t override_mask;
    uint16_t roll_target;
    uint16_t pitch_target;
    uint16_t yaw_target;
} msp2_inav_flight_axis_rate_override_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_flight_axis_rate_override_response_payload_t;
```

## MSP2_INAV_SET_LOCAL_TARGET
- MSP frame name: `MSP2_INAV_SET_LOCAL_TARGET`
- MSP frame ID: `8728 (0x2218)`
- Occurrences in file: line(s) 4237

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t offset_body_x;
    uint32_t offset_body_y;
    uint32_t offset_body_z;
} msp2_inav_set_local_target_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_local_target_response_payload_t;
```

## MSP2_INAV_LOCAL_TARGET
- MSP frame name: `MSP2_INAV_LOCAL_TARGET`
- MSP frame ID: `8729 (0x2219)`
- Occurrences in file: line(s) 4272

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_local_target_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t pos_x;
    uint32_t pos_y;
    uint32_t pos_z;
    uint16_t vel_x;
    uint16_t vel_y;
    uint16_t vel_z;
    uint32_t desired_state_yaw;
    uint16_t desired_state_climb_rate_demand;
} msp2_inav_local_target_response_payload_t;
```

## MSP2_INAV_SET_GLOBAL_TARGET
- MSP frame name: `MSP2_INAV_SET_GLOBAL_TARGET`
- MSP frame ID: `8730 (0x221A)`
- Occurrences in file: line(s) 4284

Request payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t lat;
    uint32_t lon;
    uint32_t alt;
    uint8_t datum_flag;
} msp2_inav_set_global_target_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_set_global_target_response_payload_t;
```

## MSP2_INAV_NAV_TARGET
- MSP frame name: `MSP2_INAV_NAV_TARGET`
- MSP frame ID: `8731 (0x221B)`
- Occurrences in file: line(s) 4320

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_nav_target_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint32_t target_llh_lat;
    uint32_t target_llh_lon;
    uint32_t pos_z;
    uint16_t heading_target;
    uint16_t desired_state_climb_rate_demand;
} msp2_inav_nav_target_response_payload_t;
```

## MSP2_INAV_FULL_LOCAL_POSE
- MSP frame name: `MSP2_INAV_FULL_LOCAL_POSE`
- MSP frame ID: `8736 (0x2220)`
- Occurrences in file: line(s) 691

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_inav_full_local_pose_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    uint16_t values_roll;
    uint16_t values_pitch;
    uint16_t values_yaw;
    uint32_t pos_v_axis;
    uint16_t vel_v_axis;
} msp2_inav_full_local_pose_response_payload_t;
```

## MSP2_BETAFLIGHT_BIND
- MSP frame name: `MSP2_BETAFLIGHT_BIND`
- MSP frame ID: `12288 (0x3000)`
- Occurrences in file: line(s) 3701

Request payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_betaflight_bind_request_payload_t;
```

Response payload:
```c
typedef struct __attribute__((packed)) {
    /* no direct sbufRead/sbufWrite fields in this file path */
} msp2_betaflight_bind_response_payload_t;
```

