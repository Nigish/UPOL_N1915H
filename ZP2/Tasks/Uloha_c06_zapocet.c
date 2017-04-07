#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int rows;
    int cols;
    double **data;
} MATRIX;

MATRIX create(int rows, int cols){
    MATRIX out;
    int i;
    
    out.rows = rows;
    out.cols = cols;
    
    out.data = (double **) malloc(rows*sizeof(double *));
    if (out.data==NULL){ printf("Chyba pri alokaci!\n"); exit(1);}
    for (i=0; i<rows; i++){
        out.data[i] = (double *) malloc(cols*sizeof(double));
        if (out.data[i]==NULL){ printf("Chyba pri alokaci!\n"); exit(2);}
    }
    return out;
}


void print(MATRIX m){
    int i, j;
    
    printf("\n");
    
    for(i=0; i<m.rows; i++){
        for(j=0; j<m.cols; j++)
            printf("%g\t", m.data[i][j]);
        printf("\n");
    }
}


double soucet (int i, int j){
    return i+j;
}

double postupne (int i, int j) {
    return 10*i+j;
}

MATRIX build_matrix(int r, int s, double (*f)(int, int)){
    MATRIX out;
    int i,j;
    
    out = create(r,s);
    
    for(i=0; i<out.rows; i++)
        for(j=0; j<out.cols; j++)
            out.data[i][j] = f(i,j);
    
    return out;
}

int main() {
    MATRIX m, n;
    
    m = build_matrix(3, 3, soucet);
    n = build_matrix(3, 5, postupne);
    
    printf("Matice m:");
    print(m);
    printf("Matice n:");
    print(n);
    return 0;
}
