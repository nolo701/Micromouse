
#include "Move.h"

#ifndef MATH_H
#include <math.h>
#endif

// A combined method to use encoders and distance sensors to try and remain centered
// while in a channel of a maze

void Move::moveStraight(Sensors Sensors, int desiredSpeed)
{
    static int lastEncodeVcoR = 100;
    static int lastEncodeVcoL = 100;
    Serial.print("Trying to center by: ");
    static bool succeedUltrasonic = false;
    static bool succeedEncoder = true;
    // Read the ultrasonic Sensors to see if they need to be adjusted
    Sensors.updateAll();
    int deltaDist = Sensors.getDistanceR() - Sensors.getDistanceL();
    // The encoders are used to kepe the robot drivng straight at the same velocity, it is up to
    // the distance sensors to keep it straight.
    /*
        There are 3 options when reading the sensors,
        1) Both sensor readings are valid ~centered -> fine adjustment then use encoders
            - bias using the larger of two values as it will be more accurate
        2) One sensor reading is invalid, one is valid -> use the valid to adjust
            - use the only valid distance
        3) both are invalid, either in a junction or twisted. Avoid for now!

    */
    // read the valid values first
    static bool LDistValid = Sensors.getUltrasonicL()->validateReading();
    static bool RDistValid = Sensors.getUltrasonicR()->validateReading();
    static int distanceToRef;
    static char sideToRef;

    // if both are valid use the larger of the 2 values
    if (LDistValid && RDistValid)
    {
        if (Sensors.getDistanceL() > Sensors.getDistanceR())
        {
            distanceToRef = Sensors.getDistanceL();
            sideToRef = 'L';
        }
        else
        {
            distanceToRef = Sensors.getDistanceR();
            sideToRef = 'R';
        }
    }
    // They have different validitiy values
    else if (LDistValid != RDistValid)
    {
        if (RDistValid)
        {
            distanceToRef = Sensors.getDistanceR();
            sideToRef = 'R';
        }
        else if (LDistValid)
        {
            distanceToRef = Sensors.getDistanceL();
            sideToRef = 'L';
        }
    }

    // Determine whether to straighten or continue straight
    if (distanceToRef >= 2)
    {
        Serial.print("Ultrasonic: result - ");
        // try to center with a smaller speed
        L.setVelocityCoefficient(lastEncodeVcoL);
        R.setVelocityCoefficient(lastEncodeVcoR);
        succeedUltrasonic = StraightenUltrasonicWise(Sensors, desiredSpeed, distanceToRef, sideToRef);
        Serial.println((int)succeedUltrasonic);
    }
    else
    {
        Serial.print("Encoder: result - ");
        // use the encoders to try and drive straight
        L.setVelocityCoefficient(lastEncodeVcoL);
        R.setVelocityCoefficient(lastEncodeVcoR);
        succeedEncoder = StraightenEncoderWise(Sensors, desiredSpeed);
        lastEncodeVcoL = L.getVelocityCoefficient();
        lastEncodeVcoR = R.getVelocityCoefficient();
        Serial.println((int)succeedUltrasonic);
    }
}

bool Move::StraightenUltrasonicWise(Sensors Sensors, int desiredSpeedUW, int distToRef, char sideToRef)
{
    // Read the ultrasonic Sensors to see if they need to be adjusted

    int distRUW = Sensors.getDistanceR();
    int distLUW = Sensors.getDistanceL();
    int deltaDist = distLUW - distRUW;

    

    if (sideToRef == 'L') // Go left
    {
        // int Vco = 100 * p / (abs(deltaUW));
        // int Vco = 60;
        // float Vco = 100 * exp(-m * (deltaUW * deltaUW));
        int Vco = L.getVelocityCoefficient() - (3 * distToRef)/2;
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
    else if (sideToRef == 'R') // Go right
    {
       
        int Vco = R.getVelocityCoefficient() - (3 * distToRef)/2;
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
    // Move with the updated values for a small amount of time to see if the
    // distances improved
    moveForward(desiredSpeedUW);
    //delay(5);
    
    return false;   //abs(Sensors.getDistanceL() - Sensors.getDistanceR()) < 2;
};


bool Move::StraightenEncoderWise(Sensors Sensors, int desiredSpeedEW)
{
    // Get a starting value
    int pastREW = R.getEncoderTicks();
    int pastLEW = L.getEncoderTicks();
    // Move forward with what's given
    moveForward(desiredSpeedEW);
    delay(50);
    int deltaLEW = L.getEncoderTicks() - pastLEW;
    int deltaREW = R.getEncoderTicks() - pastREW;
    //

    int netDelta = deltaLEW - deltaREW;
    Serial.print("Before Tick Error: ");
    Serial.println(netDelta);
    /*
    Serial.print("delta L: ");
    Serial.print(deltaL);
    Serial.print(" delta R: ");
    Serial.print(deltaR);
    Serial.print(" delta L-R: ");
    Serial.println(netDelta);
    Serial.println((netDelta * 2) / 3);
    */

    if (abs(netDelta) > 1) // Enough of a change in sides to modify the current values
    {
        if (netDelta > 0)
        {
            L.setVelocityCoefficient(L.getVelocityCoefficient() - (abs(netDelta) * 2));
        }
        if (netDelta < 0)
        {
            R.setVelocityCoefficient(R.getVelocityCoefficient() - abs(netDelta) * 2);
        }
    }
    else
    {
        L.setVelocityCoefficient(L.getVelocityCoefficient() + 3);
        if (L.getVelocityCoefficient() > 100)
        {
            L.setVelocityCoefficient(100);
        }
        R.setVelocityCoefficient(R.getVelocityCoefficient() + 3);
        if (R.getVelocityCoefficient() > 100)
        {
            R.setVelocityCoefficient(100);
        }
    }
    // Get a starting value
    pastREW = R.getEncoderTicks();
    pastLEW = L.getEncoderTicks();
    // Move forward with what's given
    moveForward(desiredSpeedEW);
    delay(50);
    deltaLEW = L.getEncoderTicks() - pastLEW;
    deltaREW = R.getEncoderTicks() - pastREW;
    netDelta = deltaLEW - deltaREW;
    Serial.print("After Tick Error: ");
    Serial.println(netDelta);
    return (abs(deltaLEW - deltaREW) < 2);
}

void Move::JunctionTurnL(Sensors input, int desiredSpeed)
{
    static short stage = 0;
    int FrontThresh = 15;
    int tickThresh = (input.getDistanceL() * (314 / 2) * 377) / 10000;


    if (stage == 1) // Turning Stage
    {
        int start = L.getEncoderTicks();
        while (L.getEncoderTicks() < (start + tickThresh))
        {
            L.MoveMotor(L.FORWARD, desiredSpeed / 7); // width diff 1/7
            R.MoveMotor(R.FORWARD, desiredSpeed);
        }

        stage = 0;
        return;
    }

    else
    { // Positioning stage
        while (input.getDistanceF() > FrontThresh)
        {
            moveStraight(input, desiredSpeed / 2);
            input.getUltrasonicF()->updateSensor();
        }
       
        stopMotors();
        stage = 1;
    }
}

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

void Move::setCentered(bool in)
{
    this->CENTERED = in;
}

bool Move::getCentered()
{
    return CENTERED;
}
