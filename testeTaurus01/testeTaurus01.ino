#include "MotorController.h"
#include "SoftwareSerial.h"
#include "SharpIR.h"
#include "QTRSensors.h"

DCMotorController motor1 = DCMotorController(5,7,6);
DCMotorController motor2 = DCMotorController(8,9,10);
int speed = 130;

SharpIR sensor( SharpIR::GP2Y0A21YK0F, A1 );

SoftwareSerial bluetooth(2, 3);
int incomingByte;

class Moviment{

  private:
   int _speed;
   DCMotorController leftEngine;
   DCMotorController rightEngine;

  public:
    void setSpeed(int speed){
      _speed = speed;
    }

    int getSpeed(){
      return _speed;
    }

    void setEngines(DCMotorController l, DCMotorController r){
      leftEngine = l;
      rightEngine = r;
    }

    void forward(){
      leftEngine.writo(speed);
      rightEngine.write(speed);
    }

    void left(){
      leftEngine.write(-speed);
      rightEngine.write(speed);
    }

    void right(){
      leftEngine.write(speed);
      rightEngine.write(-speed);
    }

    void stop(){
      leftEngine.brake();
      rightEngine.brake();
    }
}


void setup()
{
  bluetooth.begin(9600);
}

void loop()
{
  int distance = sensor.getDistance();
  // Direita = true - Esquerda = false
  bool direction = true, stop = false;
  Moviment moviment;
  moviment.setEngines(motor1, motor2);

  if (bluetooth.available() > 0) {
    incomingByte = bluetooth.read();
  }

  while(distance>=20) {
    distance = sensor.getDistance();
    moviment.forward();
  }

  if(distance<20){

    switch(incomingByte){
      case 'B':
        stop = false;
        break;

      case 'L':
        direction = false;
        break;

      case 'R':
        direction = true;
        break;

      case 'S':
        stop = true
        break;
    }

    if(!stop){
      if(direction) moviment.right();

      else moviment.left();
    }
    else moviment.stop();
  }
}
