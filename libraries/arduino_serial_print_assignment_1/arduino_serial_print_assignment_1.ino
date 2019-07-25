int LEDRED=7;
int LEDGREEN=8;
int blinkred;
int blinkgreen;
int redon;
int redoff;
int greenon;
int greenoff;

void setup() {
  Serial.begin(9600);
  pinMode (LEDRED,OUTPUT);
  pinMode (LEDGREEN,OUTPUT);
  Serial.println("This is my number 2 program");
  Serial.println(" ");
}

void loop() {
  Serial.println("Blink #1 is RED"); 
  digitalWrite (LEDRED,HIGH);
  delay(1000);
  digitalWrite (LEDRED,LOW);
  delay(1000);
   

  Serial.println("Blink #2 is GREEN");
  digitalWrite (LEDGREEN,HIGH);
  delay(1000);
  digitalWrite (LEDGREEN,LOW);
  delay(1000);

  digitalWrite (LEDGREEN,HIGH);
  delay(1000);
  digitalWrite (LEDGREEN,LOW);
  delay(1000);
   
  
  Serial.println("Blink #3 is RED");
  digitalWrite (LEDRED,HIGH);
  delay(1000);
  digitalWrite (LEDRED,LOW);
  delay(1000);

  digitalWrite (LEDRED,HIGH);
  delay(1000);
  digitalWrite (LEDRED,LOW);
  delay(1000);

  digitalWrite (LEDRED,HIGH);
  delay(1000);
  digitalWrite (LEDRED,LOW);
  delay(1000);
  Serial.println(" ");
  
}
