int LEDRED=10;

void setup() {
  pinMode(LEDRED,OUTPUT);

}

void loop() {
  analogWrite(LEDRED,128);
  delay(1000);
  analogWrite(LEDRED,0);
  delay(1000);

}
