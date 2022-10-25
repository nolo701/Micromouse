#ifndef ARDUINO_H
#include <Arduino.h>
#endif

#ifndef MOTOR_H
#define MOTOR_H

class Motor{

private:
    int Channel1;
    int Channel2;
    int EncoderTicks = 0;
    int VelocityCoefficient = 100;
    bool Moving = false;

public:
    enum MOTORDIRECTION
    {
        FORWARD,
        BACKWARD
    };
    Motor();
    Motor(int CH1, int CH2, int Ticks, int VCO, bool moving);
    void MoveMotor(MOTORDIRECTION, int);
    int getEncoderTicks();
    int getVelocityCoefficient();
    bool getMoving();
    void incrementEncoderTicks(int);
    void setVelocityCoefficient(int);
    void setMoving(bool);
};

#endif