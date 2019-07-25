#include <SPI.h>
#include <MFRC522.h>

#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

Servo servopin;

int red = 5;
int blue = 7;
int numblink;

void setup() 
{
  servopin.attach(8);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  Serial.println("How many times should the LED blink?");
  while(Serial.available() == 0) { }
  numblink = Serial.parseInt();
  
  Serial.println("Please tap your card...");
  Serial.println();
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);


}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "89 3C 30 5B") //change here the UID of the card/cards that you want to give access
  {
    for (int j=1; j<=numblink; j++) {
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      delay(500);
      if (numblink>0 && numblink<=5){
        servopin.write(90);
       }
      else if (numblink>5){
        servopin.write(180);
      }
      servopin.write(0);
    }
    Serial.println("Items dispensed.");
    Serial.println();
    delay(500);
  }

  if (content.substring(1) == "10 6A BB 4F") //change here the UID of the card/cards that you want to give access
  {
    for (int j=1; j<=numblink; j++) {
      digitalWrite(blue, HIGH);
      delay(500);
      digitalWrite(blue, LOW);
      delay(500);
      if (numblink>0 && numblink<=5){
        servopin.write(90);
      }
      else if (numblink>5){
        servopin.write(180);
      }
      servopin.write(0);
    } 
    
    Serial.println("Items dispensed.");
    Serial.println();
    delay(500);
}
  
 else   {
    Serial.println(" Thank you for your purchase. ");
    delay(3000);
  }
  servopin.write(0);
} 
