#define sag_isik 3
#define orta_isik 4
#define sol_isik 5

#define sol_motor1 A4
#define sol_motor2 A3
#define sol_pwm 9

#define sag_motor1 A1
#define sag_motor2 A2
#define sag_pwm 10

void setup() {
pinMode(sag_isik, INPUT);
pinMode(orta_isik,INPUT);
pinMode(sol_isik, INPUT);

pinMode(sol_motor1,OUTPUT);
pinMode(sol_motor2,OUTPUT);
pinMode(sol_pwm,OUTPUT);

pinMode(sag_motor1,OUTPUT);
pinMode(sag_motor2,OUTPUT);
pinMode(sag_pwm,OUTPUT);
}

void loop() {
if(digitalRead(orta_isik) == false)
{
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, LOW);
  analogWrite(sol_pwm,255);

  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sag_pwm,255);
}
else if(digitalRead(sag_isik) == false)
{
  digitalWrite(sol_motor1, HIGH);
  digitalWrite(sol_motor2, LOW);
  analogWrite(sol_pwm,255);

  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, HIGH);
  analogWrite(sag_pwm,255);
}
else if(digitalRead(sol_isik) == false)
{
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, HIGH);
  analogWrite(sol_pwm,255);

  digitalWrite(sag_motor1, HIGH);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sag_pwm,255);
}
else
{
  digitalWrite(sol_motor1, LOW);
  digitalWrite(sol_motor2, LOW);
  analogWrite(sol_pwm,0);

  digitalWrite(sag_motor1, LOW);
  digitalWrite(sag_motor2, LOW);
  analogWrite(sag_pwm,0);
}
}
