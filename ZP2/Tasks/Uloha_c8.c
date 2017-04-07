#include <stdio.h>
#include <stdlib.h>
#include "vypocet_c8.h"

#define CHYBA printf("Chyba, nezadali jste hodnotu nebo zadali jste spatne. \n");

int main(int argc, char* argv[])
{
    int typ;
    double hrana;
    double vyska;
    double V, S; //objem a povrch

    if (argc >= 4) {
        typ = atoi(argv[1]);
        vyska = atof(argv[2]);
        hrana = atof(argv[3]);
    }
    else{
        return CHYBA;
    }
    
    V = objem(typ, hrana, vyska);
    S = povrch(typ, hrana, vyska);
    
    switch(typ) {
        case 0:
            printf("\nValec s vyskou %.2f a polomerem podstavy %.2f ma povrch %.3f a objem %.3f.\n\n", vyska, hrana, S, V);
            break;
        case 3:
            printf("\nPravidelny 3-boky hranol s vyskou %.2f a delkou podstavne hrany %.2f ma povrch %.3f a objem %.3f.\n\n",vyska, hrana, S, V);
            break;
        case 4:
            printf("\nPravidelny 4-boky hranol s vyskou %.2f a delkou podstavne hrany %.2f ma povrch %.3f a objem %.3f.\n\n",vyska, hrana, S, V);
            break;
        case 6:
            printf("\nPravidelny 6-boky hranol s vyskou %.2f a delkou podstavne hrany %.2f ma povrch %.3f a objem %.3f.\n\n",vyska, hrana, S, V);
            break;
    }
    //printf("Povrch %.2lf a objem %.2lf", S, V); //zkouska
    return 0;
}

