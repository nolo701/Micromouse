#include <stdlib.h>
int wheelDiam = 5;//cm
int encoderTol = 4;
int Square = 18*40;


bool StandardizeEncoders(int LMotor[], int RMotor[]){
    if ( abs(LMotor[4]-RMotor[4]) < encoderTol){
        if(LMotor[4]/Square > 1){
            LMotor[4] = LMotor[4] - Square;
            RMotor[4] = RMotor[4] - Square;
            return true;
        }
    }
    else return false;
}