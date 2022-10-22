
#include <Servo.h>
                  //Bluetooth uçlarında Tx->Rx'e be Rx->Tx'e akılacak
    Servo motor1;
    Servo motor2;
    Servo motor3;
    Servo motor4;
    int servoPos; // Genel Servo motor pozisyon değeri
    int servoPos1=135; // Servo motor1 pozisyon değeri
    int servoPos2=50; // Servo motor2 pozisyon değeri
    int servoPos3=180; // Servo motor3 pozisyon değeri
    int servoPos4=80; // Servo motor2 pozisyon değeri

  int i=0; //Döngüler için atanan rastgele bir değişken
  int j=0; //Döngüler için atanan rastgele bir değişken
  int VeriAl; //Bluetooth cihazından gelecek sinyalin değişkeni
  int DonusHizi=100;     // Standart Hız, 0-255 arası bir değer alabilir

void setup() {
   motor1.attach(8);
    motor2.attach(9);
    motor3.attach(11);
    motor4.attach(12);   
    // 9600 baud hızında bir seri port açalım
    Serial.begin(9600);
}
 
void loop() {

      motor1.write(servoPos1);
      motor2.write(servoPos2);
      motor3.write(servoPos3);
      motor4.write(servoPos4);
  
  //Gelen veriyi 'VeriAl' değişkenine kaydet
    if(Serial.available() > 0){     
      VeriAl = Serial.read(); 
       Serial.println(VeriAl); delay(300);
       
    }
  
  /* Uygulamadan ayarlanabilen 4 hız seviyesi.(Değerler 0-255 arasında olmalı)*/
    if (VeriAl == '1'){
      DonusHizi=20;}
    else if (VeriAl == '2'){
      DonusHizi=50;}
    else if (VeriAl == '3'){
      DonusHizi=100;}
    else if (VeriAl == '4'){
      DonusHizi=150;}
    else if (VeriAl == '5'){
      DonusHizi=200;}

   /*******************************************************/
    
  //Gelen veri 'H' ise Tüm Motorlar Dur.
    if (VeriAl == 'H')
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
     
  /***************************************************/
    
  //Gelen veri 'G' ise 4. Motor sola döner.
    if ((VeriAl == 'G')&&(servoPos4<179))
        {
          servoPos4++;
          motor4.write(servoPos4);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
     
  /****************************************************/
  //Gelen veri 'I' ise 4. Motor sağa döner.
    if ((VeriAl == 'I')&&(servoPos4>1))
        {
           servoPos4--;
              motor4.write(servoPos4);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
/******************************************************/
       //Gelen veri 'C' ise 3. Motor öne döner.
    if ((VeriAl == 'C')&&(servoPos3>1))
        {
          servoPos3--;
          motor3.write(servoPos3);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
     
  /****************************************************/
   //Gelen veri 'M' ise 3. Motor arkaya döner.
    if ((VeriAl == 'M')&&(servoPos3<180))
        {
           servoPos3++;
              motor3.write(servoPos3);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
    
  /*****************************************************/

   //Gelen veri 'E' ise 2. Motor yukarı döner.
    if ((VeriAl == 'E')&&(servoPos2<179))
        {
          servoPos2++;
          motor2.write(servoPos2);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
     
  /****************************************************/
   //Gelen veri 'O' ise 2. Motor aşağı döner.
    if ((VeriAl == 'O')&&(servoPos2>1))
        {
           servoPos2--;
              motor2.write(servoPos2);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
    
  /******************************************************/

     //Gelen veri 'B' ise 1. Motor sola döner.
    if ((VeriAl == 'B')&&(servoPos1>0))
        {
          servoPos1--;
          motor1.write(servoPos1);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
     
  /****************************************************/
 
   //Gelen veri 'D' ise 1. Motor sağa döner.
    if ((VeriAl == 'D')&&(servoPos1<180))
        {
           servoPos1++;
              motor1.write(servoPos1);  delay(DonusHizi); 
        }
        else
        {
          motor1.write(servoPos1);
          motor2.write(servoPos2);
          motor3.write(servoPos3);
          motor4.write(servoPos4); 
        }
    
  /*******************************************************/
  // VeriAl = 'H';
}
