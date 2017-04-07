#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_fib(unsigned short n);

int fib(unsigned short n)
{
    _asm {
        movzx eax, n
        cmp eax, 1
        je jejedna
        cmp eax, 0
        je jenula
        dec eax
        push eax
        call fib
        add esp, 4
        mov ebx, eax
        movzx eax, n
        sub eax, 2
        push eax
        call fib
        add esp, 4
        add eax, ebx
        jmp konec
    jejedna: mov eax, 1
        jmp konec
    jenula: mov eax, 0
    konec:
    }
}

void print_fib(unsigned short n)
{
    char *vypis = "%d:fib(%d)\n";
    _asm {
        push dword ptr n
        call fib
        add esp, 4
        
        push dword ptr n
        push eax
        push[vypis]
        call printf
        add esp, 8
    }
}

char *my_strdup(char *s)
{
    _asm {
        push s
        call strlen
        add esp, 4
        mov esi, eax
        add eax, 1
        push eax
        call malloc
        add esp, 4
        mov edi, eax
        mov[edx + esi + 1], ebx
        mov eax, s
    opakuj:
        cmp esi, 0
        jl konec
        mov ebx, [eax + esi]
        mov[edi + esi], ebx
        dec esi
        jmp opakuj
    konec:
        mov eax, edi
    }
}

int main()
{
    printf("Fibonacciho 10 je %d\n", fib(10));
    print_fib(6);
    //printf("Fib %d:fib(%d)\n", print_fib(6));
    
    char* begin = "iMsg to gsMi";
    char* end = my_strdup(begin);
    printf("Kopie retezce: Begin \"%s\" --> End \"%s\"\n", begin, end);
    system("pause");
    return 0;
}
