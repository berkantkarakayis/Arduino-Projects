#include<LiquidCrystal.h> //lcd kullanımı için kütüphane çağrılmıştır.
#include<Servo.h> //servo kullanimi icin kütüphane çağrılmıştır
#define arkaisik A3 //lcd arka isik A3 pininden ayarlanir
//#define Servo1 2 //servo 2 numarali pine takilir //servo pini tanimlamanin 1. yontemi
#define sicakliksensor A0 //sicaklık sensor cikisi A0 portundan okunur
 
float sicaklik;
LiquidCrystal lcd(12, 11, 6, 5, 4, 3); //lcd icin kullanilan portlar tanimlandi

Servo Servo1;//servo kontrolü icin Servo1 adlı bir nesne tanimlanir
int potpin= A1;//POTANSİYOMETRE A1 portuna baglanir
int potdeg; //pot cikisi okunur
int potdeger=0;

void setup(){
  Servo1.attach(2);//servo 2 numarali pine takilir //servo pini tanimlamanin 2. yontemi
  Serial.begin(9600);//Serial Monutorden verileri gorebilmek icin yapılmıstır
  //9600 baud rate denilen saniyede gönderilebilecek veri sayisidir.

  pinMode(arkaisik,OUTPUT); //LCD ARKA AYDİNLATMASİ CİKİS OLARAK TANİMLANİR
  digitalWrite(arkaisik,HIGH);// ve arka adinlatma acilir

  lcd.begin(16,2);//16 satır 2 sutun lcd kullanildigini tanimlar
} 

void loop()
{

potdeg = analogRead(potpin);//potansiyometre degeri okunur 

sicaklik=analogRead(sicakliksensor); //sicaklik sensör çıkışı okunur

sicaklik=(5.0*sicaklik*100.0)/1024.0;//okunan analog sensor degerini sicakliga cevirir 

Serial.print("Potansiyometre degeri = ");//Serial Monitore deger yazilir
Serial.println(potdeg); 

Serial.print("Sicaklik = ");
Serial.println(sicaklik);

potdeger=potdeg;

potdeg= map(potdeg,0,1023,0,180);//okunan potansiyometre degerine gore koordineli sekilde servonun hareketini sağlayan fonksiyon
//map fonksiyonu okunan sensor degerini (0,1023) servonun donus acisi (0,179) koordine eder
Servo1.write(potdeg);//yani potdeg'i servoyu sürmek icin servoya uyguladik. 

Serial.print("Servo donus acisi = ");
Serial.println(potdeg);

lcd.clear();//lcd ekranını temizler
lcd.print("GORUNEN DERECE ");//sevo acisi lcd ekrana yazilir



lcd.setCursor(6,1);
lcd.print(potdeg);


delay(100);//10 ms gecikme verilir.
}
