#include"ArduinoComponent.h"

using namespace arduino

ArduinoComponent::ArduinoComponent(int pin)
{
    this->pin=pin
};

int ArduinoComponent::getPin()
{
    return pin;
}

void ArduinoComponent::setPin(int pin)
{
    this->pin=pin;
}