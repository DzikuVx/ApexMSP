#include <msp_inav.h>

#define FC_RX_PIN 10
#define FC_TX_PIN 8

MspINAV msp;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, FC_RX_PIN, FC_TX_PIN);
  msp.begin(Serial1, 500);
}

void loop() {
  INAV_msp2_inav_status_t status;
  uint16_t recvSize = 0;

  if (!msp.request(INAV_MSP2_INAV_STATUS, &status, sizeof(status), &recvSize)) {
    Serial.println("Request failed");
    delay(500);
    return;
  }

  Serial.printf("recvSize             : %u\n",   recvSize);
  Serial.printf("cycleTime            : %u\n",   status.cycleTime);
  Serial.printf("i2cErrorCounter      : %u\n",   status.i2cErrorCounter);
  Serial.printf("sensorStatus         : 0x%04X\n", status.sensorStatus);
  Serial.printf("averageSystemLoad    : %u%%\n", status.averageSystemLoadPercent);
  Serial.printf("configProfileIndex   : %u\n",   status.configProfileIndex);
  Serial.printf("armingFlags          : 0x%08X\n", status.armingFlags);
  Serial.printf("configMixerProfile   : %u\n",   status.configMixerProfile);

  Serial.print("modeFlags            : ");
  for (int i = 0; i < 8; i++)
    Serial.printf("%02X ", status.msp_box_mode_flags_bytes[i]);
  Serial.println();
  Serial.println("---");

  delay(1000);
}
