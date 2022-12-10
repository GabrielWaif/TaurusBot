#include "Moviment.h"
#include "SoftwareSerial.h"
#include "SharpIR.h"

Moviment moviment;

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

  if (incomingByte == 'F') {
    while(distance >= 16){
      distance = sensor.getDistance();
      moviment.forward();
    }
    moviment._stop();
    
  }

  if (incomingByte == 'B') {
    moviment.backward();
  }

  if (incomingByte == 'L') {
    while(distance <= 20){
      distance = sensor.getDistance();
      moviment.left();
    }
    moviment._stop();
    }

  if (incomingByte == 'R') {
    while(distance <= 20){
      distance = sensor.getDistance();
      moviment.right();
    }
    moviment._stop();
    }


  if (incomingByte == 'S') {
    moviment._stop();
  }

}
