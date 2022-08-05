
#include<Arduino.h>
#include"Sensor.h"
#include"../BasicComponent/BasicComponent.h"

using namespace components;

Sensor::Sensor()
{
    pin=0;
}

Sensor::Sensor(int pin): BasicComponent(pin)
{
    value=0;
    pinMode(pin,INPUT);
}

float Sensor::getValue()
{
    return value;
}

void Sensor::updateState()
{
    value=this->toCelsius();
}

float Sensor::toCelsius()
{
    int vIn=5;
    float absZero=-273.15;
    float K=6;
    int resistor=1000;
    double raw=0;
    for(int i=0;i<3;i++)
        raw+=analogRead(pin);
        delay(10);
    raw/=3;
    double v=raw/1024*vIn;
    double rTh=(resistor*v)/(vIn-v);
    double kelvin=steinhartHart(rTh)-v*v/(k*Rth);
    double celsius=kelvin-absZero;
    return (float) celsius;
}

double Sensor::steinhartHart(double r)
{
    double a=1.189148e-3;
    double b=2.34125e-4;
    double c=8.76741e-8;
    double logr=log(r);
    double logr3=logr*logr*logr;
    return 1.0/(a+b*logr+c*logr3);
}
