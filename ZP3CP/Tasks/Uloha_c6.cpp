#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <typeinfo>
using namespace std;

class KO {
    
public:
    unsigned a;
    static unsigned p;
    
    KO(int aa): a(aa % p) { ; }
    
    KO & operator = (KO & k) {
        a = k.a;
        return *this;
    }
    
    KO & operator = (unsigned aa) {
        a = (aa % p);
        return *this;
    }
    
    KO & operator += (KO & k) {
        a = ((a + k.a) % p);
        return *this;
    }
    
    KO & operator += (unsigned aa) {
        a = ((a + (aa % p)) % p);
        return *this;
    }
    
    KO & operator *= (KO & k) {
        a = ((a * k.a) % p);
        return *this;
    }
    
    KO & operator *= (unsigned aa) {
        a = ((a * (aa % p)) % p);
        return *this;
    }
    
    bool operator ! () {
        return (!a);
    }
    
    bool operator == (KO & k) {
        return (a == k.a);
    }
    
    bool operator == (unsigned aa) {
        return (a == (aa % p));
    }
    
    bool operator != (KO & k) {
        return (a != k.a);
    }
    
    bool operator != (unsigned aa) {
        return (a != (aa % p));
    }
    
    operator unsigned () {
        return a;
    }

};

unsigned KO::p = 8;

bool operator == (unsigned aa, KO & k) {
    return ((aa % KO::p) == k.a);
}

bool operator != (unsigned aa, KO & k) {
    return ((aa % KO::p) != k.a);
}

int main(){
    
    KO a(5), b(3);
    cout << (a+=b+=4) << endl;
    cout << (a*=b*=2) << endl;
    cout << boolalpha << (a==0u) << endl;
    cout << boolalpha << !a << endl;
    cout << b << endl;
    cout << boolalpha << (6u!=b) << endl;
}
