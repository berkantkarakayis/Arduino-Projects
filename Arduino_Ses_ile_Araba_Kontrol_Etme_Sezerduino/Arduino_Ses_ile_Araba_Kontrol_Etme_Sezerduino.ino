String voice;
int
pinileri = 2, //**
pingeri = 3,
pinsol =4,
pinsag =5;//**
   //**ARACIN İLERİ ,GERİ, SAĞ ,SOL KOMUT ÇIKIŞ PİNLERİ**
   //**
//ön lamba 
//arka lamba 
//korna 
//DÖRTLÜ 

void setup()
{
Serial.begin(9600); //HC-07 bluetooth modülü için btu 9600
pinMode(pinileri, OUTPUT);
pinMode(pingeri, OUTPUT);
pinMode(pinsol, OUTPUT);
pinMode(pinsag, OUTPUT);

}
void loop(){
  while (Serial.available()){
delay(10);
char c = Serial.read();
if (c == '#') {break;}
voice += c;
}
if (voice.length() > 0) {
Serial.println(voice);

if(voice == "*İleri") {digitalWrite(pinileri, HIGH);}
else if(voice == "*geri") {digitalWrite(pingeri, HIGH);}
//
else if(voice == "*Sağ geri") {digitalWrite(pingeri, HIGH);
                          digitalWrite(pinsag, HIGH);}
                          
else if(voice == "*Sağ ileri") {digitalWrite(pinileri, HIGH);
                          digitalWrite(pinsag, HIGH);}
                          
else if(voice == "*sol geri") {digitalWrite(pingeri, HIGH);
                          digitalWrite(pinsol, HIGH);}
else if(voice == "*sol ileri") {digitalWrite(pinileri, HIGH);
                          digitalWrite(pinsol, HIGH);}
//
else if(voice == "*dur") {digitalWrite(pinileri, LOW);
                          digitalWrite(pingeri, LOW);
                          digitalWrite(pinsag, LOW);
                          digitalWrite(pinsol, LOW);
                          
                          }

voice="";
}}



