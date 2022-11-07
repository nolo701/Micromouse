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
static int DefaultVCOL = 99;
static int DefaultVCOR = 100;

static bool InterruptFlag = false;

// Create the Mouse
MM SpeedyLuis = MM(Move(Motor(MotorLCh1, MotorLCh2, 0, DefaultVCOL, false),
                        Motor(MotorRCh1, MotorRCh2, 0, DefaultVCOR, false)),
                   Sensors(UltrasonicSensor(DistLTrig, DistLEcho, DistLPower),
                           UltrasonicSensor(DistFTrig, DistFEcho, DistFPower),
                           UltrasonicSensor(DistRTrig, DistREcho, DistRPower),
                           FrontProxPin));

void setup()
{
    PinModes();
    digitalWrite(DistLPower, HIGH);
    digitalWrite(DistFPower, HIGH);
    digitalWrite(DistRPower, HIGH);

    // Attach the interrupts
    attachInterrupt(digitalPinToInterrupt(EncodeL), INC_ENCODE_L, CHANGE);
    attachInterrupt(digitalPinToInterrupt(EncodeR), INC_ENCODE_R, CHANGE);

    Serial.begin(115200);

    // Wait for 3s
    delay(3000);
}

void loop()
{
    // If the encoders have tripped
    while (InterruptFlag)
    {
        // Check if you can move forward
        SpeedyLuis.onboardSensors.getUltrasonicF()->updateSensor();
        if ((SpeedyLuis.onboardSensors.getDistanceF() < 25) && (SpeedyLuis.onboardSensors.getDistanceF() > 0))
        {
            SpeedyLuis.Movement.stopMotors();
            // Make a decision on how to move
            while (1 == 1)
            {
                delay(100);
            }
        }
        InterruptFlag = false;
    }
    // Try to get more accuracy out of NewPing or Ultrasonic Sensors
    SpeedyLuis.Movement.moveStraight5(SpeedyLuis.onboardSensors, 60);
}

// Encoder interrupt routines
void INC_ENCODE_L()
{
    SpeedyLuis.Movement.L.incrementEncoderTicks();
    if ((SpeedyLuis.Movement.L.getEncoderTicks() % 68) == 67)
    {
        digitalWrite(4, !LED);
        LED = !LED;
        InterruptFlag = true;
    }
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

// This function is just to neaten up the flow when reading top down. It cleans up the setup.
void PinModes()
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
    // Diagnostic LED
    pinMode(4, OUTPUT);
    // pinMode(13, OUTPUT);
}
