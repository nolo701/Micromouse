#ifndef NEWPING_H
#include "NewPing.h"
#endif

#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor
{
private:
    int maxSensorCM;
    int triggerPin;
    int echoPin;
    int powerPin;
    int distance;
    NewPing Pingable;

public:
    UltrasonicSensor();
    UltrasonicSensor(int trigger, int echo, int power);
    int getTriggerPin();
    int getEchoPin();
    int getPowerPin();
    float getDistance();
    void setDistance(float input);
    NewPing getPingable();
    void updateSensor(); // update an ultrasonic
    bool validateReading(); // use the current distance value and check within 2cm-6cm
    
};

#endif