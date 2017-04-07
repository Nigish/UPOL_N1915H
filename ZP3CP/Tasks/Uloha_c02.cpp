#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Palec;

class Cm{
    double a;
public: Cm (double a) : a(a) {}
    double hodnotaC() { return a;}
    double palec() {return a * 2.54;}
    double rozdil(Cm &c) {return abs(c.hodnotaC() - a);}
    double rozdil(Palec &c);
    
};

class Palec{
    float b;
public: Palec (float b) : b(b) {}
    float hodnotaP() {return b;}
    float Cm() {return b / 2.54;}
    float rozdil(Palec &c) {return abs(c.hodnotaP() - b);}
    float rozdil(class Cm &n);
};

double Cm:: rozdil(Palec &c) {return abs(c.hodnotaP()* 2.54 - a);}
float Palec:: rozdil(class Cm &n) {return abs(n.palec()- b);}

int main(){
    Cm a = 2;
    Cm d = 3;
    Palec b = 3;
    Palec e = 5;
    cout <<"Hodnota: " << a.hodnotaC()<< " " << "Palec: " << a.palec() << endl;
    cout <<"Rozdil Cm: " << a.rozdil(d) << endl;
    cout <<"Rozdil Palec: " << a.rozdil(e) << endl;
    
    
    
    cout << "Hodnota: " << b.hodnotaP() << " " << "Cm: " << b.Cm() << endl;
    cout <<"Rozdi lPalec: " << b.rozdil(e) << endl;
    cout <<"Rozdil Cm: " << b.rozdil(d) << endl;
}
