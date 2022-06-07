#include"Button.h"

using namespace components;

Button::Button(int pin, bool enableAbilitation=false) : ArduinoComponent(pin)
{
    this->enableAbilitation=enableAbilitation;
}

bool Button::isAbilitationEnabled()
{
    return enableAbilitation;
}