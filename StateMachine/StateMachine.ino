/* Operations:
 * 
 * 1. Always start the robot facing Right with corner in the bottom left.
 * 
 * 
 */



// Pin declaration
static int MotorRCh1 = 5;
static int MotorRCh2 = 6;
static int MotorREN = 4;
static int EncodeR = 2;
static int DistREcho = 12;

static int MotorLCh1 = 9;
static int MotorLCh2 = 10;
static int MotorLEN = 7;
static int EncodeL = 3;
static int DistLEcho = 13;

static int DistTrig = 11;
static int IRF = 8;//Active Low

// Variable Declarations
int TicksR = 0;
int TicksL = 0;
// For Vco (Velocity Coefficient) Vc0/100 will be used to slow down motors. Set this int from 1->100.
int VcoR = 100;
int VcoL = 100;
// Sensor value variables
float DistL = 0;
float DistF = 0;
float DistR = 0;

//Motor Array
// int motor[] = {MotorCh1, MotorCh2, MotorEN, Ticks,   Vco }
//                motor[0]  motor[1]  motor[2] motor[3] motor[4]

int RMotor[] = {MotorRCh1, MotorRCh2, MotorREN, TicksR, VcoR};
int LMotor[] = {MotorLCh1, MotorLCh2, MotorLEN, TicksL, VcoL};
//Sensor Array
int sensor[] = {DistLEcho, IRF, DistREcho};
float sensorVal[] = {DistL, DistF, DistR};

enum cardDir {NORTH, EAST, SOUTH, WEST};
enum cardDir Facing;

// Maze instantiation
int maze[16][16];

#include "FunctionLibrary/FunctionLibrary.h"

//Setup Sensors
NewPing UltrasonicLeft(DistTrig, DistLEcho, 30);
NewPing UltrasonicRight(DistTrig, DistREcho, 30);

// Position Array
int xPos = 0;
int yPos = 0;
void setup() {
  // Set the maze to all zeros
  int j;
  int i;
  for (i=0;i<16;i++){
    for (j=0;j<16;j++){
      maze[i][j]=0;
    }
  }
  
  // Do all the hardware setup here
  pinMode(MotorRCh1,OUTPUT);
  pinMode(MotorRCh2,OUTPUT);
  pinMode(MotorREN,OUTPUT);
  pinMode(EncodeR,INPUT);
  pinMode(DistREcho, INPUT);
  
  pinMode(MotorLCh1,OUTPUT);
  pinMode(MotorLCh2,OUTPUT);
  pinMode(MotorLEN,OUTPUT);
  pinMode(EncodeL,INPUT);
  pinMode(DistLEcho, INPUT);

  pinMode(DistTrig, OUTPUT);
  pinMode(IRF,INPUT);

  
  // Read sensors to determine which direction is being faced
//  checkStart()
  // Update the maze array
  xPos = 0;
  yPos = 0;
  Facing = SOUTH;
  maze[xPos][yPos] = CheckSensors(sensorVal, Facing, UltrasonicLeft, UltrasonicRight);
  // Face valid direction
  
  // Start move

  // Enter loop
}

void loop() {
  //Check encoders to see if enterned next space
  if(StandardizeEncoders(LMotor,RMotor)){
     maze[xPos][yPos] = CheckSensors(sensorVal, Facing, UltrasonicLeft, UltrasonicRight);
     switch Facing
     case: 
  }

}
