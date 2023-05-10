# **Arduino Base64**
![actions:test](https://github.com/dojyorin/arduino_base64/actions/workflows/test.yaml/badge.svg)
![actions:release](https://github.com/dojyorin/arduino_base64/actions/workflows/release.yaml/badge.svg)

Convert between binary and Base64 encoded string.
Easily convert sensor raw values, structures, etc.

# Example
## Encode
```c++
const uint8_t data[] = {0x17, 0x77, 0x3B, 0x11, 0x82, 0xA4, 0xC4, 0xC8, 0x27, 0xBC, 0xED, 0x27, 0x07, 0xC1, 0x56, 0x57};
auto dataLength = sizeof(data);
char result[base64::encodeLength(dataLength)];

base64::encode(data, dataLength, result);
```

## Decode
```c++
const char data[] = "F3c7EYKkxMgnvO0nB8FWVw==";
uint8_t result[base64::decodeLength(data)];

base64::decode(data, result);
```

# Details
The only export of this library will be [`arduino_base64.hpp`](./src/arduino_base64.hpp).
Other source files are for internal use and should not normally be include.

This is library made to convert binary data (e.g. raw sensor values) to Base64 encoded string.
String can be convert by cast them to byte arrays, but that's not what this library is for, nor do we plan to provide a means.
If you want to convert string, use this library and implement the wrapper functions yourself.

# API
## `base64::encode(input, inputLength, output)`
- Arguments
    - `input` : `const uint8_t*` ... Binary data.
    - `inputLength` : `size_t` ... Number of input bytes.
    - `output` : `char*` ... Base64 encoded string.
- Result
    - `void`

If the input is string, cast it to `uint8_t*`.

## `base64::encodeLength(inputLength)`
- Arguments
    - `inputLength` : `size_t` ... Number of input bytes.
- Result
    - `size_t` ... Number of output characters.

## `base64::decode(input, output)`
- Arguments
    - `input` : `const char*` ... Base64 encoded string.
    - `output` : `uint8_t*` ... Binary data.
- Result
    - `void`

If the output is string, cast it to `char*`.

## `base64::decodeLength(input)`
- Arguments
    - `input` : `const char*` ... Base64 encoded string.
- Result
    - `size_t` ... Number of output bytes.