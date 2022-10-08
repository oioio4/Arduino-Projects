#include <LiquidCrystal.h>  
int dice1;
int dice2;
int led = 6;
int button = 7;
int buzzer = 8;
int val;
byte pos1[] = {
  B00000,
  B00000,
  B11111,
  B11001,
  B10101,
  B10011,
  B11111,
  B00000
};
byte pos2[] = {
  B00000,
  B00000,
  B11111,
  B10101,
  B10101,
  B10101,
  B11111,
  B00000
};
byte pos3[] = {
  B00000,
  B00000,
  B11111,
  B10011,
  B10101,
  B11001,
  B11111,
  B00000
};
byte pos4[] = {
  B00000,
  B00000,
  B11111,
  B10001,
  B11111,
  B10001,
  B11111,
  B00000
};
LiquidCrystal lcd(12,11, 5, 4, 3, 2); 

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, pos1);
  lcd.createChar(1, pos2);
  lcd.createChar(2, pos3);
  lcd.createChar(3, pos4);
  lcd.home();
  pinMode(led, OUTPUT);
  pinMode(button, OUTPUT);
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(0));
  lcd.write(byte(0));
  lcd.print("Digital Dice");
  lcd.write(byte( 0));
  delay(1000);
}

void loop() {
  val = digitalRead(button);
  if (val == HIGH)
  {
     lcd.clear();
     lcd.print("Rolling dice...");
     delay(1000);
     digitalWrite(led, HIGH);
     digitalWrite(buzzer, HIGH);
     delay(300);
     digitalWrite(buzzer, LOW);
     lcd.clear();
     lcd.setCursor(0, 0);
     dice1 = random(1, 7);
     lcd.write(byte(0));
     lcd.print("1 = ");
     lcd.print(dice1);
     lcd.setCursor(10, 0);
     dice2 = random(1, 7);
     lcd.write(byte(0));
     lcd.print("2 = ");
     lcd.print(dice2);
     int n = 3;
     while(n!= -1){
       lcd.setCursor(0, 1);
       lcd.write(byte(n));
       lcd.setCursor(15, 1);
       lcd.write(byte(n));
       delay(500);
       n--;
      } 
     if (n = -1){
       n = 3;
      }    
     lcd.setCursor(3, 1);
     lcd.print("Total = ");
     int total = dice1 + dice2;
     if (total < 10){
      lcd.print(0);
      lcd.print(total);
     }
     else{
      lcd.print(total);
      }
     delay(1000);
     digitalWrite(led, LOW);
      }
  delay(200);
}
