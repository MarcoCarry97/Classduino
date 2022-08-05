

#include"Button.h"

using namespace components;

Button::Button()
{

}

Button::Button(int pin, bool enableAbilitation=false) : BasicComponent(pin)
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
        if(currentState==HIGH && oldState==LOW)
            abilitation=1-abilitation;
    }
    oldState=currentState;
}

bool Button::getAbilitation()
{
    if(!isAbilitationEnabled()) return false;
    else return abilitation;
}

