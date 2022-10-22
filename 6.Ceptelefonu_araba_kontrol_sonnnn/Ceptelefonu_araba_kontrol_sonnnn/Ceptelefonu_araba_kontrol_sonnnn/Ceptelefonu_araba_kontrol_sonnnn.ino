#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8); 
//3 - 4 SOL - -- 5 - 6 SAĞ

int lDIR = 3; //in1 motor sürücünün pini arduino dijital 3 e girecek
int lPWM = 4; //in2 motor sürücünün pini arduino dijital 4 e girecek
int rDIR = 5; //in3 motor sürücünün pini arduino dijital 5 e girecek
int rPWM = 6; //in4 motor sürücünün pini arduino dijital 6 e girecek
String readString;

void setup()  
{
   
  Serial.begin(9600);
  pinMode(lDIR,OUTPUT);
  pinMode(lPWM,OUTPUT);
  pinMode(rDIR,OUTPUT);
  pinMode(rPWM,OUTPUT);
  
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
      
      
      if (readString == "dur") 
      {
          analogWrite(lPWM,0);
          analogWrite(rPWM,0);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
      }
      
   
        if (readString == "ileri")     
        {
          analogWrite(lPWM,255);
          analogWrite(rPWM,255);
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
            digitalWrite(4,LOW);
          digitalWrite(3,HIGH);
          digitalWrite(6,HIGH);
          digitalWrite(5,LOW);
        }

        else if (readString == "sag")
        {
          digitalWrite(3,LOW);
          digitalWrite(4,HIGH);
          digitalWrite(5,HIGH);
          digitalWrite(6,LOW);
          //analogWrite(lPWM,255);
          //analogWrite(rPWM,255);
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
          
          analogWrite(lPWM,125);
          analogWrite(rPWM,255);
          digitalWrite(lDIR,HIGH);
          digitalWrite(rDIR,HIGH);
        }
        else if (readString == "solasagi")     
        {
          analogWrite(lPWM,255);
          analogWrite(rPWM,125);
          digitalWrite(lDIR,HIGH);
          digitalWrite(rDIR,HIGH);
        }
        else if (readString == "sagyukari")     
        {
          analogWrite(lPWM,255);
          analogWrite(rPWM,125);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
        }
        else if (readString == "solyukari")     
        {
          analogWrite(lPWM,45);
          analogWrite(rPWM,255);
          digitalWrite(lDIR,LOW);
          digitalWrite(rDIR,LOW);
        }
       
    readString="";
    }
  } 





