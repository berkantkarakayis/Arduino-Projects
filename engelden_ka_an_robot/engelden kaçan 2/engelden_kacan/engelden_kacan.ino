#define trigPin  6
#define echoPin  7
long sure,mesafe;
int IN1 = 12;
int IN2 = 11;
int IN3 = 10;
int IN4 = 9;
const int pwm1 = 13;   // hız ayarı için pwm kullanıldı
const int pwm2 = 8; // pwm1 ve pwm2 iki motorun ayrı ayrı hızlarını pwm sinyali ile ayarlar
void setup() 
{
  pinMode(IN1, OUTPUT);   // motor bağlantıları çıkış 
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);      
  pinMode(trigPin, OUTPUT); //sinyalin gönderildiği pin
  pinMode(echoPin, INPUT); //yansıyan sinyalin alındığı pin
  Serial.begin(9600);

}

void ileri()
  {                
      analogWrite(pwm1,150);
      analogWrite(pwm2,150);       
      digitalWrite(IN1,HIGH);               
      digitalWrite(IN2,LOW);                 
      digitalWrite(IN4,HIGH);                   
      digitalWrite(IN3,LOW);         
  }
void sag()
  {     
      analogWrite(pwm1,150);            
      analogWrite(pwm2,180);        
      digitalWrite(IN1,LOW);                     
      digitalWrite(IN2,HIGH);               
     digitalWrite(IN4,HIGH);                   
      digitalWrite(IN3,LOW);       

  }
  void geri()
  {     
      analogWrite(pwm1,150);        
      analogWrite(pwm2,150);          
      digitalWrite(IN1,LOW);                    
      digitalWrite(IN2,HIGH);                 
      digitalWrite(IN4,LOW);                 
      digitalWrite(IN3,HIGH);      
  }
void dur()
  {
      digitalWrite(IN1,LOW);                   
      digitalWrite(IN2,LOW);                    
      digitalWrite(IN4,LOW);                     
      digitalWrite(IN3,LOW);        
  }
void loop() 
{
  ileri();
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100); 
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2) / 29.1;
  Serial.println(mesafe);
  if(mesafe < 35)   // 25cm den küçükse dur ve 400ms geri gel

  {
 dur();
    geri();
    delay(100);
    sag();
    delay(200);
    ileri();
  }
  else
  {
    ileri();
  }
}
