#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    unsigned int cislo, vstup, prava, leva;
    
    cislo = 1283; // na pevno, moc EASY
    //cislo = rand(); //random cislo je lespi, HARDCORE :D
    prava = 4294967295;
    leva = 0;
    
    while (vstup != cislo) //nebo na zacatku "do" na konci "while"
    {
        printf("Hadej, hadej, hadaci!\n");
        printf("Zleva nejvetsi: %u , zprava nejmensi: %u\n",leva, prava);
        scanf("%d",&vstup);
        if (vstup < cislo) {
            printf("Hledane cislo je vetsi\n");
            if (vstup > leva)
                leva = vstup;
        }
        else {
            if (vstup > cislo) {
                printf("Hledane cislo je mensi\n");
                if (vstup < prava)
                    prava = vstup;
            }
        }
    }
    
    printf("Vyhral!, hledane cislo je %u \n\n",vstup);
    
    //X
    unsigned strana;
    printf("Zadejte stranu ctverce: ");
    scanf("%u", &strana);
    for( int y = 0 ; y < strana; y++ ){
        for( int x = 0 ; x < strana; x++ ){
            if (x == y || x == (strana - 1 - y)) {
                printf("*");
            } else
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
