//
//  fib_matrix.cpp
//

#include "fib_matrix.hpp"

void matrix_mult(int M1[2][2], int M2[2][2]) {
    
    int x00 =  M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0];
    int x01 =  M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1];
    int x10 =  M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0];
    int x11 =  M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1];
    
    M1[0][0] = x00;
    M1[0][1] = x01;
    M1[1][0] = x10;
    M1[1][1] = x11;
}

void matrix_mult_mod(unsigned int M1[2][2], unsigned int M2[2][2]) {
    
    unsigned int x00 =  ((M1[0][0] * M2[0][0]) + (M1[0][1] * M2[1][0])) % MODULO;
    unsigned int x01 =  ((M1[0][0] * M2[0][1]) + (M1[0][1] * M2[1][1])) % MODULO;
    unsigned int x10 =  ((M1[1][0] * M2[0][0]) + (M1[1][1] * M2[1][0])) % MODULO;
    unsigned int x11 =  ((M1[1][0] * M2[0][1]) + (M1[1][1] * M2[1][1])) % MODULO;
    
    M1[0][0] = x00;
    M1[0][1] = x01;
    M1[1][0] = x10;
    M1[1][1] = x11;
}

void matrix_power(int M[2][2], int n) {
    
    if (n == 0 || n == 1) return;
    int N[2][2] = {{1, 1}, {1, 0}};
    
    matrix_power(M, n/2);
    matrix_mult(M, M);
    
    if (n % 2 != 0) matrix_mult(M, N);
}

void matrix_power_mod(unsigned int M[2][2], unsigned int n) {
    
    if (n == 0 || n == 1) return;
    unsigned int N[2][2] = {{1, 1}, {1, 0}};
    
    matrix_power_mod(M, n/2);
    matrix_mult_mod(M, M);
    
    if (n % 2 != 0) matrix_mult_mod(M, N);
}

int fib_matrix(int n) {
    if (n == 0 || n == 1) return n;
    int M[2][2] = {{1, 1}, {1, 0}};
    matrix_power(M, n-1);
    return M[0][0];
}

int fib_matrix_mod(unsigned int n) {
    if (n == 0 || n == 1) return n;
    unsigned int M[2][2] = {{1, 1}, {1, 0}};
    matrix_power_mod(M, n-1);
    return M[0][0];
}
