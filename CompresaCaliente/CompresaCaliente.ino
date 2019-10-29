#include <SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial BT(10,11);
int low = 2;
int medium =3;
int high = 4;


void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(low, OUTPUT);
  pinMode(medium, OUTPUT);
  pinMode(high, OUTPUT);
  digitalWrite(high,HIGH);
  digitalWrite(medium, HIGH);
  digitalWrite(low, HIGH);
}

void loop() {
  if(BT.available()>0){
    int Orden = BT.read();
    if(Orden == '1'){
      Serial.println("nojala");

      digitalWrite(high,HIGH);
      digitalWrite(medium, HIGH);
      digitalWrite(low, LOW);
    }
    if(Orden == '2'){
      digitalWrite(high,HIGH);
      digitalWrite(low, HIGH);
      digitalWrite(medium, LOW);
    }
    if(Orden == '3'){
      digitalWrite(medium, HIGH);
      digitalWrite(low, HIGH);
      digitalWrite(high,LOW);
    }
    if(Orden == '4'){
      digitalWrite(high,HIGH);
      digitalWrite(medium, HIGH);
      digitalWrite(low, HIGH);
    }
    }

}
