
#include <Servo.h> 
Servo myservo1, myservo2, myservo3;

 int  ENA = 8;      ///////////////////
 int  IN1 = 9;      //
 int  IN2 = 10;     // Motor Sürücü  
 int  IN3 = 11;     // Pin Ayarları 
 int  IN4 = 12;     //
 int  ENB = 13;     //////////////////

void setup()
{
  myservo1.attach(2);      // Sağ tarafdaki servo.İleri-Geri gitmeyi sağlayan servo
  myservo2.attach(9);      // Sol tarafdaki servo.Yukarı-Aşağı hareketi sağlar
  myservo3.attach(10);      // Açma-Kapama yapan servo
  pinMode(IN1, OUTPUT);    ///////////////////////////    
  pinMode(IN2, OUTPUT);    //  Motor Pinleri Çıkış
  pinMode(IN3, OUTPUT);    //  Olarak Ayarlandı
  pinMode(IN4, OUTPUT);    ////////////////////////////
  
  digitalWrite(IN1 ,LOW);   /////////////////////////
  digitalWrite(IN2 ,LOW);   // Bütün pinler LOW yapılarak
  digitalWrite(IN3 ,LOW);   // Motorlar ilk çalışmada hareketsiz yapıldı.
  digitalWrite(IN4 ,LOW);   /////////////////////////

  digitalWrite(ENA,HIGH);   // Motor-1 aktifleştirme            
  digitalWrite(ENB,HIGH);   // Motor-2 aktifleştirme
  
  Serial.begin(9600);       // Seri haberleşme hızı
}

void loop()
{
  ///////////// BLUETOOTH HABERLEŞMESİ //////////////////////////////////////////////////////////////
  if(Serial.available()>= 2 )                          ///////////////////////////////////////////////
  {                                                    //
    unsigned int servopos = Serial.read();             //  Bluetooth ile gönderilen veri 2bytelıktır.
    unsigned int servopos1 = Serial.read();            //  Gelen veri okunur ve Serial ekrana yazdırılır.
    unsigned int data = (servopos1 *256) + servopos;   // 
    Serial.println(data);                              /////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////// SERVO KONTROLLERİ ///////////////////////////////////////////////////////////////////////
    if (data >= 1000 && data <1180)                    ////////////////////////////////////////////////
    {                                                  //
      int servo1 = data;                               //  Gelen veri 1000-1180 arasında ise gelen veri
      servo1 = map(servo1, 1000,1180,80,170);          //  map fonksiyonu ile 80-170 arasına sığdırılır
      myservo1.write(servo1);                          //  ve servo1 isimli servoya o değer verilir
      delay(10);                                       //
    }                                                  /////////////////////////////////////////////////
    
    if (data >=2000 && data <2180)                     ////////////////////////////////////////////////
    {                                                  //
      int servo2 = data;                               // Gelen veri 2000-2180 arasında ise gelen veri
      servo2 = map(servo2,2000,2180,30,120);           // map fonksiyonu ile 30-120 arasına sığdırılır
      myservo2.write(servo2);                          // ve servo2 isimli servoya o değer verilir.
      delay(10);                                       //
    }                                                  /////////////////////////////////////////////////
    
    if (data >=3000 && data < 3180)                    /////////////////////////////////////////////////
    {                                                  //
      int servo3 = data;                               // Gelen veri 3000-3180 arasında ise gelen veri
      servo3 = map(servo3, 3000, 3180,80,140);         // map fonksiyonu ile 80-140 arasına sığdırılır
      myservo3.write(servo3);                          // ve servo3 isimli servoya o değer verilir.
      delay(10);                                       //
    }                                                  /////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// YÖN KONTROLLERİ ////////////////////////////////////////////////////////////////////////
    if(data == 4008)                                   ////////////////////////////////////////////////
    {                                                  //                                                   
      digitalWrite(IN1,HIGH);                          // 
      digitalWrite(IN2,LOW);                           // Gelen veri 4008 ise Robot İLERİ yönde gider
      digitalWrite(IN4,HIGH);                          //
      digitalWrite(IN3,LOW);                           //
    }                                                  /////////////////////////////////////////////////
    if(data == 4002)                                   ////////////////////////////////////////////////
    {                                                  //
      digitalWrite(IN1,LOW);                           //
      digitalWrite(IN2,HIGH);                          // Gelen veri 4002 ise Robot GERİ yönde gider
      digitalWrite(IN4,LOW);                           //
      digitalWrite(IN3,HIGH);                          //
    }                                                  /////////////////////////////////////////////////
    if(data == 4004)                                   /////////////////////////////////////////////////
    {                                                  //
      digitalWrite(IN1,HIGH);                          //
      digitalWrite(IN2,LOW);                           // Gelen veri 4004 ise Robot SOLA döner
      digitalWrite(IN4,LOW);                           //
      digitalWrite(IN3,HIGH);                          //
    }                                                  /////////////////////////////////////////////////
    if(data == 4006)                                   /////////////////////////////////////////////////
    {                                                  //
      digitalWrite(IN1,LOW);                           //
      digitalWrite(IN2,HIGH);                          // Gelen veri 4006 ise Robot SAĞA döner
      digitalWrite(IN4,HIGH);                          //
      digitalWrite(IN3,LOW);                           //
    }                                                  //////////////////////////////////////////////////
    if(data == 4005)                                   //////////////////////////////////////////////////
    {                                                  //
      digitalWrite(IN1,LOW);                           //
      digitalWrite(IN2,LOW);                           // Gelen veri 4005 ise Robot DURUR
      digitalWrite(IN4,LOW);                           //
      digitalWrite(IN3,LOW);                           //
    }                                                  //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////// 
  }


}
