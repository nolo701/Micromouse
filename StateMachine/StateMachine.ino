/* Operations:
 * 
 * 1. Always start the robot facing Right with corner in the bottom left.
 * 
 * 
 */


#include "FunctionLibrary/FunctionLibrary.h"
// Pin declaration
int MotorRCh1 = 5;
int MotorRCh2 = 6;
int MotorREN = 4;
int EncodeR = 2;
int DistREcho = 12;

int MotorLCh1 = 9;
int MotorLCh2 = 10;
int MotorLEN = 7;
int EncodeL = 3;
int DistLEcho = 13;

int DistTrig = 11;

int IRF = 8;//Active Low

//Motor Array

//Sensor Array

enum cardDir {NORTH, EAST, SOUTH, WEST};
enum cardDir Facing;

// Maze instantiation
int maze[16][16];




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
  checkStart(
  // Update the maze array

  // Face valid direction

  // Start move

  // Enter loop
}

void loop() {
  // Check encoder positions to update the current location in maze array
  //moveMotor(2,'f',50);
  // Check that the robot is centered

  // Check if there is a junction (split in path)
  
  // Check that the path is still valid

  // 
  
  
}
