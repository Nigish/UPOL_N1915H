/* #include <stdio.h>
//#include <stdlib.h>
#include <string.h>

int pocet_vyskytu(char *kde, char *co){
    int i = 0, j = 0, pocet = 0;
    
    while (kde[i] != '\0') {
        if (kde[i] == co[0]) {
            while (kde [i + j] == co[j]) {
                j++;
                if (co[j] == '\0'){
                    pocet++;
                }
            }
            j=0;
        }
        i++;
    }
    return pocet;
}

int main()
{
    int pocet;
    
    pocet = pocet_vyskytu("aalaalaa", "aalaa");
    printf("Pocet vyskytu \"aalaa\" v \"aalaalaa\" je %i.\n\n", pocet);
    
    return 0;
} */

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

int pocet_vyskytov(char *kde, char *co);

int main()
{
    int pocet;
    
    pocet=pocet_vyskytov("aalaalaa", "aalaa");
    printf("Pocet vyskytu \"aalaa\" v \"aalaalaa\" je %i.\n\n", pocet);
    
    return 0;
}

int pocet_vyskytov(char *kde, char *co)
{
    int pocet=0;
    char *pco = co;
    char *soukde = kde;
    
    while(*kde != '\0'){
        soukde = kde;
        if(*co == *kde){
            while(*co !='\0'){
                if(*co != *kde){
                    break;
                }
                co++;
                kde++;
                if(*co == '\0'){
                    pocet++;
                    break;
                }
            }
        }
        co = pco;
        kde = soukde;
        kde++;
    }
    return pocet;
}
