#include <Ultrasonic.h>

#define trigger_pin 10
#define echo_pin 8
int m1 = 5;  //m1 e m2 motores direita
int m2 = 4;  //m3 e m4 motores esquerda
int m3 = 3;
int m4 = 2;

int s1 = A0; //s1 é traseiro esquerda
int s2 = A1; //s2 é dianteiro esquerda
int s3 = A2; //s3 é dianteiro direita
int s4 = A3; //s4 é traseiro direita
int lei_s1 = 0;
int lei_s2 = 0;
int lei_s3 = 0;
int lei_s4 = 0;

Ultrasonic ultrasonic(trigger_pin, echo_pin);



void setup() {
 pinMode(m1,OUTPUT);
 pinMode(m2,OUTPUT);
 pinMode(m3,OUTPUT);
 pinMode(m4,OUTPUT);

 Serial.begin(9600);
 
}
void loop() {
float cmsegun;
long microsegun = ultrasonic.timing();
cmsegun = ultrasonic.convert(microsegun, Ultrasonic::CM);
Serial.print("CM: ");
Serial.println(cmsegun);
lei_s1=analogRead(s1);
lei_s2=analogRead(s2);
lei_s3=analogRead(s3);
lei_s4=analogRead(s4);




if(cmsegun < 30){
digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
}else{
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
}
}
void leitura(){
Serial.print("Sensor 1: ");
Serial.print(s1);
Serial.print(" Sensor 2: ");
Serial.print(s2);
Serial.print(" Sensor 3: ");
Serial.print(s3);
Serial.print(" Sensor 4: ");
Serial.print(s4);
}
void sensores(){

}
