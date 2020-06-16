#include <Servo.h>

#define SERVO 8

Servo s;
int pos;

char letra;
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

void setup() {
 Serial.begin(9600);
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
 s.attach(SERVO);
 s.write(0);
}

void loop() {
  letra = Serial.read();
  
  if(letra == 'F'){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  }
 else if(letra == 'B'){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  }
 else if(letra == 'R'){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
  }
 else if(letra == 'L'){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
  }
 else if(letra == 'S'){
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
  }
   else if(letra == 'X'){

  for(pos = 0; pos < 90; pos++)
  {
    s.write(pos);
  }
   }
     else if(letra == 'x'){

for(pos = 90; pos >= 0; pos--)
  {
    s.write(pos);
  }
}
}
