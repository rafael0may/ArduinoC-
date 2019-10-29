const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    int Orden = Serial.read();
    if(Orden == '1'){
      digitalWrite(led1,HIGH);
    }
    if(Orden == '2'){
      digitalWrite(led2,HIGH);
    }
    if(Orden == '3'){
      digitalWrite(led3,HIGH);
    }
    if(Orden == '4'){
      digitalWrite(led4,HIGH);
    }
    if(Orden == '5'){
      digitalWrite(led1,LOW);
    }
    if(Orden == '6'){
      digitalWrite(led2,LOW);
    }
    if(Orden == '7'){
      digitalWrite(led3,LOW);
    }
    if(Orden == '8'){
      digitalWrite(led4,LOW);
    }
    if(Orden == '0'){
      digitalWrite(led1,LOW);
      
      digitalWrite(led2,LOW);
      
      digitalWrite(led3,LOW);
      
      digitalWrite(led4,LOW);
    }
  }
}
