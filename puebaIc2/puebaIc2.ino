#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
///////////////////////////////////////////////////////////////////////////////////////
LiquidCrystal_I2C lcd(0x27,16,3);  //Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
int var = 10;
//----------------------------------------------------------------------------------------
const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el echo del sensor
//////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
//-----------------------------------------------------------------------------------  
  lcd.init();// Inicializar el LCD
  lcd.backlight();//Encender la luz de fondo.
  lcd.print("Que rollo morro");// Escribimos el Mensaje en el LCD.
  lcd.setCursor(0, 3);// Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.print("Autodestuccion en  ");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
   if(var == 0){
    lcd.setCursor(0, 1);
    lcd.print("boom");
    return;
   }
   lcd.setCursor(19, 3);
   lcd.print(" ");
   lcd.setCursor(18, 3);
   lcd.print(var);
   var--;
//------------------------------------------------------------------------------   
 
  delay(1000);
}
