#pragma once
#include <stdint.h>
#include <stddef.h>

class Stream {
public:
    virtual ~Stream() = default;
    virtual int      available() = 0;
    virtual int      read() = 0;
    virtual size_t   readBytes(char* buf, size_t len) = 0;
    virtual size_t   write(uint8_t b) = 0;
    virtual size_t   write(const uint8_t* buf, size_t size) = 0;
    virtual void     flush() = 0;
};
