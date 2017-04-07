#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Jmena2.cpp"

struct node
{
    char jmeno[20];
    struct node *left;
    struct node *right;
};

struct node *add(const char *name, struct node **root);
void inOrderWalk(struct node **root);

int main(int argc, char **argv)
{
    struct node *tree = 0;
    
    int  i;
    for (i = 0; i < Pocet ; i++) {
        add(Jmena[i], &tree);
    }
    inOrderWalk(&tree);
    printf("Výška stromu: %i\n", maxvyska(&tree));
    return 0;
}

struct node *add(const char *name, struct node **root)
{
    if (*root==0) {
        *root = malloc(sizeof(struct node));
        strcpy((*root)-> jmeno, name);
        (*root)-> left = 0;
        (*root)-> right = 0;
    }
    else if(strcmp(name, (*root)->jmeno) > 0)
        add(name, &(*root) -> right);
    else if (strcmp(name, (*root)->jmeno) < 0)
        add(name, &(*root)->left);
}

void inOrderWalk(struct node **root)
{
    if(*root==0)
        return;
    inOrderWalk(&(*root)->left);
    printf("Jmeno: %s\n", (*root)->jmeno);
    inOrderWalk(&(*root)->right);
}

int maxvyska(struct node **root)
{
    if (*root) {
        return -1;
        
        int lLeft = maxvyska(&(*root)->left);
        int rRight = maxvyska(&(*root)->right);
        return (lLeft > rRight? lLeft : rRight) + 1;
    }
}
