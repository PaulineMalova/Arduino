# include <LiquidCrystal.h>
# include <Servo.h>



int pinpot = A0;
LiquidCrystal lcd (7,8,9,10,11,12);
int LEDRED = 6;
int LEDGREEN = 5;
int readvalue;
Servo servopin;
int TRIG = 3;
int ECHO = 2;
float distance;
float Time;
int PIR = 4;
int turn;
int readvaluepir;
int Brightness;



void setup() {
  servopin.attach(13);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(PIR,INPUT);
  pinMode(LEDRED,OUTPUT);
  pinMode(LEDGREEN,INPUT);
  pinMode(pinpot,INPUT);
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(19200);
  Serial.println("This is the beginning of the program.");

}

void loop() {
  lcd.setCursor(0,0);
  readvaluepir = digitalRead(PIR);
  readvalue = analogRead(pinpot);
  Brightness = (255./1023.)*readvalue;
  if (readvaluepir == HIGH) {
    lcd.print("Alert!");
    digitalWrite(TRIG,LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG,LOW);
    Time = pulseIn(ECHO,HIGH);
    distance = (0.0343*Time)/2;
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");

    turn = (360./1023.)*distance;
    servopin.write(turn);

    if (turn >= 0 && turn <= 90) {
      analogWrite(LEDRED, Brightness);
      analogWrite(LEDGREEN,0);
      Serial.println("The intruder is very close");
    }

    else{
      analogWrite(LEDRED,0);
      analogWrite(LEDGREEN,Brightness);
      Serial.println("An intruder is approaching but is a little far.");
    }
    
  }

  else{
    lcd.print("Scanning...");
  }

  Serial.println(" ");
  delay(1000);
}
