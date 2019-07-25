int TRIG=7;
int ECHO=8;
float distance;
float Time;

void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  Time=pulseIn(ECHO,HIGH);
  distance=(0.0343*Time)/2;
  Serial.print("Distance= ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
}
