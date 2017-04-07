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
    
    bool operator < (const Zlomek &z) {
        return (c * z.j) < (z.c * j);
    }
    bool operator > (const Zlomek &z) {
        return (c * z.j) > (z.c * j);
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

// BubbleSort
template<class T>
void bubbleSort(T a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j + 1] < a[j]){
                T tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

// Median
template <class T>
T median(T a[], int n){
    T *zlomky = new T[n];
    for (int i = 0; i < n; i++) {
        zlomky[i] = a[i];
    }
    bubbleSort(zlomky, n);
    if (n % 2 == 0) {
        return (zlomky[(n - 1)/2] + zlomky[((n-1)/2)+1]) / 2;
    }
    return zlomky[n/2];
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
    //(Zlomek(1,2)/5)();
    
    Zlomek pole[10] = {Zlomek(5, 3), Zlomek(2, 7), Zlomek(4, 3), Zlomek(1, 2), Zlomek(9, 4),
        Zlomek(2, 5), Zlomek(3, 8), Zlomek(2, 3), Zlomek(3, 2), Zlomek(4, 5)};
    
    cout << "\n";
    bubbleSort(pole, 10);
    /*
    for (int i = 0; i < 10; i++) {
        pole[i]();
        cout << "";
    }*/
    cout << "\n";
    
    median(pole, 10)();
    
    cout << "\n";
    
    int a2[] = {2 , 0, 1};
    cout << median(a2, 3) << endl;
    return 0;
}
