/*
 * This is the file where the functions to make decisions and do the logic for solving the maze is.
 */


#ifndef FUNCTIONLIBRARY_H
#include "FunctionLibrary.h"
#endif

class Think {
public:
/* This function will look at the sensors to determine which direction is the best for getting to the end
 *
 * It will flow similarly to this:
 * - Read in the sensor values
 * - Associate each distance with the square that contains it
 * - Use the current position, distance, and direction facing to then determine the magnitude to the end square.
 * - With there being 4 end squares, use the one that would be within the quadrant divided equally.
 *      ex. Q1 = x{0,7} y{0,7}; Q2 = x{8,15} y{0,7}; Q3 = x{0,7} y{8,15}; Q4 = x{8,15} y{8,15}
 * - During the comparison logic, check that the goal square is unvisited (it will have value 0 in maze[][])
 *
 */

int cmPerSquare = 18;

    Position findGoal(Position currentP, Maze M){
        int dummy = checkSensors(sensorVals, Facing, UltrasonicLeft, UltrasonicForward, UltrasonicRight);
        int[3] distUnits = {int(sensorVals[0])/cmPerSquare, int(sensorVals[1])/cmPerSquare, int(sensorVals[2])/cmPerSquare};

        // create Output Goal
        Position G(currentP);

        // Define relatives from absolute
        int[3] D = {(Facing + 3)%4, Facing, (Facing + 5)%4};
        Position[3] TestPs = {Position L(currentP), Position F(currentP), Position R(currentP)};
        for (int i=0, i<3, i++){
            if(D[i] & 0x01){
                TestPs[i].setX(TestPs[i].getX() + (2-D[i])*distUnits[i]);
                TestPs[i].updatePos();
            }
            else{
                TestPs[i].setY(TestPs[i].getY() + (-1+D[i])*distUnits[i]);
                TestPs[i].updatePos();
            }
            if(i==0){
                G.setX(TestPs[i].getX());
                G.setY(TestPs[i].getY());
                G.updatePos();
            }
            else{
                if(( TestPs[i].getDistEnd()<G.getDistEnd()) && (M.getValue(TestPs[i])==0)){
                    G.setX(TestPs[i].getX());
                    G.setY(TestPs[i].getY());
                    G.updatePos();
                }
            }
        }

        return G;

    }



/*
 * Logic/Alogrithmn for solving the maze
 *
 * - Start facing right in the starting square, this is facing = SOUTH
 * - Read in sensors and update the current position
 * - Compare the distances
 *      - This should be able to see the direction to go and set the goal space.
 * - given a goal space, use the local position and facing direction to start navagating towards it.
 * - use the encoders to know when to assign the next space. Redundantly use a change in sensor reading to double check
 * - If the assigned value to a space is new and a junction, add it to the stack of most recent junctions & evaluate the
 *   directions using the function above.
 *
 *
 *
 */

};//End Think