#include "MotorController.h"
#include "SoftwareSerial.h"
#include "SharpIR.h"
#include "QTRSensors.h"

DCMotorController motor1 = DCMotorController(5,7,6);
DCMotorController motor2 = DCMotorController(8,9,10);
int _speed = 255;

SharpIR sensor( SharpIR::GP2Y0A21YK0F, A1 );

SoftwareSerial bluetooth(2, 3);
int incomingByte;

// Direita = true - Esquerda = false
bool direction = true, stop = true;


void forward(){
  motor1.write(255);
  motor2.write(131);
}

void left(){
  motor1.write(-_speed);
  motor2.write(_speed);
}

void right(){
  motor1.write(_speed);
  motor2.write(-_speed);
}

void _stop(){
  motor1.brake();
  motor2.brake();
  }


void setup()
{
  bluetooth.begin(9600);
}

void loop()
{
  int distance = sensor.getDistance();

  if (bluetooth.available() > 0) {
    incomingByte = bluetooth.read();
  }

  while(distance>=20 && !stop) {
    distance = sensor.getDistance();
    forward();
  }

  while(distance<20 || stop){
  distance = sensor.getDistance();
  if (bluetooth.available() > 0) {
    incomingByte = bluetooth.read();
  }
    
    switch(incomingByte){
      case 'B':
        stop = false;
        break;

      case 'L':
        stop = false;
        direction = false;
        break;

      case 'R':
        stop = false;
        direction = true;
        break;

      case 'S':
        stop = true
        break;
    }

    if(!_stop){
      if(direction) right();

      else left();
    }
    else _stop();
  }
}
