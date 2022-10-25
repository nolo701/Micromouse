#ifndef MOVE_H
#include "Move.h"
#endif

#ifndef SENSORS_H
#include "Sensors.h"
#endif

#ifndef MM_H
#define MM_H

class MM
{
private:
public:
    Move Movement;
    Sensors onboardSensors;
    enum DIRECTION
    {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    int Facing;
    Position currentPosition;
    Position currentGoal;
    MM();
    MM(Move, Sensors);
};

#endif