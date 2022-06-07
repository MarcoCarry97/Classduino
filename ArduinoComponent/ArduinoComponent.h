#ifndef ArduinoComponent

namespace arduino
{
    class ArduinoComponent
    {
    protected:
        int pin

    public:
        ArduinoComponent(int pin)
        int getPin();
        void setPin(int pin);
    }
}

#endif