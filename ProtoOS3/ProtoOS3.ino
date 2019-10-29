#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial (0,1);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8);
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int pin1 = 13;
int pin2 = 12;
int pin3 = 11;

void setup() {
Serial.begin(9600);
BTSerial.begin(9600);
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    int Orden = Serial.read();
    if(Orden == '1'){
      servo1.attach(2);
      servo1.write(150);
      delay(300);
      servo1.write(20);
      servo1.detach();
    }
    if(Orden == '2'){
      servo2.attach(3);
       servo2.write(10);
      delay(300);
      servo2.write(150);
     
    }
    if(Orden == '3'){
      servo3.attach(4);
       servo3.write(10);
      delay(300);
      servo3.write(150);
    }
    if(Orden == '4'){
      servo4.attach(6);
       servo4.write(10);
      delay(300);
      servo4.write(150);
    
    }
    if(Orden == '5'){
       servo4.attach(6);
       servo4.write(10);
       delay(300);
       servo4.write(150);
    }
    if(Orden == '6'){
      digitalWrite(pin1,HIGH);
      delay (1000);
      digitalWrite(pin1,LOW);

    }
    if(Orden == '7'){
      digitalWrite(pin2,HIGH);
            delay (1000);
      digitalWrite(pin2,LOW);

    }
    if(Orden == '8'){
      digitalWrite(pin3,HIGH);
            delay (1000);
      digitalWrite(pin3,LOW);

    }
    if (Orden == '9'){
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin3,LOW);
    }
    if(Orden == '0'){
        servo1.attach(2);
      servo2.attach(3);
       servo3.attach(4);
        servo4.attach(6);
      servo1.write(150);
      servo2.write(150);
      servo3.write(150);
      servo4.write(150);
    }
  }
  // put your main code here, to run repeatedly:

}
