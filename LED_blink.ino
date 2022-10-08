const int ledRed = 4;
const int ledYellow = 5;
const int ledGreen = 6;
const int ledBlue = 7;
void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode (ledBlue, OUTPUT);
}
void loop() {
  // like a traffic light 
  digitalWrite(ledRed, HIGH);
  delay(10000);
  digitalWrite(ledRed, LOW);
  delay(100);
  digitalWrite(ledYellow, HIGH);
  delay(1000);
  digitalWrite(ledYellow, LOW);
  delay(100);
  digitalWrite(ledGreen, HIGH);
  delay(10000);
  digitalWrite(ledGreen, LOW);
  delay(100);
}
