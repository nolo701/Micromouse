
#include <stdlib.h>
int wheelDiam = 5;//cm
int encoderTol = 4;
int Square = 18*40;


bool StandardizeEncoders(int LMotor[], int RMotor[]){
    bool output = false;
    if (abs(LMotor[4]-RMotor[4]) < encoderTol){
    if ( abs(LMotor[4]-RMotor[4]) < encoderTol){
        if(LMotor[4]/Square > 1){
            LMotor[4] = LMotor[4] - Square;
            RMotor[4] = RMotor[4] - Square;
            output = true;
            return true;
        }
    }
    return output;
}

int CheckSensors(float sensorVal[], int Facing, NewPing L, NewPing R){
    char mask = 0x0F;

    int wallThreshold = 10;

    //Read all the sensors, must declare the ultrasonics first
    sensorVal[0] = int(L.ping_cm());
    sensorVal[1] = !digitalRead(IRF);
    sensorVal[2] = int(R.ping_cm());

    // Make Binary mask where F = Facing, R = Right, B = Behind, L = Left
    // Mask = F R B L F R B L , which will be shifted bitwise right by
    // the enumerated value of the Facing value.
    char stateMask = 0x00;
    // F - This is a binary sensor and active low, check state
    stateMask = stateMask | ((sensorVal[0]<1)<<7);
    stateMask = stateMask | ((sensorVal[0]<1)<<3);
    // R - This is a distance sensor, compare against threshold
    stateMask = stateMask | ((sensorVal[0]>wallThreshold)<<6);
    stateMask = stateMask | ((sensorVal[0]>wallThreshold)<<2);
    // B - This should always be the direction we are coming from (except at start) and should
    //     always be open
    stateMask = stateMask | (1<<5);
    stateMask = stateMask | (1<<1);
    // L - This is a distance sensor, compare against threshold
    stateMask = stateMask | ((sensorVal[0]>wallThreshold)<<4);
    stateMask = stateMask | ((sensorVal[0]>wallThreshold)<<0);
    // Shift the mask by the facing enumeration
    stateMask = stateMask>>Facing;
    // After creating the stateMask, and it with the mask to restrict
    // to just the 4 LSBs
    return int(stateMask & mask);

}
    else return false;