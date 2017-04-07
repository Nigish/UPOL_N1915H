#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Pole {
    int *pole;
    const int n;
    int pocet;
    
public: Pole(int n): n(n) {
    pole = new int[n];
    pocet = 0;
};
     ~Pole() {
    delete [] pole; }
    
    bool pridat(int c);
    friend void vypsat(const Pole &);
    friend bool zrusit(Pole &,int c);
};


bool Pole::pridat(int c) {
    if(pocet >= n) {
        return false;
    }
    else {
        for (unsigned i = 0; i < pocet; i++) {
            if (pole[i] == c) {
                return false;
            }
        }
        //pole[pocet++] = c;
        //return true;
    }
    pole[pocet] = c;
    pocet++;
    return true;
}

bool zrusit(Pole &p, int c) {
    for(int i = 0; i < p.pocet; ++i) {
        if(p.pole[i] == c) {
            for(int j = i; j < p.pocet; ++j) {
                p.pole[j] = p.pole[j+1];
            }
            p.pocet--;
            return true;
        }
        
    }
    return false;
}

void vypsat(const Pole &p) {
    for(int i = 0; i < p.pocet; ++i) {
        cout << p.pole[i] << ", ";
    }
}

int main(){
    Pole p(6);
    p.pridat(1);
    p.pridat(3);
    p.pridat(5);
    p.pridat(7);
    p.pridat(5);
    p.pridat(2);
    p.pridat(4);
    p.pridat(6);
    
    cout << "Old Pole: ";
    vypsat(p);
    
    zrusit(p, 5);
    zrusit(p, 2);
    
    cout << "\n";
    cout << "New Pole: ";
    vypsat(p);
    
    cout << "\n\n";
    
}
