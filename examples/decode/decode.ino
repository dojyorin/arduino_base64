#include "Arduino.h"
#include "base64.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char data[] = "Zm9vYmFy";
    uint8_t result[BASE64::decodeLength(data)] = {};

    BASE64::decode(data, result);

    Serial.println((char*)result);
}

void loop(){}