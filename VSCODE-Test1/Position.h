/*

This header is to define what a Position is. For this project is
represents a square in the MM maze. It has a (x,y) coordinate pair
relative to the top left corner (0,0). Due to the 16x16 nature of the
maze, it also has a value representing the distance to the closest
end point, determined by which of the center 4 Positions are closest.
We apply a quadrant value to each Position for ease of explaination.
This could be removed but adds context.

*/

#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
    int x;
    int y;
    int quad;
    float distanceEnd;

public:
    // Constructor Prototypes
    Position();
    Position(int xIn, int yIn);
    Position(const Position &p);

    // Function Prototypes
    float distanceBetween(Position destination);
    void updatePos();

    // Getter and Setter prototypes
    int getX();
    int getY();
    int getQuad();
    float getDistEnd();
    void setX(int inputX);
    void setY(int inputY);
};

#endif