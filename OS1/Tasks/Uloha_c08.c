#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

int get_mask(unsigned char n, unsigned char p)
{
    _asm {
        mov eax, 0
        mov cl, n
        
    opakuj_1:
        shl eax, 1
        add eax, 1
        loop opakuj_1
        
        mov cl, p
        
    opakuj_0:
        add eax, 0
        shl eax, 1
        loop opakuj_0
    }
}

void divide(int x, unsigned char n , int* a , int* b)
{
    _asm {
        mov eax, x
        mov cl, byte ptr n
        mov ebx, 1
        shl ebx, cl
        cdq
        idiv ebx
        jmp end
    end:
        mov ecx, a
        mov[ecx], eax
        mov ecx, b
        mov[ecx], edx
    }
}

short nasob(short cislo)
{
    _asm { //10 = 1010 ~ 3+1 ~ 101.0
        mov ax, cislo
        mov bx, ax
        shl ax, 1
        shl bx, 3
        add ax, bx
        mov cislo, ax
    }
}

int main()
{
    _asm {
        mov eax, 123
        mov ebx, 246
        mov ecx, 369
        mov edx, 492
        
        add eax, ecx
        add ebx, edx
        adc edx, edx
    }
    
    printf("get_mask: %d\n\n", get_mask(5,5)); // 31 ~ 0000011111, 992 ~ 1111100000
    
    int podil, zbytek;
    divide( 16, 4, &podil, &zbytek);
    
    printf("divide: %d, %d\n\n", podil, zbytek);
    
    printf("Nasob 10: %d\n\n", nasob(27));
    system("pause");
    return 0;
}
