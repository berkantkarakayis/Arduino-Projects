#include <Servo.h>

Servo servo;

int pot = A0;
int deger;

void setup() {
  servo.attach(9);
}

void loop() {
deger = analogRead(pot);
deger = map(deger,0,1023,0,180);
servo.write(deger);  
}
