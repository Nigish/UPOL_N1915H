#include <stdio.h>
#include <stdlib.h>

int get_platidla(unsigned int castka, unsigned int ** platidla){
    
    int i, pocet_minci = 0;
    unsigned int  *r,  *begin_r;
    unsigned int coins_size = 12;
    unsigned int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000};
    
    r = calloc(100,sizeof(unsigned int)); // delete (unsigned int) 'for mac' "calloc...blah"
    begin_r = r;
    // platidla = calloc(, sizeof(int)* 100);
    while(castka != 0){
        i = coins_size -1;
        while(i >= 0){
            if( ((int) (castka - coins[i])) >= 0){
                pocet_minci++;
                castka = castka - coins[i];
                *r++ = (unsigned int) coins[i];
                break;
            }
            i--;
        }
    }
    *platidla = begin_r;
    return pocet_minci;
}

int get_platidla(unsigned int, unsigned int **);
int sum_array(unsigned int [], unsigned int);

int main()
{
    unsigned int * platidla;
    int temp, i;
    unsigned int castka = 12345;
    temp = (int) get_platidla(castka, &platidla);
    printf("Zadana suma je : %i\n", castka);
    printf("Pocet minci na vydaj = %i\n", temp);
    for(i=0; i<temp;i++){
        printf("Vydane hodnoty (%i.) : %i\n", i+1, *platidla++);
    }
    return 0;
}
