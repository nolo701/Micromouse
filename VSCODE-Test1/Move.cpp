
#include "Move.h"
#ifndef MATH_H
#include <math.h>
#endif

void Move::moveStraight3(Sensors Sensors, int desiredSpeed)
{
    int pastR = R.getEncoderTicks();
    int pastL = L.getEncoderTicks();
    moveForward(desiredSpeed);
    delay(100);
    int deltaL = L.getEncoderTicks() - pastL;
    int deltaR = R.getEncoderTicks() - pastR;

    int netDelta = deltaL - deltaR;
    Serial.print("delta L: ");
    Serial.print(deltaL);
    Serial.print(" delta R: ");
    Serial.print(deltaR);
    Serial.print(" delta L-R: ");
    Serial.println(netDelta);
    Serial.println((netDelta*2)/3);

    if (abs(netDelta) > 1) // Enough of a change in sides to modify the current values
    {
        if(netDelta>0){
            L.setVelocityCoefficient(L.getVelocityCoefficient()-(abs(netDelta)*2));
            
        }
        if(netDelta<0){
            R.setVelocityCoefficient(R.getVelocityCoefficient()-abs(netDelta)*2);
        }
    }
    else{
        L.setVelocityCoefficient(L.getVelocityCoefficient()+3);
        if(L.getVelocityCoefficient()>100){
            L.setVelocityCoefficient(97);
        }
        R.setVelocityCoefficient(R.getVelocityCoefficient()+3);
        if(R.getVelocityCoefficient()>100){
            R.setVelocityCoefficient(100);
        }
    }
}

void Move::moveStraight2(Sensors Sensors, int desiredSpeed)
{

    // Amount to shift the Velocity Coefficients by
    // int band = 2;
    int nullBand = 12;
    int y2 = 100;
    int y1 = 0;
    float p = 1.85; // 1.75 magic
    // int scaler = (y2-y1)/p
    int delta = Sensors.getDistanceL() - Sensors.getDistanceR();
    Serial.print("delta: ");
    Serial.println(delta);

    // Update the sensors as this will be an idle task
    /*
    if (abs(delta) > nullBand) // null sensor difference
    {
        L.setVelocityCoefficient(0);
        R.setVelocityCoefficient(0);
    }
    */

    float m = 0.05;
    float Vco = 100 * exp(-m * (delta * delta));
    Serial.println(Vco);

    if (delta > 0) // Go left
    {
        // int Vco = 100 * p / (abs(delta));
        float Vco = 100 * exp(-m * (delta * delta));
        if (Vco > 100)
            Vco = 100;
        if (Vco < 0)
            Vco = 0;
        // if the left side is further from the wall than the right side with a buffer of 1cm,
        // then increase the the right motor speed and decrease the left motor.
        Serial.println("MOVE LEFT!!!!");

        L.setVelocityCoefficient(Vco);
        R.setVelocityCoefficient(100);
    }
    else if (delta < 0) // Go right
    {
        // int Vco = 100 * p / (abs(delta));
        float Vco = 100 * exp(-m * (delta * delta));
        if (Vco > 100)
            Vco = 100;
        if (Vco < 0)
            Vco = 0;
        // if the right side is further from the wall than the left side with a buffer of 1cm,
        // then increase the the right motor speed and decrease the left motor.
        Serial.println("MOVE RIGHT!!!!");

        R.setVelocityCoefficient(Vco);
        L.setVelocityCoefficient(100);
    }

    moveForward(desiredSpeed);
};

Move::Move()
{
    this->L = Motor();
    this->R = Motor();
}
Move::Move(Motor inL, Motor inR)
{
    this->L = inL;
    this->R = inR;
};

void Move::stopMotors()
{
    L.MoveMotor(L.FORWARD, 0);
    R.MoveMotor(R.FORWARD, 0);
};

void Move::moveForward(int speed)
{
    L.MoveMotor(L.FORWARD, speed);
    R.MoveMotor(R.FORWARD, speed);
};

void Move::turnLeft(int speed)
{
    L.MoveMotor(L.BACKWARD, speed);
    R.MoveMotor(R.FORWARD, speed);
};

void Move::turnRight(int speed)
{
    L.MoveMotor(L.FORWARD, speed);
    R.MoveMotor(R.BACKWARD, speed);
};

void Move::diffLeft(int speed, int differential)
{
    L.MoveMotor(L.FORWARD, speed);
    R.MoveMotor(R.BACKWARD, speed);
};

// This will be the function to read the sensors and then
void Move::moveStraight(Sensors Sensors, int desiredSpeed)
{

    // Amount to shift the Velocity Coefficients by
    int scale = 10;

    // Update the sensors as this will be an idle task

    if ((Sensors.getDistanceL() - Sensors.getDistanceR()) > 2)
    {
        // if the left side is further from the wall than the right side with a buffer of 1cm,
        // then increase the the right motor speed and decrease the left motor.
        Serial.println("MOVE LEFT!!!!");
        if ((L.getVelocityCoefficient() - scale) >= 0)
        {
            L.setVelocityCoefficient(L.getVelocityCoefficient() - scale);
        }
        if ((R.getVelocityCoefficient() + scale) <= 100)
        {
            R.setVelocityCoefficient(R.getVelocityCoefficient() + scale);
        }
    }
    else if ((Sensors.getDistanceL() - Sensors.getDistanceR()) < 2)
    {
        Serial.println("MOVE RIGHT!!!!");
        if ((R.getVelocityCoefficient() - scale) >= 0)
        {
            R.setVelocityCoefficient(R.getVelocityCoefficient() - scale);
        }
        if ((L.getVelocityCoefficient() + scale) <= 100)
        {
            L.setVelocityCoefficient(L.getVelocityCoefficient() + scale);
        }
    }
    moveForward(desiredSpeed);
};

// This will be the function to take the current orientation and rotate towards a position and start moving
void Move::moveToPosition(Position destination){

};

Motor *Move::refMotorL()
{
    return &L;
}

Motor *Move::refMotorR()
{
    return &R;
}