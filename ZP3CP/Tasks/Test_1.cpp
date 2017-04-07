#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>
#include <stdbool.h>
using namespace std;

class Zlomek {
    unsigned c, j;
    void nsd() {
        if (c == 0 ) { j = 1; return; }
        unsigned a = c, b = j, r;
        for (;;) {
            r = a % b;
            if (r == 0) { c /= b; j /= b; return; }
            a = b; b = r;
        }
    }
public:
    Zlomek() {}
    Zlomek(unsigned c, unsigned j): c(c), j(j) {nsd();}
    
    Zlomek operator + (const Zlomek &z) {
        return Zlomek((c * z.j) + (z.c * j), j * z.j);
    }
    Zlomek operator + (const unsigned &u) {
        return Zlomek((c + (u * j)), j);
    }
    Zlomek operator - (const Zlomek &z) {
        return Zlomek((c * z.j) - (z.c * j), j * z.j);
    }
    Zlomek operator - (const unsigned &u) {
        return Zlomek((c - (u * j)), j);
    }
    Zlomek operator * (const Zlomek &z) {
        return Zlomek(c * z.c, j * z.j);
    }
    Zlomek operator * (const unsigned &u) {
        return Zlomek((c * u), j);
    }
    Zlomek operator / (const Zlomek &z) {
        return Zlomek(c, j) * Zlomek(z.j, z.c);
    }
    Zlomek operator / (const unsigned n) {
        return Zlomek(c, (j * n));
    }
    
    
    bool operator == (const Zlomek &z) {
        return (c == z.c && j == z.j);
    }
    bool operator != (const Zlomek &z) {
        return (c != z.c && j != z.j);
    }
    
    
    double operator + () const {
        return (double)c / j;
    }
    void operator () () const {
        cout << c << '/' << j << "\n";
    }
};

Zlomek operator + (const unsigned &u, const Zlomek &z) {
    return Zlomek(u, 1) + z;
}
Zlomek operator - (const unsigned &u, const Zlomek &z) {
    return Zlomek(u, 1) - z;
}
Zlomek operator * (const unsigned &u, const Zlomek &z) {
    return Zlomek(u, 1) * z;
}
Zlomek operator / (const unsigned &u, const Zlomek &z) {
    return Zlomek(u, 1) / z;
}

int main(int argc, const char * argv[])
{
    Zlomek Pr1 = (Zlomek(1, 2) - Zlomek(1, 3) + 1) * 5 / (2 + Zlomek(2, 3));
    cout << "((1/2) - (1/3)) * 5u / (2u + (2/3)) = ";
    Pr1();
    
    Zlomek Pr2 = (Zlomek(3, 2) - Zlomek(1, 8));
    cout << "(3/2) - (1/8) = " << +Pr2 << "\n";
    
    Zlomek Zl1 = Zlomek(1, 2) - Zlomek(1, 3);
    Zlomek Zl2 = 2 * Zlomek(1, 12);
    cout << "(1/2) - (1/3) == 2u * (1/12) = " << (Zl1 == Zl2) << "\n";
    (Zlomek(1,2)/5)();
    cout << "\n";
    return 0;
}
