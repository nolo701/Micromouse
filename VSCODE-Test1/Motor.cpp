#include "Motor.h"

Motor::Motor()
{
    this->Channel1 = 0;
    this->Channel2 = 0;
    this->EncoderTicks = 0;
    this->VelocityCoefficient = 0;
    this->Moving = true;
}
Motor::Motor(int CH1, int CH2, int Ticks, int VCO, bool moving)
{
    this->Channel1 = CH1;
    this->Channel2 = CH2;
    this->EncoderTicks = Ticks;
    this->VelocityCoefficient = VCO;
    this->Moving = moving;
}

void Motor::MoveMotor(MOTORDIRECTION inputDirection, int speed)
{
    int speed8bitdutycycle = 255 * (speed * (VelocityCoefficient / float(100))) / 100; // int division
    analogWrite(Channel1, (inputDirection == FORWARD) * speed8bitdutycycle);
    analogWrite(Channel2, (inputDirection == BACKWARD) * speed8bitdutycycle);
    Serial.print("8bit speed: ");
    Serial.println(speed8bitdutycycle);
    if (speed8bitdutycycle > 0)
    {
        setMoving(true);
    }
    else
    {
        setMoving(false);
    }
}

// Getters and Setters - Motor Channels should Never Change and will not have these
int Motor::getEncoderTicks()
{
    return EncoderTicks;
}

int Motor::getVelocityCoefficient()
{
    return VelocityCoefficient;
}

bool Motor::getMoving()
{
    return Moving;
}

void Motor::incrementEncoderTicks(int inc)
{
    this->EncoderTicks = EncoderTicks + inc;
}

void Motor::setVelocityCoefficient(int input)
{
    this->VelocityCoefficient = input;
}

void Motor::setMoving(bool in)
{
    this->Moving = in;
}
