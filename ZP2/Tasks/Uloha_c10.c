#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#define MAX_ROK 2010
#define MIN_ROK 1960
#define POCET_STAVU 4
#define DELKA 20

const int jmena_m_pocet = 10;
const int jmena_z_pocet = 10;
const int prijmeni_m_pocet = 10;
const int prijmeni_z_pocet = 10;
const char *jmena_m[] =
{ "Jakub", "Jan", "Tomas", "Lukas", "Ondrej", "Vojtech", "Matej", "Adam", "Daniel", "Filip" };
const char *jmena_z[] =
{ "Tereza", "Natalie", "Anna", "Adela", "Eliska", "Karolina", "Katerina", "Barbora", "Lucie",
    "Kristyna" };
const char *prijmeni_m[] =
{ "Novak", "Svoboda", "Novotny", "Dvorak", "Cerny", "Prochazka", "Kucera", "Vesely", "Horak",
    "Nemec" };
const char *prijmeni_z[] =
{ "Novakova", "Svobodova", "Novotna", "Dvorakova", "Cerna", "Prochazkova", "Kucerova", "Vesela",
    "Horakova", "Nemcova" };

typedef enum {
    MUZ = 'M', ZENA = 'Z'
} POHLAVI;

typedef enum {
    SVOBODNY = 'S', ZENATY = 'Z', ROZVEDENY = 'R', VDOVEC = 'V'
} STAV;

typedef struct {
    char den;
    char mesic;
    int rok;
} datum;

typedef struct {
    char jmeno[DELKA];
    char prijmeni[DELKA];
    datum narozen;
    POHLAVI pohlavi;
    STAV stav;
} osoba;

int je_prestupny(unsigned int rok);
unsigned int pocet_dnu(unsigned int mesic);
datum generuj_datum(int rok_od, int rok_do);
int generator(char *soubor, int pocet);
int vyhledej(char *soubor, char *kriteria, ...);
void vypis(osoba o);

int main()
{
    /* vygenerovani binarni databaze */
    generator("databaze.dat", 10000);
    
    /* vyhledavani v databazi */
    //   vyhledej("databaze.dat", "P", ZENA);
    printf("\n");
    vyhledej("databaze.dat", "jps", "Anna", "Novotna", VDOVEC);
    printf("\n");
    vyhledej("databaze.dat", "n", 27, 5, 2009);
    printf("\n");
    vyhledej("databaze.dat", "n", 6, 11, 2009);
    
    return 0;
}

int je_prestupny(unsigned int rok)
{
    if (rok % 100 == 0)
        return (rok % 400 == 0);
    else
        return (rok % 4 == 0);
}

unsigned int pocet_dnu(unsigned int mesic)
{
    const static int pocet[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mesic <= 12)
        return pocet[mesic - 1];
    else
        return 0;
}

datum generuj_datum(int rok_od, int rok_do)
{
    char den;
    char mesic;
    int rok;
    char max_den;
    datum d;
    
    rok = (rand() % (rok_do - rok_od + 1)) + rok_od;
    mesic = (rand() % 12) + 1;
    max_den = pocet_dnu(mesic);
    if ((mesic == 2) && (je_prestupny(rok)))
        max_den++;
    den = (rand() % max_den) + 1;
    
    d.den = den;
    d.mesic = mesic;
    d.rok = rok;
    return d;
}

int generator(char *soubor, int pocet)
{
    int i;
    size_t zapsano;
    FILE *fw;
    
    /* otevreni souboru */
    fw = fopen(soubor, "wb");
    if (fw == NULL) {
        printf("Chyba: Vystupni soubor nebyl vytvoren. \n");
        return 1;
    }
    
    /* generovani udaju a zapis do souboru */
    srand((unsigned) time(NULL));
    for (i = 0; i < pocet; i++) {
        osoba o;
        char stav_cislo;
        
        o.pohlavi = (rand() % 2) ? MUZ : ZENA;
        if (o.pohlavi == MUZ) {
            strcpy(o.jmeno, jmena_m[rand() % jmena_m_pocet]);
            strcpy(o.prijmeni, prijmeni_m[rand() % prijmeni_m_pocet]);
        } else {
            strcpy(o.jmeno, jmena_z[rand() % jmena_z_pocet]);
            strcpy(o.prijmeni, prijmeni_z[rand() % prijmeni_z_pocet]);
        }
        o.narozen = generuj_datum(MIN_ROK, MAX_ROK);
        stav_cislo = rand() % POCET_STAVU;
        switch (stav_cislo) {
            case 0:
                o.stav = SVOBODNY;
                break;
            case 1:
                o.stav = ZENATY;
                break;
            case 2:
                o.stav = ROZVEDENY;
                break;
            case 3:
                o.stav = VDOVEC;
                break;
        }
        
        /* zapis a test */
        zapsano = fwrite(&o, sizeof(osoba), 1, fw);
        if (zapsano != 1) {
            fclose(fw);
            return 2;
        }
    }
    /* uzavreni souboru a test */
    if (fclose(fw) == EOF) {
        printf("Chyba: Vystupni soubor nebyl uzavren. \n");
        return 3;
    }
    
    return 0;
}

int vyhledej(char *soubor, char *kriteria, ...)
{
    FILE *fw;
    
    /* otevreni souboru */
    fw = fopen(soubor, "rb");
    if (fw == NULL) {
        printf("Chyba: Vystupni soubor nebyl otevren. \n");
        return 1;
    }
    
    va_list param;
    int i, shoda, pruchod=0;
    int pocet = strlen (kriteria);
    osoba hledana;
    osoba argumenty;
    
    va_start(param, kriteria);
    
    while (fread(&hledana, sizeof(osoba), 1, fw)){
        pruchod++;
        shoda = 0;
        for (i=0; i<pocet; i++){
            switch (kriteria[i]){
                case 'j': //jmeno
                    if (pruchod == 1){
                        strcpy(argumenty.jmeno, va_arg(param, char*));
                    }
                    shoda += ((strcmp(hledana.jmeno, argumenty.jmeno))==0) ? 1 : 0;
                    break;
                case 'p': //prijmeni
                    if (pruchod == 1){
                        strcpy(argumenty.prijmeni, va_arg(param, char*));
                    }
                    shoda += ((strcmp(hledana.prijmeni, argumenty.prijmeni))==0) ? 1 : 0;
                    break;
                case 'n': //datum narozeni
                    if (pruchod == 1){
                        argumenty.narozen.den = va_arg(param, int);
                        argumenty.narozen.mesic = va_arg (param, int);
                        argumenty.narozen.rok = va_arg (param, int);
                    }
                    shoda +=(hledana.narozen.den == argumenty.narozen.den &&
                             hledana.narozen.mesic == argumenty.narozen.mesic &&
                             hledana.narozen.rok == argumenty.narozen.rok) ? 1 : 0;
                    break;
                case 'd': //den narozeni
                    if (pruchod == 1){
                        argumenty.narozen.den = va_arg(param, int);
                    }
                    shoda += (hledana.narozen.den==argumenty.narozen.den) ? 1 : 0;
                    break;
                case 'm': //mesic narozeni
                    if (pruchod == 1){
                        argumenty.narozen.mesic = va_arg(param, int);
                    }
                    shoda += (hledana.narozen.mesic==argumenty.narozen.mesic) ? 1 : 0;
                    break;
                case 'r': //rok narozeni
                    if (pruchod == 1){
                        argumenty.narozen.rok = va_arg(param, int);
                    }
                    shoda += (hledana.narozen.rok == argumenty.narozen.rok) ? 1 : 0;
                    break;
                case 'P': //pohlavi
                    if (pruchod == 1){
                        argumenty.pohlavi = va_arg(param, POHLAVI);
                    }
                    shoda +=(hledana.pohlavi == argumenty.pohlavi) ? 1 : 0;
                    break;
                case 's': //stav
                    if (pruchod == 1){
                        argumenty.stav = va_arg(param, STAV);
                    }
                    shoda +=(hledana.stav == argumenty.stav) ? 1 : 0;
                    break;
            }
        }
        if (shoda == pocet){
            vypis(hledana);
        }
        else{
            continue;
        }
    }
    va_end (param);
    if (fclose(fw) == EOF) {
        printf("Chyba: Vystupni soubor nebyl uzavren. \n");
        return 3;
    }
    return 0;
}

void vypis(osoba o)
{
    static char *stavy[] =
    { "svobodny", "svobodna", "zenaty", "vdana", "rozvedeny", "rozvedena", "vdovec", "vdova" };
    int stavy_index;
    
    printf("%s %s ", o.jmeno, o.prijmeni);
    
    if (o.pohlavi == MUZ)
        printf("narozen ");
    else
        printf("narozena ");
    
    printf("%i. %i. %i", o.narozen.den, o.narozen.mesic, o.narozen.rok);
    
    switch (o.stav) {
        case SVOBODNY:
            stavy_index = 0;
            break;
        case ZENATY:
            stavy_index = 2;
            break;
        case ROZVEDENY:
            stavy_index = 4;
            break;
        case VDOVEC:
            stavy_index = 6;
            break;
    }
    stavy_index += (o.pohlavi == MUZ) ? 0 : 1;
    printf(", %s\n", stavy[stavy_index]);
    
}

