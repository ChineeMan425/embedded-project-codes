/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-keypad
 */

#include <Keypad.h>

const int ROW_NUM = 4;     //four rows
const int COLUMN_NUM = 3;  //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte pin_rows[ROW_NUM] = { 9, 8, 7, 6 };    //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = { 5, 4, 3 };  //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

const String password = "2032";  // change your password here
String input_password;

void setup() {
  Serial.begin(9600);
  input_password.reserve(32);  // maximum input characters is 33, change if needed
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '*') {
      input_password = "";  // clear input password
      Serial.println("password cleared");
    } else if (key == '#') {
      if (password == input_password) {
        Serial.println("password is correct");
        // DO YOUR WORK HERE

      } else {
        Serial.println("password is incorrect, try again");
      }

      input_password = "";  // clear input password
    } else {
      input_password += key;  // append new character to input password string
    }
  }
}
