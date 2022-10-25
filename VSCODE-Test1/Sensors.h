#ifndef ULTRASONICSENSOR_H
#include "UltrasonicSensor.h"
#endif

#ifndef SENSORS_H
#define SENSORS_H

class Sensors
{
private:
    // For now there are 3 ultrasonic sensors, later this can be changed to work
    // with the i2c IR sensors. This header can include the back end communication
    // to have just read commands.
    UltrasonicSensor L;
    UltrasonicSensor F;
    UltrasonicSensor R;
    int ProxPinF;
    int ProxF = 0;

public:
    // Functional Constructor
    Sensors();
    Sensors(UltrasonicSensor inL, UltrasonicSensor inF, UltrasonicSensor inR, int inFrontProx);
    void updateSensor(int inputPin); // Read a digital pin
    void updateProxF();
    float getDistanceL();
    float getDistanceF();
    float getDistanceR();
    int getProxF();
    UltrasonicSensor* getUltrasonicL();
    UltrasonicSensor* getUltrasonicF();
    UltrasonicSensor* getUltrasonicR();
    void setDistanceL(float);
    void setDistanceF(float);
    void setDistanceR(float);
    void updateAll();
};

#endif