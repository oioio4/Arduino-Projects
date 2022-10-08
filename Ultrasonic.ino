#include <HCSR04.h>
int ledRed = 4;
int ledYellow = 5;
int ledGreen = 7;
int buzzer = 9;
int echo = 6;
int trigger= 8;

long readTime(int echo, int trigger) {
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger, LOW);
  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH);
}


void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int distance;
  distance = 0.01715 * readTime(trigger, echo);

  if(distance > 25){
    green();
  }
  else if(distance > 10 && distance < 25){
    yellow();
  }
  else if(distance < 10){
    red();
  }
}

void green(){
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(buzzer, LOW);
  delay(100);
}

void yellow(){
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(buzzer, LOW);
  delay(100);
}

void red(){
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(buzzer, HIGH);
  delay(100);
}
