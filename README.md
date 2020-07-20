# Arduino Base64 Codec
Binary based simple Base64 Codec for Arduino.


# API
## `void BASE64::encode(const uint8_t* input, char* output, size_t length)`
**Arguments**
- `input`: Receives raw data as a binary array.
- `output`: Base64 encoded string.
- `length`: Number of bytes of input data.

**Return**
- Nothing.

**Note**
- If the input data is a `char*`, cast it to `uint8_t*`.


## `size_t BASE64::encodeLength(size_t length)`
**Arguments**
- `length`: Number of bytes of input data.

**Return**
- Number of characters after Base64 encoding.


## `void BASE64::decode(const char* input, uint8_t* output)`
**Arguments**
- `input`: Receives string data as a base64 encoded.
- `output`: Raw binary data.

**Return**
- Nothing.


## `size_t BASE64::decodeLength(const char* input)`
**Arguments**
- `input`: Receives string data as a base64 encoded.

**Return**
- Number of bytes after Base64 decoding.

# Disclaimer
According to MIT License.