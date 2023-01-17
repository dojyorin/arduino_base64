/*
  Demo code to encode and decode a String usign Base64.
  Author: Abhay Bharadwaj (https://github.com/abhaysbharadwaj/)
*/

#include "base64.hpp"

//original plain text that needs encoding.
//keeping it long on purpose!
String original_string = "{\"device_status\":1,\"ftp_port\":990,\"ftp_url\":\"ftp://internet.address.edu\",\"clientId\":\"ABCD1234\",\"username\":\"ABCD1234\",\"password\":\"ABCD1234\",\"SecretToken\":\"ABCD1234\",\"SleepTime_sec\":86400}";
String encoded_string = "";
String decoded_string = "";

void setup()
{
  //initilizing serial port to 115200bps for print statements
  Serial.begin(115200);
  delay(1000);
  Serial.println("Serial port initialized...");
  Serial.println("Demo program to encode original string and then decode it back using Base64");
  delay(1000);
}

void loop()
{
  Serial.println("*******************************************************************");

  //calling custom function "lets_encode"
  //to pass: plain text string in "String" type
  //return: returns the base64 encoded string in "String" type
  encoded_string = lets_encode(original_string);

  //debug print statements
  Serial.print("Encoded string : ");
  Serial.println(encoded_string);
  delay(1000);

  //calling custom function "lets_decode"
  //to pass: encoded string in "String" type
  //return: returns the plain text decoded string in "String" type
  decoded_string = lets_decode(encoded_string);

  //debug print statements
  Serial.print("Decoded string : ");
  Serial.println(decoded_string);


  Serial.println("*******************************************************************\r\n");
  delay(10000);
}
