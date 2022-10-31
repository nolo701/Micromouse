#include <Arduino.h>
#include "Position.h"
#include "Motor.h"
#include "NewPing.h"
#include "Move.h"
#include "UltrasonicSensor.h"
#include "Sensors.h"
#include "MM.h"

bool LED = false;

static int MotorRCh1 = 6;
static int MotorRCh2 = 5;
static int EncodeR = 2;

static int MotorLCh1 = 9;
static int MotorLCh2 = 10;
static int EncodeL = 3;

static int DistLEcho = 13; // Distance Sensor
static int DistFEcho = 8;  // Distance Sensor
static int DistREcho = 12; // Distance Sensor

int FrontProxPin = 11;

static int DistLTrig = A2;
static int DistFTrig = A4;
static int DistRTrig = A3;

static int DistLPower = A5;
static int DistFPower = A0;
static int DistRPower = A1;

// Default Velocity Coefficients
static int DefaultVCOL = 97;
static int DefaultVCOR = 100;

// ORIGINAL

/*
Motor Left = Motor(MotorLCh1, MotorLCh2, 0, DefaultVCOL, false);
Motor Right = Motor(MotorRCh1, MotorRCh2, 0, DefaultVCOR, false);

// Create the Move class
Move MoveSpeedyLuis = Move(Left, Right);
// Create the NewPings
UltrasonicSensor UltrasonicLeft = UltrasonicSensor(DistLTrig, DistLEcho, DistLPower);
UltrasonicSensor UltrasonicForward = UltrasonicSensor(DistFTrig, DistFEcho, DistFPower);
UltrasonicSensor UltrasonicRight = UltrasonicSensor(DistRTrig, DistREcho, DistRPower);
// Create the sensors class
Sensors SensorsSpeedyLuis = Sensors(UltrasonicLeft, UltrasonicForward, UltrasonicRight, FrontProxPin);
// Create the Mouse
MM SpeedyLuis = MM(MoveSpeedyLuis, SensorsSpeedyLuis);
// Test create a position
// Position Test1 = Position(5,5);

*/
// Create the Mouse
MM SpeedyLuis = MM(Move(Motor(MotorLCh1, MotorLCh2, 0, DefaultVCOL, false),
                        Motor(MotorRCh1, MotorRCh2, 0, DefaultVCOR, false)),
                   Sensors(UltrasonicSensor(DistLTrig, DistLEcho, DistLPower),
                           UltrasonicSensor(DistFTrig, DistFEcho, DistFPower),
                           UltrasonicSensor(DistRTrig, DistREcho, DistRPower),
                           FrontProxPin));

void setup()
{
    pinMode(MotorRCh1, OUTPUT);
    pinMode(MotorRCh2, OUTPUT);
    pinMode(EncodeR, INPUT);
    pinMode(MotorLCh1, OUTPUT);
    pinMode(MotorLCh2, OUTPUT);
    pinMode(EncodeL, INPUT);
    pinMode(DistLEcho, INPUT);
    pinMode(DistLTrig, OUTPUT);
    pinMode(DistLPower, OUTPUT);
    pinMode(DistFEcho, INPUT);
    pinMode(DistFTrig, OUTPUT);
    pinMode(DistFPower, OUTPUT);
    pinMode(DistREcho, INPUT);
    pinMode(DistRTrig, OUTPUT);
    pinMode(DistRPower, OUTPUT);
    // pinMode(13, OUTPUT);
    digitalWrite(DistLPower, HIGH);
    digitalWrite(DistFPower, HIGH);
    digitalWrite(DistRPower, HIGH);

    // Attach the interrupts
    attachInterrupt(digitalPinToInterrupt(EncodeL), INC_ENCODE_L, CHANGE);
    attachInterrupt(digitalPinToInterrupt(EncodeR), INC_ENCODE_R, CHANGE);

    //Serial.begin(115200);

    // Wait for 3s
    delay(3000);

    // Diagnostic LED
    pinMode(4, OUTPUT);
}

void loop()
{

    // Try to get more accuracy out of NewPing or Ultrasonic Sensors
    digitalWrite(4, !LED);
    LED = !LED;
    SpeedyLuis.Movement.moveStraight4(SpeedyLuis.onboardSensors, 100);
    //SpeedyLuis.onboardSensors.updateAll();
    /* Main Loop before 10/31/22
    Serial.println("Start: ");

    // read the front prox value
    SpeedyLuis.onboardSensors.updateProxF();
    if (SpeedyLuis.onboardSensors.getProxF() == 1)
    {
        Serial.println("We can move forward!");
    }
    else if (SpeedyLuis.onboardSensors.getProxF() == 0)
    {
        Serial.println("We CAN'T move forward!");
    }
    // While it is possible to go straight, continue and try and straighten
    while (SpeedyLuis.onboardSensors.getProxF() == 1)
    {
        // TestSensors();
        digitalWrite(4, !LED);
        LED = !LED;
        SpeedyLuis.Movement.moveStraight4(SpeedyLuis.onboardSensors, 100);
        SpeedyLuis.onboardSensors.updateProxF();
    }
    SpeedyLuis.Movement.stopMotors();
    Serial.println("End: ");
    delay(5000);

    */

    // TestSensors();
    // SpeedyLuis.Movement.moveStraight2(SpeedyLuis.onboardSensors, 50);
    /*
    Serial.print("Left Motor: ");
    Serial.println(SpeedyLuis.Movement.L.getVelocityCoefficient());
    Serial.print("Right Motor: ");
    Serial.println(SpeedyLuis.Movement.R.getVelocityCoefficient());
    */
    // delay(10);

    /*
    SpeedyLuis.Movement.moveForward(100);
    delay(500);
    SpeedyLuis.Movement.stopMotors();
    Serial.print("Encoder Val L: ");
    Serial.println(SpeedyLuis.Movement.L.getEncoderTicks());
    Serial.print("Encoder Val R: ");
    Serial.println(SpeedyLuis.Movement.R.getEncoderTicks());
    delay(1000);
    // read the front prox value
    SpeedyLuis.onboardSensors.updateProxF();
}
SpeedyLuis.Movement.stopMotors();
Serial.println("End: ");
delay(5000);

*/

    // Make a turn if possible

    /*


    // Get the current ones
    Left.setVelocityCoefficient(100);
    Right.setVelocityCoefficient(100);
    Serial.println("Before: ");
    Serial.print("Left Motor: ");
    Serial.println(Left.getVelocityCoefficient());
    Serial.print("Right Motor: ");
    Serial.println(Right.getVelocityCoefficient());
    delay(1000);
    Left.setVelocityCoefficient(50);
    Right.setVelocityCoefficient(50);
    Serial.println("After: ");
    Serial.print("Left Motor: ");
    Serial.println(Left.getVelocityCoefficient());
    Serial.print("Right Motor: ");
    Serial.println(Right.getVelocityCoefficient());
    delay(1000);

    // Try again
    SpeedyLuis.Movement.refMotorR()->setVelocityCoefficient(100);
    SpeedyLuis.Movement.refMotorL()->setVelocityCoefficient(100);
    Serial.println("Before: ");
    Serial.print("Left Motor: ");
    Serial.println(SpeedyLuis.Movement.refMotorL()->getVelocityCoefficient());
    Serial.print("Right Motor: ");
    Serial.println(SpeedyLuis.Movement.refMotorR()->getVelocityCoefficient());

    // Try again
    SpeedyLuis.Movement.refMotorR()->setVelocityCoefficient(50);
    SpeedyLuis.Movement.refMotorL()->setVelocityCoefficient(50);
    Serial.println("After: ");
    Serial.print("Left Motor: ");
    Serial.println(SpeedyLuis.Movement.refMotorL()->getVelocityCoefficient());
    Serial.print("Right Motor: ");
    Serial.println(SpeedyLuis.Movement.refMotorR()->getVelocityCoefficient());

    // Try again
    SpeedyLuis.Movement.refMotorR()->setVelocityCoefficient(100);
    SpeedyLuis.Movement.refMotorL()->setVelocityCoefficient(100);
    Serial.println("Before: ");
    Serial.print("Left Motor: ");
    Serial.println(SpeedyLuis.Movement.refMotorL()->getVelocityCoefficient());
    Serial.print("Right Motor: ");
    Serial.println(SpeedyLuis.Movement.refMotorR()->getVelocityCoefficient());

    Serial.println("After: ");
    Serial.print("Left Motor: ");
    Serial.println(Left.getVelocityCoefficient());
    Serial.print("Right Motor: ");
    Serial.println(Right.getVelocityCoefficient());

    */
}

// Encoder interrupt routines
void INC_ENCODE_L()
{
    SpeedyLuis.Movement.L.incrementEncoderTicks();
}
void INC_ENCODE_R()
{
    SpeedyLuis.Movement.R.incrementEncoderTicks();
}

// Test Functions

// Test Motors - Move forward and then backwards

// Test Ultrasonic Sensors - Read and print out the sensor values to the serial monitor
void TestSensors()
{

    // Update the values
    SpeedyLuis.onboardSensors.updateAll();
    // Print them out
    Serial.print(" L: ");
    Serial.print(SpeedyLuis.onboardSensors.getDistanceL());
    Serial.print(" F: ");
    Serial.print(SpeedyLuis.onboardSensors.getDistanceF());
    Serial.print(" R: ");
    Serial.print(SpeedyLuis.onboardSensors.getDistanceR());
    Serial.print(" Proximity F: ");
    Serial.println(SpeedyLuis.onboardSensors.getProxF());
}
/*
void TestSensorsFromMouse(){

    // Update the values
    SpeedyLuis.onboardSensors.updateAll();
    // Print them out
    Serial.print(" L: ");
    Serial.print(SpeedyLuis.onboardSensors.getDistanceL());
    Serial.print(" F: ");
    Serial.print(SpeedyLuis.onboardSensors.getDistanceF());
    Serial.print(" R: ");
    Serial.print(SpeedyLuis.onboardSensors.getDistanceR());
    Serial.print(" Proximity F: ");
    Serial.println(SpeedyLuis.onboardSensors.getProxF());

}
*/