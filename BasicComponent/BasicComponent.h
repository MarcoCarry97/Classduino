#pragma once
#ifndef BasicComponent

namespace components
{
    class BasicComponent
{
    protected:
        int pin;

    public:
        BasicComponent();
        BasicComponent(int pin);
        int getPin();
        void setPin(int pin);
        void updateState();
};
}

#endif