//
// Created by nolo7 on 9/26/2022.
//

#include <math.h>

enum CardDirection{NORTH, EAST, SOUTH, WEST};
enum CardDirection Facing;


class Position
{
private:
    int x;
    int y;
    int quad;
    float distanceEnd;

public:
    Position(int xIn, int yIn){
        x = xIn;
        y = yIn;
        if (x>7){
            if(y>7){
                quad=4;
                distanceEnd = distanceBetween(Position(8,8));
            }
            else {
                quad = 2;
                distanceEnd = distanceBetween(Position(8,7));
            }

        }
        else if(y>7){
            quad=3;
            distanceEnd = distanceBetween(Position(7,8));
        }
        else {
            quad = 1;
            distanceEnd = distanceBetween(Position(7,7));
        }

    }
    /*
    Position(const Position &p){
        x = p.x;
        y = p.y;
        quad = p.quad;  
        distanceEnd = p.distanceEnd;
    }
    */

    [[nodiscard]] float distanceBetween(Position destination) const{
        return sqrt((pow(x-destination.getX(),2)) + pow(y - destination.getY(),2));
    }

    [[nodiscard]] int getX() const{
        return x;
    }

    [[nodiscard]] int getY() const{
        return y;
    }

    [[nodiscard]] int getQuad() const{
        return quad;
    }

    [[nodiscard]] float getDistEnd() const{
        return distanceEnd;
    }
    void setX(int inputX){
        x = inputX;
    }

    void setY(int inputY){
        y = inputY;
    }

    void updatePos(){
        if (x>7){
            if(y>7){
                quad=4;
                distanceEnd = distanceBetween(Position(8,8));
            }
            else {
                quad = 2;
                distanceEnd = distanceBetween(Position(8,7));
            }

        }
        else if(y>7){
            quad=3;
            distanceEnd = distanceBetween(Position(7,8));
        }
        else {
            quad = 1;
            distanceEnd = distanceBetween(Position(7,7));
        }
    }


};



class Maze
{
private:
    int length = 16;//x
    int height = 16;//y
    int maze[16][16];

public:
    Maze(int l, int h){
        length = l;
        height = h;
    }

    void instantMaze(){
        for (int i=0;i<length;i++){
            for (int j=0;j<height;j++){
                maze[i][j]=0;
            }
        }
    }

    [[nodiscard]] int getLength() const{
        return length;
    }

    [[nodiscard]] int getHeight() const{
        return height;
    }

    int getValue(int inputX, int inputY){
        return maze[inputX][inputY];
    }

    int getValue(Position point){
        int pointX = point.getX();
        int pointY = point.getY();
        return maze[pointX][pointY];
    }

    void setLength(int l){
        length = l;
    }

    void setHeight(int h){
        height = h;
    }

    void setValue(Position point, int inputVal){
        int pointX = point.getX();
        int pointY = point.getY();
        maze[pointX][pointY] = inputVal;
    }
};
