#include"PlusUtils.h"
#include<vector>
#include<string>
#include<regex>

vector<string> split()
{
    vector<string> elems;
    sregex_token_iterator regexIter(s.begin(),s.end(),re,-1);
    sregex_token_iterator regexEnd;
    while(regexIter!=regexEnd)
    {
        if(regexIter->length())
            elems.push_back(*iter);
        ++iter;
    }
    return elems;
}