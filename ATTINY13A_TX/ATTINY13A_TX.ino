
//#define F_CPU 9600000
#define TX 4

void setup() {
  // put your setup code here, to run once:
  pinMode(TX,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  digitalWrite(TX,1);
  delay(1000);
  digitalWrite(TX,0);
  delay(1000);
  */
  if(digitalRead(A3) == 0){
    write_freq(3000);
  }else{
    write_freq(1500);
  }
}


/****************************************************************************

                                  FUNCTIONS
 
 ****************************************************************************/

void write_freq(int DELAY){
  digitalWrite(TX,LOW);
  delayMicroseconds(DELAY);
  //delay(DELAY);
  digitalWrite(TX,HIGH);
  delayMicroseconds(DELAY);
  //delay(DELAY);
}

