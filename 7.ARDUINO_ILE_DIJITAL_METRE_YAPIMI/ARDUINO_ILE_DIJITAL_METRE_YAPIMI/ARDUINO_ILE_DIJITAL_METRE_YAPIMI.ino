#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int trigPin=2; //define trigPin 2
int echoPin=3; //define echoPin 3
int led=13;
void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,OUTPUT); 
 lcd.begin(16,2);
}

void loop() {
  int sure, uzaklik;
  lcd.clear(); 
  lcd.setCursor(0,0);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  uzaklik = (sure/58);
  
  if (uzaklik<25)
  {digitalWrite(led,HIGH);}
  else {digitalWrite(led,LOW);} 
  
  lcd.print("Uzaklik = ");
  lcd.print(uzaklik);
  lcd.print(" cm"); 
   delay(400);   
}
