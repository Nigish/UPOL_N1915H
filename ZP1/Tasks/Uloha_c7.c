#include <stdio.h>
#include <stdlib.h>

/* Doplnte implementaci seznamu - podobnou Schemeu (3 body)
 (1) NULL je seznam (delky 0)
 (2) par typu {cislo, nasledovnik}, kde nasledovnik je seznam, je seznam
 */

typedef struct tcons{
    int car;
    struct tcons *cdr;
}tcons;


tcons *cons(int car, tcons *cdr){
    /* vytvori v pameti par - provede alokaci, nastavi car a cdr, vrati ho */
    struct tcons *ukazovatel;
    
    ukazovatel = malloc(sizeof(tcons)); // alokace pameti na tcons
    ukazovatel->car = car;
    ukazovatel->cdr = cdr;
    return ukazovatel;
}

int car(tcons *pair){
    /* vrati hodnotu car z paru pair */
    return pair->car;
    
}

tcons *cdr(tcons *pair){
    /* vrati cdr z paru pair */
    return pair->cdr;
}

unsigned length(tcons *list){
    /* spocita delku seznamu list */
    int i = 0;
    while(list != NULL){
        i++;
        list = list-> cdr;
    }
    return i;
}

tcons * reverse(tcons * list){
    /* obrati seznam list (nedestruktivne) - nesmi zmenit strukturu list - musi vybudovat novy */
    tcons * seznam = NULL;
    
    while(list != NULL){
        seznam = cons(list->car, seznam);
        list = list-> cdr;
    }
    
    return seznam;
}

void print_list(tcons * list){
    /* vytiskne seznam list na standardni vystup, ve formatu schemeu */
    /* Napr: print_list(NULL) => () */
    /* Napr: print_list( cons(3,NULL) ) => (3) */
    /* Napr: print_list( reverse(cons(3, cons(2,NULL)))) => (2 3)*/
    /* .. */
    printf("(");
    while(list != NULL){
        printf("%i",car(list));
        list = list->cdr;
    }
    printf(") ");
}

/* TEST */
int main(int argc, char ** argv){
    tcons * t = cons(1, cons(2, cons(3, NULL)));
    print_list( t );
    printf("\n");
    print_list( reverse(t) );
    printf("\n");
    printf("LENGTH - FULL: %d, CDR: %d, reversed: %d\n" , length(t), length(cdr(t)), length(reverse(t)));
    print_list( reverse(cons(3, cons(2,NULL))));
    
    return 0;
}
/*
 Vystup:
 (1 2 3)
 (3 2 1)
 LENGTH - full: 3, cdr: 2, reversed: 3
 (2 3)
 */

