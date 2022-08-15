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

string WebClient::create(string host,int port,string path,map<string,void*> params)
{
    string method="POST";
    bool first=true;
    String data="";
    for(auto iter=params.begin();iter!params.end();iter++)
    {
        if(first)
        {
            data+=iter.first()+"="+iter.second();
            first=false;
        }
        else data+="&"+iter.first()+"="+iter.second();
    }
    client.println(method+" "+path" HTTP/1.1");
    client.println("Host: "+host);
    client.println("Connection: close");
    client.println();
    client.println(data);
    string response="";
    while (isConnected())
    {
        if(isAvailable())
        {
            response+=client.read();
        }
    }
    return response;
}

string WebClient::read(string url,map<string, void*> params)
{
    string method="GET";
    bool first=true;
    String data="";
    for(auto iter=params.begin();iter!params.end();iter++)
    {
        if(first)
        {
            data+=iter.first()+"="+iter.second();
            first=false;
        }
        else data+="&"+iter.first()+"="+iter.second();
    }
    client.println(method+" "+path" HTTP/1.1");
    client.println("Host: "+host);
    client.println("Connection: close");
    client.println();
    string response="";
    while (isConnected())
    {
        if(isAvailable())
        {
            response+=client.read();
        }
    }
    return response;
}

string WebClient::update(string url,map<string, void*> params)
{
    string method="PUT";
    bool first=true;
    String data="";
    for(auto iter=params.begin();iter!params.end();iter++)
    {
        if(first)
        {
            data+=iter.first()+"="+iter.second();
            first=false;
        }
        else data+="&"+iter.first()+"="+iter.second();
    }
    client.println(method+" "+path" HTTP/1.1");
    client.println("Host: "+host);
    client.println("Connection: close");
    client.println();
    client.println(data);
    string response="";
    while (isConnected())
    {
        if(isAvailable())
        {
            response+=client.read();
        }
    }
    return response;
}

string WebClient::cancel(string url,map<string, void*> params)
{
    string method="DELETE";
    bool first=true;
    String data="";
    for(auto iter=params.begin();iter!params.end();iter++)
    {
        if(first)
        {
            data+="?"+iter.first()+"="+iter.second();
            first=false;
        }
        else data+="&"+iter.first()+"="+iter.second();
    }
    client.println(method+" "+path+data" HTTP/1.1");
    client.println("Host: "+host);
    client.println("Connection: close");
    client.println();
    string response="";
    while (isConnected())
    {
        if(isAvailable())
        {
            response+=client.read();
        }
    }
    return response;
}
