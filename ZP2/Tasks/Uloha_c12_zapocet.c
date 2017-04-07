//
//  Uloha_c12_zapocet.c
//  Viet_TH_UPOL
//
//  Created by Viet Tran Hoang on 03.05.16.
//  Copyright © 2016 Viet Tran Hoang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cetnost_slova(char *soubor,char *hledane){
    char *obsah;
    int i, j, k, cetnost;
    char temp[31];
    FILE *f;
    
    obsah=malloc(sizeof(char)*1000);
    k = 0;
    cetnost = 0;
    f=fopen(soubor,"r");
    
    for(i=0;feof(f) == 0;i++){
        obsah[i] = fgetc(f);
    }
    
    for(j=0;j<i;j++){
        if((obsah[j]>='A' && obsah[j]<='Z') || (obsah[j]>='a' && obsah[j]<='z')){
            temp[k++]=obsah[j];
        }
        else{
            temp[k]='\0';
            if(strcmp(temp,hledane)==0)cetnost++;
            k=0;
        }
    }
    
    fclose(f);
    return cetnost;
}

int main()
{
    printf("Mac %i\n", cetnost_slova("text.txt", "Mac"));
    printf("is %i\n", cetnost_slova("text.txt","is"));
    printf("friend %i\n", cetnost_slova("text.txt","friend"));
}

/*
#include <stdio.h>
#include <stdlib.h>

int cetnost_slova(char *soubor, char *hledane) {
    FILE *fr = fopen(soubor, "r+t");
    char slovo[30];
    int vyskyt = 0;
    
    while (fscanf(fr, "%s", slovo) != EOF) {
        //P¯evedenÌ ¯etÏzce na malÈ pÌsmena
        for (int i = 0; i < 30; i++) {
            slovo[i] = tolower(slovo[i]);
            
            //OdstranÏnÌ p¯ÌpadnÈ teËky, Ë·rky nebo st¯ednÌku
            if (slovo[i] == ',' || slovo[i] == ';' || slovo[i] == '.') {
                slovo[i] = NULL;
            }
        }
        if (strcmp(hledane, slovo) == 0) {
            vyskyt++;
        }
    }
    fclose(fr);
    return vyskyt;
}

int main(){
    printf("in %i\n", cetnost_slova("text.txt", "in"));
    printf("is %i\n", cetnost_slova("text.txt", "is"));
    printf("trie %i\n", cetnost_slova("text.txt", "trie"));
}
*/