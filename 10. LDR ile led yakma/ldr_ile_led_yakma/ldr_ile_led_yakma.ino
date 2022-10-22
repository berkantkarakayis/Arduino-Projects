int LDR_deger = 0;
 
//Tanımlanan LED pinleri
int Ledpin1 = 12;
int Ledpin2 = 11;
int Ledpin3 = 10;
int Ledpin4 = 9;
int Ledpin5 = 8;
 
//Okunun değişken LDR_pin olarak tanımlandı
int LDR_pin = 0;
 
void setup()
 
{
Serial.begin(9600);
//giriş çıkışlar belirlendi
pinMode(Ledpin1, OUTPUT);
pinMode(Ledpin2, OUTPUT);
pinMode(Ledpin3, OUTPUT);
pinMode(Ledpin4, OUTPUT);
pinMode(Ledpin5, OUTPUT);
 
}
 
void loop()
{
//Okunan deger LDR_deger ye atılıyor
LDR_deger = analogRead(LDR_pin);
 
//parametre aralıklarımız belirleniyor 0 ile 1023 arasında yani 10 bit kullanıyoruz
if(LDR_deger >= 1020)
{
digitalWrite(Ledpin1, HIGH);
digitalWrite(Ledpin2, HIGH);
digitalWrite(Ledpin3, HIGH);
digitalWrite(Ledpin4, HIGH);
digitalWrite(Ledpin5, HIGH);
}
else if((LDR_deger >= 1018) && (LDR_deger < 1023))
{
digitalWrite(Ledpin1, LOW);
digitalWrite(Ledpin2, HIGH);
digitalWrite(Ledpin3, HIGH);
digitalWrite(Ledpin4, HIGH);
digitalWrite(Ledpin5, HIGH);
}
else if((LDR_deger >= 1010) && (LDR_deger < 1018))
{
digitalWrite(Ledpin1, LOW);
digitalWrite(Ledpin2, LOW);
digitalWrite(Ledpin3, HIGH);
digitalWrite(Ledpin4, HIGH);
digitalWrite(Ledpin5, HIGH);
}
else if((LDR_deger >= 1003) && (LDR_deger < 1010))
{
digitalWrite(Ledpin1, LOW);
digitalWrite(Ledpin2, LOW);
digitalWrite(Ledpin3, LOW);
digitalWrite(Ledpin4, HIGH);
digitalWrite(Ledpin5, HIGH);
}
else if((LDR_deger >= 990) && (LDR_deger < 1003))
{
digitalWrite(Ledpin1, LOW);
digitalWrite(Ledpin2, LOW);
digitalWrite(Ledpin3, LOW);
digitalWrite(Ledpin4, LOW);
digitalWrite(Ledpin5, HIGH);
}
else
{
digitalWrite(Ledpin1, LOW);
digitalWrite(Ledpin2, LOW);
digitalWrite(Ledpin3, LOW);
digitalWrite(Ledpin4, LOW);
digitalWrite(Ledpin5, LOW);
}
Serial.print("LDR Deger: ");
Serial.print(LDR_deger);
Serial.println("www.makermalzeme.com");
delay(500);
 
}
