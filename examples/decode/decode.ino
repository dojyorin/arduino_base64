#include "Arduino.h"
#include "base64.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char* encoded = "Zm9vYmFy";

    uint8_t raw[BASE64::decodeLength(encoded)];
    BASE64::decode(encoded, raw);

    Serial.println((char*)raw);
}

void loop(){}