#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROK 1993

// void int2bits(char *vystup, int pocet)
void int2bits(char c)
{
    for (int i = 31; i >= 0; --i)
    {
        putchar((c & (1 << i)) ? '1' : '0');
    }
}

short encode_date(char day, char month, short year)
{
    short date = (year - ROK);
    date = date << 4;
    date += month;
    date = date << 5;
    date += day;
    return date;
}

void decode_date(short date, int *day, int *month, int *year)
{
    *day = date & 31;
    date = date >> 5;
    *month = date & 15;
    date = date >> 4;
    *year = (date & 127) + ROK;
}
/*
my_memcpy(void *dest, void *src, size_t size)
{
    
}
 */

int main(int argc, char **argv)
{
    char a[32];
    int2bits(27);
    printf("%s\n", a);
    
    short encodedDate = encode_date(27, 01, 1993);
    printf("%d\n", encodedDate);
    
    int DDay = 0, DMonth = 0, DYear = 0;
    decode_date(encodedDate, &DDay, &DMonth, &DYear);
    printf("%d. %d. %d\n", DDay, DMonth, DYear);
    
    return 0;
}

