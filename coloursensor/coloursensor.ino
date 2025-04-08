// colour sensor pins wiring to Arduino
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define coloursensorOut 6
#define DHT11_PIN 9
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <dht.h>
dht DHT;

// Stores frequency read by the colour sensor
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

const int motionsensor = 7;  // signal pin of sensor to digital pin 5.
const int buzzer = 8;
int state = LOW;
int val = 0;
int motioncount = 0;

const int ROW_NUM = 4;     //four rows
const int COLUMN_NUM = 4;  //four columns
char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte pin_rows[ROW_NUM] = { 23, 25, 27, 29 };       //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = { 31, 33, 35, 37 };  //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

const String password = "2032";  // change your password here
String input_password;

int redPin = 40;
int greenPin = 42;
int bluePin = 44;


void setup() {
  input_password.reserve(32);  // maximum input characters is 33, change if needed
  //RGB LED
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(motionsensor, INPUT);  // PIR motion sensor is determined is an input here.
  pinMode(buzzer, OUTPUT);

  // Setting the colour sensorOut as an input
  pinMode(coloursensorOut, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, HIGH);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  // Begins serial communication
  Serial.begin(4800);
}


void loop() {

  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(6, 1);
  lcd.print("T:");
  lcd.print(DHT.temperature, 0);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(DHT.humidity, 0);
  lcd.print("%");
  delay(1000);
  lcd.clear();
  delay(500);



  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Reading the output frequency
  redFrequency = pulseIn(coloursensorOut, LOW);

  // Printing the RED (R) value
  if (redFrequency <= 19) {
    Serial.print("R = ");
    Serial.println(redFrequency);
    lcd.setCursor(0, 0);
    lcd.print("RIPE!");  //RED
    analogWrite(greenPin, 0);
    analogWrite(redPin, 255);
    analogWrite(bluePin, 0);
    delay(1000);
    lcd.clear();
  }

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  greenFrequency = pulseIn(coloursensorOut, LOW);
  // take out so that system will display not ripe constantly and LED green 
  // Printing the GREEN (G) value
  if (greenFrequency <= 30) {
    Serial.print(" G = ");  
    Serial.println(greenFrequency);
    lcd.setCursor(0, 0);
    lcd.print("NOT RIPE!");  //GREEN
    analogWrite(greenPin, 255);
    analogWrite(redPin, 0);
    analogWrite(bluePin, 0);
    delay(1000);
    lcd.clear();
  }


  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  blueFrequency = pulseIn(coloursensorOut, LOW);

  // Printing the BLUE (B) value
  if (blueFrequency <= 50) {
    Serial.print(" B = ");
    Serial.println(blueFrequency);
    lcd.setCursor(0, 0);
    lcd.print("FUNGUS!");  //BLUE
    analogWrite(greenPin, 0);
    analogWrite(redPin, 0);
    analogWrite(bluePin, 255);
    delay(1000);
    lcd.clear();
  }

  // motion sensor
  val = digitalRead(motionsensor);
  if (val == HIGH) {
    if (state == LOW) {
      Serial.println("  Motion detected ");
      state = HIGH;
      motioncount = motioncount + 1;
      Serial.println(motioncount);
      if (motioncount >= 5) {
        digitalWrite(buzzer, HIGH);
      }
    }
  } else {
    if (state == HIGH) {
      Serial.println("The action/ motion has stopped");
      state = LOW;
    }
  }
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
