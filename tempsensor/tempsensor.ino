#include <dht.h>

dht DHT;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHT11_PIN 9

void setup() {
  Serial.begin(4800);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(6,1); 
  lcd.print("T:");
  lcd.print(DHT.temperature, 0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("H:");
  lcd.print(DHT.humidity,0);
  lcd.print("%");
  delay(2000);
  lcd.clear();
  delay(1000);
}