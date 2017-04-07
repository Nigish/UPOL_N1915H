#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vypocet_c8.h"

#define PI  3.14159265359

static double s_podstavy(int typ, double hrana);
static double s_valec(double a);
static double s_3boky(double a);
static double s_4boky(double a);
static double s_6boky(double a);
static double o_kruh(double a);
static double o_hrana(double a, int stran);

static double s_podstavy(int typ, double hrana){
    switch (typ){
        case 0:
            return s_valec(hrana);
        case 3:
            return s_3boky(hrana);
        case 4:
            return s_4boky(hrana);
        case 6:
            return s_6boky(hrana);
        default:
            return -1;
    }
}

double objem(int typ, double hrana, double vyska){
    double S_podst = s_podstavy(typ, hrana);
    
    return vyska * S_podst;
}
double povrch(int typ, double hrana, double vyska){
    double o_podstavy;
    double S_podst;
    
    if (typ==0) o_podstavy = o_kruh(hrana); //pro valec
    else o_podstavy = o_hrana(hrana, typ);
    S_podst = s_podstavy(typ, hrana);
    
    return 2 * S_podst + vyska * o_podstavy;
}
static double s_valec(double r){
    return PI * r * r;
}
static double s_3boky(double a){ 
    double s = (3*a)/2;
    return sqrt(s*(s-a)*(s-a)*(s-a));
}
static double s_4boky(double a){
    return a * a;
}
static double s_6boky(double a){
    return 6 * s_3boky(a);
}
static double o_kruh(double r){
    return 2 * PI * r;
}
static double o_hrana(double a, int stran){
    return stran * a;
}
