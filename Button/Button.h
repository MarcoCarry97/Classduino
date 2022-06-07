#ifndef Button

#include"ArduinoComponent.h"
#include"OnClick.h"

namespace components
{
    class Button : ArduinoComponent,OnClick
    {
        private:
            bool enableAbilitation;
            int abilitation;

        public:
            Button(int pin,bool enableAbilitation);
            bool isAbilitationEnabled();
    }
}


#endif