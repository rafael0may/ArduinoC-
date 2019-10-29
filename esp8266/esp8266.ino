void setup() {
  pinMode(D0,OUTPUT);
  digitalWrite(D0, LOW);

}

void loop() {
  delay(1000);
  digitalWrite(D0, HIGH);
  delay(1000);
  digitalWrite(D0, LOW);
}
