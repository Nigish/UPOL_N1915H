#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

char *spoj(int pocet, ...)
{
    int i, delka = 0;
    char *vysledek, *temp;
    va_list zasobnik;
    
    va_start(zasobnik, pocet);
    for (i = 0; i < pocet; i++)
    {
        delka += strlen(va_arg(zasobnik, char*));
    }
    vysledek = malloc((delka) * sizeof(char));
    va_end(zasobnik);
    
    va_start(zasobnik, pocet);
    for (i = 0; i < pocet; i++) {
        temp  = va_arg(zasobnik, char*);
        {
            vysledek = strcat(vysledek, temp);
        }
    }
    va_end(zasobnik);
    return vysledek;
}

int main()
{
    //char *spojeny = spoj(4, "Ahoj ", "ty ", "muj ", "svete! ");
    char *spojeny = spoj(5, "Jdi ", "do ", "haje ","muj ", "svete!");
    char *spojeny_2 = spoj(5, "5", " + ", "5", " = ", "10");
    printf("%s", spojeny);
    printf("\n");
    printf("%s", spojeny_2);
    printf("\n");
    return 0;
}
