#ifndef Base64_Header
#define Base64_Header

#include "inttypes.h"
#include "string.h"

namespace BASE64{
    void encode(const uint8_t* input, char* output, size_t length);
    size_t encodeLength(size_t length);
    void decode(const char* input, uint8_t* output);
    size_t decodeLength(const char* input);
}

#endif