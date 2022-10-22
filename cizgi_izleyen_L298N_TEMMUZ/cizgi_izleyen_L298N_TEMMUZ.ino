#include <QTRSensors.h>

#define NUM_SENSORS 7 // Kullanılacak olan pin sayısı
#define NUM_SAMPLES_PER_SENSOR 4
#define EMITTER_PIN QTR_NO_EMITTER_PIN

QTRSensorsRC qtrrc((unsigned char[]) { 1, 2, 3, 4, 5, 12, 13}, //Sensör giriş pinlerimizi belirliyoruz.
NUM_SENSORS, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

int ena=10; //PWM için enable pin giriş pini tanımlanır
int in1=6; //Motor1 için (+) pin giriş pini tanımlanır
int in2=7; //Motor1 için (-) pin giriş pini tanımlanır
int enb=11; //PWM için enable pin giriş pini tanımlanır
int in3=8; //Motor2 için (+) pin giriş pini tanımlanır
int in4=9; //Motor2 için (-) pin giriş pini tanımlanır

void setup()
{
delay(500);
Serial.begin(9600);
delay(1000);

pinMode(ena,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(enb,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
}

void loop()
{
qtrrc.read(sensorValues); //Sensör değeri okuma fonksiyonu

Serial.print(sensorValues[1]); /* Tüm sensörlerin değerlerini ekrana yazdırmak için ayrı ayrı sensör değerleri seri port üzerinde ekrana yazdırıyoruz.*/
Serial.print('\t');
Serial.print(sensorValues[2]);
Serial.print('\t');
Serial.print(sensorValues[3]);
Serial.print('\t');
Serial.print(sensorValues[4]);
Serial.print('\t');
Serial.print(sensorValues[5]);
Serial.print('\t');
Serial.print(sensorValues[6]);
Serial.print('\t');
Serial.print(sensorValues[7]);
Serial.print('\t');
Serial.print(sensorValues[8]);

Serial.print('\t');

Serial.println();

/* Eğer sensör3 ve sensör 4 değerleri belirlenmiş eşik değeri olan 250 ‘ nin altına düşerse sol ve sağ motor enable olarak pwm ile işlenerek tam güç olarak çalışacaktır.*/

if( sensorValues[3] < 250 || sensorValues[4] < 250 ) 
{
digitalWrite(7,HIGH); //Sol
analogWrite(10,255);
digitalWrite(8,HIGH); //Sag
analogWrite(11,255);
delay(60);
}

/* Eğer sensör 1 ve sensör 2 değerleri belirlenmiş eşik değeri olan 250 ‘ nin altına düşerse sol motor enable olarak pwm ile işlenerek tam güç olarak çalışacaktır.*/
else if (sensorValues[1] < 250 || sensorValues[2] < 250)
{
digitalWrite(7,LOW); //Sol
analogWrite(10,255);
digitalWrite(8,HIGH); 
analogWrite(11,200);
delay(60);

}

/* Eğer sensör 5 ve sensör 6 değerleri belirlenmiş eşik değeri olan 250 ‘ nin altına düşerse sağ motor enable olarak pwm ile işlenerek tam güç olarak çalışacaktır.*/
else if (sensorValues[3] < 250 || sensorValues[4] < 250)
{
digitalWrite(7,HIGH); 
analogWrite(10,255);
digitalWrite(8,LOW); //Sag
analogWrite(11,255);
delay(60);
}

// Eğer hiç bir sensör hiç birşey görmüyorsa bütün motorlar kapalı ve sistem yani robotumuz durmaktadır.
else if (sensorValues[5] < 250 || sensorValues[6] < 250)
{
digitalWrite(7,LOW); //Sol
analogWrite(10,155);
digitalWrite(8,LOW); //Sag
analogWrite(11,255);
delay(60);
delay(60);
}
}
