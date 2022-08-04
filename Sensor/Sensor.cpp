
#include<Arduino.h>
#include"Sensor.h"
#include"../BasicComponent/BasicComponent.h"

using namespace components;

Sensor::Sensor()
{

}

Sensor::Sensor(int pin): BasicComponent(pin)
{
    value=0;
    pinMode(pin,INPUT);
}

float Sensor::getValue()
{
    return value;
}

void Sensor::updateState()
{
    value=analogRead(pin);
}