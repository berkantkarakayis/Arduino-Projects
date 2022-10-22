#define trigPin 9  // trigPin motor 13 numarali pine baglandi 
#define echoPin 8  // echoPin motor 12 numarali pine baglandi 
#define led0 2
#define led1 3
#define led2 13
#define led3 5
#define led4 6
#define led5 7
#define led6 12
#define led7 0
#define led8 10
#define led9 11
#define led10 A0
#define led11 A1
#define led12 A2
#define led13 A3
#define led14 A4
#define led15 A5
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(led11,OUTPUT);
  pinMode(led12,OUTPUT);
  pinMode(led13,OUTPUT);
  pinMode(led14,OUTPUT);
  pinMode(led15,OUTPUT);
}

void loop() {
  long sure, mesafe;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2) / 29.1;
  mesafe = map(mesafe, 0, 200, 0, 255);
  if(mesafe == 80)
  {
    digitalWrite(led15,HIGH);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);
  }
  else if(mesafe == 75)
  {
    digitalWrite(led14,HIGH);
    digitalWrite(led15,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);  
  }
  else if(mesafe == 70)
  {
    digitalWrite(led13,HIGH);  
    digitalWrite(led14,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);
  }
  else if(mesafe == 65)
  {
    digitalWrite(led12,HIGH);  
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);
  }
  else if(mesafe == 60)
  {
    digitalWrite(led11,HIGH);  
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);
  }
  else if(mesafe == 55)
  {
    digitalWrite(led10,HIGH);  
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);
  }
  else if(mesafe == 50)
  {
    digitalWrite(led9,HIGH);  
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);
  }
  else if(mesafe == 45)
  {
    digitalWrite(led8,HIGH); 
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW); 
  }
  else if(mesafe == 40)
  {
    digitalWrite(led7,HIGH); 
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW); 
  }
  else if(mesafe == 35)
  {
    digitalWrite(led6,HIGH);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);  
  }
  else if(mesafe == 30)
  {
    digitalWrite(led5,HIGH);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);  
  }
  else if(mesafe == 25)
  {
    digitalWrite(led4,HIGH);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);  
  }
  else if(mesafe == 20)
  {
    digitalWrite(led3,HIGH);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);  
  }
  else if(mesafe == 15)
  {
    digitalWrite(led2,HIGH); 
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW); 
  }
  else if(mesafe == 10)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led15,LOW);
    digitalWrite(led0,LOW);  
  }
  else if(mesafe == 5)
  {
    digitalWrite(led0,HIGH);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led15,LOW);
  }
  else
  {
    digitalWrite(led15,LOW);
    digitalWrite(led14,LOW);
    digitalWrite(led13,LOW);
    digitalWrite(led12,LOW);
    digitalWrite(led11,LOW);
    digitalWrite(led10,LOW);
    digitalWrite(led9,LOW);
    digitalWrite(led8,LOW);
    digitalWrite(led7,LOW);
    digitalWrite(led6,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led0,LOW);
  }
}
