int pot=A0;
int led=2;
int potDeger;
void setup (){
  pinMode (pot, INPUT);
  Serial.begin(9600);
  pinMode (led, OUTPUT);
}
void loop (){
  potDeger =analogRead (pot);
  potDeger =map (potDeger,0,1023,0,253);
  analogWrite(led,potDeger);
  delay(10);
  
  Serial.println(potDeger);
}

