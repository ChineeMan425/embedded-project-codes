const  int sensor = 7; // signal pin of sensor to digital pin 5.   
const int buzzer = 8;            
int state = LOW;            
int val = 0;                 
int motioncount=0;

void  setup() { // Void setup is ran only once after each powerup or reset of the Arduino  board.
  pinMode(sensor, INPUT); // PIR motion sensor is determined is an input here. 
  pinMode(buzzer,OUTPUT); 
  Serial.begin(4800);      
}

void loop(){ // Void loop is ran over and  over and consists of the main program.
  val = digitalRead(sensor);   
  if  (val == HIGH) {                        
    if (state == LOW) {
      Serial.println("  Motion detected "); 
      state = HIGH;       
      state = HIGH;
      motioncount= motioncount+1; 
      Serial.println(motioncount);  
      if(motioncount >= 5){
        digitalWrite(buzzer, HIGH);
        

      }     
    }
  } 
  else {
      if  (state == HIGH){
        Serial.println("The action/ motion has stopped");
        state = LOW;       
    }
  }
}
