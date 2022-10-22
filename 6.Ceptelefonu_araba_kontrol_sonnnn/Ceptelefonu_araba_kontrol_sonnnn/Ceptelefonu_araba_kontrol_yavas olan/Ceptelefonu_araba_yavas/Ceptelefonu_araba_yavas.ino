#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8); 
#include <Servo.h>
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
  servo_motor.attach(10);  
  servo_motor.write(90);  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A3, INPUT); 
  pinMode(A4, INPUT); 
  pinMode(A5, INPUT); 
  pinMode(lDIR,OUTPUT);
  pinMode(lPWM,OUTPUT);
  pinMode(rDIR,OUTPUT);
  pinMode(rPWM,OUTPUT);
  pinMode(Buzzer, OUTPUT); 
  BT.begin(9600);
  
}





void loop() 
{
  basa:
    while (BT.available())
    {  
      delay(3);  
      char c = BT.read();
      readString += c; 
    }
    
    if (readString.length() >0) 
    {
      Serial.println(readString);
      
      if(readString == "i")
      {
        j = 0;
        k = 0;
        ivme = true;
        buton = false;
        dur = false;
        cizgi=false;
        servo = false;
        servo_motor.detach();
      }
      if(readString == "b")
      {
        j = 0;
        k = 0;
        buton = true;
        ivme= false;
        dur = false;
        servo = false;
        cizgi=false;
        servo_motor.detach();
      }
      if(readString == "d")
      {
        j = 0;
        k = 0;
        buton = false;
        ivme= false;
        dur = true;
        servo = false;
        cizgi=false;
        servo_motor.detach();
      }
      if(readString == "s")
      {
        j = 0;
        k = 0;
        servo_motor.attach(10);
        buton = false;
        ivme= false;
        dur = false;
        cizgi=false;
        servo = true;
      }
      if(readString == "c")
      {
        j = 0;
        k = 0;
        servo_motor.detach();
        buton = false;
        ivme= false;
        dur = false;
        servo = false;
        cizgi=true;
      }
      if(cizgi == true)
      {
        while(1)
        {
          devam:
          while (BT.available())
          {  
            delay(3);  
            char c = BT.read();
            readString += c; 
          }
          
          if (readString.length() >0) 
          {
            if(readString != "c")
            {
              cizgi = false;
              goto basa;
            }
          }
            
            if (digitalRead(A4)==HIGH){
            analogWrite(rPWM, 98);
            digitalWrite (rDIR, LOW);
            analogWrite(lPWM, 98);
            digitalWrite (lDIR, LOW);
            }
            else   if (digitalRead(A5)==HIGH){
            analogWrite(rPWM, 98);
            digitalWrite (rDIR, LOW);
            analogWrite(lPWM, 97);
            digitalWrite (lDIR, HIGH);
            }
            else   if (digitalRead(A3)==HIGH){
            analogWrite(rPWM, 97);
            digitalWrite (rDIR, HIGH);
            analogWrite(lPWM, 98);
            digitalWrite (lDIR, LOW);
            }
           
            
            if(digitalRead(A4)==HIGH)
            {
              
              if(j == 100)
              {
                BT.println(2);
                j = 0;
              }
              j++;
              delay(1);
              goto devam;
            }
            else   if (digitalRead(A5)==HIGH)
            {
              if(j == 100)
              {
                BT.println(1);
                j = 0;
              }
              j++;
              delay(1);
              goto devam;
            }
            else   if (digitalRead(A3)==HIGH)
            {
              if(j == 100)
              {
                BT.println(3);
                j = 0;
              }
              j++;
              delay(1);
              goto devam;
            }
            else if (digitalRead(A4) == LOW &&digitalRead(A5)==LOW && digitalRead(A3)==LOW)
            {
              if(j == 100)
              {
                BT.println(4);
                j = 0;
              }
              j++;
              delay(1);
              goto devam;
            }
            
        
        }
      }
      else if(servo == true)
      {/*
        if(readString != "k")
        {
          servo_aci = readString.toInt();
          servo_motor.write(servo_aci);
        }

        
        */
        
        digitalWrite(trigPin, LOW);
        delayMicroseconds(5);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        
        duration = pulseIn(echoPin, HIGH);
        cm = (duration/2) / 29.1;
        delay(2);
        if(cm <= 15)
        {
            digitalWrite(lDIR,HIGH);
            digitalWrite(rDIR,HIGH);
            analogWrite(lPWM,100);
            analogWrite(rPWM,100);
            delay(1000);
            digitalWrite(lDIR,HIGH);
            digitalWrite(rDIR,LOW);
            analogWrite(lPWM,60);
            analogWrite(rPWM,60);
            delay(200);
        }
        else
        {
          analogWrite(lPWM,60);
          analogWrite(rPWM,60);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
        }
        /*
        if(k == 1)
        {
          BT.println(cm);
          k = 0;
        }
        
        k++;*/
        
      }
      else if(dur == true)
      {
          analogWrite(lPWM,0);
          analogWrite(rPWM,0);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
      }
      else if(buton == true)
      {
        if (readString == "ileri")     
        {
          analogWrite(lPWM,100);
          analogWrite(rPWM,100);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
        }
        else if (readString == "geri")
        {
          digitalWrite(lDIR,HIGH);
          digitalWrite(rDIR,HIGH);
          analogWrite(lPWM,0);
          analogWrite(rPWM,0);
        }
        else if (readString == "sol")
        {
          digitalWrite(lDIR,HIGH);
          digitalWrite(rDIR,LOW);
          analogWrite(lPWM,0);
          analogWrite(rPWM,100);
        }
        else if (readString == "sag")
        {
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,HIGH);
          analogWrite(lPWM,100);
          analogWrite(rPWM,0);
        }
        else if (readString == "dur")
        {
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
          analogWrite(lPWM,0);
          analogWrite(rPWM,0);
        }
        else if (readString == "sagasagi")     
        {
          
          analogWrite(lPWM,45);
          analogWrite(rPWM,100);
          digitalWrite(lDIR,HIGH);
          digitalWrite(rDIR,HIGH);
        }
        else if (readString == "solasagi")     
        {
          analogWrite(lPWM,100);
          analogWrite(rPWM,45);
          digitalWrite(lDIR,HIGH);
          digitalWrite(rDIR,HIGH);
        }
        else if (readString == "sagyukari")     
        {
          analogWrite(lPWM,100);
          analogWrite(rPWM,45);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
        }
        else if (readString == "solyukari")     
        {
          analogWrite(lPWM,45);
          analogWrite(rPWM,100);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
        }
      }
      else if(ivme == true)
      {
        
        if (readString.toInt() > 100 && readString.toInt() < 500)     
        {
          int i = readString.toInt();
          //int y = map(i, 220, 380, 1, 255);
          analogWrite(lPWM,100);
          analogWrite(rPWM,100);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
        }

        else if (readString.toInt() < -100 && readString.toInt() > -500)     
        {
          int i = readString.toInt();
          //int y = map(i, -220, -380, 1, 255);
          analogWrite(lPWM,100);
          analogWrite(rPWM,100);
          digitalWrite(lDIR,HIGH);
          digitalWrite(rDIR,HIGH);
        }

        else if(readString.toInt() < -900 && readString.toInt() > -1300)
        {
           int i = readString.toInt();
           //int y = map(i, -1110, -1270, 1, 255);
           digitalWrite(lDIR,LOW);
           digitalWrite(rDIR,HIGH);
           analogWrite(lPWM,100);
           analogWrite(rPWM,100);
        }


        else if(readString.toInt() > 900 && readString.toInt() < 1300)
        {
           int i = readString.toInt();
           //int y = map(i, 1110, 1270, 1, 255);
           digitalWrite(lDIR,HIGH);
           digitalWrite(rDIR,LOW);
           analogWrite(lPWM,100);
           analogWrite(rPWM,100);
        }

        else if(readString.toInt() > -70 && readString.toInt() < 70)
        {
           digitalWrite(lDIR,LOW);
           digitalWrite(rDIR,LOW);
           analogWrite(lPWM,0);
           analogWrite(rPWM,0);
        }
        
      }
    
    readString="";
  } 
}




