#include <stdio.h>
#include <stdlib.h>

int main()
{
    char abc [52];
    char text [] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque semper vehicula risus, id sodales sapien. Quisque accumsan arcu placerat, commodo lorem id, facilisis dolor. Duis sed justo sed nulla dictum fringilla vel ac enim. Aenean et pellentesque erat. Duis sodales tristique dui. Nullam leo risus, aliquet non aliquam eu, sagittis vel metus. Nam magna arcu, vestibulum at blandit eu, blandit vitae dolor. Maecenas vel turpis erat. Vivamus sollicitudin nibh neque, ut rutrum mi volutpat non. ";
    int pocet;
    int dtext = sizeof(text);
    //printf("%d",text);
    
    for (int i=0; i<26; i++){
        abc [i]=((char)(i+65));// + ASCII kod (tabulka)
    }
    for (int j=26; j<52; j++){
        abc [j]=((char)(j+71));// +ASCII kod (tabulka)
    }
    for (int i=0; i<52; i++){
        pocet=0;
        for (int j=0; j<dtext; j++){
            if (abc[i]==text[j]){
                pocet++;
            }
        }
        printf("%c : %d\n", abc[i], pocet);
    }
    
    int a, b, c;
    int d0 = 0;
    int pole[] = {3, 2, 8, 1, 0};
    int sizep = 5;
    
    for(a = 1; a < sizep; a++){
        printf("beh: %d\n", a);
        for(b = 0; b < sizep - 1; b++){
            if(pole[b] > pole[b+1]){
                d0 = pole[b + 1];
                pole[b + 1] = pole[b];
                pole[b] = d0;
                printf("    prohazuji: %d s %d\n", pole[b + 1], pole[b]);
            }
        }
    }
    printf("\nSerazene hodnoty: ");
    for(c = 0; c < sizep; c++){
        printf("%d ", pole[c]);
    }
    return 0;
}
