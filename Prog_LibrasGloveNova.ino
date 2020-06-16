#include <Wire.h>
#include <Adafruit_ADXL345_U.h>
#include "BluetoothSerial.h"
BluetoothSerial ESP_Glove;
int incoming;
const int dedao1 = 39;
const int indi1 = 33;
const int meio1 = 32;
const int anel1= 35;
const int mind1= 34;

int indi1position = 0;
int dedao1position = 0;
int meio1position = 0;
int anel1position = 0;
int mind1position = 0;
int feito = 0;
int ativJ =0;
int ativK =0;
int ativH = 0;
int ativW = 0;
float eixoX;
float eixoY;
float eixoZ;
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
void setup() {
Serial.begin(9600);
ESP_Glove.begin("ESP32_LibrasGlove"); //Nome da luva no Bluetooth
Serial.println("Bluetooth Device is Ready to Pair");
pinMode(dedao1,INPUT);
pinMode(indi1,INPUT);
pinMode(meio1,INPUT);
pinMode(anel1,INPUT);
pinMode(mind1,INPUT);
accel.setRange(ADXL345_RANGE_16_G);
accel.begin();
}

void loop() {
dedao1position = analogRead(dedao1);
dedao1position = map(dedao1position, 0, 4095, 0, 255);
indi1position = analogRead(indi1);
indi1position = map(indi1position, 0, 4095, 0, 255);
meio1position = analogRead(meio1);
meio1position = map(meio1position, 0, 4095, 0, 255);
anel1position = analogRead(anel1);
anel1position = map(anel1position, 0, 4095, 0, 255);
mind1position = analogRead(mind1);
mind1position = map(mind1position, 0, 4095, 0, 255);
sensors_event_t event; 
accel.getEvent(&event);
eixoX = event.acceleration.x;
eixoY = event.acceleration.y;
eixoZ = event.acceleration.z;
leitura_dedos();
comandos();
  if (ESP_Glove.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_Glove.read(); //Read what we recevive
    Serial.print("Received:"); 
    Serial.println(incoming);
   
    if(incoming == 97){
   ESP_Glove.print("Dedao: ");
   ESP_Glove.print(dedao1position);
   ESP_Glove.print(" Indicador: ");
   ESP_Glove.print(indi1position);
   ESP_Glove.print(" Meio: ");
   ESP_Glove.print(meio1position);
   ESP_Glove.print(" Anelar: ");
   ESP_Glove.print(anel1position);
   ESP_Glove.print(" Mindinho: ");
   ESP_Glove.println(mind1position);
   ESP_Glove.print("X: "); 
   ESP_Glove.print(eixoX);
   ESP_Glove.print(" Y: "); 
   ESP_Glove.print(eixoY);
   ESP_Glove.print(" Z: "); 
   ESP_Glove.print(eixoZ);
   ESP_Glove.println(" m/s^2");
    }  
     else if(incoming == 100){
     feito = 2;
     }
     else if(incoming == 102){
      feito = 0;
     }
      }
}
void leitura_dedos(){
Serial.print("Dedão: ");
Serial.print(dedao1position);
Serial.print(" Indicador: ");
Serial.print(indi1position);
Serial.print(" Meio: ");
Serial.print(meio1position);
Serial.print(" Anelar: ");
Serial.print(anel1position);
Serial.print(" Mindinho: ");
Serial.println(mind1position);
Serial.print("X: "); 
Serial.print(eixoX);
Serial.print(" Y: "); 
Serial.print(eixoY);
Serial.print(" Z: "); 
Serial.print(eixoZ);
Serial.print(" m/s^2 ");
Serial.print(feito);
Serial.print(" AJ:");
Serial.print(ativJ);
Serial.print(" AK:");
Serial.print(ativK);
Serial.print(" AH:");
Serial.print(ativH);
Serial.print(" AW:");
Serial.println(ativW);
delay(400);

}
void comandos(){
if(feito == 0){
    if((dedao1position<80 && dedao1position>60) && (indi1position<=85 && indi1position>=65) && (meio1position<83 && meio1position>69) && (anel1position<115 && anel1position>35) && (mind1position<100 && mind1position>80) && (eixoX<10.00 && eixoX>9.50)){
    ESP_Glove.println("6");
    Serial.println("6");
    }
    }
  if((dedao1position>65) && (indi1position<1) && (meio1position<10) && (anel1position<20 && anel1position>10) && (mind1position<=24 && mind1position>10) && (eixoX<10.50 && eixoX>9.50) && (feito == 2)){
 
ESP_Glove.println("a");
Serial.println("a");
delay(50);
  }
else  if((dedao1position<1) && (indi1position>65) && (meio1position>=70) && (anel1position<110 && anel1position>38) && (mind1position<110 && mind1position>40) && (eixoX<10.50 && eixoX>9.50) && (feito == 2)){
 
ESP_Glove.println("b");
Serial.println("b");
delay(50);
  }
  else  if((dedao1position<70 && dedao1position>10) && (indi1position>60) && (meio1position<10) && (anel1position<50 && anel1position>5) && (mind1position<30) && (eixoX<10.50 && eixoX>9.50) && (eixoY<0.50 && eixoY>-2.00) && (feito == 2)){
 
ESP_Glove.println("c");
Serial.println("c");
delay(50);
  }
    else  if((dedao1position<10) && (indi1position>65) && (meio1position<50) && (anel1position<20) && (mind1position<50 && mind1position>10) && (eixoX<10.50 && eixoX>9.50) && (eixoY>-4.00 && eixoY<0.00) && (feito == 2)){
 
ESP_Glove.println("d");
Serial.println("d");
delay(50);
  }
  else  if((dedao1position<1) && (indi1position>70) && (meio1position<20) && (anel1position<50 && anel1position>20) && (mind1position>70) && (eixoX<10.50 && eixoX>9.50) && (eixoY<4.00 && eixoY>0.50) && (feito == 2)){
 
ESP_Glove.println("e");
Serial.println("e");
delay(50);
  }
 else  if((dedao1position<70 && dedao1position>=50) && (indi1position<10) && (meio1position>70) && (anel1position>70) && (mind1position>85) && (eixoX<10.00 && eixoX>9.50)){
 
ESP_Glove.println("f");
Serial.println("f");
delay(50);
  }
 else  if((dedao1position>46 && dedao1position<50) && (indi1position>60) && (meio1position<10) && (anel1position<30) && (mind1position<30) && (eixoX<10.00 && eixoX>9.50) && (feito == 2)){
 
ESP_Glove.println("g");
Serial.println("g");
delay(50);
  }
 else  if((dedao1position>70) && (indi1position>60) && (meio1position<20) && (anel1position<30) && (mind1position<30) && (eixoX<10.00 && eixoX>7.00) && (eixoY<-1.00 && eixoY>-4.00) && (feito == 2)){
ativH = 1;
delay(100);
if(eixoX>9.50 && ativH == 1){
ESP_Glove.println("h");
Serial.println("h");
ativH = 0;
delay(200);
  }
 }
 else  if((dedao1position<10) && (indi1position<10) && (meio1position<30) && (anel1position<30) && (mind1position>70 ) && (eixoX<10.00 && eixoX>9.50) && (eixoY>0.90 && eixoY<3.00) && (feito == 2)){
ativJ = 1;
delay(100); 
ESP_Glove.println("i");
Serial.println("i");
delay(200);
  }
 else  if((dedao1position<10) && (indi1position<10) && (meio1position<30) && (anel1position<30) && (mind1position>70 ) && (eixoX<11.00 && eixoX>9.20) && (eixoY<0.90 && eixoY>-3.00) && (ativJ == 1) && (feito == 2)){
delay(80);
ESP_Glove.println("j");
Serial.println("j");
delay(50);
ativJ = 0;
 }
 else  if((dedao1position>60) && (indi1position>60) && (meio1position>70) && (anel1position<30) && (mind1position<30) && (eixoX<11.00 && eixoX>9.20) && (feito == 2)){
ativK = 1;
delay(200);
if(eixoY<0.00 && ativK == 1){
ESP_Glove.println("k");
Serial.println("k");
delay(5);
ativK=0;
  }
 }
else  if((dedao1position>70) && (indi1position>60) && (meio1position<10) && (anel1position<20) && (mind1position<25 ) && (eixoX<10.00 && eixoX>9.50) && (eixoY<3.00 && eixoY>0.00) && (feito == 2)){
 
ESP_Glove.println("l");
Serial.println("l");
delay(50);
  }
else  if((dedao1position<10) && (indi1position>60) && (meio1position>70) && (anel1position>55) && (mind1position<30 ) && (eixoX<-6.00 && eixoX>-9.00) && (feito == 2)){
 
ESP_Glove.println("m");
Serial.println("m");
delay(50);
  }
else  if((dedao1position<10) && (indi1position>60) && (meio1position>70) && (anel1position<30) && (mind1position<30 ) && (eixoX<-6.00 && eixoX>-9.00) && (feito == 2)){
 
ESP_Glove.println("n");
Serial.println("n");
delay(50);
  }
else  if((dedao1position<10) && (indi1position<10) && (meio1position<10) && (anel1position<20) && (mind1position<25 ) && (eixoX<10.00 && eixoX>9.50) && (eixoY<0.00 && eixoY>-5.80) && (feito == 2)){
 
ESP_Glove.println("o");
Serial.println("o");
delay(50);
  }
 else  if((dedao1position<1) && (indi1position>60) && (meio1position<10) && (anel1position<30) && (mind1position<30) && (eixoX<8.00 && eixoX>4.00) && (feito == 2)){
delay(300);
ESP_Glove.println("p");
Serial.println("p");
delay(50);
  }
else  if((dedao1position>40 && dedao1position<80) && (indi1position>60) && (meio1position<10) && (anel1position<30) && (mind1position<30 ) && (eixoX<-6.00 && eixoX>-9.00) && (feito == 2)){
 
ESP_Glove.println("q");
Serial.println("q");
delay(50);
}
else  if((dedao1position<10) && (indi1position>60) && (meio1position<=68 && meio1position>10) && (anel1position<20) && (mind1position<30 ) && (eixoX<10.00 && eixoX>9.50) && (feito == 2)){
 
ESP_Glove.println("r");
Serial.println("r");
delay(50);
  }
else  if((dedao1position<10) && (indi1position<10) && (meio1position<10) && (anel1position<30) && (mind1position<30 ) && (eixoX<10.00 && eixoX>9.50) && (eixoY>0.00 && eixoY<5.80) && (feito == 2)){
 
ESP_Glove.println("s");
Serial.println("s");
delay(50);
  }
  else  if((dedao1position<10) && (indi1position>60) && (meio1position<10) && (anel1position<30) && (mind1position<30 ) && (eixoX<10.00 && eixoX>9.50) && (eixoY>0.00 && eixoY<5.80) && (feito == 2)){
 
ESP_Glove.println("t");
Serial.println("t");
delay(50);
  }
  else  if((dedao1position<10) && (indi1position>60) && (meio1position>60) && (anel1position<30) && (mind1position<30 ) && (eixoX<10.00 && eixoX>9.50) && (eixoY>0.00 && eixoY<5.80) && (feito == 2)){
 
ESP_Glove.println("u");
Serial.println("u");
delay(100);
  }
    else  if((dedao1position<70 && dedao1position>30) && (indi1position>60) && (meio1position>60) && (anel1position<30) && (mind1position<30 ) && (eixoX<10.00 && eixoX>9.50) && (eixoY>0.00 && eixoY<5.80) && (feito == 2)){
 
ESP_Glove.println("v");
Serial.println("v");
delay(50);
  }
   else  if((dedao1position<10) && (indi1position>60) && (meio1position>60) && (anel1position>60) && (mind1position<30) && (eixoX<10.00 && eixoX>7.00) && (eixoY<0.00 && eixoY>-5.80) && (feito == 2)){
ativW = 1;
delay(100);
if(eixoX>9.00 && ativW == 1){
ESP_Glove.println("w");
Serial.println("w");
ativW = 0;
delay(200);
  }
   }
 else  if((dedao1position<10) && (indi1position>60) && (meio1position>60) && (anel1position<30) && (mind1position<30) && (eixoX>1.00 && eixoX<6.00) && (eixoY<0.00 && eixoY>-10.00) && (feito == 2)){
 delay(50);
ESP_Glove.println("x");
Serial.println("x");
  }
   else  if((dedao1position>60) && (indi1position<10) && (meio1position<10) && (anel1position<30) && (mind1position>60) && (eixoX>1.00 && eixoX<6.00) && (eixoY<0.00 && eixoY>-10.00) && (feito == 2)){
 delay(50);
ESP_Glove.println("y");
Serial.println("y");
  }
     else  if((dedao1position<10) && (indi1position>60) && (meio1position<10) && (anel1position<30) && (mind1position<30) && (eixoX>1.00 && eixoX<4.00) && (eixoY<0.00 && eixoY>-10.00) && (feito == 2)){
 delay(100);
ESP_Glove.println("z");
Serial.println("z");
delay(200);
  }
}
