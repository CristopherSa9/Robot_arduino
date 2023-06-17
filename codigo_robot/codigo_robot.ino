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
  BT.begin(9600);
  pinMode(piston,OUTPUT);
 digitalWrite(piston, LOW);
  motor.attach(motor1);
  motor_v2.attach(motor2);
  motor_v3.attach(motor3);
  motor_v4.attach(motor4);
  motor_v5.attach(motor_lento);

}

void loop() {
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
  if(Serial.available() > 0)
  {
  char entrada = Serial.read();

  if(entrada =='O' || entrada =='o'){
    
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
    
    cont = 50;
    cont_2 = - 50; 
  }
  if(entrada == 'f' || entrada == 'F')
  {
    motorControl(0);
    motorControl_v2(0);
    motorControl_v3(0);
    motorControl_v4(0);
    cont = 0;
    cont_2 = 0;
  }
  if(entrada == 'r' || entrada == 'R')
  {
    Serial.print("Contador: ");
    cont = cont + 10;
    cont_2 = cont_2 -10;
    
    motorControl(cont);
    motorControl_v2(cont);
    motorControl_v3(cont_2);
    motorControl_v4(cont_2);
    Serial.println(cont);
    Serial.print("Contador: ");
    Serial.println(cont_2);
  }
  if(entrada == 'x' || entrada == 'X')
  {
    Serial.print("Contador: ");
    cont = cont - 10;
    cont_2 = cont_2 + 10;
    motorControl(cont);
    motorControl_v2(cont);
    motorControl_v3(cont_2);
    motorControl_v4(cont_2);
    Serial.println(cont);
    Serial.print("Contador: ");
    Serial.println(cont_2);
  }
  if(entrada =='T' || entrada == 't')
  {
    motorControl_v5(20);
    delay(1000);

  }
   if(entrada =='n' || entrada == 'N')
  {
    motorControl_v5(0);

  }
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
