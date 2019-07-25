int PIR=5;
int servopin=4;
int pulse=1500;
int Readvalue;

void setup() {
  pinMode(PIR,INPUT);
  pinMode(servopin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  Readvalue=digitalRead(PIR);
  if (Readvalue==HIGH){
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulse);
    Serial.print("Readvalue = ");
    Serial.print(Readvalue);
    Serial.print("  ");
    Serial.print("Pulse = ");
    Serial.println(pulse);
    Serial.println(" ");
  }
  else{
    digitalWrite(servopin,LOW);
    delay(20);
    Serial.print("Readvalue = ");
    Serial.println(Readvalue);
  }

}
