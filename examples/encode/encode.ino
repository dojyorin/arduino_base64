#include "Arduino.h"
#include "mod.base64.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char data[] = "foobar";
    size_t dataLength = strlen(data);
    char result[BASE64::encodeLength(dataLength)];

    BASE64::encode((const uint8_t*)data, dataLength, result);

    Serial.println(result);
}

void loop(){}