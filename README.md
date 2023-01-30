# **Arduino BASE64 Codec**
Binary based simple BASE64 Codec for Arduino.

**Note!**

This is library made to convert binary data (e.g. raw sensor values) to BASE64.
String can be convert by cast them to byte arrays, but that's not what this library is for, nor do we plan to provide a means.
If you want to convert string, use this library and implement your own wrapper functions.

# Example
## Encode
```c++
const char data[] = "foobar";
size_t dataLength = strlen(data);
char result[BASE64::encodeLength(dataLength)];

BASE64::encode((const uint8_t*)data, dataLength, result);
```

## Decode
```c++
const char data[] = "Zm9vYmFy";
uint8_t result[BASE64::decodeLength(data)];

BASE64::decode(data, result);
```

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

# Disclaimer
According to MIT License.