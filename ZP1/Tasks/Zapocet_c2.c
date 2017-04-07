#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mystrndup (const char * str, unsigned n){
    
    char * novy_retezec = calloc(n, sizeof(char)); // cast z prvniho ukolu...blah
    char * begin_retezec = novy_retezec; // 
    
    int i=0;
    while(*str != '\0' && i<n){ //kdyz != \0 a je mensi nez 3
        *novy_retezec++ = *str++; // -||-
        i++;
    }
    return begin_retezec;
}

int main()
{
    printf("%s\n", mystrndup("Hello", 3));
    return 0;
}
