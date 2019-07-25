int LED=7;
int PIR=5;
int Readvalue;

void setup() {
  pinMode (LED,OUTPUT);
  pinMode (PIR,INPUT);

}

void loop() {
  Readvalue=digitalRead(PIR);
  if(Readvalue==HIGH){
     digitalWrite(LED,HIGH);
    }
  else{
     digitalWrite(LED,LOW);   
  }
    

}


