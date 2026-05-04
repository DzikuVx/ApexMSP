/*
  ActiveFlightModesINAV.ino

  Queries INAV_MSP_ACTIVEBOXES (frame 113) from a connected INAV flight
  controller and prints the names of all currently active flight modes
  to the USB serial monitor every 500 ms.

  Bit positions in the ACTIVEBOXES bitmap are FC-specific; INAV_MSP_BOXIDS
  (frame 119) is queried first to build the actual bit→permanentId mapping.

  Wiring:
    FC TX  →  board RX1
    FC RX  →  board TX1
    GND    →  GND

  The FC serial port must have MSP enabled (not CLI or telemetry).
*/

#include <msp_inav.h>

// Adjust to match your wiring
#define FC_RX_PIN 10  // ESP32C3 pin connected to FC TX
#define FC_TX_PIN 8   // ESP32C3 pin connected to FC RX

MspINAV msp;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, FC_RX_PIN, FC_TX_PIN);
  msp.begin(Serial1, 500);     // 500 ms timeout

  // List of mode IDs is dynamic; fetch it from the FC first.
  // We need it to interpret the ACTIVEBOXES bitmap.
  while (!msp.loadBoxIds()) {
    Serial.println("BOXIDS request failed, retrying...");
    delay(500);
  }
  Serial.println("BOXIDS loaded");
}

void loop()
{
  if (!msp.loadActiveFlightModes()) {
    Serial.println("ACTIVEBOXES request failed");
    delay(500);
    return;
  }

  Serial.print("Active modes: ");
  bool anyActive = false;

  for (uint8_t i = 0; i < INAV_MODE_DEFS_COUNT; i++) {
    if (msp.isFlightModeActive(INAV_MODE_DEFS[i].permanentId)) {
      if (anyActive) Serial.print(", ");
      Serial.print(INAV_MODE_DEFS[i].name);
      anyActive = true;
    }
  }

  if (!anyActive) Serial.print("none");
  Serial.println();

  delay(500);
}
