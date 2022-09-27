/* Operations:
 * 
 * 1. Always start the robot facing Right with corner in the bottom left.
 * 
 * 
 */



// Pin declaration
static int MotorRCh1 = 5;
static int MotorRCh2 = 6;
static int EncodeR = 2;
static int DistREcho = 12; // Distance Sensor

static int MotorLCh1 = 9;
static int MotorLCh2 = 10;
static int EncodeL = 3;
static int DistLEcho = 13; // Distance Sensor

static int DistTrig = 4;
static int DistFEcho = 8; // Distance Sensor

// Variable Declarations

// Keep track of the number of ticks on each wheel
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
// int motor[] = {MotorCh1, MotorCh2, Ticks,   Vco }
//                motor[0]  motor[1]  motor[2] motor[3]

int RMotor[] = {MotorRCh1, MotorRCh2, TicksR, VcoR};
int LMotor[] = {MotorLCh1, MotorLCh2, TicksL, VcoL};
//Sensor Array
int sensors[] = {DistLEcho, DistFEcho, DistREcho};
float sensorVals[] = {DistL, DistF, DistR};

#include "FunctionLibrary/FunctionLibrary.h"
// Create Maze
Maze M(16,16);


//Setup Sensors
NewPing UltrasonicLeft(DistTrig, DistLEcho, 30);
NewPing UltrasonicForward(DistTrig, DistFEcho, 30);
NewPing UltrasonicRight(DistTrig, DistREcho, 30);

// Position Array
Position currentPos(0,0); // Update as current position


void setup(){
  M.instantMaze();
  
  // Do all the hardware setup here
  pinMode(MotorRCh1,OUTPUT);
  pinMode(MotorRCh2,OUTPUT);
  pinMode(EncodeR,INPUT);
  pinMode(DistREcho, INPUT);
  
  pinMode(MotorLCh1,OUTPUT);
  pinMode(MotorLCh2,OUTPUT);
  pinMode(EncodeL,INPUT);
  pinMode(DistLEcho, INPUT);

  pinMode(DistTrig, OUTPUT);
  pinMode(DistFEcho,INPUT);

  
  // Read sensors to determine which direction is being faced
  //  checkStart()
  // Update the maze array
  // Set position to 0,0 & direction to south
  Facing = SOUTH;

  // Update the starting square value
  M.setValue(currentPos, checkSensors(sensorVals, Facing, UltrasonicLeft, UltrasonicForward, UltrasonicRight)); 
  // Error correct the starting space
  M.setValue(currentPos, M.getValue(currentPos) & 0x77);
  
  // Face valid direction
  
  // Start move
/*if( (maze[xPos][yPos] & (0x08>>Facing)) > 0 ){
       moveForward(100, LMotor, RMotor);
     }
     else if( (maze[xPos][yPos] & (0x44>>Facing)) > 0 ){
       turnRight(100, 50, LMotor, RMotor);
     }
     else if( (maze[xPos][yPos] & (0x11>>Facing)) > 0 ){
       turnLeft(100, 50, LMotor, RMotor);
     }
     else if( (maze[xPos][yPos] & (0x22>>Facing)) > 0 ){
       turnRight(100, 50, LMotor, RMotor);
       turnRight(100, 50, LMotor, RMotor);
       moveForward(100, LMotor, RMotor);
     }
  // Enter loop
  */
}

void loop() {
  //Check encoders to see if enterned next space
  if(standardizeEncoders(LMotor,RMotor)){
     stopMotors(LMotor,RMotor);
     delay(1000);
     //maze[xPos][yPos] = CheckSensors(sensorVal, Facing, UltrasonicLeft, UltrasonicRight);
     
  }
}
