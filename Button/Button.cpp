#include"Button.h"

using namespace components;

Button::Button(int pin, bool enableAbilitation=false) : ArduinoComponent(pin)
{
    this->enableAbilitation=enableAbilitation;
    currentState=false;
    oldState=false;
    //pinMode
}

bool Button::isAbilitationEnabled()
{
    return enableAbilitation;
}

void Button::updateState()
{
    //read current state here
    if(this->isAbilitationEnabled())
    {
        if(!currentState && oldState)
            abilitation=1-abilitation
        if(abilitation==1)
            onClick();
    }
    else if(currentState)
        onClick();
}