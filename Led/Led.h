#ifndef Led
#include"ArduinoComponent.h"

namespace components
{
    class Led : ArduinoComponent
    {
        private:
            int intensity;

        public:
            Led(int pin);
            int getIntensity();
            void turnOn(int intensity);
            void turnOff();

    }
}

#endif