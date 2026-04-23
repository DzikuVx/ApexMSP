#pragma once
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include "Stream.h"

typedef uint8_t byte;

// PROGMEM is a no-op on native; pgm_read_byte dereferences normally.
#define PROGMEM
#define pgm_read_byte(addr) (*(const uint8_t *)(addr))

// Controlled mock clock — set this in tests to drive timeout paths.
extern uint32_t g_mock_millis;
inline uint32_t millis() { return g_mock_millis; }
