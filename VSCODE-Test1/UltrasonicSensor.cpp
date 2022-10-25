#include "UltrasonicSensor.h"


UltrasonicSensor::UltrasonicSensor(){
    
}
// Ultrasonic Sensor Constructor
UltrasonicSensor::UltrasonicSensor(int inTrig, int inEcho, int inPow)
{
    this->maxSensorCM = 500;
    this->Pingable = NewPing(inTrig, inEcho, maxSensorCM);
    this->triggerPin = inTrig;
    this->echoPin = inEcho;
    this->powerPin = inPow;
    this->distance = 99;
}

void UltrasonicSensor::updateSensor()
{
    float temp = Pingable.ping_cm();
    delay(30);
    if (temp == 0 && digitalRead(echoPin) == HIGH)
    {
        digitalWrite(powerPin, LOW);
        delay(50);                    // 50 mS is the minimum Off time to get clean restart
        digitalWrite(powerPin, HIGH); // Adjust this value if your sensors don't read after reset
        delay(60);                    // Some sensors throw out a very short false echo after timeout
        Pingable.ping_cm();           // 5cm-10cm value.  If your sensors do not throw out
                                      // this false echo, you can get rid of this delay and ping after power HIGH
    }
    distance = temp;
}

void UltrasonicSensor::setDistance(float in)
{
    this->distance = in;
}

int UltrasonicSensor::getEchoPin()
{
    return echoPin;
}

int UltrasonicSensor::getTriggerPin()
{
    return triggerPin;
}

int UltrasonicSensor::getPowerPin()
{
    return powerPin;
}

NewPing UltrasonicSensor::getPingable()
{
    return Pingable;
}

float UltrasonicSensor::getDistance()
{
    return distance;
}
