#include <stdio.h>

int main()

{
    printf("Velmi 'slozity' vypocet:\n");
    
    float computation = 3.14159;
    printf("Semilogaritmicky: %e\n",computation);
    
    int cislo = 0xff;
    printf("V desitkove: %d\n",cislo);
    
    char c;
    printf ("Zadejte znak: ");
    scanf("%c", &c);
    printf("Znak '%c' v ASCII je: %d \n", c, c);
    
    double _compUTation2, a, b;
    a = (((1/((1-3.14)*3))/2));
    b = ((3-(10/2))/(((7.7+3)/(4*2))+5));
    _compUTation2 = a * b;
    printf("Vyseldek: %f \n\n",_compUTation2);
    
    return 0;
}
