#include <stdio.h>
#include <string.h>
#define rozsah 128

typedef enum { // Vytvavim si typ promene
    Menu,
    Vytvor,
    Odstranit,
    Zobrazit,
    Hledat,
    Konec
} h_menu;

typedef enum { // Vytvavim si typ prof.
    RDT,
    URD,
    DEL,
    MAN
} h_povolani;

typedef struct {
    char jmeno[128], prijmeni[128];
    int index;
    h_povolani pozice; // Pridelovani pozic z h_povolani
} s_user;

h_menu main_menu; // Vytvarim si menu
s_user user[rozsah];

void setMenu(h_menu);
void printInfo(int);
int freeFreeSlot();
int findUser(char []);

int findFreeSlot(){ // Hledani volneho inxdexu pro uzivatele
    int i;
    for(i=0; i<rozsah; i++){
        if(user[i].index != i){
            return i;
        }
    }
    return -1;
}

int findUser(char prijmeni[]){ // Hledani uzivatele podle prijmeni
    int i, j = 0;
    for(i = 0; i<rozsah; i++){
        if(user[i].index > 0 && user[i].prijmeni[0] == prijmeni[0]){ // Zjistuje index a zaroven prvy znak prijmeni
            while(user[i].prijmeni[j] != '\0'){
                if (user[i].prijmeni[j] != prijmeni[j]){ // Pokud ne
                    j=0;
                    break; // Pokud ne, tak se to tu ZLOMI...
                }
                j++; // Porovnani dalsi znak...
            }
            if(prijmeni[j] == '\0'){
                return i;
            }
        }
    }
    return -1;
}

// here... bylo jen struktura a fuknce...

void printInfo(int i){ // Vystisne info o uzivatelovi...
    printf("Jmeno : %s\n", user[i].jmeno);
    printf("Prijmeni : %s\n", user[i].prijmeni);
    printf("Pozice : ");
    switch(user[i].pozice){
        case 0: printf("RDT\n");
            break;
        case 1: printf("URD\n");
            break;
        case 2: printf("DEL\n");
            break;
        case 3: printf("MAN\n");
            break;
        default: printf("Chyba !\n");
            break;
    }
    printf("ID: %i\n", user[i].index);
}

void setMenu(h_menu novy_menu){
    int id = -1, i =0;
    char temp_jmeno[64], temp_prijmeni[64];
    
    main_menu = novy_menu;
    switch (novy_menu) {
        case 0: printf("(1) Zadejte noveho uzivatele\n(2) Odstranit uzivatele\n(3) Zobrazit uzivatele\n(4) Hledat uzivatele podle prijmeni\n(5) Konec\n");
            scanf("%i", &i);
            if ((i > 0) && (i < 6))  {
                setMenu(i);
            }else{
                printf("Neznamy prikaz! \n");
                setMenu(Menu);
            }
            break;
            
        case 1: id = findFreeSlot();
            if (id != -1) {
                printf("Jmeno : ");
                scanf("%s", &temp_jmeno);
                printf("Prijmeni : ");
                scanf("%s", &temp_prijmeni);
                printf("Pozice :  (0)RDT  (1)URD  (2)DEL  (3)MAN\n");
                scanf("%i",&i);
                if( (i >= 0) && (i < 4)){ // Pro pozice
                    strcpy(user[id].jmeno, temp_jmeno); // copy
                    strcpy(user[id].prijmeni, temp_prijmeni); // copy
                    user[id].index = id;
                    user[id].pozice = i;
                    printf("Uzivatel uspesne vytvoreny s ID: %i!\n", id);
                }else{
                    printf("Neznamy prikaz.\n");
                }
            }else{
                printf("Databaze je plna !\n");
            }
            setMenu(Menu);
            break;
            
        case 2: printf("Zadejte ID uzivatele: ");
            scanf("%i",&i);
            if(i>0 && user[i].index > 0){
                user[i].index = -1; //Nastav na -1
                printf("Uzivatel s ID %i uspesne odstranen !\n", i);
            }else{
                printf("CHYBA : Uzivatel s ID %i neexistuje !\n", i);
            }
            setMenu(Menu);
            break;
            
        case 3: printf("Zadejte ID uzivatele: ");
            scanf("%i",&i);
            if(i>0 && user[i].index > 0){
                printInfo(i);
            }else{
                printf("CHYBA : Uzivatel s ID %i neexistuje !\n", i);
            }
            setMenu(Menu);
            break;
            
        case 4: printf("Zadejte prijmeni uzivatele: ");
            scanf("%s",&temp_prijmeni);
            id = findUser(temp_prijmeni);
            if(id != -1){
                printInfo(id);
            }else{
                printf("Uzivatel s prijmenim \"%s\" nebyl nalezen!\n", temp_prijmeni);
            }
            setMenu(Menu);
            break;
            
        case 5:
            printf("Konec");
            break;
            
        default: printf("Menu : %i neexistuje !", main_menu);
    }
}

int main()
{
    setMenu(Menu);
    return 0;
}

