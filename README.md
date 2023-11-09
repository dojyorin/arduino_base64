# **Arduino Base64**
![actions:test](https://github.com/dojyorin/arduino_base64/actions/workflows/test.yaml/badge.svg)
![actions:release](https://github.com/dojyorin/arduino_base64/actions/workflows/release.yaml/badge.svg)
![shields:license](https://img.shields.io/github/license/dojyorin/arduino_base64)
![shields:release](https://img.shields.io/github/release/dojyorin/arduino_base64)

Convert between binary and base64 encoded string.
Easily convert sensor raw values, structures, etc...

# Details
This library made to convert binary data (e.g. raw sensor values) to base64 encoded string.
String can be convert by cast them to `uint8_t*`, but that not what this library is for, nor do we plan to provide means.
If you want to convert string, use this library and implement wrapper functions yourself.

# API
See [`arduino_base64.hpp`](./src/arduino_base64.hpp) for details.