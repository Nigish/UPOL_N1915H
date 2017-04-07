#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <typeinfo>
using namespace std;

class Fronta {int *fronta;
    unsigned size; //Velikost
    unsigned n;  //PocetPrvku
    
public: Fronta(unsigned n) : size(n) {
    fronta = new int[n];
    n = 0;}
    
    ~Fronta() {
        delete[] fronta;}
    
    Fronta &operator << (int a) {
        fronta[n++] = a; return *this;
    };
    Fronta &operator >> (int &a) {
        a = fronta[0];
        for (int i = 0; i < n; i++) {
            fronta[i] = fronta[i + 1];
        }
        --n;
        return *this;
    };
    unsigned operator + () {
        return n;
    };
    void operator () () {
        for (int i = 0; i < n; i++) {
            cout << fronta[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Fronta f(5);
    f << 5 << 8 << 2 << 6 << 3;
    int a, b;
    f >> a >> b;
    cout << a << " " << b << endl;
    f();
    f << 4 << 7;
    cout << +f << endl;
    f();
}

