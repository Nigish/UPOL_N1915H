#include <stdio.h>
#include <stdlib.h>

static int pole[10];
static short pole2[10];
int *int_pole = (int*)malloc(sizeof(int) * 10);
int *int_pole_avg = (int*)malloc(10 * sizeof(int));
char *char_pole = (char*)malloc(10 * sizeof(char));

void sestupna_sekvence(short n)
{
    _asm {
        mov ebx, 10
        mov ecx, 0
    opakuj:
        mov[pole + ecx * 4], ebx
        sub ebx, 1
        inc ecx
        cmp ecx, 10
        jnz opakuj
    }
}

void alternujici_sekvence(short n)
{
    _asm {
        mov ax, n
        mov ebx, 0
        mov ecx, 5
    opakuj:
        mov[pole2 + ebx], ax
        add ebx, 2
        shl ax, 1
        mov[pole2 + ebx], ax
        add ebx, 2
        shr ax, 1
        loop opakuj
    }
}

void mocniny2()
{
    _asm {
        mov ebx, int_pole
        mov eax, 1
        mov edi, 2
        mov esi, 0
        mov ecx, 10
    opakuj:
        mov[ebx + esi * 4], eax
        mul edi
        inc esi
        loop opakuj
    }
}

int avg(unsigned int n)
{
    _asm {
        mov eax, 0
        mov ecx, n
        mov esi, 0
        mov ebx, int_pole_avg
    opakuj:
        add eax, [ebx + esi * 4]
        inc esi
        loop opakuj
        mov edx, 0
        mov ebx, n
        idiv ebx
    }
}

void smaz(unsigned int n, char x)
{
    _asm {
        //mov eax, 0
        mov ebx, char_pole
        mov ecx, n
        mov dl, x
        mov esi, 0
    opakuj:
        cmp [ebx + esi], dl
        //inc esi
        ja vetsi
        jbe mensi
    vetsi:
        mov[ebx + esi], '0'
        inc esi
    mensi:
        inc esi
        loop opakuj
    }
}

int main()
{
    sestupna_sekvence(10);
    printf("Sestupna sekvence: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", pole[i]);
    }
    printf("\n");
    
    alternujici_sekvence(2);
    printf("Alternujici sekvence: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", pole2[i]);
    }
    printf("\n");
    
    mocniny2();
    printf("Mocniny^2: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%i ", int_pole[i]);
    }
    printf("\n");
    
    printf("Avg: ");
    for (int i = 0; i < 5; i++)
    {
        int_pole_avg[i] = i-1;
    }
    printf("%d",avg(5));
    printf("\n");
    
    printf("Smaz: ");
    char a = 'a';
    for (int i = 0; i < 5; i++)
    {
        a = a + 1;
        char_pole[i] = a-1;
        //printf("%c", char_pole[i]);
    }
    
    smaz(5, 'd');
    for (int i = 0; i < 5; i++)
    {
        printf("%c ", char_pole[i]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}
