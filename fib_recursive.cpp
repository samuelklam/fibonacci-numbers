//
//  fib_recursive.cpp
//

#include "fib_recursive.hpp"

int fib_recursive(int n) {
    if (n == 0 || n == 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_recursive_mod(int n) {
    if (n == 0 || n == 1) return n;
    return (fib_recursive_mod(n - 1) + (fib_recursive_mod(n - 2))) % MODULO;
}
