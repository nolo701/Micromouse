#include "Motor.c"

void moveMotor(int [], char, int);
void stopMotors(int [], int []);
void moveForward(int,int [],int []);
void turnLeft(int,int motorL[],int motorR[]);
void turnRight(int, int [],int []);

void diffRight(int duty,int diff, int motorL[], int motorR[]);
void diffLeft(int duty,int diff, int motorL[], int motorR[]);
