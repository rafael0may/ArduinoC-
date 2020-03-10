//Bibliotecas///////////
#include <SoftwareSerial.h>

//Se le asigna un nombre a la conexion SerialBluethoot
//RX = 7 TX = 8 (estos son los pines de datos para el modulo bluethoot,
//el RX del modulo se conecta al TX del arduino 
//y el TX del modulo al RX del arduino)
SoftwareSerial BTSerial(7, 8); 

//Aqui se le asigna un nombre a cada puerto//////////////////
//Puertos para el relevador////////////////////
int Rele1 = 9; 
int Rele2 = 10;
int Rele3 = 11;
int Rele4 = 12;
//Puertos para los led indicadores/////////////
int led1 = A3;
int led2 = A2;
int led3 = A1;
int led4 = A0;

//Creacion de comunicaiones SerialUSB y SerialBluethoot/////////////
//configuraciones de las conexiones a los Relevadores//////////////
//configuraciones de las conexiones a los led indicadores//////////
void setup() {
Serial.begin(9600);//configuracion de velocidad de transimision de datos del puerto SerialUSB
BTSerial.begin(9600);//configuracion de velocidad de transimision de datos del puerto SerialBuethoot
pinMode(Rele1, OUTPUT);//se indica que el puerto de nombre "Rele1" se comportarà como salida
digitalWrite (Rele1 , HIGH);//se mantiene desactivado el relevador
pinMode(Rele2, OUTPUT);
digitalWrite (Rele2 , HIGH);
pinMode(Rele3, OUTPUT);
digitalWrite (Rele3 , HIGH);
pinMode(Rele4, OUTPUT);
digitalWrite (Rele4 , HIGH);
pinMode(led1, OUTPUT);//se indica que el puerto con el nombre "led1" se comportarà como salida
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  //Ordenes por cable//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(Serial.available()>0){//evalua si el puerto SerialUSB se ha recibido alguna señal//////////
    int Orden = Serial.read();//Se asigna el valor que entrò por el puerto SerialUSB a la variable llamada "Orden"/////
    if(Orden == '1'){//Se evalua si el valor dentro de "Orden" es igual a 1/////////
      digitalWrite (Rele1 , LOW);//se activa el relevador de nombre "Rele"/////////
      digitalWrite (led1, HIGH);//se enciende el led conectado al puerto de nombre led1////////
    }
    if(Orden == '2'){//Se evalua si el valor dentro de "Orden" es igual a 2/////////
      digitalWrite (Rele1 , HIGH);//se desactiva el relevador de nombre "Rele"/////////
      digitalWrite (led1, LOW);//se apaga el led conectado al puerto de nombre led1////////
    }
    if(Orden == '3'){
      digitalWrite (Rele2 , LOW);
      digitalWrite (led2, HIGH);
    }
    if(Orden == '4'){
      digitalWrite (Rele2 , HIGH);
      digitalWrite (led2, LOW);
    }
    if(Orden == '5'){
      digitalWrite (Rele3 , LOW);
      digitalWrite (led3, HIGH);
    }
    if(Orden == '6'){
      digitalWrite (Rele3 , HIGH);
      digitalWrite (led3, LOW);
    }
    if(Orden == '7'){
      digitalWrite (Rele4 , LOW);
      digitalWrite (led4, HIGH);
    }
    if(Orden == '8'){
      digitalWrite (Rele4 , HIGH);
      digitalWrite (led4, LOW);
    }
    if (Orden == '9'){
      digitalWrite (Rele1 , HIGH);
      digitalWrite (Rele2 , HIGH);
      digitalWrite (Rele3 , HIGH);
      digitalWrite (Rele4 , HIGH);
      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
    }
    if(Orden == '0'){
      digitalWrite (Rele1 , LOW);
      digitalWrite (Rele2 , LOW);
      digitalWrite (Rele3 , LOW);
      digitalWrite (Rele4 , LOW);
      digitalWrite (led1, HIGH);
      digitalWrite (led2, HIGH);
      digitalWrite (led3, HIGH);
      digitalWrite (led4, HIGH);
    }
  }
  //Ordenes por Bluetooth/////////////////////////////////////////////////////////////////////////////////////////////////
  if(BTSerial.available()>0){
    int Orden = BTSerial.read();
    if(Orden == '1'){
      digitalWrite (Rele1 , LOW);
      digitalWrite (led1, HIGH);
    }
    if(Orden == '2'){
      digitalWrite (Rele1 , HIGH);
      digitalWrite (led1, LOW);
    }
    if(Orden == '3'){
      digitalWrite (Rele2 , LOW);
      digitalWrite (led2, HIGH);
    }
    if(Orden == '4'){
      digitalWrite (Rele2 , HIGH);
      digitalWrite (led2, LOW);
    }
    if(Orden == '5'){
      digitalWrite (Rele3 , LOW);
      digitalWrite (led3, HIGH);
    }
    if(Orden == '6'){
      digitalWrite (Rele3 , HIGH);
      digitalWrite (led3, LOW);
    }
    if(Orden == '7'){
      digitalWrite (Rele4 , LOW);
      digitalWrite (led4, HIGH);
    }
    if(Orden == '8'){
      digitalWrite (Rele4 , HIGH);
      digitalWrite (led4, LOW);
    }
    if (Orden == '9'){
      digitalWrite (Rele1 , HIGH);
      digitalWrite (Rele2 , HIGH);
      digitalWrite (Rele3 , HIGH);
      digitalWrite (Rele4 , HIGH);
      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
    }
    if(Orden == '0'){
      digitalWrite (Rele1 , LOW);
      digitalWrite (Rele2 , LOW);
      digitalWrite (Rele3 , LOW);
      digitalWrite (Rele4 , LOW);
      digitalWrite (led1, HIGH);
      digitalWrite (led2, HIGH);
      digitalWrite (led3, HIGH);
      digitalWrite (led4, HIGH);
    }
  }
}
//avance y retoceso de servomotores
    /*
      servo1.attach(2);
      servo1.write(150);
      delay(300);
      servo1.write(20);
     */
      
