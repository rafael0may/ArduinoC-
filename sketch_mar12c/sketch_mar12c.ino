const int L1 = 13;
const int L2 = 12;
const int L3 = 8;
void setup() {
  Serial.begin(9600);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);

}

void loop() {
  if(Serial.available()>0){
    int Caracter = Serial.read();
    if(Caracter == 'A'){
      digitalWrite(L1,HIGH);
    }
    if (Caracter == 'B'){
      digitalWrite(L1,LOW);
    }
    if (Caracter == 'C'){
      digitalWrite(L2,HIGH);
    }
    if (Caracter == 'D'){
      digitalWrite(L2,LOW);
    }
    if (Caracter == 'E'){
      digitalWrite(L3,HIGH);
    }
    if (Caracter == 'F'){
      digitalWrite(L3,LOW);
    }
  }
}
