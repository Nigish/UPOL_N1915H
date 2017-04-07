#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

unsigned int BPHash(char* str, unsigned int len)
{
    unsigned int hash = 0;
    unsigned int i    = 0;
    for(i = 0; i < len; str++, i++)
    {
        hash = hash << 7 ^ (*str);
    }
    
    return hash;
}
/* End Of BP Hash Function */

typedef struct PRVEK{
    char *string;
    struct PRVEK *dalsi;
    int size;
} PRVEK;


typedef struct{
    struct PRVEK **prvky;
    int velikost;
} HASH;

HASH *hashtabulka(int velikost)
{
    int i;
    HASH *tabulka;
    tabulka = (HASH*)malloc(sizeof(HASH));
    tabulka->velikost=velikost;
    tabulka->prvky = malloc(velikost*sizeof(PRVEK*));
    for(i=0; i<velikost; i++){
        tabulka->prvky[i] = NULL;
        //tabulka->prvky[i]->size = 1; //novy
    }
    return tabulka;
}

PRVEK *kontrola(HASH *tabulka, char *str, int delka){
    PRVEK *prvek;
    int velikost,pozice;
    velikost=tabulka->velikost;
    pozice = BPHash(str, delka)%velikost;
    for(prvek = tabulka->prvky[pozice];
        prvek != NULL; prvek = prvek->dalsi)
    {
        if ((strcmp(str, prvek->string)) == 0)
        {
            return prvek;
        }
    }
    return NULL;
}

int generujdelku(){
    int delka = rand()%(20+1-5)+5;
    return delka;
}

char* generator(int delka){
    int i;
    char*slovo;
    slovo = malloc(sizeof(char)*delka+1);
    for(i=0; i<delka; i++){
        slovo[i] = rand()%(122+1-97)+97;
    }
    slovo[i]='\0';
    return slovo;
}

int pridat(HASH *tabulka, char *str, int delka){
    PRVEK *novy;
    PRVEK *aktualni;
    int velikost;
    velikost = tabulka->velikost;
    int pozice = BPHash(str, delka)%velikost;
    novy = (PRVEK*)malloc(sizeof(PRVEK));
    aktualni = kontrola(tabulka, str, delka);
    novy->string = strdup(str);
    novy->dalsi = tabulka->prvky[pozice];
    //novy->size = aktualni->size+1; // novy
    tabulka->prvky[pozice] = novy;
    return 0;
}

void naplnit(int pocet, HASH *tabulka, int velikost)
{   int i,delka;
    char *jmeno;
    for (i=0;i<pocet;i++){
        delka = generujdelku();
        jmeno = malloc (delka*(sizeof(char)));
        jmeno = generator(delka);
        while (kontrola(tabulka, jmeno, delka) != NULL) { // novy - block: kontrola
            jmeno = generator(delka); // novy - block; kontrola
        }
        pridat(tabulka,jmeno,delka);
    }
}

int main (){
    
    float pocet_1 = 0, pocet_2 = 0;
    float prum = 0;
    int max = 0, pocet = 0;
    HASH *table = hashtabulka(10007);
    HASH *table1 = hashtabulka(10000);
    printf("######## BPHash ########\n");
    //VYSLEDKY PRO TABULKU S POCTEM PRIHRADEK = 10 007
    
    printf("Tabulka s poctem prihradek = 10007\n");
    printf("%%\t \tPrum. Max.\n");
    printf("-----------------------\n");
    //50%
    naplnit(10007*0.5, table, 10007);
    for (int i = 0; i < 10007; i++) {
        pocet = 0;
        if (table -> prvky[i] != NULL)
        {
            
            PRVEK *tab;
            tab = table->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    
    printf("50%% \t%0.2f\t%d\n", prum, max);
    pocet_1 = pocet_2 = pocet = prum = 0;
    //75%
    naplnit(10007*0.25, table, 10007);
    for (int i = 0; i < 10007; i++) {
        pocet = 0;
        if (table -> prvky[i] != NULL)
        {
            PRVEK *tab;
            tab = table->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    
    printf("75%% \t%0.2f\t%d\n", prum, max);
    pocet_1 = pocet_2 = pocet = prum = 0;
    //100%
    naplnit(10007*0.25, table, 10007);
    for (int i = 0; i < 10007; i++) {
        pocet = 0;
        if (table -> prvky[i] != NULL)
        {
            PRVEK *tab;
            tab = table->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    
    printf("100%% \t%0.2f\t%d\n", prum, max);
    pocet_1 = pocet_2 = pocet = prum = 0;
    //125%
    naplnit(10007*0.25, table, 100007);
    for (int i = 0; i < 10007; i++) {
        pocet = 0;
        if (table -> prvky[i] != NULL)
        {
            PRVEK *tab;
            tab = table->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    
    printf("125%% \t%0.2f\t%d\n", prum, max);
    pocet_1 = pocet_2 = pocet = prum = 0;
    
    ///VYSLEDKY PRO TABULKU S POCTEM PRIHRADEK = 10 000
    
    printf("\nTabulka s poctem prihradek = 10000\n");
    printf("%%\t \tPrum. Max.\n");
    printf("-----------------------\n");
    //50%
    naplnit(10000*0.5, table1, 10000);
    for (int i = 0; i < 10000; i++) {
        pocet = 0;
        if (table1 -> prvky[i] != NULL)
        {
            PRVEK *tab;
            tab = table1->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    
    printf("50%% \t%0.2f\t%d\n", prum, max);
    pocet_1 = pocet_2 = pocet = prum = 0;
    //75%
    naplnit(10000*0.25, table1, 10000);
    for (int i = 0; i < 10000; i++) {
        pocet = 0;
        if (table1 -> prvky[i] != NULL)
        {
            PRVEK *tab;
            tab = table1->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    
    printf("75%% \t%0.2f\t%d\n", prum, max);
    pocet_1 = pocet_2 = pocet = prum = 0;
    //100%
    naplnit(10000*0.25, table1, 10000);
    for (int i = 0; i < 10000; i++) {
        pocet = 0;
        if (table1 -> prvky[i] != NULL)
        {
            PRVEK *tab;
            tab = table1->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    
    printf("100%% \t%0.2f\t%d\n", prum, max);
    pocet_1 = pocet_2 = pocet = prum = 0;
    //125%
    naplnit(10000*0.25, table1, 10000);
    for (int i = 0; i < 10000; i++) {
        pocet = 0;
        if (table1 -> prvky[i] != NULL)
        {
            PRVEK *tab;
            tab = table1->prvky[i];
            pocet++;
            pocet_2++;
            while (tab->dalsi != NULL) {
                tab = tab->dalsi;
                pocet++;
                pocet_2++;
            }
            pocet_1++;
        }
        //if (tab != NULL)
        //pocet_2 += pocet;
        if (pocet > max) {
            max = pocet;
        }
    }
    prum = pocet_2/pocet_1;
    printf("125%% \t%0.2f\t%d\n\n", prum, max);
    
    return 0;
}
