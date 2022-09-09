#include "Motor.h"

void moveMotor(int motor[], char dir, int duty){
    digitalWrite(motor[2],HIGH);
    int numDir = dir;
    //If the current speed does not match the
    if(duty != motor[3]){

    }
    int bitDuty = 255*duty/100;
    //This will turn on the corresponding motor depending on direction
    analogWrite(motor[0],(numDir=='f')*bitDuty);
    analogWrite(motor[1],(numDir=='r')*bitDuty);
    Serial.println(numDir);
    Serial.println(bitDuty);
    Serial.println((numDir=='f'));
    Serial.println((numDir=='f')*bitDuty);

}

void EnableMotors(void){
    digitalWrite(MotorREn,HIGH);
    digitalWrite(MotorLEn,HIGH);
}