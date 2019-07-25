 #include <SPI.h>
#include <MFRC522.h>
#include <Stepper.h>

 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

float num_turns;

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 2,4,3,5);

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

   // set the speed at 60 rpm:
  myStepper.setSpeed(5);

  Serial.println("How many times should the stepper motor turn?");
  while(Serial.available() == 0) {};
  num_turns = Serial.parseFloat();
  Serial.println(" ");
  
  Serial.println("Please tap your card...");
  Serial.println();


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
  if (content.substring(1) == "89 3C 30 5B" || content.substring(1) == "10 6A BB 4F") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution * num_turns);
    delay(500);
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution * num_turns);
    delay(500);
    Serial.println("Items dispensed.");
    Serial.println();
    delay(500);
  }

  
  
 else   {
    Serial.println(" Thank you for your purchase. ");
    delay(3000);
  }
} 
