#include<Wire.h>
#include<LiquidCrystal_I2C.h>

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2);

 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int turn;

Servo servopin;

void setup() 
{
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  servopin.attach(7);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin(); 
  mfrc522.PCD_Init();   // Initiate MFRC522


}
void loop() 
{
  Serial.println("What angle should the servo motor turn?");
  lcd.setCursor(0,0);
  lcd.print("What angle?");
  while(Serial.available() == 0) {}
  turn = Serial.parseInt();
  lcd.setCursor(0,1);
  lcd.print(turn);
  delay(1000);
  lcd.clear();
  
  Serial.println(" ");
  
  Serial.println("Please tap your card...");
  Serial.println();

  lcd.setCursor(0,0);
  lcd.print("Tap your card...");
  
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
  if (content.substring(1) == "89 3C 30 5B" || content.substring(1) == "10 6A BB 4F") //change here the UID of the card/cards that you want to give access
  {
    lcd.clear();
    servopin.write(turn);
    lcd.setCursor(0,0);
    lcd.print("Items dispensed");
    Serial.println("Items dispensed.");
    Serial.println();
    delay(500);
  }

  
  
 else   {
    lcd.setCursor(0,1);
    lcd.print("Thank you");
    Serial.println(" Thank you for your purchase. ");
    delay(3000);
  }
} 
