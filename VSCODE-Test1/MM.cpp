#include "MM.h"

MM::MM()
{
}
MM::MM(Move inMove, Sensors inSensors)
{
    this->Facing = SOUTH;
    this->currentPosition = Position(0, 0);
    this->currentGoal = Position(-1, -1);
    this->Movement = inMove;
    this->onboardSensors = inSensors;
}