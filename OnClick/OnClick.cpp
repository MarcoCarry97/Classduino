#include"OnClick.h"

using namespace interfaces;

void OnClick::setOnClickListener([]() onClick)
{
    this->onClick=onClick;
}