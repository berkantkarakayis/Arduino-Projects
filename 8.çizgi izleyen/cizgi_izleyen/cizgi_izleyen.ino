#define sag_cizgi 7
#define orta_cizgi 6
#define sol_cizgi 5

#define sol_motor1 A4
#define sol_motor2 A3
#define sol_pwm 9

#define sag_motor1 A1
#define sag_motor2 A2
#define sag_pwm 10

bool sag = false, sol = false;
void setup() {
pinMode(sag_cizgi, INPUT);
pinMode(orta_cizgi, INPUT);
pinMode(sol_cizgi, INPUT);

pinMode(sol_motor1,OUTPUT);
pinMode(sol_motor2,OUTPUT);
pinMode(sol_pwm,OUTPUT);

pinMode(sag_motor1,OUTPUT);
pinMode(sag_motor2,OUTPUT);
pinMode(sag_pwm,OUTPUT);
}

void loop() {
if(digitalRead(sag_cizgi) == true && digitalRead(sol_cizgi) == false && digitalRead(orta_cizgi) == false) 
{
  digitalWrite(sol_motor1,HIGH);
  digitalWrite(sol_motor2,LOW);
  analogWrite(sol_pwm,120);
  
  digitalWrite(sag_motor1,HIGH);
  digitalWrite(sag_motor2,LOW);
  analogWrite(sag_pwm,120);

  sol = false;
  sag = true;
}
else if(digitalRead(orta_cizgi) == true && digitalRead(sag_cizgi) == false && digitalRead(sol_cizgi) == false)
{
  digitalWrite(sol_motor1,HIGH);
  digitalWrite(sol_motor2,LOW);
  analogWrite(sol_pwm,125);

  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sag_pwm,125);
}
else if(digitalRead(sol_cizgi) == true && digitalRead(sag_cizgi) == false && digitalRead(orta_cizgi) == false)
{
  digitalWrite(sol_motor1,HIGH);
  digitalWrite(sol_motor2,LOW);
  analogWrite(sol_pwm,120);

  digitalWrite(sag_motor1,HIGH);
  digitalWrite(sag_motor2,LOW);
  analogWrite(sag_pwm,125);
  sol = true;
  sag = false;
}
else
{
  if(sag == true)
  {
    digitalWrite(sol_motor1, HIGH);
    digitalWrite(sol_motor2, LOW);
    analogWrite(sol_pwm,145);
  
    digitalWrite(sag_motor1, LOW);
    digitalWrite(sag_motor2, HIGH);
    analogWrite(sag_pwm,100);
  }
  else if(sol == true)
  {
    digitalWrite(sol_motor1, LOW);
    digitalWrite(sol_motor2, HIGH);
    analogWrite(sol_pwm,100);
    
    digitalWrite(sag_motor1, HIGH);
    digitalWrite(sag_motor2, LOW);
    analogWrite(sag_pwm,135);
  }
}
}
