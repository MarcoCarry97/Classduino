#include"BasicComponent.h"

using namespace components;

BasicComponent::BasicComponent()
{

}

BasicComponent::BasicComponent(int pin)
{
    this->pin=pin;
}

int BasicComponent::getPin()
{
    return pin;
}

void BasicComponent::setPin(int pin)
{
    this->pin=pin;
}