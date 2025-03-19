/* Motion Sensor Prototype Code
 * modified 13 November 2020
 * by Katie Byard
 * Inspired by
 * Arduino Project Hub Tutorial:
 * https://create.arduino.cc/projecthub/electropeak/pir-motion-sensor-how-to-use-pirs-w-arduino-raspberry-pi-18d7fa
 */

int ledPin = 9;                  // LED
int pirPin = 5;                   // PIR Out pin
int pirStat = 0;                  // PIR status

void setup() {
  pinMode(ledPin, OUTPUT);        // declare LED as output
  pinMode(pirPin, INPUT);         // declare sensor as input
  Serial.begin(9600);
  Serial.println("Serial Monitor connected");
  delay(1000);
  Serial.print(".");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.println(".");
  delay(500);
  Serial.println("Please let your sensor calibrate");
  delay(1000);
  Serial.println("for 15 to 30 seconds before testing");
  delay(1000);
  Serial.print(".");
  delay(500);
  Serial.print(".");
  delay(500);
  Serial.println(".");
  delay(500);
}

void loop(){
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH) {             // if motion detected
   Serial.println("Motion Detected!");
   digitalWrite(ledPin, HIGH);      // turn LED ON
   delay(100);                      // wait for a second
   digitalWrite(ledPin, LOW);       // turn LED OFF
   delay(100);                      // wait for a second
 } 
 else {
   digitalWrite(ledPin, LOW);       // LED stays off if no motion detected
   Serial.println("No Motion Detected!");
 }
} 
