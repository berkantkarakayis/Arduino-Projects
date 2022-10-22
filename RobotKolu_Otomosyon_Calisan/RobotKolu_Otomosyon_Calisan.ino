/*
 4 adet SG90 9 g Micro Servo 
 Kontrolü
 */
#include <Servo.h>

    Servo motor1;
    Servo motor2;
    Servo motor3;
    Servo motor4;
    int servoPos; // Genel Servo motor pozisyon değeri
    int servoPos1; // Servo motor1 pozisyon değeri
    int servoPos2; // Servo motor2 pozisyon değeri
void setup() {
    motor1.attach(8);
    motor2.attach(9);
    motor3.attach(11);
    motor4.attach(12);
}

void loop() {

      motor1.write(135);
      motor2.write(50);
      motor3.write(180);
      motor4.write(80);

      
      // motor4 80'den 170 dereceye gidecek
    for (servoPos=80; servoPos<170; servoPos++)
      {
        motor4.write(servoPos);  delay(20);
      }    
     delay(1000);        
     
//------------------------------------------------------------

     // motor3 180'den 100 dereceye gidecek
     servoPos2=50;
    for (servoPos=180; servoPos>100; servoPos--)
      {
         if (servoPos2<130) 
                  { servoPos2++;}
           motor2.write(servoPos2);
       motor3.write(servoPos);              
        delay(20);
      }    
     delay(1000);  
     
//-------------------------------------------------

     // motor2 130'den 110 dereceye gidecek       
    for (servoPos2=130; servoPos2>110; servoPos2--)
      {
        motor2.write(servoPos2);  delay(20);
      }    
     delay(1000);
     
//-------------------------------------------------  
    
       // motor3 100'den 180 dereceye gidecek  
       servoPos2=110;     
    for (servoPos=100; servoPos<180; servoPos++)
      {
        if (servoPos2>50) 
             { servoPos2--; 
                motor2.write(servoPos2);
                }
       motor3.write(servoPos);              
        delay(20);
      }    
     delay(1000);

//-------------------------------------------------

 // motor1 135'den 80 dereceye gidecek
    for (servoPos1=135; servoPos1>80; servoPos1--)
      {
        motor1.write(servoPos1);  delay(20);
      }    
     delay(1000);

     // motor1 80'den 180 dereceye gidecek
    for (servoPos1=80; servoPos1<180; servoPos1++)
      {
        motor1.write(servoPos1);  delay(20);
      }    
     delay(1000);

     // motor1 180'den 135 dereceye gidecek
    for (servoPos1=180; servoPos1>135; servoPos1--)
      {
        motor1.write(servoPos1);  delay(20);
      }    
     delay(1000);

     
//-------------------------------------------------

 // motor4 170'den 80 dereceye gidecek
    for (servoPos=170; servoPos>80; servoPos--)
      {
        motor4.write(servoPos);  delay(20);
      }    
     delay(2000);  
    
}
