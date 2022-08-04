#ifndef Sensor
#pragma once
#include<Arduino.h>
#include"../BasicComponent/BasicComponent.h"

namespace components
{
    class Sensor : public BasicComponent
    {
        private:
            float value;

        public:
            Sensor();
            Sensor(int pin);
            float getValue();
            void updateState();
    };
};

#endif