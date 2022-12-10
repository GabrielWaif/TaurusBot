#pragma once
#include "Arduino.h"
#include "MotorController.h"

class Moviment
{
public:
        void forward();
        void backward();
        void left();
        void right();
        void _stop();
};
