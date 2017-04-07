#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()

{
    srand(time(0));
    int pole[20];
    int i, j, t;
    
    for (i = 0 ; i <= 20 ; i++) {
        pole[i] = rand()%100;
        printf("%d ", pole[i]);
    }
    printf("\n\n");
    
    for (j = 1; j <= 20; j++) {
        t = pole[j];
        i = j - 1;
        while (i >= 0 && pole[i] > t ) {
            pole[i + 1] = pole[i];
            i = i - 1;
        }
        pole[i + 1] = t;
    }
    for (i = 0; i < 20 ; i++) {
        printf("%d ", pole[i]);
    }
    printf("\n");
    return 0;
}
