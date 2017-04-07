//#include "stdafx.h"
#include <stdlib.h>

int sgn(int i)
{
    _asm {
        mov eax, i
        cmp eax, 0 //cmp 01,02 -> 01-02
        jg vetsi
        jl mensi
        jmp konec
    vetsi: mov eax, 1
        jmp konec
    mensi: mov eax, -1
        jmp konec
    konec:
    }
}

short short_avg(short a, short b, short c)
{
    _asm {
        mov ax, a
        add ax, b
        add ax, c
        cwd
        mov bx, 3
        idiv bx
    }
}

int int_avg(int a, int b, int c)
{
    _asm {
        mov eax, a
        add eax, b
        add eax, c
        cdq
        mov ebx, 3
        div ebx
        
    }
}

char diff(char a, char b)
{
    _asm {
        mov al, a
        mov bl, b
        cmp al, bl
        jge vetsi
        jle mensi
        jmp konec
    vetsi: sub al, bl
        jmp konec
    mensi: sub bl, al
        mov al, bl
        jmp konec
    konec:
    }
}

char max(short a, short b, short c)
{
    _asm {
        mov ax, a
        mov bx, b
        mov cx, c
        
        cmp ax, bx
        jge vetsiA
        jle mensiA
        
    vetsiA:
        cmp ax, cx
        jge nejvetsiA
        jle nejvetsiC
    nejvetsiA:
        mov ax, 1
        jmp konec
    nejvetsiC:
        mov ax, 3
    mensiA:
        cmp bx, cx
        jge nejvetsiB
        jle nejvetsiC
    nejvetsiB:
        mov ax, 2
        jmp konec
    konec:
    }
}

int main()
{
    printf("Cislo -27: %d\n", sgn(-27));
    printf("Prumer: %d\n", short_avg(10, 20, 30));
    printf("Prumer: %d\n", int_avg(-10, 20, 30));
    printf("Diff: %d\n", diff(20, 50));
    printf("Max: %d\n", max(2, 3, 1));
    system("pause");
    return 0;
}

