// colour sensor pins wiring to Arduino
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define DHT11_PIN 9

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <dht.h>
dht DHT;



// Stores frequency read by the colour sensor
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;




void setup() {

  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);

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
  redFrequency = pulseIn(sensorOut, LOW);

  // Printing the RED (R) value
  if (redFrequency <= 15) {
    Serial.print("R = ");
    Serial.println(redFrequency);
    lcd.setCursor(0, 0);
    lcd.print("RIPE!");  //RED
    delay(1000);
    lcd.clear();
  }

  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);

  // Printing the GREEN (G) value
  if (greenFrequency <= 25) {
    Serial.print(" G = ");
    Serial.println(greenFrequency);
    lcd.setCursor(0, 0);
    lcd.print("NOT RIPE!");  //GREEN
    delay(1000);
    lcd.clear();
  }


  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);

  // Printing the BLUE (B) value
  if (blueFrequency <= 20) {
    Serial.print(" B = ");
    Serial.println(blueFrequency);
    lcd.setCursor(0, 0);
    lcd.print("FUNGUS!");  //BLUE
    delay(1000);
    lcd.clear();
  }
}