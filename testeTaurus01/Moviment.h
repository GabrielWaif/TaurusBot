#pragma once
#include "Arduino.h"
#include "MotorController.h"

class Moviment
{
public:
        Moviment (DCMotorController motor1, DCMotorController motor2);  
        void forward();
        void left();
        void right();
        void stop();
        
private:
        int _speed = 255;
        bool direction = true, stop = true;
};
