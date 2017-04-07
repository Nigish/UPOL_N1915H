/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void soucet(const char* vstup, const char* vystup) {
    char znak;
    float radek, cislo, suma = 0;
    
    FILE* text_in = fopen(vstup, "r");
    FILE* text_out = fopen(vystup, "w");
    
    
    while (znak != EOF) {
        radek = 0;
        
        while ((znak != EOF) && (znak != '\n')) {
            
            fscanf(text_in, "%f", &cislo);
            radek += cislo;
            znak = fgetc(text_in);
        }
        if (znak == '\n') {
            znak = fgetc(text_in);
            
            if ((znak >= '0') && (znak <= '9'))
                ungetc(znak, text_in);
        }
        suma+=radek;
        printf("%0.4f\n", radek);
        fprintf(text_out, "%.4f\n", radek);
    }
    printf("%0.4f\n", suma);
    fprintf(text_out, "%.4f\n", suma);
    fclose(text_in);
    fclose(text_out);
}

int main ()
{
    soucet("Uloha_c9.txt", "V_1.txt");
    
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

FILE *vstup,*vystup; //pointer

int main(int argc, char **argv)
{
    char soubor[256];
    char znak;
    float cislo;
    float radek;
    float suma = 0;
    
    if(argc>1){
        vstup = fopen(argv[1], "r");
        if (vstup == NULL){
            printf("\nVstupni soubor nelze otevrit\n");
            return 1;
        }
    }
    else{
        printf("Zadejte nazev vstupniho souboru: ");
        gets(soubor);
        vstup = fopen(soubor, "r");
        if(vstup == NULL){
            printf ("\nVstupni soubor nelze otevrit\n");
            return 1;
        }
    }
    if(argc>2){
        vystup = fopen(argv[2], "w");
        if (vystup == NULL){
            printf("\nVystupni soubor nelze otevrit\n");
            return 1;
        }
    }
    
    else{
        printf("Zadejte nazev vystupniho souboru: ");
        gets(soubor);
        vystup = fopen(soubor, "w");
        if(vystup == NULL){
            printf ("\nVystupni soubor nelze otevrit\n");
            return 1;
        }
    }
    while (znak != EOF) {
        radek = 0;
        
        while ((znak != EOF) && (znak != '\n')) {
            
            fscanf(vstup, "%f", &cislo);
            radek = radek + cislo;
            znak = fgetc(vstup);
        }
        if (znak == '\n') {
            znak = fgetc(vstup);
            
            if ((znak >= '0') && (znak <= '9'))
                ungetc(znak, vstup);
        }
        suma = suma + radek;
        printf("%0.4f\n", radek);
        fprintf(vystup, "%.4f\n", radek);
        
    }
    printf("%0.4f\n", suma);
    fprintf(vystup,"%0.4f\n", suma);
    fclose(vstup);
    fclose(vystup);
    return 0;
}
