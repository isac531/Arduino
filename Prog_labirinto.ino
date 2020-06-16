#include <Ultrasonic.h>

#define triggerfrente_pin 8
#define echofrente_pin 11
#define triggerdireita_pin 12
#define echodireita_pin 13
#define triggeresquerda_pin 6 
#define echoesquerda_pin 7

Ultrasonic ultrasonicF(triggerfrente_pin,echofrente_pin);
Ultrasonic ultrasonicD(triggerdireita_pin,echodireita_pin);
Ultrasonic ultrasonicE(triggeresquerda_pin,echoesquerda_pin);

int m1 = 2;
int m2 = 3;
int m3 = 4;
int m4 = 5;
int vm1 = 9;
int vm2 = 10;

float cmsegunF;
float cmsegunD;
float cmsegunE;

void setup() {
 pinMode(m1,OUTPUT);
 pinMode(m2,OUTPUT);
 pinMode(m3,OUTPUT);
 pinMode(m4,OUTPUT);
 Serial.begin(9600);
}

void loop() {
long microsegunF = ultrasonicF.timing();
long microsegunD = ultrasonicD.timing();
long microsegunE = ultrasonicE.timing();
cmsegunF = ultrasonicF.convert(microsegunF, Ultrasonic::CM);
cmsegunD = ultrasonicD.convert(microsegunD, Ultrasonic::CM);
cmsegunE = ultrasonicE.convert(microsegunE, Ultrasonic::CM);
leitura();
comandos();

}
void leitura(){

Serial.print("Frente: ");
Serial.print(cmsegunF);
Serial.print(" Esquerda: ");
Serial.print(cmsegunE);
Serial.print(" Direita: ");
Serial.println(cmsegunD);


}
void comandos(){
if(cmsegunF<4){
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
analogWrite(vm1,200);
analogWrite(vm2,200);
delay(200);
}
else if(cmsegunD<4){
digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
analogWrite(vm1,200);
analogWrite(vm2,200);
}
else if(cmsegunE<4){
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
analogWrite(vm1,200);
analogWrite(vm2,200);
}
else if(cmsegunE<4 && cmsegunF<4){
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
analogWrite(vm1,200);
analogWrite(vm2,200);
}
else if(cmsegunD<4 && cmsegunF<4){
digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
analogWrite(vm1,200);
analogWrite(vm2,200);
}
else{
digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
analogWrite(vm1,200);
analogWrite(vm2,200);
  
}
}
