#include "SoftwareSerial.h"
#include "SharpIR.h"
#include "Moviment.h"

Moviment moviment;

SharpIR sensor( SharpIR::GP2Y0A21YK0F, A1 );

SoftwareSerial bluetooth(2, 3);
int incomingByte;

// Direita = true - Esquerda = false
bool direction = true, stop = true;

void setup()
{
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  int distance = sensor.getDistance();

  while(distance>=20 && !stop) {
    distance = sensor.getDistance();
    bluetooth.println(distance);
    bluetooth.println(incomingByte);
    moviment.forward();
  }

while(distance<20 || stop){
  distance = sensor.getDistance();
  bluetooth.println(distance);
  bluetooth.println(incomingByte);
  
  if (bluetooth.available() > 0) {
    incomingByte = bluetooth.read();
  }
    switch(incomingByte){
      case 'F':
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
        stop = true;
        break;
    }

    if(!stop){
      if(direction) moviment.right();

      else moviment.left();
    }
    else moviment._stop();
  }
}
