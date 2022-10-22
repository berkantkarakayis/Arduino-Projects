#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8); //Bluetooth Tx,Rx uçları
#include <Servo.h>

    Servo motor1;
    Servo motor2;
    Servo motor3;
    Servo motor4;
    int servoPos; // Genel Servo motor pozisyon değeri
    int servoPos1=135; // Servo motor1 pozisyon değeri
    int servoPos2=50; // Servo motor2 pozisyon değeri
    int servoPos3=180; // Servo motor3 pozisyon değeri
    int servoPos4=80; // Servo motor2 pozisyon değeri

      String VeriAl="dur"; //Bluetooth cihazından gelecek sinyalin değişkeni
      int DonusHizi=30;     // Standart Hız, 0-255 arası bir değer alabilir
Servo servo_motor;
//4 - 3 SOL - -- 5 - 6 SAĞ
int i;
int j = 0;
int k = 0;

int lDIR = 4; //in1 motor sürücünün pini arduino dijital 4 e girecek
int lPWM = 3; //in2 motor sürücünün pini arduino dijital 3 e girecek
int rDIR = 5; //in3 motor sürücünün pini arduino dijital 5 e girecek
int rPWM = 6; //in4 motor sürücünün pini arduino dijital 6 e girecek
int Buzzer = 16;//A1
int trigPin = 12;    //Trig
int echoPin = 11;    //Echo

String readString;

bool ivme = false;
bool buton = false;
bool dur = false;
bool servo = false;
bool cizgi = false;

byte servo_aci = 0;

long duration, cm, inches;

void setup()
{
      motor1.attach(2);
      motor2.attach(9);
      motor3.attach(10);
      motor4.attach(13);   
  
 
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(lDIR, OUTPUT);
  pinMode(lPWM, OUTPUT);
  pinMode(rDIR, OUTPUT);
  pinMode(rPWM, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  BT.begin(9600); // Bluetooth için;
  // 9600 baud hızında bir seri port açalım

}





void loop()
{     
      
      if (VeriAl=="dur")
       {
        Serial.println("Motorlar Duruyor");
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4);
        }
  Serial.println("Loop Döngü Başı");   // delay(2000);
basa:
  while (BT.available())
  {
    delay(3);
    char c = BT.read();  // Seri Porttan Gelen Veriyi Tek Karakter Oku
    readString += c;     // Tek Karakter Okunan veriyi Birleştir.
  }
    
    Serial.println(readString); // Yön tuş Komutlarını veren String
    
  if (readString.length() > 0)
  {
    VeriAl=readString;  // Seri Porttan Gelen veriyi Aldığımız yer
    Serial.println(readString); 

    if (readString == "i")
    {
      j = 0;
      k = 0;
      ivme = true;
      buton = false;
      dur = false;
      cizgi = false;
      servo = false;
      servo_motor.detach();
    }
    if (readString == "b")
    {
      j = 0;
      k = 0;
      buton = true;
      ivme = false;
      dur = false;
      servo = false;
      cizgi = false;
      servo_motor.detach();
    }
    

/****************************************************/
      //Gelen veri 'sol' ise 4. Motor sola döner.
    if ((VeriAl == "sol")&&(servoPos4<180))
        {
          Serial.println("içinde_____Sol");
          servoPos4++;
          motor4.write(servoPos4);  delay(DonusHizi); 
        }
             
/****************************************************/
    //Gelen veri 'sag' ise 4. Motor sağa döner.
    if ((VeriAl == "sag")&&(servoPos4>0))
        {
           Serial.println("içinde______Sağ");
           servoPos4--;
           motor4.write(servoPos4);  delay(DonusHizi); 
        } 

/******************************************************/
       //Gelen veri 'ileri' ise 3. Motor öne döner.
    if ((VeriAl == "ileri")&&(servoPos3>1))
        {
          Serial.println("içinde_____İleri");
          servoPos3--;
          motor3.write(servoPos3);  delay(DonusHizi); 
        }
     
/****************************************************/
   //Gelen veri 'geri' ise 3. Motor arkaya döner.
    if ((VeriAl == "geri")&&(servoPos3<180))
        {
          Serial.println("içinde_____Geri");
           servoPos3++;
              motor3.write(servoPos3);  delay(DonusHizi); 
        }
/*****************************************************/

   //Gelen veri 'sagyukari' ise 2. Motor yukarı döner.
    if ((VeriAl == "sagyukari")&&(servoPos2<180))
        {
          Serial.println("içinde_____Yukarı");
          servoPos2++;
          motor2.write(servoPos2);  delay(DonusHizi); 
        }
     
/****************************************************/
   //Gelen veri 'sagasagi' ise 2. Motor aşağı döner.
    if ((VeriAl == "sagasagi")&&(servoPos2>0))
        {
          Serial.println("içinde_____Aşağı");
           servoPos2--;
              motor2.write(servoPos2);  delay(DonusHizi); 
        }

/******************************************************/
     //Gelen veri 'solyukari' ise 1. Motor sola döner.
    if ((VeriAl == "solyukari")&&(servoPos1>0))
        {
          Serial.println("içinde_____Bilek_Sol");
          servoPos1--;
          motor1.write(servoPos1);  delay(DonusHizi); 
        }
     
/****************************************************/
        //Gelen veri 'solasagi' ise 1. Motor sağa döner.
       if ((VeriAl == "solasagi")&&(servoPos1<180))
          {
            Serial.println("içinde_____Bilek_Sağ");
             servoPos1++;
                motor1.write(servoPos1);  delay(DonusHizi); 
          }}}
          
     
  
  





