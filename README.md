# **Arduino BASE64**
![actions:test](https://github.com/dojyorin/arduino_base64/actions/workflows/test.yaml/badge.svg)
![actions:release](https://github.com/dojyorin/arduino_base64/actions/workflows/release.yaml/badge.svg)

Convert between binary and BASE64.
Easily convert sensor raw values, structures, etc.

# Example
## Encode
```c++
const uint8_t data[] = {0x17, 0x77, 0x3B, 0x11, 0x82, 0xA4, 0xC4, 0xC8, 0x27, 0xBC, 0xED, 0x27, 0x07, 0xC1, 0x56, 0x57};
auto dataLength = sizeof(data);
char result[BASE64::encodeLength(dataLength)];

BASE64::encode(data, dataLength, result);
```

## Decode
```c++
const char data[] = "F3c7EYKkxMgnvO0nB8FWVw==";
uint8_t result[BASE64::decodeLength(data)];

BASE64::decode(data, result);
```

# Details
The only export of this library will be [`mod.arduino_base64.hpp`](./src/mod.arduino_base64.hpp).
Other source files are for internal use and should not normally be include.

This is library made to convert binary data (e.g. raw sensor values) to BASE64.
String can be convert by cast them to byte arrays, but that's not what this library is for, nor do we plan to provide a means.
If you want to convert string, use this library and implement the wrapper functions yourself.

# API
## `BASE64::encode()`
- Arguments
    - `input` : `const uint8_t*` ... Binary data.
    - `inputLength` : `size_t` ... Number of bytes of input data.
    - `output` : `char*` ... BASE64 encoded string.
- Result
    - `void`

If the input data is string such as `char*`, cast it to `uint8_t*`.

## `BASE64::encodeLength()`
- Arguments
    - `inputLength` : `size_t` ... Number of bytes of input data.
- Result
    - `size_t` ... Number of characters after BASE64 encoding.

## `BASE64::decode()`
- Arguments
    - `input` : `const char*` ... BASE64 encoded string.
    - `output` : `uint8_t*` ... Binary data.
- Result
    - `void`

If the output data is string, you can cast it to `char*`.

## `BASE64::decodeLength()`
- Arguments
    - `input` : `const char*` ... BASE64 encoded string.
- Result
    - `size_t` ... Number of bytes after BASE64 decoding.