//
//  fib_iterative.cpp
//

#include "fib_iterative.hpp"

int fib_iterative(int n) {
    int f0 = 0;
    int f1 = 1;
    int tmp;
    
    if (n == 0 || n == 1) return n;
    
    for (int i = 1; i < n; i++) {
        tmp = f1;
        f1 += f0;
        f0 = tmp;
    }
    return f1;
}

int fib_iterative_mod(int n) {
    int f0 = 0;
    int f1 = 1;
    int tmp;
    
    if (n == 0 || n == 1) return n;
    
    for (int i = 1; i < n; i++) {
        tmp = f1;
        f1 = (f1 + f0) % MODULO;
        f0 = tmp;
    }
    return f1;
}
