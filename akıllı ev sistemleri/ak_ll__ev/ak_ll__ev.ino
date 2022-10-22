#include <SoftwareSerial.h> // gerekli olan kütüphane.
#include <Servo.h> // servomotor için gerekli olan kütüphane

 Servo myservomotor; // sınıfın bir örneğini aldık
 SoftwareSerial myBluetooth(10, 11); // Bluetooth modülün RX, TX ayakları 10 ve 11 e bağlanacak.
 int ledPinOpen=5; // 5. pin led çıkış olacak.
 int ledPinClose=6; // 6. pin led çıkış olacak.
 int ledPinBell=4; // 6. pin led çıkış olacak.
 int buzzerPin=7; // 7. pin buzzer çıkış olacak.
 int buttonPin=2; // 2. pin button giriş olacak.
 char deger; // Android uygulamadan gelecek olan değer
 int buttonState = 0;  
 float sicaklik;
 float gerilim;
 int sicaklikPin = 0; // analog giriş

void setup() {
Serial.begin(9600);
myservomotor.attach(8);             // arduinonun 8. pinini servo çıkış olacak.
myservomotor.write(0);               // motoru çev
myBluetooth.begin(9600);          // 10 ve 11 den okuma başlasın.
pinMode(buzzerPin,OUTPUT);   // çıkış olacak
pinMode(buttonPin,INPUT);      // giriş olacak
digitalWrite(ledPinClose,HIGH);
}

void loop() {
gerilim = analogRead(sicaklikPin); // analog degeri oku
gerilim = (gerilim/1023)*5000;        // analog deger mv ye çevirir.
sicaklik = gerilim/10.0;                         // celciusa çevirip sicakliğa atadık.

buttonState = digitalRead(buttonPin);  // butondan gelen degeri oku
   if (myBluetooth.available())                         // bluetooth bağlantısı varsa
   {
deger=myBluetooth.read();    // bluetooth'tan gelen degeri oku

if(deger == '1'){ // gelen değer 1 ise
myBluetooth.println("Kapi Acildi");         // bluetooth üzerinden değer döndür.  bu dönen değeri android uygulamasında görülür
for(int derece = 0; derece < 90; derece++){
myservomotor.write(derece);                // motoru çevir
        }
   }
if (deger == '0'){
digitalWrite(ledPinOpen,0); // ledi sondur
digitalWrite(ledPinClose,1); // ledi yak
myBluetooth.println("Kapi Kapandi");
for(int derece = 90; derece > 1; derece){ // 90 derecelik açı yap
myservomotor.write(derece); // motoru çevir
      }
   }
 if(deger == '2')
  { 
myBluetooth.print("Ortam sicakligi ");
myBluetooth.print(sicaklik);
myBluetooth.print(" derecedir.");
   }
}
if (buttonState == HIGH) {
myBluetooth.println("Kapi Zili Caldi");
digitalWrite(buzzerPin, HIGH);
delay(1000);
} 
else {
digitalWrite(buzzerPin, LOW);
digitalWrite(ledPinBell, LOW);
}
delay(100);   // bir sonraki veriyi hazırlamak için

}
