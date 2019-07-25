int LEDRED=7;
int LEDGREEN=8;
int blinkred;
int blinkgreen;
int redon;
int redoff;
int greenon;
int greenoff;
String message1="This is the ledred blink # ";
String message2="This is the ledgreen blink # ";


void setup() {
  Serial.begin(19200);
  pinMode (LEDRED,OUTPUT);
  pinMode (LEDGREEN,OUTPUT);
  Serial.println("This is my first program.");
  Serial.println(" ");

  Serial.print("How many blinks for the red LED?");
  while(Serial.available()==0){ };
  blinkred= Serial.parseInt();
  Serial.println(" ");

  Serial.print("How many blinks for the green LED?");
  while(Serial.available()==0){ };
  blinkgreen=Serial.parseInt();
  Serial.println(" ");

  Serial.print("For how long should the red LED be on?");
  while(Serial.available()==0){ };
  redon=Serial.parseInt();
  Serial.println(" ");

  Serial.print("For how long should the red LED be off?");
  while(Serial.available()==0){ };
  redoff=Serial.parseInt();
  Serial.println(" ");

  Serial.print("For how long should the green LED be on?");
  while(Serial.available()==0){ };
  greenon=Serial.parseInt();
  Serial.println(" ");

  Serial.print("For how long should the green LED be off?");
  while(Serial.available()==0){ };
  greenoff=Serial.parseInt();
  Serial.println(" ");
}

void loop() {
 for (int j=1; j<=blinkred; j=j+1) {
  Serial.print(message1);
  Serial.println(j);
  digitalWrite (LEDRED,HIGH);
  delay(redon);
  digitalWrite (LEDRED, LOW);
  delay(redoff);
 }
  Serial.println(" ");

  for (int i=1; i<=blinkgreen; i=i+1) {
    Serial.print(message2);
    Serial.println(i);
    digitalWrite (LEDGREEN,HIGH);
    delay(greenon);
    digitalWrite (LEDGREEN,LOW);
    delay(greenoff);
   
}

Serial.println(" ");

}
