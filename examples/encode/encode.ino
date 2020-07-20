#include "Arduino.h"
#include "Base64.h"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char* rawData = "foobar";
    size_t rawSize = strlen(rawData);

    char encoded[BASE64::encodeLength(rawSize)];
    BASE64::encode((const uint8_t*)rawData, encoded, rawSize);

    Serial.println(encoded);
}

void loop(){}