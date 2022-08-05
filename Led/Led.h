#pragma once
#ifndef Led
#include"../BasicComponent/BasicComponent.h"

namespace components
{
    class Led : public BasicComponent
    {
        private:
            int intensity;

        public:
            Led();
            Led(int pin);
            int getIntensity();
            void turnOn(int intensity);
            void turnOff();
            void updateState();

    };
}

#endif