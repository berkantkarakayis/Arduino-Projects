#include <Servo.h>
int pos1 = A0;
int pos2 = A1;
int pos3 = A2;
int pos4 = A3;
Servo myservo;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int deger_1_1 = 200;
int deger_2_2 = 200;
int deger_3_3 = 200;
int deger_4_4 = 200;
void setup()
{
myservo.attach(3);
myservo2.attach(5);
myservo3.attach(6);
myservo4.attach(9);
}
void loop()
{
int deger_1 = analogRead(pos1);
deger_1 = map(deger_1,0,1023,0,90);
if (deger_1 != deger_1_1);
{
deger_1_1 = deger_1;
myservo.write(deger_1);
}
int deger_2 = analogRead(pos2);
deger_2 = map(deger_2,0,1023,0,90);
if (deger_2 != deger_2_2);
{
deger_2_2 = deger_2;
myservo2.write(deger_2);
}
int deger_3 = analogRead(pos3);
deger_3 = map(deger_3,0,1023,0,90);
if (deger_3 != deger_3_3);
{
deger_3_3 = deger_3;
myservo3.write(deger_3);
}
int deger_4 = analogRead(pos4);
deger_4 = map(deger_4,0,1023,0,180);
if (deger_4 != deger_4_4);
{
deger_4_4 = deger_4;
myservo4.write(deger_4);
}
}
