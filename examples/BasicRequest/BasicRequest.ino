/*
  BasicRequest.ino

  Demonstrates using ApexMSP to query attitude, GPS, and analog data
  from an INAV flight controller over a hardware serial port.

  Wiring (example — adjust pins for your board):
    FC TX  →  board RX1
    FC RX  →  board TX1
    GND    →  GND

  The FC serial port must have MSP enabled (not CLI or telemetry).
*/

#include <msp.h>
#include <msp_inav.h>

MSP msp;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);          // serial port connected to FC
  msp.begin(Serial1, 500);        // 500 ms timeout
}

void loop()
{
  // --- Attitude ---
  INAV_msp_attitude_t att;
  if (msp.request(INAV_MSP_ATTITUDE, &att, sizeof(att))) {
    Serial.print("Roll: ");   Serial.print(att.roll  / 10.0f, 1);
    Serial.print("  Pitch: "); Serial.print(att.pitch / 10.0f, 1);
    Serial.print("  Yaw: ");   Serial.println(att.yaw);
  }

  // --- GPS ---
  INAV_msp_raw_gps_t gps;
  if (msp.request(INAV_MSP_RAW_GPS, &gps, sizeof(gps))) {
    const char* fixStr = (gps.fixType == INAV_MSP_GPS_FIX_3D) ? "3D" :
                         (gps.fixType == INAV_MSP_GPS_FIX_2D) ? "2D" : "none";
    Serial.print("GPS fix: "); Serial.print(fixStr);
    Serial.print("  Sats: ");  Serial.print(gps.numSat);
    Serial.print("  Lat: ");   Serial.print(gps.lat / 10000000.0, 6);
    Serial.print("  Lon: ");   Serial.println(gps.lon / 10000000.0, 6);
  }

  // --- Battery ---
  INAV_msp_analog_t analog;
  if (msp.request(INAV_MSP_ANALOG, &analog, sizeof(analog))) {
    Serial.print("Vbat: "); Serial.print(analog.vbat / 10.0f, 1);
    Serial.print(" V  mAh drawn: "); Serial.println(analog.mAhDrawn);
  }

  // --- Active flight modes ---
  uint32_t modes = 0;
  if (msp.getActiveModes(&modes)) {
    Serial.print("Armed: ");    Serial.print((modes >> INAV_MSP_MODE_ARM)   & 1);
    Serial.print("  Angle: ");  Serial.print((modes >> INAV_MSP_MODE_ANGLE) & 1);
    Serial.print("  RTH: ");    Serial.println((modes >> INAV_MSP_MODE_NAVRTH) & 1);
  }

  Serial.println("---");
  delay(500);
}
