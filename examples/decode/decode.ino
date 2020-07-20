#include "Arduino.h"
#include "Base64.h"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char* encodedData = "Zm9vYmFy";

    uint8_t raw[BASE64::decodeLength(encodedData)];
    BASE64::decode(encodedData, raw);

    Serial.println((char*)raw);
}

void loop(){}