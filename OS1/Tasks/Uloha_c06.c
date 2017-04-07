// První zápočtová písemka

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

short *int_pole = (short*)malloc(sizeof(int) * 10);

int deleni(int a, int b)
{
    _asm {
        mov eax, a
        mov ebx, b
        cdq
        idiv ebx
        
        mov ebx, eax
        mov eax, a
        cdq
        idiv ebx
    }
}

int mocnina(int n, unsigned int m)
{
    _asm {
        mov ebx, n
        mov ecx, m
        mov eax, 1
    mocnina__:
        jcxz mocnina__konec //Registr cx je nulovy
        mul bx
        loop mocnina__
    mocnina__konec:
    }
}

short* alokace()
{
    _asm {
        
    }
}

int main()
{
    printf("Deleni: %d\n", deleni(4,-2));
    printf("Mocnia: %d\n", mocnina(4,2));
    alokace(10);
    system("pause");
    return 0;
}
