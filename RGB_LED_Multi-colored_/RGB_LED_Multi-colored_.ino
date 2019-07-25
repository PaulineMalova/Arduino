int redPin = 11;
int greenPin = 10;
int bluePin = 6;
int brightness = 255;
String colorChoice;

void setup() {
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);

}

void loop() {
  Serial.println("What color would you like the LED? (red, green or blue)");
  while (Serial.available() == 0) { }
  colorChoice = Serial.readString();

  if (colorChoice == "red") {
    analogWrite(redPin, brightness);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }

  if (colorChoice == "blue") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, brightness);
  }

  if (colorChoice == "green") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, brightness);
    analogWrite(bluePin, 0);
  }

  if (colorChoice == "yellow") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, brightness);
    analogWrite(bluePin, brightness);
  }

  if (colorChoice == "violet") {
    analogWrite(redPin, brightness);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, brightness);
  }

  if (colorChoice == "redgreen") {
    analogWrite(redPin, brightness);
    analogWrite(greenPin, brightness);
    analogWrite(bluePin, 0);
  }

  if (colorChoice!="red" && colorChoice!= "green" && colorChoice!= "blue" && colorChoice!= "yellow" && colorChoice!="violet" && colorChoice!= "redgreen") {
    Serial.println("That is not a valid color choice, please try again.");
    Serial.println(" ");
  }
}
