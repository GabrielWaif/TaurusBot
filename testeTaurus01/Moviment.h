#pragma once
#include "Arduino.h"
#include "MotorController.h"

class Moviment
{
public:
        Moviment (DCMotorController _motor1, DCMotorController _motor2);  
        void forward();
        void left();
        void right();
        void _stop();
        
private:
        DCMotorController motor1;
        DCMotorController motor2;
        const int _speed = 255;
        bool direction = true, stop = true;
};
