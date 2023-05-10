#pragma once

#include "stdint.h"
#include "string.h"

/**
* Convert between binary and Base64 encoded string.
* @see https://github.com/dojyorin/arduino_base64
*/
namespace base64{
    /**
    * Convert binary to Base64 encoded string.
    * If the input is string, cast it to `uint8_t*`.
    * @param input Binary data.
    * @param inputLength Number of input bytes.
    * @param output Base64 encoded string.
    */
    void encode(const uint8_t* input, size_t inputLength, char* output);

    /**
    * Calculate the number of output characters.
    * @param inputLength Number of input bytes.
    * @return Number of output characters.
    */
    size_t encodeLength(size_t inputLength);

    /**
    * Convert Base64 encoded string to binary.
    * If the output is string, cast it to `char*`.
    * @param input Base64 encoded string.
    * @param output Binary data.
    */
    void decode(const char* input, uint8_t* output);

    /**
    * Calculate the number of output bytes.
    * @param input Base64 encoded string.
    * @return Number of output bytes.
    */
    size_t decodeLength(const char* input);
}