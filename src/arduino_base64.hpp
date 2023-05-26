#pragma once

#include "stdint.h"
#include "string.h"

/**
* Convert between binary and base64 encoded string.
* @see https://github.com/dojyorin/arduino_base64
*/
namespace base64{
    /**
    * Convert binary to base64 encoded string.
    * If input is string, cast to `uint8_t*`.
    * @example
    * ```c++
    * ```
    */
    void encode(const uint8_t* input, size_t inputLength, char* output);

    /**
    * Calculate number of output characters.
    * @example
    * ```c++
    * ```
    */
    size_t encodeLength(size_t inputLength);

    /**
    * Convert base64 encoded string to binary.
    * If output is string, cast to `char*`.
    * @example
    * ```c++
    * ```
    */
    void decode(const char* input, uint8_t* output);

    /**
    * Calculate number of output bytes.
    * @example
    * ```c++
    * ```
    */
    size_t decodeLength(const char* input);
}