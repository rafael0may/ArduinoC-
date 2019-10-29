#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(6);
  servo1.write(150);
  servo2.write(150);
  servo3.write(150);
  servo4.write(150);

}

void loop() {
  if(Serial.available()>0){
    int Orden = Serial.read();
    if(Orden == '1'){
      
       servo1.write(10);
      delay(300);
      servo1.write(150);
    }
    if(Orden == '2'){
       servo2.write(10);
      delay(300);
      servo2.write(150);
     
    }
    if(Orden == '3'){
       servo3.write(10);
      delay(300);
      servo3.write(150);
    }
    if(Orden == '4'){
       servo4.write(10);
      delay(300);
      servo4.write(150);
    
    }
    if(Orden == '5'){
      servo1.write(150);
      servo2.write(150);
      servo3.write(150);
      servo4.write(150);
    }
    if(Orden == '6'){
      digitalWrite(led2,LOW);
    }
    if(Orden == '7'){
      digitalWrite(led3,LOW);
    }
    if(Orden == '8'){
      digitalWrite(led4,LOW);
    }
    if(Orden == '0'){
      digitalWrite(led1,LOW);
      
      digitalWrite(led2,LOW);
      
      digitalWrite(led3,LOW);
      
      digitalWrite(led4,LOW);
    }
  }
  // put your main code here, to run repeatedly:

}
