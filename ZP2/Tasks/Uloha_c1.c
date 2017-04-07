//
//  Uloha_c1.c
//  Viet_TH_UPOL
//
//  Created by Viet Tran Hoang on 20.02.16.
//  Copyright © 2016 Viet Tran Hoang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vypocitej(char *priklad)
{
    int i;
    for (i = 0; ; i++) {
        if (*(priklad + i) == '\0')
            break;
    }
    return vypocitej_2(priklad, 0, i-1);
}

int vypocitej_2(char *zadani, int i1, int i2)
{
    int i;
    int nasobeni = -1;
    int levazavor = 0, pravazavor = 0;
    for (i = i1; i <= i2 ; i++) {
        if (*(zadani+i) == '*' && pravazavor == levazavor) {
            //return vypocitej_2(zadani, i1, i-1) * vypocitej_2(zadani, i+1, i2);
            nasobeni = i;
        }
        if (*(zadani+i) == '+' && pravazavor == levazavor) {
            return vypocitej_2(zadani, i1, i-1) + vypocitej_2(zadani, i+1, i2);
        }
        if (*(zadani+i) == '(') {
            levazavor++;
        }
        if (*(zadani+i) == ')') {
            pravazavor++;
        }
    }
    
    if (nasobeni != -1) {
        return vypocitej_2(zadani, i1, nasobeni-1) * vypocitej_2(zadani, nasobeni+1, i2);
    }
    if (levazavor != 0 && levazavor == pravazavor) {
        return vypocitej_2(zadani, i1+1, i2-1);
    }
    return atoi(zadani + i1);
}

int main()
{
    char *zadani;
    zadani = "23";
    printf("%s = %i\n", zadani, vypocitej(zadani)); // 23 = 23
    zadani = "2+3";
    printf("%s = %i\n", zadani, vypocitej(zadani)); // 2+3 = 5
    zadani = "(((2))+3)";
    printf("%s = %i\n", zadani, vypocitej(zadani)); // (((2))+3) = 5
    zadani = "2+3*4+5";
    printf("%s = %i\n", zadani, vypocitej(zadani)); // 2+3*4+5 = 19
    zadani = "(2+3)*(4+5)";
    printf("%s = %i\n", zadani, vypocitej(zadani)); // (2+3)*(4+5) = 45
    return 0;
}