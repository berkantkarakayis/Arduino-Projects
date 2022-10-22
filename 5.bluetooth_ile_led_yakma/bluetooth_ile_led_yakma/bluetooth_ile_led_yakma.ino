//Bluetooth bağlantısı 

//Bluetooth pinleri      Arduino pin girişleri
//Vcc------------------>>> Vcc
//GND------------------>>> GND
//TXD------------------>>> RXD
//RXD------------------>>> TXD

int data;
int led1=11;
int led2=12;
int led3=13;
void setup()
{
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
Serial.begin(9600);   //Seri iletişimi başlatır
}
void loop()
{
if(Serial.available()) // Eğer Bluetooth bağlantısı varsa kodaları çalıştırır
{
int data = Serial.read();
delay(100);
if(data=='1')
digitalWrite(led1,1);
if(data=='2')
digitalWrite(led1,0);
if(data=='3')
digitalWrite(led2,1);
if(data=='4')
digitalWrite(led2,0);
if(data=='5')
digitalWrite(led3,1);
if(data=='6')
digitalWrite(led3,0);
delay(100);
}
}

