#include <stdio.h>
// PRVNI UKOL
int bracketing_p(char expr[]){
    int i = 0;
    int ctrl = 0;
    while (expr[i] != '\0'){
        if(expr[i] == ')'){
            ctrl--; // pro uzavrene
        }else if(expr[i] == '('){
            ctrl++; // pro otevrene
        }
        if(ctrl < 0){ // Zavorka zacina minus "-1", nezle v pripade pro '))(('
            return 0;
        }
        i++;
    }
    if(ctrl == 0){ // pokud pocet zavorek na obou stran se shoduji cos je 0, vrat 1
        return 1;
    }else{
        return 0; // pokud ne, vrat 0
    }
}

int main()
{
    char tst1[] = "))((";
    char tst2[] = "((AbC)D)";
    printf("%d\n", bracketing_p(tst1));
    printf("%d\n", bracketing_p(tst2));
    return 0;
}

//DRUHY UKOL
unsigned int find_extension(char path[])
{
    int i = 0;
    int tecka = -1;
    while (path[i] != '\0'){
        if(path[i] == '.' && path[i+1] != '\0'){ //hleda tecku dokud tam nebude '\0', vrati posledni pozice tecky
            tecka = i;
        }
        i++;
    }
    if (tecka != -1){ //bug v zadani?? 0
        return tecka;
    }else{
        return i;
    }
}
int main()
{
    char tst1[] = "/home/nobody/im.age.jpeg";
    char tst2[] = " .image";
    char tst3[] = " ";
    printf("%i %i %i \n", find_extension(tst1), find_extension(tst2), find_extension(tst3));
    return 0;
}

//TRETI UKOL
unsigned int find_extension(char path[])
{
    int i = 0;
    int tecka = -1;
    while (path[i] != '\0'){
        if(path[i] == '.' && path[i+1] != '\0'){
            tecka = i;
        }
        i++;
    }
    if (tecka != -1){ //??
        return tecka;
    }else{
        return i;
    }
}

void print_extension(char path[], unsigned int idx){
    
    while(path[idx] != '\0'){
        printf("%c",path[idx+1]); //index + 1, vypise to co je za teckou
        idx++;
    }
    printf("\n");
}
int main()
{
    char tst1[] = "/home/nobody/im.age.jpeg";
    char tst2[] = ".image";
    
    print_extension(tst1 ,find_extension(tst1));
    print_extension(tst2 ,find_extension(tst2));
    return 0;
}

