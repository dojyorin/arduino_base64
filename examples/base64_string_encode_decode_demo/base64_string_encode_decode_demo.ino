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

/*
   custom function to encode plain text string to base64
*/
String lets_encode(String plain_string)
{
  //converting "String" to char array since library needs it to be in "char array"
  char test_string[plain_string.length() + 1];
  plain_string.toCharArray(test_string, sizeof(test_string) + 1);

  //converting char* to unsigned char* since library function uses unsigned char* only
  unsigned char *string = (unsigned char*)test_string;

  Serial.print("Original String: "); Serial.println(plain_string);

  // variable to hold base64 encoded string. 300 is a random value since test string was encoded upto 260 bytes
  unsigned char base64[300];

  //library function to encode plain text to base64
  // encode_base64() places a null terminator automatically, because the output is a string
  unsigned int base64_length = encode_base64(string, strlen((char *) string), base64);

  //debug print to print the base64 encoded length
  //Serial.println(base64_length); // Prints "20"

  //String variable to hold the final result in "String"
  String temp_string = "";

  //converting char* to String
  temp_string += (char *) base64;

  //returning the final base64 encoded string in "String" type
  return temp_string;
}


/*
    custom function to decode base64 string to plain text
*/
String lets_decode(String secret_string)
{
  //converting "String" to char array since library needs it to be in "char array"
  char test_string[secret_string.length() + 1];
  secret_string.toCharArray(test_string, sizeof(test_string) + 1);

  //converting char* to unsigned char* since library function uses unsigned char* only
  unsigned char *base64 = (unsigned char*)test_string;

  Serial.print("Secret String  : "); Serial.println(secret_string);

  // variable to hold decoded plain text. 300 is a random value since test string was encoded upto 220 bytes
  unsigned char string[300];

  //library function to decode base64 string into plain text
  // decode_base64() does not place a null terminator, because the output is not always a string
  unsigned int string_length = decode_base64(base64, string);
  string[string_length] = '\0';

  //debug print to print the base64 encoded length
  //Serial.println(string_length);

  //String variable to hold the final result in "String" type
  String temp_string = "";

  //converting char* to String
  temp_string += (char *) string;
  
  //returning the final decoded plain text in "String" type
  return temp_string;
}
