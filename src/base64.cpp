#include "./base64.hpp"

namespace{
    constexpr char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    uint8_t alphabetOf(char c){
        uint8_t result = 0xFF;

        for(uint8_t i = 0; i < 64; i++){
            if(alphabets[i] == c){
                result = i;
                break;
            }
        }

        return result;
    }

    void a3to4(uint8_t* a3, uint8_t* a4){
        a4[0] = (a3[0] & 0xFC) >> 2;
        a4[1] = ((a3[0] & 0x03) << 4) + ((a3[1] & 0xF0) >> 4);
        a4[2] = ((a3[1] & 0x0F) << 2) + ((a3[2] & 0xC0) >> 6);
        a4[3] = a3[2] & 0x3F;
    }

    void a4to3(uint8_t* a4, uint8_t* a3){
        a3[0] = (a4[0] << 2) + ((a4[1] & 0x30) >> 4);
        a3[1] = ((a4[1] & 0x0F) << 4) + ((a4[2] & 0x3C) >> 2);
        a3[2] = ((a4[2] & 0x03) << 6) + a4[3];
    }
}

void BASE64::encode(const uint8_t* input, size_t inputLength, char* output){
    uint8_t pos = 0;
    uint8_t a3[3];
    uint8_t a4[4];

    while(inputLength--){
        a3[pos++] = *input++;

        if(pos == 3){
            a3to4(a3, a4);

            for(uint8_t i = 0; i < 4; i++){
                *output++ = alphabets[a4[i]];
            }

            pos = 0;
        }
    }

    if(pos){
        for(uint8_t i = pos; i < 3; i++){
            a3[i] = 0x00;
        }

        a3to4(a3, a4);

        for(uint8_t i = 0; i < pos + 1; i++){
            *output++ = alphabets[a4[i]];
        }

        while(pos++ < 3){
            *output++ = '=';
        }
    }

    *output = '\0';
}

size_t BASE64::encodeLength(size_t inputLength){
    return (inputLength + 2 - ((inputLength + 2) % 3)) / 3 * 4 + 1;
}

void BASE64::decode(const char* input, uint8_t* output){
    size_t inputLength = strlen(input);
    uint8_t pos = 0;
    uint8_t a3[3];
    uint8_t a4[4];

    while(inputLength--){
        if(*input == '='){
            break;
        }

        a4[pos++] = alphabetOf(*input++);

        if(pos == 4){
            a4to3(a4, a3);

            for(uint8_t i = 0; i < 3; i++){
                *output++ = a3[i];
            }

            pos = 0;
        }
    }

    if(pos){
        for(uint8_t i = pos; i < 4; i++){
            a4[i] = 0x00;
        }

        a4to3(a4, a3);

        for(uint8_t i = 0; i < pos - 1; i++){
            *output++ = a3[i];
        }
    }
}

size_t BASE64::decodeLength(const char* input){
    size_t inputLength = strlen(input);
    uint8_t equal = 0;

    for(size_t i = inputLength - 1; input[i] == '='; i--){
        equal++;
    }

    return 6 * inputLength / 8 - equal;
}