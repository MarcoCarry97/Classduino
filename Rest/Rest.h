#include<string>
#include<map>

#pragma once

#ifndef Rest

class Rest
{
    public:
        static bool create(string url, map<string,void*> params);
        static string read(string url);
        static bool update(string url, map<string,void* params);
        static bool cancel(string url);
}

#endif