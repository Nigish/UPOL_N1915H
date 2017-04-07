#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FREE ""
#define SIZE 159

const char *Jmena[]=
{ "Marie","Jan","Jana","Petr","Josef","Pavel","Jaroslav","Martin","Miroslav","Eva",
    "Anna","Hana","Karel","Lenka","Milan","Michal","Alena","Petra","Lucie","Jaroslava",
    "Ludmila","Helena","David","Ladislav","Jitka","Martina","Jakub","Veronika","Jarmila","Stanislav",
    "Michaela","Ivana","Roman","Monika","Tereza","Zuzana","Radek","Vlasta","Marcela","Marek",
    "Dagmar","Dana","Daniel","Marta","Irena","Miroslava","Barbora","Pavla","Miloslav","Olga",
    "Andrea","Iveta","Filip","Blanka","Milada","Ivan","Zdenka","Libor","Renata","Rudolf",
    "Vlastimil","Nikola","Gabriela","Adam","Radka","Simona","Milena","Miloslava","Iva","Daniela",
    "Patrik","Bohumil","Denisa","Robert","Romana","Aneta","Ilona","Dominik","Stanislava","Emilie",
    "Radim","Richard","Kamila","Ivo","Rostislav","Vladislav","Bohuslav","Alois","Vit","Kamil",
    "Jozef","Vendula","Bohumila","Viktor","Emil","Michael","Ladislava","Magdalena","Eduard","Dominika",
    "Marcel","Sabina","Julie","Antonie","Alice","Peter","Dalibor","Kristina","Otakar","Karla",
    "Hedvika","Alexandra","Silvie","Erika","Nela","Vratislav","Nikol","Leona","Jolana","Margita",
    "Bohuslava","Radovan","Josefa","Terezie","Marian","Linda","Igor" };

const unsigned Pocet=sizeof(Jmena)/sizeof(*Jmena);

const char *JmenaN[]=
{ "Robert","Sabina","Julie","Nikol","Alexa","Alice","Leona","Linda","Igor" };

const unsigned PocetN=sizeof(JmenaN)/sizeof(*JmenaN);

const char *JmenaZ[]=
{ "Marie","Jan","Petr","Josef","Jaroslav","Miroslav","Eva",
    "Anna","Karel","Milan","Michal","Alena","Jaroslava",
    "Ludmila","Ladislav","Martina","Jakub","Veronika","Jarmila","Stanislav",
    "Zuzana","Vlasta","Marcela",
    "Dagmar","Dana","Daniel","Marta","Miroslava","Barbora","Pavla","Miloslav","Olga",
    "Andrea","Iveta","Filip","Milada","Zdenka","Rudolf",
    "Vlastimil","Nikola","Gabriela","Milena","Miloslava","Daniela",
    "Patrik","Bohumil","Denisa","Aneta","Ilona","Stanislava","Emilie",
    "Radim","Kamila","Ivo","Rostislav","Vladislav","Bohuslav","Alois","Vit","Kamil",
    "Jozef","Vendula","Bohumila","Michael","Ladislava","Magdalena","Eduard","Dominika",
    "Julie","Antonie","Peter","Kristina","Otakar","Karla",
    "Hedvika","Alexandra","Erika","Nela","Vratislav","Jolana","Margita",
    "Bohuslava","Josefa","Terezie","Igor" };

const unsigned PocetZ=sizeof(JmenaZ)/sizeof(*JmenaZ);

const char *JmenaZN[]=
{ "Robert","Sabina","Julie","Nikol","Alexa","Alice","Leona","Linda","Igor" };

const unsigned PocetZN=sizeof(JmenaZN)/sizeof(*JmenaZN);


unsigned Hash(const char *string) {
    
    unsigned h = 0;
    for (const unsigned char *r = (const unsigned char*)string; *r; ++r) {
            h = h + *r;
            h = h + (h << 10);
            h = h ^ (h >> 6);
        }
    h = h + (h << 3);
    h = h ^ (h >> 11);
    h = h + (h << 15);
        return h;
    }

char* SearchQuadr(const char **table, int size, const char *x) {
    int i;
    unsigned h, h0 = Hash(x);
    
    for (i = 0; i < size; i++) {
            h = (h0 + i*i) % size;
        
            if (table[h] == NULL)
                    return NULL;
            if ((table[h] == x) && (strcmp(table[h], FREE) != 0))
                    return (char*)table[h];
        }
    return NULL;
}

int InsertQuadr(const char **table, int size, const char *x) {
    int i;
    unsigned h, h0 = Hash(x);
    
    for (i = 0; i < size; i++) {
            h = (h0 + i*i) % size;
        
            if ((table[h] == NULL) || (strcmp(table[h], FREE) == 0)) {
                    table[h] = x;
                    return 1;
                }
        }
    return 0;
}

int DeleteQuadr(const char **table, int size, const char *x) {
    int i;
    unsigned h, h0 = Hash(x);
    
    for (i = 0; i < size; i++) {
            h = (h0 + i*i) % size;
        
            if (table[h] == NULL)
                    return 0;
            if ((strcmp(table[h], FREE) != 0) && (strcmp(table[h], x) == 0)) {
                    table[h] = FREE;
                    return 1;
                }
        }
    return 0;
}


int main()
{
    int i;
    const char* temp;
    
    const char* hashtable[SIZE];
    for (i = 0; i < SIZE; i++)
        hashtable[i] = NULL;
    
    for (i = 0; i < Pocet; i++)
        if (InsertQuadr(hashtable, SIZE, Jmena[i]) == 0)
            printf("Chyba.\n");
    
    for (i = 0; i < PocetN; i++) {
        temp = SearchQuadr(hashtable, SIZE, JmenaN[i]);
        
        if (temp == NULL)
            printf("Nenalezeno.\n");
        else
            printf("%s\n", temp);
    }
    
    for (i = 0; i < PocetZ; i++) {
        if (DeleteQuadr(hashtable, SIZE, JmenaZ[i]) == 0)
            printf("\nDoslo k selhani pri odebirani z tabulky.\n");
    }
    printf("\n");
    
    for (i = 0; i < PocetZN; i++) {
        temp = SearchQuadr(hashtable, SIZE, JmenaZN[i]);
        
        if (temp == NULL)
            printf("Nenalezeno.\n");
        else
            printf("%s\n", temp);
    }
    
    return 0;
}

