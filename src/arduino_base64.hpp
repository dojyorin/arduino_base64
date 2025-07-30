#pragma once

#include "stdint.h"
#include "string.h"

namespace base64 {
    void encode(const uint8_t* input, size_t inputLength, char* output);
    size_t encodeLength(size_t inputLength);
    void decode(const char* input, uint8_t* output);
    size_t decodeLength(const char* input);
}