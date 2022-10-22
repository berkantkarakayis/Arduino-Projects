#define LED 13
#define BAUDRATE 57600
#define DEBUGOUTPUT 0

#define powercontrol 10
int motor1=8;
int motor2=9;
int motor3=10;
int motor4=11;
byte generatedChecksum = 0;
byte checksum = 0; 
int payloadLength = 0;
byte payloadData[64] = {
  0};
byte poorQuality = 0;
byte attention = 0;
byte meditation = 0;

// system variables
long lastReceivedPacket = 0;
boolean bigPacket = false;

void setup() {
  Serial.begin(BAUDRATE);    
 pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
   pinMode(motor3, OUTPUT);
    pinMode(motor4, OUTPUT);
}
byte ReadOneByte() {
  int ByteRead;

  while(!Serial.available());
  ByteRead = Serial.read();

#if DEBUGOUTPUT  
  Serial.print((char)ByteRead);  
#endif

  return ByteRead;
}

void loop() {


  if(ReadOneByte() == 170) {
    if(ReadOneByte() == 170) {

      payloadLength = ReadOneByte();
      if(payloadLength > 169)                      
          return;

      generatedChecksum = 0;        
      for(int i = 0; i < payloadLength; i++) {  
        payloadData[i] = ReadOneByte();            //Read payload into memory
        generatedChecksum += payloadData[i];
      }   

      checksum = ReadOneByte();                         
      generatedChecksum = 255 - generatedChecksum;  

        if(checksum == generatedChecksum) {    

        poorQuality = 200;
        attention = 0;
        meditation = 0;

        for(int i = 0; i < payloadLength; i++) {    
          switch (payloadData[i]) {
          case 2:
            i++;            
            poorQuality = payloadData[i];
            bigPacket = true;            
            break;
          case 4:
            i++;
            attention = payloadData[i];                        
            break;
          case 5:
            i++;
            meditation = payloadData[i];
            break;
          case 0x80:
            i = i + 3;
            break;
          case 0x83:
            i = i + 25;      
            break;
          default:
            break;
          } 
        } 

#if !DEBUGOUTPUT

        if(bigPacket) {
          if(poorQuality == 0){
            digitalWrite(LED, HIGH);
          }
          if(poorQuality == 200||poorQuality == 80||meditation==0||attention==0)//sensörden bilgi gelmiyor veya sensör bağlanmamışsa motorlar duruyor.
          //poorQuality sensörün bağlantı kalitesini göstermektedir. Bağlantı kalitesi 0'dan farklı ise sensörden arduinoya bilgi gelmez. 
          {
         digitalWrite(motor1, LOW);
          digitalWrite(motor2, LOW);
           digitalWrite(motor3, LOW);
            digitalWrite(motor4, LOW);
           }
          else if ( attention>=45&&meditation<=45)//sensörden alınan attention(odaklanma) hali değeri 0 ile 100 arasında değişmektedir.
         
        {    //attention(odaklanma değeri belirlenen değerden(45) büyük ve meditation değeri belirlenen değerden(45) ise küçük ise araba ileri gider. 
          digitalWrite(motor1, HIGH);
          digitalWrite(motor2, LOW);
           digitalWrite(motor3, LOW);
            digitalWrite(motor4, HIGH); 
           } 
          else if ( meditation>=45&&attention<=45)//sensörden alınan meditation(sakinlik) hali değeri 0 ile 100 arasında değişmektedir. 
        {    //meditasyon değeri belirlenen değerden(45) büyük ve atttention(odaklanma) değeri belirlenen değerden(45) ise küçük ise araba geri gider. 
            digitalWrite(motor1,LOW);
          digitalWrite(motor2, HIGH);
           digitalWrite(motor3, HIGH);
            digitalWrite(motor4, LOW);
            }
      /*      
      //meditasyon veya attention değeri son değerlere yükselirse araba sağa döner
      else if ( meditation>=97||attention>=97)
            {
          digitalWrite(motor1,LOW);
          digitalWrite(motor2, HIGH);
           digitalWrite(motor3, LOW);
            digitalWrite(motor4, HIGH);
            }*/
         Serial.print("bağlantı kalitesi: ");
          Serial.print(poorQuality, DEC);
          Serial.print(" meditation(sakinlik): ");
          Serial.println(meditation, DEC); 
          Serial.print(" attention(odaklanma): ");
          Serial.println(attention, DEC);
          Serial.print("\n");
     
        }
#endif        
        bigPacket = false;        
      }
      }
  }      }



