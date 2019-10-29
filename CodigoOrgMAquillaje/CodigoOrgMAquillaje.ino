#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial BTSerial(7, 8); //RX = 7 TX = 8 (estos son los pines de datos para el modulo bluethoot, el RX del modulo se conecta al TX del arduino, y el TX del modulo al RX del arduino)
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
}

void loop() {
  //Ordenes por cable
  if(Serial.available()>0){
    int Orden = Serial.read();
    if(Orden == '1'){
      
    }
    if(Orden == '2'){

    }
    if(Orden == '3'){

    }
    if(Orden == '4'){
    
    }
    if(Orden == '5'){

    }
    if(Orden == '6'){

    }
    if(Orden == '7'){

    }
    if(Orden == '8'){

    }
    if (Orden == '9'){

    }
    if(Orden == '0'){

    }
  }
  //Ordenes por Bluetooth
  if(BTSerial.available()>0){
    int Orden = BTSerial.read();
    if(Orden == '1'){//esta condicion mueve el servo 360 a una direccion
      servo1.attach(2);
      servo1.write(0);
      delay(2000);
      servo1.detach();
    }
    if(Orden == '2'){//esta condicion mueve el servo 360 a otra direccion
      servo1.attach(2);
      servo1.write(180);
      delay(2000);
      servo1.detach();
    }
    if(Orden == '3'){//esta condicion mueve el servo conectado al pin 3
      servo2.attach(3);
      servo2.write(180);       
    }
    if(Orden == '4'){//esta condicion mueve el servo conectado al pin 4
      servo2.attach(4);
      servo2.write(180); 
    }
    if(Orden == '5'){//esta condicion mueve el servo conectado al pin 5
      servo2.attach(5);
      servo2.write(180); 

    }
    if(Orden == '6'){
            servo2.attach(3);
      servo2.write(0);  

    }
    if(Orden == '7'){
            servo2.attach(4);
      servo2.write(0);  

    }
    if(Orden == '8'){
            servo2.attach(5);
      servo2.write(0);  

    }
    if (Orden == '9'){

    }
    if(Orden == '0'){

    }
    if(Orden == 'a'){

    }
    if(Orden == 'b'){

    }
  }
}
