#pragma once

#ifndef MacAddress

namespace internet
{
    class MacAddress
    {
        private:
            int first;
            int second;
            int third;
            int fourth;
            int fifth;
            int sixth;

        public:
            MacAddress();
            MacAddress(int first,int second,int third,int fourth,int fifth,int sixth);
            byte* toBytes();

    };
};

#endif