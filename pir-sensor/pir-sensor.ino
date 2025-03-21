const int led = 9; // Led positive terminal to the digital pin 9.              
const  int sensor = 5; // signal pin of sensor to digital pin 5.               
int state = LOW;            
int val = 0;                 

void  setup() { // Void setup is ran only once after each powerup or reset of the Arduino  board.
  pinMode(led, OUTPUT); // Led is determined as an output here.    
  pinMode(sensor, INPUT); // PIR motion sensor is determined is an input here.  
  Serial.begin(4800);      
}

void loop(){ // Void loop is ran over and  over and consists of the main program.
  val = digitalRead(sensor);   
  if  (val == HIGH) {           
    digitalWrite(led, HIGH);   
      // Delay of led is 500             
    
    if (state == LOW) {
      Serial.println("  Motion detected "); 
      state = HIGH;       
    }
  } 
  else {
      digitalWrite(led, LOW);
                 
      
      if  (state == HIGH){
        Serial.println("The action/ motion has stopped");
        state = LOW;       
    }
  }
}
