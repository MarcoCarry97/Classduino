#include"Led.h"

Led::Led(int pin) : ArduinoObject(pin)
{};

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