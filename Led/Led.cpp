#include<Arduino.h>
#include"Led.h"
#include"../BasicComponent/BasicComponent.h"

using namespace components;

Led::Led()
{
    
}

Led::Led(int pin) : BasicComponent(pin)
{
    intensity=0;
}

int Led::getIntensity()
{
    return intensity;
}

void Led::turnOn(int intensity)
{
    this->intensity=intensity;
}

void Led::turnOff()
{
    intensity=0;
}

void Led::updateState()
{
    digitalWrite(pin,intensity);
}