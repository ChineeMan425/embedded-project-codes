/* Hello Wokwi! */
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
void setup() {
lcd.init();
lcd.backlight();
lcd.setCursor(1, 0);
lcd.print("Zurich is shit");
delay(500);
lcd.clear();
}
void loop() {
}