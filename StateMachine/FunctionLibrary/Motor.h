#include "Motor.c"

void moveMotor(int [], char, int);
void enableMotors(void);
void stopMotors(int [], int []);
void moveForward(int,int [],int []);
void turnLeft(int duty,int diff, int motorL[],int motorR[]);
void turnRight(int duty,int diff, int motorL[],int motorR[]);
