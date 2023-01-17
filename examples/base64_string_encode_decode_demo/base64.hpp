/**
   Base64 encoding and decoding of strings. Uses '+' for 62, '/' for 63, '=' for padding
   Original: https://github.com/Densaugeo/base64_arduino
   
   Modified by: Abhay Bharadwaj (https://github.com/abhaysbharadwaj/)
   Library will now handle taking input from a "String variable" and return results in "String"

*/

#ifndef BASE64_H_INCLUDED
#define BASE64_H_INCLUDED

/* binary_to_base64:
     Description:
       Converts a single byte from a binary value to the corresponding base64 character
     Parameters:
       v - Byte to convert
     Returns:
       ascii code of base64 character. If byte is >= 64, then there is not corresponding base64 character
       and 255 is returned
*/
unsigned char binary_to_base64(unsigned char v);

/* base64_to_binary:
     Description:
       Converts a single byte from a base64 character to the corresponding binary value
     Parameters:
       c - Base64 character (as ascii code)
     Returns:
       6-bit binary value
*/
unsigned char base64_to_binary(unsigned char c);

/* encode_base64_length:
     Description:
       Calculates length of base64 string needed for a given number of binary bytes
     Parameters:
       input_length - Amount of binary data in bytes
     Returns:
       Number of base64 characters needed to encode input_length bytes of binary data
*/
unsigned int encode_base64_length(unsigned int input_length);

/* decode_base64_length:
     Description:
       Calculates number of bytes of binary data in a base64 string
       Variant that does not use input_length no longer used within library, retained for API compatibility
     Parameters:
       input - Base64-encoded null-terminated string
       input_length (optional) - Number of bytes to read from input pointer
     Returns:
       Number of bytes of binary data in input
*/
unsigned int decode_base64_length(unsigned char input[]);
unsigned int decode_base64_length(unsigned char input[], unsigned int input_length);

/* encode_base64:
     Description:
       Converts an array of bytes to a base64 null-terminated string
     Parameters:
       input - Pointer to input data
       input_length - Number of bytes to read from input pointer
       output - Pointer to output string. Null terminator will be added automatically
     Returns:
       Length of encoded string in bytes (not including null terminator)
*/
unsigned int encode_base64(unsigned char input[], unsigned int input_length, unsigned char output[]);

/* decode_base64:
     Description:
       Converts a base64 null-terminated string to an array of bytes
     Parameters:
       input - Pointer to input string
       input_length (optional) - Number of bytes to read from input pointer
       output - Pointer to output array
     Returns:
       Number of bytes in the decoded binary
*/
unsigned int decode_base64(unsigned char input[], unsigned char output[]);
unsigned int decode_base64(unsigned char input[], unsigned int input_length, unsigned char output[]);

unsigned char binary_to_base64(unsigned char v) {
  // Capital letters - 'A' is ascii 65 and base64 0
  if (v < 26) return v + 'A';

  // Lowercase letters - 'a' is ascii 97 and base64 26
  if (v < 52) return v + 71;

  // Digits - '0' is ascii 48 and base64 52
  if (v < 62) return v - 4;

#ifdef BASE64_URL
  // '-' is ascii 45 and base64 62
  if (v == 62) return '-';
#else
  // '+' is ascii 43 and base64 62
  if (v == 62) return '+';
#endif

#ifdef BASE64_URL
  // '_' is ascii 95 and base64 62
  if (v == 63) return '_';
#else
  // '/' is ascii 47 and base64 63
  if (v == 63) return '/';
#endif

  return 64;
}

unsigned char base64_to_binary(unsigned char c) {
  // Capital letters - 'A' is ascii 65 and base64 0
  if ('A' <= c && c <= 'Z') return c - 'A';

  // Lowercase letters - 'a' is ascii 97 and base64 26
  if ('a' <= c && c <= 'z') return c - 71;

  // Digits - '0' is ascii 48 and base64 52
  if ('0' <= c && c <= '9') return c + 4;

#ifdef BASE64_URL
  // '-' is ascii 45 and base64 62
  if (c == '-') return 62;
#else
  // '+' is ascii 43 and base64 62
  if (c == '+') return 62;
#endif

#ifdef BASE64_URL
  // '_' is ascii 95 and base64 62
  if (c == '_') return 63;
#else
  // '/' is ascii 47 and base64 63
  if (c == '/') return 63;
#endif

  return 255;
}

unsigned int encode_base64_length(unsigned int input_length) {
  return (input_length + 2) / 3 * 4;
}

unsigned int decode_base64_length(unsigned char input[]) {
  return decode_base64_length(input, -1);
}

unsigned int decode_base64_length(unsigned char input[], unsigned int input_length) {
  unsigned char *start = input;

  while (base64_to_binary(input[0]) < 64 && (unsigned int) (input - start) < input_length) {
    ++input;
  }

  input_length = (unsigned int) (input - start);
  return input_length / 4 * 3 + (input_length % 4 ? input_length % 4 - 1 : 0);
}

unsigned int encode_base64(unsigned char input[], unsigned int input_length, unsigned char output[]) {
  unsigned int full_sets = input_length / 3;

  // While there are still full sets of 24 bits...
  for (unsigned int i = 0; i < full_sets; ++i) {
    output[0] = binary_to_base64(                         input[0] >> 2);
    output[1] = binary_to_base64((input[0] & 0x03) << 4 | input[1] >> 4);
    output[2] = binary_to_base64((input[1] & 0x0F) << 2 | input[2] >> 6);
    output[3] = binary_to_base64( input[2] & 0x3F);

    input += 3;
    output += 4;
  }

  switch (input_length % 3) {
    case 0:
      output[0] = '\0';
      break;
    case 1:
      output[0] = binary_to_base64(                         input[0] >> 2);
      output[1] = binary_to_base64((input[0] & 0x03) << 4);
      output[2] = '=';
      output[3] = '=';
      output[4] = '\0';
      break;
    case 2:
      output[0] = binary_to_base64(                         input[0] >> 2);
      output[1] = binary_to_base64((input[0] & 0x03) << 4 | input[1] >> 4);
      output[2] = binary_to_base64((input[1] & 0x0F) << 2);
      output[3] = '=';
      output[4] = '\0';
      break;
  }

  return encode_base64_length(input_length);
}

unsigned int decode_base64(unsigned char input[], unsigned char output[]) {
  return decode_base64(input, -1, output);
}

unsigned int decode_base64(unsigned char input[], unsigned int input_length, unsigned char output[]) {
  unsigned int output_length = decode_base64_length(input, input_length);

  // While there are still full sets of 24 bits...
  for (unsigned int i = 2; i < output_length; i += 3) {
    output[0] = base64_to_binary(input[0]) << 2 | base64_to_binary(input[1]) >> 4;
    output[1] = base64_to_binary(input[1]) << 4 | base64_to_binary(input[2]) >> 2;
    output[2] = base64_to_binary(input[2]) << 6 | base64_to_binary(input[3]);

    input += 4;
    output += 3;
  }

  switch (output_length % 3) {
    case 1:
      output[0] = base64_to_binary(input[0]) << 2 | base64_to_binary(input[1]) >> 4;
      break;
    case 2:
      output[0] = base64_to_binary(input[0]) << 2 | base64_to_binary(input[1]) >> 4;
      output[1] = base64_to_binary(input[1]) << 4 | base64_to_binary(input[2]) >> 2;
      break;
  }

  return output_length;
}

/*
   Description: custom function to encode plain text string to base64
   Author: Abhay Bharadwaj (https://github.com/abhaysbharadwaj/)
   Parameters: Pass the plain string in "String" Type
   Return: Returns the Base64 encoded String in "String" Type
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
   Description: custom function to decode base64 string to plain text
   Author: Abhay Bharadwaj (https://github.com/abhaysbharadwaj/)
   Parameters: Pass the base64 encoded string in "String" Type
   Return: Returns the base64 decoded String (plain text) in "String" Type
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

#endif // ifndef
