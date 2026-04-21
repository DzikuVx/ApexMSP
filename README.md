# ApexMSP

An Arduino library for communicating with [INAV](https://github.com/iNavFlight/inav) and [Betaflight](https://github.com/betaflight/betaflight) flight controllers over **MSP v2** (MultiWii Serial Protocol version 2).

Works on any platform that provides an Arduino `Stream` — AVR, ESP32, ESP8266, STM32, RP2040, etc.

## Features

- MSP v2 framing with CRC-8/DVB-S2 checksum
- Low-level `send` / `recv` primitives
- Higher-level `request` (send + wait for reply) and `command` (send + optional ACK)
- `getActiveModes()` — resolves box IDs to a 32-bit flight-mode bitmask
- Full set of INAV payload structures and constants (`msp_inav.h`)

## Installation

### Arduino IDE (Library Manager)
Search for **ApexMSP** and click *Install*.

### Manual
Download the ZIP, then in the Arduino IDE choose **Sketch → Include Library → Add .ZIP Library**.

### PlatformIO
```ini
lib_deps = https://github.com/pspychalski/ApexMSP
```

## Wiring

Connect the FC serial port (with MSP enabled) to any hardware UART on your board:

| FC       | Board   |
|----------|---------|
| TX       | RX1     |
| RX       | TX1     |
| GND      | GND     |

## Quick start

```cpp
#include <msp.h>
#include <msp_inav.h>

MSP msp;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  msp.begin(Serial1);           // default 500 ms timeout

  INAV_msp_attitude_t att;
  if (msp.request(INAV_MSP_ATTITUDE, &att, sizeof(att))) {
    Serial.print("Roll: ");  Serial.println(att.roll  / 10.0f);
    Serial.print("Pitch: "); Serial.println(att.pitch / 10.0f);
    Serial.print("Yaw: ");   Serial.println(att.yaw);
  }
}

void loop() {}
```

See [`examples/BasicRequest`](examples/BasicRequest/BasicRequest.ino) for attitude, GPS, battery, and flight-mode queries.

## API

### `MSP`

| Method | Description |
|--------|-------------|
| `begin(stream, timeout=500)` | Attach to a `Stream`; set timeout in ms |
| `reset()` | Flush the stream and discard pending bytes |
| `send(id, payload, size)` | Send an MSP v2 frame |
| `recv(&id, payload, maxSize, &recvSize)` | Receive one MSP v2 frame |
| `request(id, payload, maxSize, &recvSize)` | Send + wait for matching reply |
| `command(id, payload, size, waitACK=true)` | Send + optional ACK wait |
| `getActiveModes(&modes)` | Return active flight-mode bitmask |

Flight-mode bits in the `getActiveModes` result correspond to the `INAV_MSP_MODE_*` constants (e.g. `INAV_MSP_MODE_ARM`, `INAV_MSP_MODE_ANGLE`).

## License

GNU Lesser General Public License v2.1 — see [LICENSE](LICENSE).

Original MSP library by Fabrizio Di Vittorio. INAV extensions and packaging by Pawel Spychalski.
