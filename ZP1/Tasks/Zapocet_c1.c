#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * string_add (const char * A, const char * B){
    
    char * novy_retezec = calloc(strlen(A)+strlen(B), sizeof(char)); // Nulovani pro novy retezec pro A a B
    char * begin_retezec = novy_retezec;
    while(*A != '\0'){ //Kdyz neni \0
        *novy_retezec++ = *A++; //tak zvysuje jak *novy.. tez *A
    }
    while(*B != '\0'){ // -||-
        *novy_retezec++ = *B++; // -||-
    }
    return begin_retezec;
}

int main ()
{
    printf("%s\n\n", string_add("Hello ", "World"));
    return 0;
}
