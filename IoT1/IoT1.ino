#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino 
#include <DNSServer.h> 
#include <ESP8266WebServer.h> 
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager 
#include <FirebaseArduino.h> 
#define FIREBASE_HOST "primerdb-b7af4.firebaseio.com" 
#define FIREBASE_AUTH "24rL0eYmolQIfuS8Qzl6mZykbT8Ozl904jk8dRW3" 
String estado; 
 
void setup() {
  WiFi.disconnect();     
  Serial.begin(115200);     
  WiFiManager wifiManager;     
  wifiManager.autoConnect("Rafailito");     
  Serial.println("Ya estás en linea");     
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);     
  pinMode(2, OUTPUT);     
  digitalWrite(2,LOW); 
} 
  
void loop() {         
  estado = Firebase.getString("/ESTADO");         
  estado = estado.substring(1,estado.length()-1);         
  if (estado == "ON"){           
    digitalWrite (2, LOW);         
    }         
  if (estado == "OFF"){           
    digitalWrite (2, HIGH);           
    }           
  delay (1000);         
  Serial.println (estado);    
}
