#include "arduino_base64.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const uint8_t data[] = {0x17, 0x77, 0x3B, 0x11, 0x82, 0xA4, 0xC4, 0xC8, 0x27, 0xBC, 0xED, 0x27, 0x07, 0xC1, 0x56, 0x57};
    auto dataLength = sizeof(data);
    char result[base64::encodeLength(dataLength)];

    base64::encode(data, dataLength, result);

    Serial.println(result);
}

void loop(){}