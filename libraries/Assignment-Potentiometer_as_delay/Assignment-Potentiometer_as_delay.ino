int pinpot = A0;
int LEDRED = 10;
int Readvalue;
int delayled;

void setup() {
  pinMode(pinpot,INPUT);
  pinMode(LEDRED,OUTPUT);

}

void loop() {
  Readvalue = analogRead(pinpot);
  delayled = (900./1023.)*Readvalue;
  analogWrite(LEDRED,255);
  delay(delayled);
  analogWrite(LEDRED,0);
  delay(delayled);


}

