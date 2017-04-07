//
//  Uloha_c2.c
//  Viet_TH_UPOL
//
//  Created by Viet Tran Hoang on 23.02.16.
//  Copyright © 2016 Viet Tran Hoang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int x;
    int y;
    
} bod;


void vypis(bod pole[][3], int pocet) {
    
    for (int i = 0; i < pocet; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%d, %d]", pole[i][j].x, pole[i][j].y);
            
        }
        printf("\n");
    }
    
}


bod *teziste_trojuhel(bod troj[][3], int pocet) {
    
    bod teziste = { 0,0 };
    bod *pole;
    pole = malloc(pocet * sizeof(bod));
    for (int i = 0; i < pocet; i++) {
        teziste.x = 0;
        teziste.y = 0;
        
        for (int j = 0; j < 3; j++) {
            teziste.x = teziste.x + troj[i][j].x;
            teziste.y = teziste.y + troj[i][j].y;
        }
        teziste.x = teziste.x / 3;
        teziste.y = teziste.y / 3;
        
        pole[i] = teziste;
    }
    
    return pole;
}


int main() {
    
    bod Pole[2][3] = { {{0,0},{12,12},{12,0} }, {{-8,-4}, {12,12}, {2,1}} };
    vypis(Pole, 2);
    bod *stred;
    stred = teziste_trojuhel(Pole, 2);
    
    printf("\nTeziste jsou: ");
    for (int i = 0; i < 2; i++) {
        
        printf("[%d, %d]", stred[i].x, stred[i].y);
    }
    printf("\n\n");
    
    return 0;
    
}