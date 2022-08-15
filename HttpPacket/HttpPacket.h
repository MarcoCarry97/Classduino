#pragma once

#include<string>
#include<map>

#ifndef HttpPacket

namespace internet
{
    class HttpPacket
    {
        private:
            class Builder
            {
                private:
                    string method;
                    string host;
                    string path;
                    map<string,string> headers;
                    map<string,string> body;

                public:
                    void setMethod(string method);
                    void setHost(string host);
                    void setPath(string path);
                    void addHeader(string key,string value);
                    void addParameter(string key,void* value);

            };
            string method;
            string host;
            string path;
            map<string,string> headers;
            map<string,string> body;
            HttpPacket();

        public:
            string getMethod();
            string getHost();
            string getPath();
            map<string,string> getHeaders();
            map<string,string> getBody();
            Builder builder();
            string toString();
    };

};

#endif