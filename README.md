# Embedded Systems Project
Embedded Systems arduino project

Designing a smart agri system to detect when a mango is ripe, not ripe or covered by fungus, this would notify the farmer through an LCD display, coloured LEDs and buzzer for varying states of the mango detected. 
A motion sensor would be present to detect unwanted movement in the orchard. There is also a temperature and humidity sensor to check for the environment’s weather. 
The Keypad would be used to reset the system.


Colour detector:
https://projecthub.arduino.cc/SurtrTech/color-detection-using-tcs3200230-a1e463
https://randomnerdtutorials.com/arduino-color-sensor-tcs230-tcs3200/

Keypad:
https://arduinogetstarted.com/tutorials/arduino-keypad#content_wiring_diagram


HC SR501 PIR motion sensor:
left to right pin outs (3pin): GND, signal ,VCC-5V
potentiometers: left (sensitivity), right(time delay after detection)
https://lastminuteengineers.com/pir-sensor-arduino-tutorial/




Buzzer – fungus buzz, double buzz for fungus and triple for ripe.
LEDs – green blue and red. 


LCD (4pin) – display colour, ripe or not ripe, fungus.
https://www.hackster.io/Hack-star-Arduino/learn-to-use-lcd-1602-i2c-parallel-with-arduino-uno-f73f07
library (Frank de Brabander): https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c 


Temperature and humidity sensor:
https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
datasheet: https://www.circuitbasics.com/wp-content/uploads/2015/11/DHT11-Datasheet.pdf
left to right pin outs (3pin) : signal, VCC-5V , ground
library (DHTLib)
