int contador = 0;
int pin = 9;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(contador = 0; contador <= 255; contador ++){
  analogWrite(pin, contador);
  delay(15);
  }
  for(contador = 255; contador >= 0; contador --){
  analogWrite(pin, contador);
  delay(15);
  }
  delay(600);
}
