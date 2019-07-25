int red=5;
int amber=12;
int green=11;
int button=2;
int buttonValue=0;


void setup() {
 pinMode(red,OUTPUT);
 pinMode(amber,OUTPUT); 
 pinMode(green,OUTPUT);
 pinMode(button,INPUT);
}

void loop() {
  buttonValue= digitalRead(button);
  if (buttonValue == HIGH){
   changeLights();
  }
}
void changeLights(){
  digitalWrite(red,HIGH);
  delay(5000);
  digitalWrite(amber,HIGH);
 delay(2000);
 digitalWrite(red,LOW);
 digitalWrite(amber,LOW);
 digitalWrite(green,HIGH);
 delay(5000);
 digitalWrite(green,LOW);
 delay(5000);
}

