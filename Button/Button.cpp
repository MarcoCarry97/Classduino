#include"Button.h"

using namespace components;

Button::Button(int pin, bool enableAbilitation=false) : ArduinoComponent(pin)
{
    this->enableAbilitation=enableAbilitation;
    currentState=false;
    oldState=false;
    pinMode(pin,OUTPUT);
}

bool Button::isAbilitationEnabled()
{
    return enableAbilitation;
}

void Button::updateState()
{
    //read current state here
    currentState=digitalRead(pin);
    if(this->isAbilitationEnabled())
    {
        if(!currentState && oldState)
            abilitation=1-abilitation
        oldState=currentState;
        if(abilitation==1)
            onClick();
    }
    else if(currentState)
        onClick();
}