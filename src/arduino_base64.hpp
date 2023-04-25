#pragma once

#include "stdint.h"
#include "string.h"

/**
* Convert between binary and BASE64.
* @see https://github.com/dojyorin/arduino_base64
*/
namespace BASE64{
    /**
    * Convert binary to BASE64.
    * If the input is string, cast it to `uint8_t*`.
    * @param input Binary data.
    * @param inputLength Number of input bytes.
    * @param output BASE64 encoded string.
    */
    void encode(const uint8_t* input, size_t inputLength, char* output);

    /**
    * Calculate the number of output characters.
    * @param inputLength Number of input bytes.
    * @return Number of output characters.
    */
    size_t encodeLength(size_t inputLength);

    /**
    * Convert BASE64 to binary.
    * If the output is string, you can cast it to `char*`.
    * @param input BASE64 encoded string.
    * @param output Binary data.
    */
    void decode(const char* input, uint8_t* output);

    /**
    * Calculate the number of output bytes.
    * @param input BASE64 encoded string.
    * @return Number of output bytes.
    */
    size_t decodeLength(const char* input);
}