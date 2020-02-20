int RX = 3;
int pin_state= 0;
unsigned long counter = 0;
unsigned long prev_counter = 0;
long DELAY = 0;
float freq = 0;


unsigned long previousMillis = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(RX,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();  
  if(currentMillis - previousMillis >= 100){
  
      previousMillis += 100;
      if(DELAY > 500 && DELAY < 2000)
      {
       Serial.println("Button2");
      }
     
      if(DELAY > 2500 && DELAY < 3500)
      {
       Serial.println("Button4");
      }
      
      
  }

  
 if(digitalRead(RX) && pin_state== 0)
 {
  pin_state=1;
  prev_counter = micros();
 }

 if(!digitalRead(RX) && pin_state== 1)
 {
  pin_state=0;
  counter = micros();
  DELAY = counter - prev_counter;   
 }
 
  if(DELAY > 2500)
  {
    digitalWrite(13,LOW);
  }
  if(DELAY < 1000)
  {
    digitalWrite(13,HIGH);
  }
  
 
  
 
}
