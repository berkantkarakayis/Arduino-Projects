int q1 = 2;
int q2 = 4;
int q3 = 5;
int q4 = 6;
int q5= 7;
int q6 =8;
int q7 = 9;
int q8 = 10;

//qtr 1 arduino 2. pin
//qtr 2 arduino 4. pin
//qtr 3 arduino 5. pin
//qtr 4 arduino 6. pin
//qtr 5 arduino 7. pin
//qtr 6 arduino 8. pin
//qtr 7 arduino 9. pin
//qtr 8 arduino 10. pin



//sol motor
//arduino 3. pin l298n devrede ın1 pinine
//arduino 12. pin l298n devrede ın2 pinine


//sol motor
//arduino 11. pin l298n devrede ın4 pinine
//arduino 13. pin l298n devrede ın3 pinine
int l1 = 3;
int l2 = 12;

int r1 = 11;
int r2 = 13;

void setup() {
pinMode(q1,INPUT);
pinMode(q2,INPUT);
pinMode(q3,INPUT);
pinMode(q4,INPUT);
pinMode(q5,INPUT);
pinMode(q6,INPUT);
pinMode(q7,INPUT);
pinMode(q8,INPUT);

digitalWrite(q1,HIGH);
digitalWrite(q2,HIGH);
digitalWrite(q3,HIGH);
digitalWrite(q4,HIGH);
digitalWrite(q5,HIGH);
digitalWrite(q6,HIGH);
digitalWrite(q7,HIGH);
digitalWrite(q8,HIGH);







}

void loop() {
   analogWrite(l1,0);
digitalWrite(l2,LOW);
analogWrite(r1,0);
digitalWrite(r2,LOW);
  delay(2000);
  basla:
  if(digitalRead(q4)== LOW){
 analogWrite(l1,150);
digitalWrite(l2,LOW);
analogWrite(r1,150);
digitalWrite(r2,LOW);
  }else if(digitalRead(q5)== LOW){
 analogWrite(l1,150);
digitalWrite(l2,LOW);
analogWrite(r1,150);
digitalWrite(r2,LOW);
  }else if(digitalRead(q4)== LOW && digitalRead(q5)== LOW){
 analogWrite(l1,150);
digitalWrite(l2,LOW);
analogWrite(r1,150);
digitalWrite(r2,LOW);
  } else if(digitalRead(q3)== LOW){
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
analogWrite(r1,50);
digitalWrite(r2,LOW);
  }else if(digitalRead(q6)== LOW){
analogWrite(l1,50);
digitalWrite(l2,LOW);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
  }else if(digitalRead(q2)== LOW){
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
analogWrite(r1,0);
digitalWrite(r2,LOW);
  }else if(digitalRead(q7)== LOW){
analogWrite(l1,0);
digitalWrite(l2,LOW);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
  }else if(digitalRead(q1)== LOW){
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
digitalWrite(r1,LOW);
digitalWrite(r2,HIGH);
  }else if(digitalRead(q8)== LOW){
digitalWrite(l1,LOW);
digitalWrite(l2,HIGH);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
  }else if(digitalRead(q8)== LOW && digitalRead(q7)== LOW){
digitalWrite(l1,LOW);
digitalWrite(l2,HIGH);
digitalWrite(r1,HIGH);
digitalWrite(r2,LOW);
  }else if(digitalRead(q1)== LOW && digitalRead(q2)== LOW){
digitalWrite(l1,HIGH);
digitalWrite(l2,LOW);
digitalWrite(r1,LOW);
digitalWrite(r2,HIGH);
  }
  goto basla ;
}
