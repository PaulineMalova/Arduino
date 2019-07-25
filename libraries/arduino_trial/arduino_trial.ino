int LEDRED=8;
int REDLED=10;
int blinkled;
int blinkred;
int j;
int delayledon;
int delayredon;
int delayledoff;
int delayredoff;

void setup() {
  Serial.begin(9600);
  pinMode(LEDRED,OUTPUT);
  pinMode(REDLED,OUTPUT);
  Serial.println("This is a personal arduino trial.");
  Serial.println(" ");

  Serial.print("How many times should the red LED blink?");
  while(Serial.available()==0) { };
  blinkled=Serial.parseInt();
  Serial.println(" ");

  Serial.print("How many times should the second LED blink?");
  while(Serial.available()==0) { };
  blinkred=Serial.parseInt();
  Serial.println(" ");

  Serial.print("For how long should the first LED be on?");
  while(Serial.available()==0) { };
  delayledon=Serial.parseInt();
  Serial.println(" ");

  Serial.print("For how long should the first LED be off?");
  while(Serial.available()==0) { };
  delayledoff=Serial.parseInt();
  Serial.println(" ");

  Serial.print("For how long should the second LED be on?");
  while(Serial.available()==0) { };
  delayredon=Serial.parseInt();
  Serial.println(" ");

  Serial.println("For how long should the second LED be off?");
  while(Serial.available()==0) { };
  delayredoff=Serial.parseInt();
  Serial.println(" ");

  
}

void loop() {
  for(j=1; j<=blinkled; j++) {
    Serial.println("Blink #1 is RED.");  
    digitalWrite(LEDRED,HIGH);
    delay(delayledon);
    digitalWrite(LEDRED,LOW);
    delay(delayledoff);
  }
  Serial.println(" ");

  for(j=1; j<=blinkred; j++) {
    Serial.println("Blink #2 is also RED.");
    digitalWrite(REDLED,HIGH);
    delay(delayredon);
    digitalWrite(REDLED,LOW);
    delay(delayredoff);
  }

  Serial.println(" ");
}
