#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <typeinfo>
//#define _USE_MATH_DEFINES

using namespace std;

class Teleso{
protected:
    float vyska;
public:
    Teleso(float v): vyska(v) { }
    virtual float objem() = 0;
};

class Kvadr: public Teleso {
protected:
    float a, b;
public:
    Kvadr(float a, float b, float c): a(a), b(b), Teleso(c) {}
    float objem() {return a * b * vyska;}
};

class TelesoObsahPodstavy: public Teleso{
protected:
    float r;
public:
    TelesoObsahPodstavy(float p, float v): r(p), Teleso(v) {}
    float obsah() {return M_PI * r * r;}
};

class Valec: public TelesoObsahPodstavy {
public:
    Valec(float p, float v): TelesoObsahPodstavy(p, v) {}
    float objem() { return obsah() * vyska; };
};

class Kuzel: public TelesoObsahPodstavy {
public:
    Kuzel(float p, float v): TelesoObsahPodstavy(p, v) {}
    float objem() { return (obsah() * vyska) / 3; }
};

int main()
{
    Teleso *t[3] = {new Kvadr (5, 4, 7), new Valec (5, 4), new Kuzel(5, 4)};
    for (int i=0; i<3; ++i) cout << typeid(*t[i]).name() << "  " << t[i]->objem()<< "\n";
    return 0;
}
