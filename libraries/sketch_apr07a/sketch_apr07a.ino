int LEDRED=7;
int LEDGREEN=10;
int blinkred;
int blinkgreen;
int j;
int delayredon;
int delayredoff;
int delaygreenon;
int delaygreenoff;

void setup() {
  Serial.begin(9600);
  pinMode(LEDRED,OUTPUT);
  pinMode(LEDGREEN,OUTPUT);
  Serial.println("This is fun guyz!!");
  Serial.println(" ");

  Serial.print("How many times should the red LED blink?");
  while(Serial.available()==0) { }; 
  blinkred=Serial.parseInt();
  Serial.println(" ");

  

  Serial.print("For how long should the red LED be on?");
  while(Serial.available()==0) { };
  delayredon=Serial.parseInt();
  Serial.println(" ");
}

void loop() {
  for(j=1; j<=blinkred; j++) {
    Serial.println("Blink #1 is RED.");
    digitalWrite(LEDRED,HIGH);
    delay(delayredon);
    digitalWrite(LEDRED,LOW);
    delay(delayredoff);
  }
  Serial.println(" ");

  for(j=1; j<=blinkgreen; j++) {
    Serial.println("Blink #2 is GREEN");
    digitalWrite(LEDGREEN,HIGH);
    delay(delaygreenon);
    digitalWrite(LEDGREEN,LOW);
    delay(delaygreenoff);
  }
  Serial.println(" ");
}
