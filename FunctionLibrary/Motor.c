
// A motor should look like:

// int motor[] = {MotorCh1, MotorCh2, Ticks,   Vco }
//                motor[0]  motor[1]  motor[2] motor[3]
#ifndef NEWPING_CPP
#include "NewPing.cpp"
#endif

void moveMotor(int motor[], char dir, int duty){
    int numDir = dir;   
    int bitDuty = 255*duty/100;
    //This will turn on the corresponding motor depending on direction
    analogWrite(motor[0],(numDir=='f')*bitDuty);
    analogWrite(motor[1],(numDir=='r')*bitDuty);
	motor[4] = 1;
	
   /* Serial.println(numDir);
    Serial.println(bitDuty);
    Serial.println((numDir=='f'));
    Serial.println((numDir=='f')*bitDuty);*/

}

void stopMotors(int motorL[], int motorR[]){
    analogWrite(motorL[0],0);
    analogWrite(motorR[0],0);
    analogWrite(motorL[1],0);
    analogWrite(motorR[1],0);
	motorL[4] = 0;
}

void moveForward(int duty, int motorL[],int motorR[]){  
	moveMotor(motorL,'f',duty);
    moveMotor(motorR,'f',duty);
	return;
}

void turnLeft(int duty, int motorL[],int motorR[]){  //diff should be <1 and determines the ratio of motor speeds
			moveMotor(motorL,'r',duty);
			moveMotor(motorR,'f',duty);
			return;
}

void turnRight(int duty, int motorL[],int motorR[]){  //diff should be <1 and determines the ratio of motor speeds
			moveMotor(motorL,'f',duty);
			moveMotor(motorR,'r',duty);
			return;
}

void diffLeft(int duty,int diff, int motorL[], int motorR[]){
			moveMotor(motorL,'f',1/diff*duty);
			moveMotor(motorR,'f',duty);
			return;
}

void diffRight(int duty,int diff, int motorL[], int motorR[]){
			moveMotor(motorL,'f',duty);
			moveMotor(motorR,'f',1/diff*duty);
			return;
}

void updateMotorSpeeds(int motorL[], int motorR[], NewPing L, NewPing R){
// void updateMotorSpeeds(int motorL[], int motorR[]){
    int scale = 1;

    if ((L.ping_cm() - R.ping_cm()) > 1) {
      // if the left side is further from the wall than the right side with a buffer of 1cm,
      //then increase the the right motor speed and decrease the left motor.
        motorL[3] = motorL[3]-scale;
        motorR[3] = motorR[3]+scale;
    } else if (int(R.ping_cm()) - int(L.ping_cm()) > 1) {
        motorL[3] = motorL[3]+scale;
        motorR[3] = motorR[3]-scale;

    }
    moveForward( 100, motorL,motorR);
    return;
    
}