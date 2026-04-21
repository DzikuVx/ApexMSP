/*
  crc.h - CRC-8/DVB-S2 used by MSP v2 framing.
*/

#pragma once

#include <stdint.h>

static inline uint8_t crc8_dvb_s2(uint8_t crc, uint8_t a)
{
  crc ^= a;
  for (int i = 0; i < 8; ++i) {
    if (crc & 0x80)
      crc = (crc << 1) ^ 0xD5;
    else
      crc <<= 1;
  }
  return crc;
}
