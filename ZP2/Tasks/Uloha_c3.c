//
//  Ukola_c3.c
//  Viet_TH_UPOL
//
//  Created by Viet Tran Hoang on 01.03.16.
//  Copyright © 2016 Viet Tran Hoang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int carky = 0;

char **rozdel (char *data, char oddelovac)
{
    char temp[20];
    //int carky;
    int i = 0;
    while (data[i] != '\0'){
        if (data[i] == oddelovac){
            carky += 1;
        }
        i++;
    }
    carky +=1;
    int delka = i;
    char **vysledne;
    vysledne = (char **)malloc(carky * sizeof(char *));
    
    int j=0, k=0;
    for (i=0; i<=delka; i++){
        if (data[i] == oddelovac || i == delka){
            temp[k] = '\0';
            vysledne[j]= (char *)malloc((k+1) * sizeof(char));
            strcpy(vysledne[j], temp);
            j++;
            k=0;
            continue;
        }
        temp[k] = data[i];
        k++;
    }
    
    return vysledne;
}

int main()
{
    char *string = "maslo,mleko,vejce,mouka,rohliky";
    char **vyslednepole;
    //int carky = 5;
    vyslednepole = rozdel (string, ',');
    
    printf ("Vysledne pole je:\n");
    int i;
    for (i=0; i<carky; i++){
        printf ("%s\n", vyslednepole[i]);
    }
    return 0;
    
}