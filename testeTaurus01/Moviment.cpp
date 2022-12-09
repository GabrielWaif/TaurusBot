#include "Moviment.h"



Moviment::Moviment(DCMotorController _motor1(5,6,7), DCMotorController _motor1(8,9,10)){
  motor1 = _motor1;
  motor2 = _motor2;
}

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
