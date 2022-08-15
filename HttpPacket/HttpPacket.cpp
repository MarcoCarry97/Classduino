#include<HttpPacket.h>
#include<string>
#include<map>

using namespace internet;

HttpPacket::HttpPacket(string method,string host,string path,map<string,string> headers, map<string,string> body)
{
    this->method=method;
    this->host=host;
    this->path=path;
    this->headers=headers;
    this->body=body;
}

HttpPacket.Builder HttpPacket::builder()
{
    return new HttpPacket.Builder();
}

string HttpPacket::getMethod()
{
    return method;
}

string HttpPacket::getHost()
{
    return host;
}

map<string,string> HttpPacket::getBody()
{
    return body;
}

map<string,string> HttpPacket::getHeaders()
{
    return headers;
}

string HttpPacket::getPath()
{
    return path;
}

HttpPacket::Builder()
{
    method=path=host="";
    headers=body=map<string,string>();
}

void HttpPacket::Builder::setMethod(string method)
{
    this->method=method;
}

void HttpPacket::Builder::setHost(string host)
{
    this->host=host;
}

void HttpPacket::Builder::setPath(string path)
{
    this->path=path;
}

void HttpPacket::Builder::addHeader(string key,string value)
{
    this->headers[key]=value;
}

void HttpPacket::Builder::addParameter(string key,void* value)
{
    this->body[key]=value;
}