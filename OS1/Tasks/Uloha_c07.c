#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

struct person
{
    char* name; //jmeno
    char* date; //datum
    unsigned char height; //vyska
    unsigned short weight; //vaha
};

struct person db[10];
int db_index = 0;

void db_add(char* name, char* date, unsigned char height, unsigned short weight)
{
    _asm {
        lea ebx, db
        mov esi, 16
        imul esi, db_index
        mov eax, name
        mov[ebx + esi], eax
        add esi, 4
        mov eax, date
        mov[ebx + esi], eax
        add esi, 4
        movzx eax, height
        mov[ebx + esi], eax
        add esi, 4
        movzx eax, weight
        mov[ebx + esi], eax
    }
    db_index++;
}

void db_avg_height()
{
    _asm {
        mov edi, db_index
        mov esi, 0
        mov ebx, offset db
        mov eax, 0
        for:
            mov esi, 16
            imul esi, edi
            add esi, 8
            mov edx, [ebx + esi]
            add eax, edx
            dec edi
            cmp edi, 0
            jns for
                mov edx, 0
                mov edi, db_index
                div edi
                konec:
                }
}

void db_avg_weight()
{
    _asm {
        mov edi, db_index
        mov esi, 0
        mov ebx, offset db
        mov eax, 0
        for:
            mov esi, 16
            imul esi, edi
            add esi, 12
            mov edx, [ebx + esi]
            add eax, edx
            dec edi
            cmp edi, 0
            jns for
                mov edx, 0
                mov edi, db_index
                div edi
                konec:
                }
}

void db_print()
{
    char* strPerson = "Person no. %d \nJmeno: %s, Date: %s, Height: %d cm, Weight: %d kg\n\n";
    char* strStatistics = "Average height: %d\nAverage weight: %d\n\n";
    _asm {
        mov edi, db_index
        mov esi, 0
        mov ebx, offset db
        mov eax, 0
        
        for:
            mov ecx, 16
            imul ecx, esi
            add ecx, 12 //Jmeno
            mov eax, [ebx + ecx]
            push eax
            sub ecx, 4 //Narozeni
            mov eax, [ebx + ecx]
            push eax
            sub ecx, 4 //Vyska
            mov eax, [ebx + ecx]
            push eax
            sub ecx, 4 //Vaha
            mov eax, [ebx + ecx]
            push eax
            inc esi
            push esi
            push dword ptr strPerson
            call dword ptr[printf]
            add esp, 24
            cmp esi, edi
            jnz for
                call db_avg_height
                mov ebx, eax
                call db_avg_weight
                push eax
                push ebx
                push[strStatistics]
                call printf
                add esp, 12
                }
}


int main()
{
    db_add("Petra Kocibova", "16.03.1994", 158, 55);
    db_add("Barbora Jilkova", "29.09.1995", 166, 50);
    db_add("Libor Machalek", "20.05.1994", 185, 65);
    db_add("Zaneta Ruzickova", "12.01.1995", 177, 58);
    db_add("Karolina Adamova", "21.04.1994", 169, 60);
    
    db_print();
    system("pause");
    return 0;
}
