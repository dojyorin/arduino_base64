#pragma once

void BASE64::encode(const uint8_t* input, size_t inputLength, char* output);
size_t BASE64::encodeLength(size_t inputLength);
void BASE64::decode(const char* input, uint8_t* output);
size_t BASE64::decodeLength(const char* input);