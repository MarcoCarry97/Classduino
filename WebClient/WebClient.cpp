#include "WebClient.h"
#include "PlusUtils/PlusUtils.h"
#include "HttpClient.h"
#include<string>
#include<map>
#include<regex>



using namespace internet;

WebClient::WebClient()
{
    mac=MacAddress();
    ip=IpAddress();
    dns=IpAddress();
    client=EthernetClient();
    http=HttpClient(client);
}

WebClient(MacAddress mac,IpAddress dns) : WebClient()
{
    this->mac=mac;
    this->dns=dns;
    if(isDhcpAbilitated()
    && isShieldConnected()
    && isCableConnected())
        ip=Ethernet.localIP();
    else
    {
        throw exception();
    }
}

bool WebClient::isDhcpAbilitated()
{
    return Ethernet.begin(mac)!=0;
}

bool WebClient::isCableConnected()
{
    return Ethernet.linkStatus!=LinkOFF;
}

bool WebClient::isShieldConnected()
{
    return Ethernet.hardwareStatus()!=EthernetNoHardware;
}

bool WebClient::isConnected()
{
    return client.connected();
}

bool WebClient::isAvailable()
{
    return client.available();
}

int WebClient::connect(IpAddress destIp,int destPort)
{
    return client.connect(destIp,destPort);
}

IpAddress WebClient::getRemoteIp()
{
    return client.getRemoteIP();
}

char read()
{
    return client.read();
}

void WebClient::write(byte *buffer,int len)
{
    client.write(buffen,len);
}

void WebClient::stop()
{
    client.stop();
}

string WebClient::create(string url,map<string,void*> params)
{
    if(isConnected())
    {
        bool first=true;
        String path=url;
        String data="";
        for(auto iter=params.begin();iter!params.end();iter++)
        {
            if(first)
            {
                data+=iter.first()+"="+iter.second();
            }
            else data+="&"+iter.first()+"="+iter.second();
            http.begin(path);
            http.addHeader("Content-Type","application/x-www-form-urlencoded");
            int responseCode=http.POST(data);
            if(responseCode>0)
            {
                return http.getString();
            }
            else return "Error "+responseCode;
        }
    }
    else return "Not connected";
}

string WebClient::read(string url,map<string, void*> params)
{
    if(isConnected())
    {
        bool first=true;
        String path=url;
        for(auto iter=params.begin();iter!params.end();iter++)
        {
            if(first)
            {
                path+="?"+iter.first()+"="+iter.second();
            }
            else path+="&"+iter.first()+"="+iter.second();
            http.begin(path);
            int responseCode=http.GET();
            if(responseCode>0)
            {
                return http.getString();
            }
            else return "Error "+responseCode;
        }
    }
    else return "Not connected";
}

string WebClient::update(string url,map<string, void*> params)
{
    if(isConnected())
    {
        bool first=true;
        String path=url;
        String data="";
        for(auto iter=params.begin();iter!params.end();iter++)
        {
            if(first)
            {
                path+=iter.first()+"="+iter.second();
            }
            else path+="&"+iter.first()+"="+iter.second();
            http.begin(path);
            http.addHeader("Content-Type","application/x-www-form-urlencoded");
            int responseCode=http.PUT(data);
            if(responseCode>0)
            {
                return http.getString();
            }
            else return "Error "+responseCode;
        }
    }
    else return "Not connected";
}

string WebClient::delete(string url,map<string, void*> params)
{
    if(isConnected())
    {
        bool first=true;
        String path=url;
        for(auto iter=params.begin();iter!params.end();iter++)
        {
            if(first)
            {
                path+="?"+iter.first()+"="+iter.second();
            }
            else path+="&"+iter.first()+"="+iter.second();
            http.begin(path);
            int responseCode=http.DELETE();
            if(responseCode>0)
            {
                return http.getString();
            }
            else return "Error "+responseCode;
        }
    }
    else return "Not connected";
}
