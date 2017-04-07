#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

int delka_hran_kvadru(int a, int b, int c)
{
    _asm {
        MOV EAX, a
        SHL EAX, 2
        MOV EBX, b
        SHL EBX, 2
        ADD EAX, EBX
        MOV ECX, c
        SHL ECX, 2
        ADD EAX, EBX
        
    }
}

int objem_kvadru(int a, int b, int c)
{
    _asm {
        MOV EAX, a
        MUL b
        MUL c
    }
}

int obsah_trojuhelniku(int a, int b)
{
    _asm {
        MOV EAX, a
        MUL b
        MOV EDX, 0
        MOV EBX, 2
        DIV EBX
    }
    
}

int objem_krychle(int a)
{
    _asm {
        MOV EAX, a
        SHL EAX, 3
    }
}

int rozdel_kvadr(int a, int b, int c)
{
    _asm {
        MOV EAX, a
        MUL b
        MUL c
        MOV EBX, 2
        SHL EBX, 2
        DIV EBX
    }
}

int main()
{
    printf("Delka hran kvadru: %d \n", delka_hran_kvadru(1, 2, 3));
    printf("Objem Kvadru: %d \n", objem_kvadru(1, 2, 3));
    printf("Obsah troj: %d \n", objem_krychle(1));
    printf("Rozdel kvadr: %d \n", rozdel_kvadr(1, 2, 3));
    //system("Pause");
    return 0;
}
