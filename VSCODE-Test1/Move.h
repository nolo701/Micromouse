
#ifndef MOTOR_H
#include "Motor.h"
#endif

#ifndef POSITION_H
#include "Position.h"
#endif


#ifndef SENSORS_H
#include "Sensors.h"
#endif


#ifndef MOVE_H
#define MOVE_H

class Move
{
    enum MotorSide {Left, Right};
    

private:
    bool CENTERED = true;

public:
    Motor R;
    Motor L;
    Move();
    Move(Motor inL, Motor inR);
    // Function Prototypes
    bool StraightenUltrasonicWise(Sensors onBoard, int desiredSpeed);
    bool StraightenEncoderWise(Sensors onBoard, int desiredSpeed);
    void moveStraight4(Sensors onBoard, int desiredSpeed);

    void JunctionTurnL(Sensors onBoard, int desiredSpeed);

    // 11/2/22 - Attempt at improving performance by decreasing sensor errors
    void moveStraight5(Sensors onBoard, int desiredSpeed);
    bool StraightenUltrasonicWise2(Sensors onBoard, int desiredSpeed, int distRef, char sideRef);



    void moveStraight3(Sensors Sensors, int desiredSpeed);
    void moveStraight2(Sensors Sensors, int desiredSpeed);
    void stopMotors();
    void moveForward(int in);
    void turnLeft(int in);
    void turnRight(int in);
    void diffRight(int duty, int diff);
    void diffLeft(int duty, int diff);
    void moveStraight(Sensors avaiableSensors, int desiredSpeed);
    void moveToPosition(Position);
    Motor* refMotorR();
    Motor* refMotorL();
    void setCentered(bool in);
    bool getCentered();

};

#endif