# Arduino Base64 Codec
Binary based simple Base64 Codec for Arduino.


# Example
## Encode
```c++
const char* rawData = "foobar";
size_t rawSize = strlen(rawData);

char encoded[BASE64::encodeLength(rawSize)];
BASE64::encode((const uint8_t*)rawData, encoded, rawSize);

Serial.println(encoded);
```


## Decode
```c++
const char* encodedData = "Zm9vYmFy";

uint8_t raw[BASE64::decodeLength(encodedData)];
BASE64::decode(encodedData, raw);

Serial.println((char*)raw);
```


# API
## void BASE64::encode(const uint8_t* input, char* output, size_t length)
**Arguments**
- `input`: Receives raw binary data as a byte array.
- `output`: Base64 encoded string.
- `length`: Number of bytes of input data.

**Return**
- Nothing.

**Note**
- If the input data is `char*` string, cast it to `uint8_t*`.


## size_t BASE64::encodeLength(size_t length)
**Arguments**
- `length`: Number of bytes of input data.

**Return**
- Number of characters after Base64 encoding.


## void BASE64::decode(const char* input, uint8_t* output)
**Arguments**
- `input`: Receives string data as a base64 encoded.
- `output`: Raw binary data.

**Return**
- Nothing.

**Note**
- If the output data is string, you can cast it to `char*`.


## size_t BASE64::decodeLength(const char* input)
**Arguments**
- `input`: Receives string data as a base64 encoded.

**Return**
- Number of bytes after Base64 decoding.


# Disclaimer
According to MIT License.