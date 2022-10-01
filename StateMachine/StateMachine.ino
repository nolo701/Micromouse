/* Operations:

   1. Always start the robot facing Right with corner in the bottom left.


*/



// Pin declarations
static int MotorRCh1 = 6;
static int MotorRCh2 = 5;
static int EncodeR = 2;
static int MotorLCh1 = 9;
static int MotorLCh2 = 10;
static int EncodeL = 3;
static int DistLEcho = 13; // Distance Sensor
static int DistFEcho = 8; // Distance Sensor
static int DistREcho = 12; // Distance Sensor
static int DistLTrig = A2;
static int DistFTrig = A4;
static int DistRTrig = A3;

// Variable Declarations
int TicksR = 0; // Keep track of the number of ticks on each wheel
int TicksL = 0; // Keep track of the number of ticks on each wheel
int VcoR = 100; // For Vco (Velocity Coefficient) Vc0/100 will be used to slow down motors. Set this int from 1->100.
int VcoL = 100; // For Vco (Velocity Coefficient) Vc0/100 will be used to slow down motors. Set this int from 1->100.
float DistL = 0; // Sensor value variables
float DistF = 0; // Sensor value variables
float DistR = 0; // Sensor value variables

int Moving = 0; // Integer bool for knowing if we are moving
//Motor Array
// int motor[] = {MotorCh1, MotorCh2, Ticks,   Vco }
//                motor[0]  motor[1]  motor[2] motor[3]

int RMotor[] = {MotorRCh1, MotorRCh2, TicksR, VcoR, Moving};
int LMotor[] = {MotorLCh1, MotorLCh2, TicksL, VcoL, Moving};
//Sensor Array
int sensors[] = {DistLEcho, DistFEcho, DistREcho};
float sensorVals[] = {DistL, DistF, DistR};


#include "FunctionLibrary/FunctionLibrary.h"
// Create Maze
Maze M(16, 16);

// CPP 
Position findGoal(Position , Maze);
void Drive2Goal(Position, Position);


//Setup Sensors
NewPing UltrasonicLeft(DistLTrig, DistLEcho, 100);
NewPing UltrasonicForward(DistFTrig, DistFEcho, 100);
NewPing UltrasonicRight(DistRTrig, DistREcho, 100);

// Position Array
Position currentPos(0, 0); // Update as current position
Position goal(99, 99); // Goal space
// Create Pathing Stack
int PathLength = 0;
Position PathStack[] = {currentPos};
//Position *End = &PathStack[0];

void setup() {
  M.instantMaze();

  // Do all the hardware setup here
  pinMode(MotorRCh1, OUTPUT);
  pinMode(MotorRCh2, OUTPUT);
  pinMode(EncodeR, INPUT);
  pinMode(MotorLCh1, OUTPUT);
  pinMode(MotorLCh2, OUTPUT);
  pinMode(EncodeL, INPUT);
  pinMode(DistLEcho, INPUT);
  pinMode(DistLTrig, OUTPUT);
  pinMode(DistFEcho, INPUT);
  pinMode(DistFTrig, OUTPUT);
  pinMode(DistREcho, INPUT);
  pinMode(DistRTrig, OUTPUT);

  // Set position to 0,0 & direction to south
  Facing = SOUTH;
  // Update the starting square value
  M.setValue(currentPos, checkSensors(sensorVals, Facing, UltrasonicLeft, UltrasonicForward, UltrasonicRight));
  // Error correct the starting space
  M.setValue(currentPos, M.getValue(currentPos) & 0x77);
  // Check sensor for a goal
  goal = findGoal(currentPos, M);
  // Add the goal to the stack
  Drive2Goal(currentPos, goal);

}

void loop() {
  //Check encoders to see if enterned next space
  if (standardizeEncoders(LMotor, RMotor)) {
    // Check a goal

  }
}
