/*
  MSP.cpp

  Copyright (c) 2017, Fabrizio Di Vittorio (fdivitto2013@gmail.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>

#include "msp.h"
#include "crc.h"
#include "msp_inav.h"

void MSP::begin(Stream &stream, uint32_t timeout)
{
  _stream = &stream;
  _timeout = timeout;
}

void MSP::reset()
{
  _stream->flush();
  while (_stream->available() > 0)
    _stream->read();
}

void MSP::send(uint16_t messageID, void *payload, uint16_t size)
{
  uint8_t flag = 0;
  int msg_size = MSP2_HEADER_SIZE;
  uint8_t crc = 0;
  uint8_t tmp_buf[2];

  msg_size += (int)size;

  _stream->write('$');
  _stream->write('X');
  _stream->write('<');

  crc = crc8_dvb_s2(crc, flag);
  _stream->write(flag);

  memcpy(tmp_buf, &messageID, 2);
  crc = crc8_dvb_s2(crc, tmp_buf[0]);
  crc = crc8_dvb_s2(crc, tmp_buf[1]);
  _stream->write(tmp_buf, 2);

  memcpy(tmp_buf, &size, 2);
  crc = crc8_dvb_s2(crc, tmp_buf[0]);
  crc = crc8_dvb_s2(crc, tmp_buf[1]);
  _stream->write(tmp_buf, 2);

  uint8_t *payloadPtr = (uint8_t *)payload;
  for (uint8_t i = 0; i < size; ++i)
  {
    uint8_t b = *(payloadPtr++);
    crc = crc8_dvb_s2(crc, b);
    _stream->write(b);
  }

  _stream->write(crc);
}

bool MSP::recv(uint16_t *messageID, void *payload, uint16_t maxSize, uint16_t *recvSize)
{
  uint32_t t0 = millis();
  uint8_t tmp_buf[2];

  while (1)
  {

    // read header
    while (_stream->available() < 6)
      if (millis() - t0 >= _timeout)
      {
        return false;
      }
    char header[3];
    _stream->readBytes((char *)header, 3);

    // check header
    if (header[0] == '$' && header[1] == 'X' && header[2] == '>')
    {
      uint8_t flag = _stream->read();
      uint8_t checksumCalc = 0;
      checksumCalc = crc8_dvb_s2(checksumCalc, flag);
      // read message ID (type)
      _stream->readBytes((char *)(messageID), 2);
      memcpy(&tmp_buf[0], messageID, 2);
      checksumCalc = crc8_dvb_s2(checksumCalc, tmp_buf[0]);
      checksumCalc = crc8_dvb_s2(checksumCalc, tmp_buf[1]);

      // header ok, read payload size
      _stream->readBytes((char *)(recvSize), 2);
      memcpy(&tmp_buf[0], recvSize, 2);
      checksumCalc = crc8_dvb_s2(checksumCalc, tmp_buf[0]);
      checksumCalc = crc8_dvb_s2(checksumCalc, tmp_buf[1]);

      // read payload
      uint8_t *payloadPtr = (uint8_t *)payload;
      uint16_t idx = 0;
      while (idx < *recvSize)
      {
        if (millis() - t0 >= _timeout)
        {
          return false;
        }
        if (_stream->available() > 0)
        {
          uint8_t b = _stream->read();
          checksumCalc = crc8_dvb_s2(checksumCalc, b);
          if (idx < maxSize)
            *(payloadPtr++) = b;
          ++idx;
        }
      }
      // zero remaining bytes if *size < maxSize
      for (; idx < maxSize; ++idx)
        *(payloadPtr++) = 0;

      // read and check checksum
      while (_stream->available() == 0)
        if (millis() - t0 >= _timeout)
        {
          return false;
        }
      uint8_t checksum = _stream->read();
      if (checksumCalc == checksum)
      {
        return true;
      }
    }
  }
}

// wait for messageID
// recvSize can be NULL
bool MSP::waitFor(uint16_t messageID, void *payload, uint16_t maxSize, uint16_t *recvSize)
{
  uint16_t recvMessageID;
  uint16_t recvSizeValue;
  uint32_t t0 = millis();
  while (millis() - t0 < _timeout)
    if (recv(&recvMessageID, payload, maxSize, (recvSize ? recvSize : &recvSizeValue)) && messageID == recvMessageID)
      return true;

  // timeout
  return false;
}

// send a message and wait for the reply
// recvSize can be NULL
bool MSP::request(uint16_t messageID, void *payload, uint16_t maxSize, uint16_t *recvSize)
{
  send(messageID, NULL, 0);
  return waitFor(messageID, payload, maxSize, recvSize);
}

// send message and wait for ack
bool MSP::command(uint16_t messageID, void *payload, uint16_t size, bool waitACK)
{
  send(messageID, payload, size);

  // ack required
  if (waitACK)
    return waitFor(messageID, NULL, 0);

  return true;
}

bool MSP::checkFlightMode(const uint8_t *boxIdMap, uint8_t boxIdCount, const uint8_t bitmap[8], uint8_t permanentId)
{
  for (uint8_t bit = 0; bit < boxIdCount; bit++) {
    if (boxIdMap[bit] == permanentId) {
      return (bitmap[bit >> 3] & (uint8_t)(1u << (bit & 7))) != 0;
    }
  }
  return false;
}
