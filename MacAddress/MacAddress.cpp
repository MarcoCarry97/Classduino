#include"MacAddress.h"

using namespace internet;

MacAddress::MacAddress()
{
    first=second=third=fouth=fifth=sixth=0;
}

MacAddress::MacAddress(int first,int second,int third,int fourth,int fifth,int sixth)
{
    this->first=first;
    this->second=second;
    this->third=third;
    this->fourth=fourth;
    this->fifth=fifth;
    this->sixth=sixth;
}

byte* MacAddress::toBytes()
{
    return {first,second,third,fourth,fifth,sixth};
}