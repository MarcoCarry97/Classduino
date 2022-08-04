#pragma once
#ifndef Button

#include<Arduino.h>
#include"../BasicComponent/BasicComponent.h"

namespace components
{
    class Button : public BasicComponent
    {
        private:
            bool enableAbilitation;
            int abilitation;
            bool currentState;
            bool oldState;

        public:
            Button();
            Button(int pin,bool enableAbilitation);
            bool isAbilitationEnabled();
            bool getCurrentState();
            bool getAbilitation();
            void updateState();
    };
}


#endif