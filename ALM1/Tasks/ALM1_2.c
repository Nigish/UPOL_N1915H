#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertsort(int pocet)
{
    int A[pocet], i, j, t, srovnani=0, presuny=0;
    
    for (i = 0; i < pocet; i++)
        A[i] = rand()%100000;
    
    for (i = 1; i<pocet; i++){
        t = A[i];
        j = i - 1;
        
        if (i >= 0){
            srovnani++;
            if (A[i] > t){
                srovnani++;
            }
        }
        while (j >= 0 && A[j] > t){
            srovnani++;
            A[j + 1] = A[j];
            presuny++;
            j--;
        }
        A[j + 1]=t;
    }
    
    for (i = 0; i < pocet; i++){
        //printf("%i ", A[i]);
    }
   
    
    float pocet_srovnani, pocet_presunu;
    
    pocet_srovnani  = (float)srovnani/(pocet*pocet);
    pocet_presunu = (float)presuny/(pocet*pocet);
    
    printf("%i\t\t %i %.2f\t %i %.2f\n", pocet, srovnani, pocet_srovnani, presuny, pocet_presunu);
    
    if(pocet == 5000){
        printf("\nPrvnich 20 cisel :\n");
        for(i = 0; i < 20 ; i++){
            printf("%i, ",A[i]);
        }
        printf("\nPoslednich 10 cisel :\n");
        for(i = pocet-10 ; i < pocet ; i++){
            printf("%i, ",A[i]);
        }
        printf("\n\n");
    }
    
    return 0;
}

int main()

{
    srand(time(0));
    
    printf("Pocet\t Srovnani\t Vymeny\n---------------------------\n");
    
    insertsort(10);
    insertsort(20);
    insertsort(50);
    insertsort(100);
    insertsort(200);
    insertsort(500);
    insertsort(1000);
    insertsort(2000);
    insertsort(5000);
    
    return 0;
}
