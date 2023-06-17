
#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(9,10); 

int piston = 11;
int cont= 0;
int cont_2 = 0;
int motor1 = 2;
int motor2 = 3;
int motor3 = 4;
int motor4 = 5;
int motor_lento = 6;
Servo motor;
Servo motor_v2;
Servo motor_v3;
Servo motor_v4;
Servo motor_v5;

void setup() {
  Serial.begin(9600);
   
  pinMode(piston,OUTPUT);
  digitalWrite(piston, LOW);
  motor.attach(motor1);
  motor_v2.attach(motor2);
  motor_v3.attach(motor3);
  motor_v4.attach(motor4);
  motor_v5.attach(motor_lento);
  BT.begin(57600); 
}

void loop() {
  if(BT.available() > 0)
  {
  char entrada = BT.read();

  if(entrada =='F' || entrada =='f'){
   adelante(),adelante_2();
   Serial.println(BT.read());
  }
  if(entrada =='D' || entrada =='d'){
   atras(),atras_2();
   Serial.println(BT.read());
   
  }
  if(entrada == 'S' || entrada == 's')
  {
    motorControl(0);
    motorControl_v2(0);
    motorControl_v3(0);
    motorControl_v4(0);
    Serial.write(BT.read());
  }
  if(entrada == 'L' || entrada == 'l')
  {
    motorControl(-50);
    motorControl_v2(-50);
    motorControl_v3(-50);
    motorControl_v4(-50);
    Serial.println(BT.read());
  }
  if(entrada == 'R' || entrada == 'r')
  {
    motorControl(50);
    motorControl_v2(50);
    motorControl_v3(50);
    motorControl_v4(50);
    Serial.println(BT.read());
  }
  if(entrada == 'G' || entrada == 'g')
  {
    digitalWrite(piston, HIGH);
    delay(2000);
    motorControl_v5(20);
    delay(1000);
    motorControl_v5(0);
    digitalWrite(piston, LOW);
  }
  if(entrada == 'A' || entrada == 'a')
  {
    motorControl(50);
    motorControl_v2(50);
    motorControl_v3(-50);
    motorControl_v4(-50);
    delay(2000);
    motorControl(0);
    motorControl_v2(0);
    motorControl_v3(0);
    motorControl_v4(0);
    delay(2000);  
    digitalWrite(piston, HIGH);
    delay(2000);
    motorControl_v5(20);
    delay(1000);
    motorControl_v5(0);
    digitalWrite(piston, LOW);
    delay(6000);
  }  
  }



}

int adelante(){
  for(int i = 30 ;i >= 90; i = i +5){
    motorControl(i);
    motorControl_v2(i);
    Serial.println(i);
    delay(250);
  }
}

int adelante_2(){
  for(int i = -30 ; i >= -90; i = i - 5){
    motorControl_v3(i);
    motorControl_v4(i);
    Serial.println(i);
    delay(250);
  }
}
int atras(){
  for(int i = 30 ;i <= 90; i = i - 5){
    motorControl(i);
    motorControl_v2(i);
    Serial.println(i);
    delay(250);
  }
}
int atras_2(){
  for(int i = 30 ; i >= 90; i = i + 5){
    motorControl_v3(i);
    motorControl_v4(i);
        Serial.println(i);
    delay(250);
  }
}

int motorControl(int value){
motor.write(map(value,-100,100,1000,2000));
}
int motorControl_v2(int value){
motor_v2.write(map(value,-100,100,1000,2000));
}
int motorControl_v3(int value){
motor_v3.write(map(value,-100,100,1000,2000));
}
int motorControl_v4(int value){
motor_v4.write(map(value,-100,100,1000,2000));
}
int motorControl_v5(int value){
motor_v5.write(map(value,-100,100,1000,2000));
}
