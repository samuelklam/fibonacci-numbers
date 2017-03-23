//
//  fib_iterative.hpp
//
//  Functions to calculate fibonacci numbers iteratively
//

#ifndef fib_iterative_hpp
#define fib_iterative_hpp

#include <stdio.h>

#define MODULO 65536

/*
 * Iterative fibonacci computation (bottom up) uses O(1) space
 * @param n : fibonacci # to compute to
 */
int fib_iterative(int n);

/*
 * Iterative fibonacci computation (bottom up) uses O(1) space
 * mod by 65536 to prevent integer overflow
 *
 * @param n : fibonacci # to compute to
 */
int fib_iterative_mod(int n);

#endif /* fib_iterative_hpp */
