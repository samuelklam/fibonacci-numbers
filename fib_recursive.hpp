//
//  fib_recursive.hpp
//
// Functions to calculate fibonacci numbers recursively
//

#ifndef fib_recursive_hpp
#define fib_recursive_hpp

#include <stdio.h>

#define MODULO 65536

/*
 * Recursive fibonacci (no memoization)
 * @param n : fibonacci # to compute
 */
int fib_recursive(int n);

/*
 * Recursive fibonacci (no memoization), mod 65536 to prevent integer overflow
 * @param n : fibonacci # to compute
 */
int fib_recursive_mod(int n);

#endif /* fib_recursive_hpp */
