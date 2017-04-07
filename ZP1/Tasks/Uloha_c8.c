#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib(int);

char * algae(unsigned int iterations){
    /* doimplementujte */
    int i;
    char *A =NULL, *B=NULL, *output, *begin;
    //unsigned next_len (char *str);
    A = (char*) calloc(fib(iterations +3)+1, sizeof(char)); //nulovani pro A
    B = (char*) calloc(fib(iterations +3)+1, sizeof(char)); //nulovani pro B
    output = B; // Prirad pointer na B (na zacatku)
    begin = A;
    *B++ = 'A'; // Prida znak 'A'
    *B++ = '\0'; // Prida znak ' '
    
    for (i = 0; i <= iterations; i++) {
        strcpy(A, B); // Zkopiruje stringy z B do A
        while (*A != '\0') { // Dokud hodnota pointeru != '\0'
            if (*A == 'A') { // Jestlize hodnota se rovna 'A'
                *B++ = 'A'; // Prida 'A'
                *B++ = 'B'; // Prida 'B'
            }
            else{
                *B++ = 'A'; // Jinak prida jen 'A'
            }
            A++; // zvys o jedno v "if"
        }
        B = output; // Prizaruju pointer zpet na zacatku, protoze je nakonci...
    }
    free(begin);
    return output;
}

int fib(int n){
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else
        return ( fib(n-1) + fib(n-2) );
}

/* test */
int main(int argc, char ** argv){
    int n;
    char * p;
    for( n = 0 ; n <= 50 ; n++ ){
        p = algae(n);
        printf("n=%d: %s\n", n, p );
        free(p);
    }
    //printf("%i\n",fib(n+2));
    return 0;
}

/* ma vracet */
/*
 n=0: A
 n=1: AB
 n=2: ABA
 n=3: ABAAB
 n=4: ABAABABA
 n=5: ABAABABAABAAB
 n=6: ABAABABAABAABABAABABA
 n=7: ABAABABAABAABABAABABAABAABABAABAAB
 */

// *A: pointer pracuje s hodnoutou
// A: pracuje s adresou pameti
