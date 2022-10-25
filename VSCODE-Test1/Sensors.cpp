#include "Sensors.h"
// Functional Constructor
Sensors::Sensors()
{
}
Sensors::Sensors(UltrasonicSensor inL, UltrasonicSensor inF, UltrasonicSensor inR, int inFrontProx)
{
    this->L = inL;
    this->F = inF;
    this->R = inR;
    this->ProxPinF = inFrontProx;
}

void Sensors::updateProxF(){
     this->ProxF = digitalRead(ProxPinF);
}

void Sensors::updateAll()
{
    L.updateSensor();
    F.updateSensor();
    R.updateSensor();
    this->ProxF = digitalRead(ProxPinF);

}
// Getters and Setters
float Sensors::getDistanceL()
{
    return L.getDistance();
}

float Sensors::getDistanceF()
{
    return F.getDistance();
}

float Sensors::getDistanceR()
{
    return R.getDistance();
}

int Sensors::getProxF(){
    return ProxF;
}

UltrasonicSensor *Sensors::getUltrasonicL()
{
    return &L;
}

UltrasonicSensor *Sensors::getUltrasonicF()
{
    return &F;
}

UltrasonicSensor *Sensors::getUltrasonicR()
{
    return &R;
}
