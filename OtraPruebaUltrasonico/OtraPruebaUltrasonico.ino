/*Practica 09 (Integradora)
Se cuentan cuantas personas entran en una fila y se muestra la cantidad en un display*/
// SE importa la libreria NewPing
#include <NewPing.h>
// Se crea un objeto con la libreria NewPing llamado sonar
NewPing sonar(2, 3); // Each sensor's trigger pin, echo pin, and max distance to ping.
/* Contadores */
int cuenta =0; 


int distancia;


void setup(){
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(9, OUTPUT); //led azul
  pinMode(10, OUTPUT); //led rojo
};

void loop() {
  // en la variable distancia guardamos la distancia en centimetros que detecta el sonar respecto al objetivo
  distancia = sonar.ping_cm(); 
  if (distancia < 15){
    //hacemos delay para que detecte correctamente el paso de las personas
    
    //agregamos los contadores
    cuenta++;
    Serial.print(cuenta);
    Serial.println();
  }
  delay(500);
}
