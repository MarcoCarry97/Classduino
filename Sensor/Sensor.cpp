#include<Arduino.h>
#include"Sensor.h"
#include"ArduinoComponent.h"

using namespace components;

Sensor::Sensor(int pin):public ArduinoComponent(pin)
{
    value=0;
    pinMode(pin,INPUT);
}

float Sensor::getValue()
{
    return value;
}

float Sensor::updateState()
{
    value=analogRead(pin);
}