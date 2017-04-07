#include <stdio.h>

#define je_cislice(zaklad,znak) \
((('0'<=(znak)) && ((znak)<='9') && ((znak)<'0'+(zaklad))) || (('A'<=(znak)) && ((znak)<='Z') && ((znak)<'A'-10+(zaklad))))
/* '\' - Delici znak telo makra na vice radku*/

int main()
{
    printf("1. ");
    if (je_cislice(8, '8') != /* DISABLES CODE */ (0)) printf("Ano ");
    else printf("Ne ");
    printf("2. ");
    if (je_cislice(10 + 6, '0' + 4) != /* DISABLES CODE */ (0)) printf("Ano ");
    else printf("Ne ");
    printf("3. ");
    if (je_cislice(30, '@') != /* DISABLES CODE */ (0)) printf("Ano ");
    else printf("Ne ");
    printf("4. ");
    if (je_cislice(16, 'G') != /* DISABLES CODE */ (0)) printf("Ano ");
    else printf("Ne ");
    printf("5. ");
    if (je_cislice(8, '6' + 1) != /* DISABLES CODE */ (0)) printf("Ano ");
    else printf("Ne ");
    
    printf("\n");
    return 0;
}
