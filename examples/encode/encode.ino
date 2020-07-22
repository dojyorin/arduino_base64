#include "Arduino.h"
#include "Base64.h"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char* rawData = "foobar";
    size_t rawLength = strlen(rawData);

    char encoded[BASE64::encodeLength(rawLength)];
    BASE64::encode((const uint8_t*)rawData, rawLength, encoded);

    Serial.println(encoded);
}

void loop(){}