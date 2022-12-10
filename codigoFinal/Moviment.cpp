#include "Moviment.h"


DCMotorController motor1 = DCMotorController(5,7,6);
DCMotorController motor2 = DCMotorController(8,9,10);

void Moviment::forward(){
  motor1.write(255);
  motor2.write(131);
}

void Moviment::backward(){
  motor1.write(-255);
  motor2.write(-131);
}

void Moviment::left(){
  motor1.write(0);
  motor2.write(255);
}

void Moviment::right(){
  motor1.write(255);
  motor2.write(0);
}

void Moviment::_stop(){
  motor1.brake();
  motor2.brake();
}
