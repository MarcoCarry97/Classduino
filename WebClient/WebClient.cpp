#include "WebClient.h"

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

byte* read()
{
    int len=80;
    byte buffer[len];
    client.read(buffer,len);
    return buffer;
}

void WebClient::write(byte *buffer,int len)
{
    client.write(buffen,len);
}

void WebClient::stop()
{
    client.stop();
}
