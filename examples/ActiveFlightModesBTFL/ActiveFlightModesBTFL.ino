/*
  ActiveFlightModesBTFL.ino

  Queries MSP_STATUS_EX (frame 150) from a connected Betaflight flight
  controller and prints the names of all currently active flight modes
  to the USB serial monitor every 500 ms.

  Betaflight has no dedicated ACTIVEBOXES command. Flight mode bits are
  packed inside MSP_STATUS_EX; 

  Bit positions in the bitmap are FC-specific; BTFL_MSP_BOXIDS (frame 119)
  is queried first to build the actual bit→permanentId mapping.

  Wiring:
    FC TX  →  board RX1
    FC RX  →  board TX1
    GND    →  GND

  The FC serial port must have MSP enabled (not CLI or telemetry).
*/

#include <msp_btfl.h>

// Adjust to match your wiring
#define FC_RX_PIN 10  // ESP32C3 pin connected to FC TX
#define FC_TX_PIN 8   // ESP32C3 pin connected to FC RX

MspBTFL msp;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, FC_RX_PIN, FC_TX_PIN);
  msp.begin(Serial1, 500);     // 500 ms timeout

  // Box ID list is FC-specific; fetch it first so we can interpret the bitmap.
  while (!msp.loadBoxIds()) {
    Serial.println("BOXIDS request failed, retrying...");
    delay(500);
  }
  Serial.println("BOXIDS loaded");
}

void loop()
{
  if (!msp.loadActiveFlightModes()) {
    Serial.println("MSP_STATUS_EX request failed");
    delay(500);
    return;
  }

  Serial.print("Active modes: ");
  bool anyActive = false;

  for (uint8_t i = 0; i < BTFL_MODE_DEFS_COUNT; i++) {
    if (msp.isFlightModeActive(BTFL_MODE_DEFS[i].permanentId)) {
      if (anyActive) Serial.print(", ");
      Serial.print(BTFL_MODE_DEFS[i].name);
      anyActive = true;
    }
  }

  if (!anyActive) Serial.print("none");
  Serial.println();

  delay(500);
}
