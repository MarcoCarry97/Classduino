#pragma once

#include<Arduino.h>
#include<Ethernet.h>
#include<SPI.h>
#include<string>
#include<HttpClient.h>
#include"../MacAddress/MacAddress.h"

#ifndef WebClient

namespace internet
{
    class WebClient
    {
        private:
            MacAddress mac;
            IpAddress ip;
            IpAddress dns;
            EthernetClient client;
            HttpClient http;

        public:
            WebClient();
            WebClient(MacAddress mac,IpAddress dns)
            bool isDhcpAbilitated();
            bool isShieldConnected();
            bool isCableConnected();
            bool isConnected();
            bool isAvailable();
            int connect(IpAddress destIp,int destPort);
            IpAddress getRemoteIp();
            byte *read();
            void write(byte*buffer,int len);
            void stop();
            bool create(string url, map<string,void*> params);
            string read(string url, map<string,void*> params);
            bool update(string url, map<string,void*> params);
            bool cancel(string url, map<string,void*> params);
    };
};

#endif