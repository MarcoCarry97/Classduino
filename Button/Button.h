#ifndef Button

#include"ArduinoComponent.h"
#include"OnClick.h"

using namespace interfaces;

namespace components
{
    class Button : public ArduinoComponent, virtual OnClick
    {
        private:
            bool enableAbilitation;
            int abilitation;
            bool currentState;
            bool oldState;

        public:
            Button(int pin,bool enableAbilitation);
            bool isAbilitationEnabled();
            bool getCurrentState();
    }
}


#endif