#include <LiquidCrystal.h> /* LCD kullanimi icin kutuphane dahil edilmelidir */
#define trigPin 2  // trigPin motor 10 numarali pine baglandi 
#define echoPin 3  // echoPin motor 9 numarali pine baglandi 
#define led 13
#define buzzer 6 
/*
 Devre şeması;
 - LCD'nin RS pini -> Arduino'nun 12. pini
 - LCD'nin Enable (E) pini -> Arduino'nun 11. pini
 - LCD'nin D4 pini -> Arduino'nun 5. pini
 - LCD'nin D5 pini -> Arduino'nun 4. pini
 - LCD'nin D6 pini -> Arduino'nun 3. pini
 - LCD'nin D7 pini -> Arduino'nun 2. pini
 
 - LCD'nin R/W pini -> toprağa
 - LCD'nin R0 pini -> potansiyometre çıkışına
 - LCD VDD -> Arduino 5 Voltuna
 - LCD VSS -> toprağa
*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); /* LCDnin baglandigi Arduino pinleri */

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  lcd.begin(16, 2); /* Kullandigimiz LCDnin sutun ve satir sayisini belirtmeliyiz */
  lcd.clear();
}

void loop() {
  
  long sure, mesafe;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2) / 29.1;
  mesafe = map(mesafe, 0, 200, 0, 255);

  lcd.setCursor(0,0);
  lcd.print("Mesafe =");
  lcd.setCursor(9,0);
  lcd.print(mesafe);
  if(mesafe < 5)
  {
     digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(180);
    tone(buzzer,500);
    delay(100);
    noTone(buzzer);
    delay(150);
   
  }
  else if(mesafe < 15)
  {
    tone(buzzer,300);
    digitalWrite(led,HIGH);
    delay(12);
    noTone(buzzer);
    digitalWrite(led,LOW);
    delay(10);
  }
  
}
