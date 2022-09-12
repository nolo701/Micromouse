
// A motor should look like:

// int motor[] = {MotorCh1, MotorCh2, MotorEN, Ticks,   Vco }
//                motor[0]  motor[1]  motor[2] motor[3] motor[4]


void moveMotor(int motor[], char dir, int duty){
    digitalWrite(motor[2],HIGH);
    int numDir = dir;   
    int bitDuty = 255*duty/100;
    //This will turn on the corresponding motor depending on direction
    analogWrite(motor[0],(numDir=='f')*bitDuty);
    analogWrite(motor[1],(numDir=='r')*bitDuty);
    Serial.println(numDir);
    Serial.println(bitDuty);
    Serial.println((numDir=='f'));
    Serial.println((numDir=='f')*bitDuty);

}

void stopMotors(int motorL[], int motorR[]){
    digitalWrite(motorL[2],LOW);
    digitalWrite(motorR[2],LOW);
}

void moveForward(int duty, int motorL[],int motorR[]){  
	moveMotor(motorL,'f',duty);
    moveMotor(motorR,'f',duty);
	return;
}

void turnLeft(int duty,int diff, int motorL[],int motorR[]){  //diff should be <1 and determines the ratio of motor speeds
			moveMotor(motorL,'f',diff*duty);
			moveMotor(motorR,'f',duty);
			return;
}

void turnRight(int duty,int diff, int motorL[],int motorR[]){  //diff should be <1 and determines the ratio of motor speeds
			moveMotor(motorL,'f',duty);
			moveMotor(motorR,'f',diff*duty);
			return;
}

