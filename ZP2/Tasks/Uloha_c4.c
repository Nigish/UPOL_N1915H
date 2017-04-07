#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double **map( double(*fce[])(double), double*vstup, int pocet_fce, int pocet_vstup)
{
    int i, j, temp;
    double **vysledek;
    vysledek = (double **)malloc((pocet_fce) * sizeof(double *));
    if (vysledek == NULL){
        printf("Nemam dostatek pameti, ikdyz mam 16GB RAM! :'(");
        return NULL;
    }
    for (i = 0; i < pocet_fce; i++) {
        vysledek[i] = (double *)malloc(pocet_vstup * sizeof(double));
        if (vysledek[i] == NULL) {
            printf("Nemam dostatek pameti, ikdyz mam 16GB RAM :'(");
            for (temp = 0; temp < i ; temp++) {
                free(vysledek[temp]);
            }
            free(vysledek);
            return NULL;
        }
            for (j = 0; j < pocet_vstup; j++) {
                if (i == 0) {
                    vysledek[i][j] = vstup[j];
                }
                else vysledek[i][j] = fce[i - 1](vstup[j]);
            }
        }
    return vysledek;
}

    double na2
    (double x){
        return x*x;
    }
    double na3
    (double x){
        return x*x*x;
    }
    double na4
    (double x){
        return x*x*x*x;
    }




int main()
{
    int i, j;
    double pole[] = {1, 2, 3, 4, 5};
    double(* pole_fci [])(double) = {na2, na3, na4};
    
    double **konecna;
    konecna = map(pole_fci, pole, 4, 5);
    //double **map(pole_fci, pole, 2, 5);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("%0.f ", konecna[i][j]);
        }
        printf("\n");
    }
    return 0;
}
