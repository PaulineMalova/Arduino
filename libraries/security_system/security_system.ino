int PIR = 7;
int led = 9;
int buzzer = 10;


void setup() {
  pinMode(PIR, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(PIR) == HIGH){
    digitalWrite(led, HIGH);
     digitalWrite(buzzer, HIGH);
     delay(1000);
      digitalWrite(led, LOW);
      delay(1000);
      Serial.println("THIEF! THIEF!");
  }
  else{
     digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
      Serial.println("Scanning...");
      delay(1000);
  }
}
     
