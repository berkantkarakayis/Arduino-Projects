#include <dht11.h>
 
dht11 DHT11;
 
void setup()
{
 DHT11.attach(2);
 Serial.begin(9600);
 Serial.println("DHT11 TEST PROGRAM ");
 Serial.print("LIBRARY VERSION: ");
 Serial.println(DHT11LIB_VERSION);
}
 
void loop()
{
 Serial.println("\n");
 
 int chk = DHT11.read();
 
 Serial.print("Read sensor: ");
 switch (chk)
 {
 case 0: Serial.println("OK"); break;
 case -1: Serial.println("Checksum error"); break;
 case -2: Serial.println("Time out error"); break;
 default: Serial.println("Unknown error"); break;
 }
 
 Serial.print("Humidity (%): ");   //Nem yüzdesini ekrana yazdırıyoruz
 Serial.println((float)DHT11.humidity, DEC);
 
 Serial.print("Temperature (°C): ");   //Sıcaklığı santigrad olarak ekrana yazdırıyoruz
 Serial.println((float)DHT11.temperature, DEC);
 
 Serial.print("Temperature (°F): ");   //Sıcaklığı fahrenayt olarak ekrana yazdırıyoruz
 Serial.println(DHT11.fahrenheit(), DEC);
 
 Serial.print("Temperature (°K): ");   //Sıcaklığı kelvin olarak ekrana yazdırıyoruz
 Serial.println(DHT11.kelvin(), DEC);
 
 Serial.print("Dew Point (°C): ");    //Sıcaklık aynı nem oranında bu sıcaklık değerine düşerse kar,yağmur,sis,çiğ bilimum doğa olayları görülür.
 Serial.println(DHT11.dewPoint(), DEC);
 
 Serial.print("Dew PointFast (°C): ");
 Serial.println(DHT11.dewPointFast(), DEC);
 
 delay(2000);
}
