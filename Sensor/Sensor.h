#ifndef Sensor

#include"ArduinoComponent.h"

namespace components
{
    virtual class Sensor : public ArduinoComponent
    {
        private:
            float value;

        public:
            Sensor(int pin);
            float getValue();
    }
}