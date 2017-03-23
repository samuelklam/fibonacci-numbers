//
//  fib_matrix.hpp
//
//  Functions to calculate fibonacci numbers using matrices & repeated squaring
//

#ifndef fib_matrix_hpp
#define fib_matrix_hpp

#include <stdio.h>

#define MODULO 65536

/*
 * Performs standard matrix multiplication
 * @param M1 : 2 x 2 matrix
 * @param M2 : 2 x 2 matrix
 */
void matrix_mult(int M1[2][2], int M2[2][2]);

/*
 * Performs standard matrix multiplication, mod to prevent int overflow
 * @param M1 : 2 x 2 matrix
 * @param M2 : 2 x 2 matrix
 */
void matrix_mult_mod(unsigned int M1[2][2], unsigned int M2[2][2]);

/*
 * Calculates fibonnaci # using matrices and repeated squaring
 * @param M : 2 x 2 matrix
 * @param n : value to reach for repeated squaring
 */
void matrix_power(int M[2][2], int n);

/*
 * Calculates fibonnaci # using matrices and repeated squaring, mod to prevent int overflow
 * @param M : 2 x 2 matrix
 * @param n : value to reach for repeated squaring
 */
void matrix_power_mod(unsigned int M[2][2], unsigned int n);

/*
 * Calulates fibonacci # using matrices, calls matrix_power
 * @param n : fibonacci # to compute
 * @return : fibonacci value for fib #
 */
int fib_matrix(int n);

/*
 * Calculates fibonacci # using matrices, calls matrix_power_mod to prevent int overflow
 * @param n : fibonacci # to compute
 * @return : fibonacci value for fib #
 */
int fib_matrix_mod(unsigned int n);

#endif /* fib_matrix_hpp */
