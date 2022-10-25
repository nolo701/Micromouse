
#include "Position.h"
#include <math.h>

Position::Position()
{
    x = -1;
    y = -1;
    quad = 0;
    distanceEnd = -1;
}

Position::Position(int xIn, int yIn)
{
    this->x = xIn;
    this->y = yIn;
    // Set the quadrant distance only if it isnt an end space
    if (!(
            ((xIn == 7) && (yIn == 7)) ||
            ((xIn == 7) && (yIn == 8)) ||
            ((xIn == 8) && (yIn == 7)) ||
            ((xIn == 8) && (yIn == 8))

                ))
    {
        if (x > 7)
        {
            if (y > 7)
            {
                this->quad = 4;
                this->distanceEnd = distanceBetween(Position(8, 8));
            }
            else
            {
                this->quad = 2;
                this->distanceEnd = distanceBetween(Position(8, 7));
            }
        }
        else if (y > 7)
        {
            this->quad = 3;
            this->distanceEnd = distanceBetween(Position(7, 8));
        }
        else
        {
            this->quad = 1;
            this->distanceEnd = distanceBetween(Position(7, 7));
        }
    }
    else
    {
        // if its an end square let quad == 5 & distance = 0
        this->quad = 5;
        this->distanceEnd = 0;
    }
}

Position::Position(const Position &p)
{
    this->x = p.x;
    this->y = p.y;
    this->quad = p.quad;
    this->distanceEnd = p.distanceEnd;
}

float Position::distanceBetween(Position destination)
{
    return sqrt((pow(x - destination.getX(), 2)) + pow(y - destination.getY(), 2));
}

int Position::getX()
{
    return x;
}

int Position::getY()
{
    return y;
}

int Position::getQuad()
{
    return quad;
}

float Position::getDistEnd()
{
    return distanceEnd;
}
void Position::setX(int inputX)
{
    this->x = inputX;
}

void Position::setY(int inputY)
{
    this->y = inputY;
}

void Position::updatePos()
{
    if (x > 7)
    {
        if (y > 7)
        {
            this->quad = 4;
            this->distanceEnd = distanceBetween(Position(8, 8));
        }
        else
        {
            this->quad = 2;
            this->distanceEnd = distanceBetween(Position(8, 7));
        }
    }
    else if (y > 7)
    {
        this->quad = 3;
        this->distanceEnd = distanceBetween(Position(7, 8));
    }
    else
    {
        this->quad = 1;
        this->distanceEnd = distanceBetween(Position(7, 7));
    }
}

bool validatePosition(Position input)
{
    return true;
}