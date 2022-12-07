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

  while (distance>=20) {
    distance = sensor.getDistance();
    motor1.write(speed);
    motor2.write(speed);
  }

  motor1.brake();
  motor2.brake();

  while(distance<20){
    distance = sensor.getDistance();
    incomingByte = bluetooth.read();

    if (incomingByte == 'B') {
      motor1.write(-speed);
      motor2.write(-speed);
   }

    if (incomingByte == 'L' ) {
      motor1.write(-speed);
      motor2.write(speed);
    }

    if (incomingByte == 'R') {
      motor1.write(speed);
      motor2.write(-speed);
    }

    if (incomingByte == 'S' ) {
      motor1.brake();
      motor2.brake();
    }
  }
}
