String a = "Cell A        : ";
String b = "Cell B        : ";
String c = "Cell(A*B)     : ";
String d = "Cell (A+B)    : ";
String e = "[15,21,19,23]";
String f = "[21,16,24,15]";
String g = "[13,26,28,11]";
String h = "[12,12,12,12]";

void setup() {
  Serial.begin(9600);
  Serial.print(a);
  Serial.println(e);
  Serial.print(b);
  Serial.println(f);
  Serial.print(c);
  Serial.println(g);
  Serial.print(d);
  Serial.println(h);
  Serial.println(" ");

  Serial.println("Name        : Mary");
  Serial.println("Age         : 21");
  Serial.println("Weight      : 60kgs");
  Serial.println("Occupation  : Teller");
}

void loop() {
  // put your main code here, to run repeatedly:

}
