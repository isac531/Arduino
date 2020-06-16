#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     13

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
float cm;
long microsec;

int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

int v1 = 6;
int v2 = 7;

int sE2 = A5;
int sE1 = A4;
int sC = A3;
int sD1 = A2;
int sD2 = A1;

int vE2 = 0;
int vE1 = 0;
int vC = 0;
int vD1 = 0;
int vD2 = 0;
int vP = 300;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(v2, OUTPUT);
  pinMode(sE2, INPUT);
  pinMode(sE1, INPUT);
  pinMode(sC, INPUT);
  pinMode(sD1, INPUT);
  pinMode(sD2, INPUT);
  Serial.begin(9600);
}

void loop() {
  vE2 = analogRead(sE2);
  vE1 = analogRead(sE1);
  vC = analogRead(sC);
  vD1 = analogRead(sD1);
  vD2 = analogRead(sD2);
  microsec = ultrasonic.timing();
  cm = ultrasonic.convert(microsec, Ultrasonic::CM);

  LeituraS();
  Comandos();
}

void LeituraS() {
  Serial.print("SE2: ");
  Serial.print(vE2);
  Serial.print(" SE1: ");
  Serial.print(vE1);
  Serial.print(" SC: ");
  Serial.print(vC);
  Serial.print(" SD1: ");
  Serial.print(vD1);
  Serial.print(" SD2: ");
  Serial.print(vD2);
  Serial.print(" Cm: ");
  Serial.println(cm);
  delay(300);
}

void Comandos() {
  if ((vE2 < vP) & (vE1 > vP) & (vC < vP) & (vD1 < vP) & (vD2 < vP)) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);  //ESQUERDA SENSOR 1
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(v1, 200);
    analogWrite(v2, 200);
  }
else if ((vE2 > vP) & (vE1 < vP) & (vC < vP) & (vD1 < vP) & (vD2 < vP)) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH); //ESQUERDA SENSOR 2
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(v1, 200);
    analogWrite(v2, 200);
  }
else if ((vE2 < vP) & (vE1 < vP) & (vC > vP) & (vD1 < vP) & (vD2 < vP)) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); //FRENTE
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(v1, 200);
    analogWrite(v2, 200);
  }
else if ((vE2 > vP) & (vE1 < vP) & (vC > vP) & (vD1 < vP) & (vD2 > vP)) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); //DIREITA SENSOR 1
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(v1, 200);
    analogWrite(v2, 200);
  }

else if ((vE2 < vP) & (vE1 < vP) & (vC < vP) & (vD1 < vP) & (vD2 > vP)) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); //DIREITA SENSOR 2
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(v1, 200);
    analogWrite(v2, 200);
  }


}
