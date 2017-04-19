//
//  Uloha_c09.c
//  VTH_UPOL
//
//  Created by Viet Tran Hoang on 11.04.17.
//  Copyright © 2017 Viet Tran Hoang. All rights reserved.
//

#include "stdafx.h"
#include <stdlib.h>

__declspec(naked) int max1(int a, int b) {
    _asm {
        push ebp;
        mov ebp, esp;
        mov eax, [ebp + 8];
        mov ebx, [ebp + 12];
        cmp eax, ebx;
        ja vetsi;
        jb mensi;
    vetsi:
        mov eax, ebx;
    mensi:
        mov esp, ebp;
        pop ebp;
        ret;
    }
}

__declspec(naked) int max2(int a, int b) {
    _asm {
        push ebp;
        mov ebp, esp;
        mov eax, [ebp + 8];
        mov ebx, ecx;
        cmp eax, ebx;
        ja vetsi;
        jb mensi;
    vetsi:
        mov eax, ebx;
    mensi:
        mov esp, ebp;
        pop ebp;
        ret;
    }
}

__declspec(naked) int max3(int a, int b) {
    _asm {
        push ebp;
        mov ebp, esp;
        mov eax, ecx;
        mov ebx, edx;
        cmp eax, ebx;
        ja vetsi;
        jb mensi;
    vetsi:
        mov eax, ebx;
    mensi:
        mov esp, ebp;
        pop ebp;
        ret;
    }
}

int main()
{
    int i1, i2, i3;
    _asm {
        push 1
        push 2
        call max1
        add esp, 8
        mov i1, eax
        
        push 4
        mov ecx, 3
        call max2
        add esp, 4
        mov i2, eax
        
        mov ecx, 3
        mov edx, 4
        call max3
        mov i3, eax
    }
    
    printf("%i\n", i1);
    printf("%i\n", i2);
    printf("%i\n", i3);
    system("pause");
    return 0;
}

