#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Seznam {
    static Seznam *prvni, *iterator;
    int cislo;
    Seznam *dalsi;
public: Seznam(int cislo){
    this->cislo = cislo;
    dalsi = prvni;
    prvni = this;
}
    
    int prvek() const{
        return this->cislo; };
    
    static bool nastavitNaPrvni() {
        if (prvni == NULL) return false;
        iterator = prvni;
        return true;
    };
    
    static Seznam *aktualni(){
        return iterator; };
    
    static bool posunoutNaDalsi() {
        if (iterator->dalsi == NULL) return false;
        
        iterator = iterator->dalsi;
        return true;
    };
    
};

Seznam *Seznam::prvni = NULL;
Seznam *Seznam::iterator = NULL;

int main()

{
    cout << "Vstup: ";
    for (int i = 0; i < 50; i++) {
        Seznam *cislo = new Seznam(i);
        
        cout << cislo->prvek() << " ";
    }
    
    cout << endl << endl;
    cout <<"Vystup: ";
    if (Seznam::nastavitNaPrvni()) {
        do {
            Seznam * vypsat = Seznam::aktualni();
            cout << vypsat->prvek() << " ";
        }
        while (Seznam::posunoutNaDalsi());
    }
    return 0;
}
