#include"Led.h"

Led::Led(int pin) : ArduinoObject(pin)
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