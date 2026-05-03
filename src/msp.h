/*
  MSP.h

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
#pragma once

#include <Arduino.h>
#include <Stream.h>

// MSP2 header size (without payload)
#define MSP2_HEADER_SIZE 9

typedef struct {
    uint8_t permanentId;
    uint8_t boxId;
    const char *name;
} flight_mode_definition_t;

class MSP {

  public:

    void begin(Stream & stream, uint32_t timeout = 500);
    void send(uint16_t messageID, void * payload, uint16_t size);
    bool recv(uint16_t *messageID, void * payload, uint16_t maxSize, uint16_t *recvSize);
    bool waitFor(uint16_t messageID, void * payload, uint16_t maxSize, uint16_t *recvSize = NULL);
    bool request(uint16_t messageID, void * payload, uint16_t maxSize, uint16_t *recvSize = NULL);
    bool command(uint16_t messageID, void * payload, uint16_t size, bool waitACK = true);
    void reset();
    bool getActiveModes(uint32_t * activeModes);
    static bool checkFlightMode(const flight_mode_definition_t *defs, uint8_t defCount, const uint8_t bitmap[8], uint8_t permanentId);
    
  private:
  
    Stream * _stream;
    uint32_t _timeout;
    
};

