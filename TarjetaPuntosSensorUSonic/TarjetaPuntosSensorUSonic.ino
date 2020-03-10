#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
LiquidCrystal_I2C lcd(0x27,16,3);  //Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros

int cuenta =0;
int entero;
const int buzzer = 6;
int rojo = A1;
int verde = A0;
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación

  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  
  lcd.init();// Inicializar el LCD
  lcd.backlight();//Encender la luz de fondo.
  
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readm
}

void loop(){
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

  if (d < 15){    
    //agregamos los contadores
    cuenta++;
    lcd.setCursor(0,0);
    lcd.print("UTSCoins:");
    lcd.setCursor(13, 0);
    lcd.print(cuenta);
    lcd.setCursor(0,3);
    tone(buzzer, 500);digitalWrite(rojo, HIGH);
    delay(100);        // ...for 1 sec
    noTone(buzzer);
    
    
    digitalWrite(rojo, LOW);
    lcd.print("Coloca tu tarjeta");
  }
  delay(100);
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  consegir_saldo();
  cuenta = cuenta + entero;
  Serial.println(cuenta);
  Escribir();
  delay(5000);
  lcd.clear();
  cuenta = 0; 
}
void Escribir(){
  MFRC522::StatusCode status;
  MFRC522::MIFARE_Key key; 
  byte block;
  byte len;
  byte buffer[34];
  String cadena;
  int var;
  char datos[16];
  Serial.print(F("Card UID:"));    //Dump UID
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.print(F(" PICC type: "));   // Dump PICC type
  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.println(mfrc522.PICC_GetTypeName(piccType));

  block = 1;
  
  
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    tone(buzzer, 100); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    noTone(buzzer);
    return;
  }
  else Serial.println(F("PCD_Authenticate() success: "));

  // Write block
  for (byte i = 0; i < 30; i++) buffer[i] = ' ';
  status = mfrc522.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  else Serial.println(F("MIFARE_Write() success: "));
  cadena = (String)cuenta;
  var = cadena.length();
  for (int i = 0; i < 16; i++) { 
        datos[i] = ' '; 
        
    }
  for (int i = 0; i < var; i++) { 
        datos[i] = cadena[i]; 
        
    }

  status = mfrc522.MIFARE_Write(block, (byte *)datos, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Write() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }
  else {
    Serial.println(F("MIFARE_Write() success: "));
    lcd.setCursor(0,0);
    lcd.print("UTSCoins:");
    lcd.setCursor(0, 2);
    lcd.print("tu saldo ahora:");
    lcd.setCursor(15, 2);
    lcd.print(cuenta);
    tone(buzzer, 1000);
    digitalWrite(verde, HIGH);// Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    noTone(buzzer);
    digitalWrite(verde, LOW);
  }
  
  Serial.println(" ");
  mfrc522.PICC_HaltA(); // Halt PICC
  mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
}


void consegir_saldo(){
  MFRC522::StatusCode status;
  MFRC522::MIFARE_Key key;
  char cadena2[16];
  String cadena3;
  byte buffer2[18];
  byte block;
  byte len;
  block = 1;
  len = 18;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    tone(buzzer, 100); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    noTone(buzzer);
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer2, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    tone(buzzer, 100); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    noTone(buzzer);
    return;
  }
  
  //PRINT LAST NAME
  for (uint8_t i = 0; i < 16; i++) {
    cadena2 [i]= buffer2[i];
  }

  for(int i = 0; i < 5; i++){
    cadena3 = cadena3+cadena2[i];
  }
  entero = cadena3.toInt();
  lcd.setCursor(0,0);
  lcd.print("UTSCoins:");
  lcd.setCursor(0, 1);
  lcd.print("tu saldo antes:" + cadena3);
  
  
}
