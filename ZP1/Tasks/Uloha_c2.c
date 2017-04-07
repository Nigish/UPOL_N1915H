#include <stdio.h>

int main()

{
    int a, b, c;
    
    printf("Zadejte 3 pismena: ");
    
    a = getchar();
    b = getchar();
    c = getchar();
    
    if ((a <= b) && (b <= c) && (a <= c)) { //abc
        printf("Setrizeno: %c %c %c \n\n", a, b, c);
    }
    else if ((a <= b) && (b >= c) && (a <= c)) { //acb
        printf("Setrizeno: %c %c %c \n\n", a, c, b);
    }
    else if ((a >= b) && (b <= c) && (a <= c)) { //bac
        printf("Setrizeno: %c %c %c \n\n", b, a, c);
    }
    else if ((a <= b) && (b >= c) && (a >= c)) { //bca?
        printf("Setrizeno: %c %c %c \n\n", c, a, b);
    }
    else if ((a >= b) && (b >= c) && (a >= c)) { //cba
        printf("Setrizeno: %c %c %c \n\n", c, b, a);
    }
    else if ((a >= b) && (b <= c) && (a >= c)) { //cab
        printf("Setrizeno: %c %c %c \n\n", b, c, a);
    }
    
    int x, y , z , w , iavb , ic , cvd;
    
    printf("Vlozte pravdivostni hodnoty A, B, C, D: ");
    scanf("%d %d %d %d", &x, &y, &z, &w);
        
    (x || y) ? (iavb=0) : (iavb=1);
    (z) ? (ic=0) : (ic=1);
    (z || w) ? (cvd=1) : (cvd=0);
    (iavb) && (ic) && (cvd) ? printf("=> 1 \n") : printf("=> 0 \n");
    
    return 0;
}
