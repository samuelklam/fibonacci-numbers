//
//  main.c
//  PSET1-CS124
//
//  Created by Samuel K. Lam on 1/30/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>

#define MODULO 65536
#define INT_MAX 2147483647

clock_t start, end;

int fib_recursive(int n) {
    if (n == 0 || n == 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_recursive_mod(int n) {
    if (n == 0 || n == 1) return n;
    return (fib_recursive_mod(n - 1) + (fib_recursive_mod(n - 2))) % MODULO;
}

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

// Code for Matrix Fib + Helper Functions

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

// recursive implementation
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


int main(int argc, const char * argv[]) {
    
    printf("Fib_number,Fib_value,Time_spent\n");
    
//    for (int i = 0; i < 47; i++) {
//        start = clock();
////        int n = fib_recursive(i);
//        int n = fib_iterative(i);
////        int n = fib_matrix(i);
////        int n = fib_recursive_mod(i);
//        end = clock();
//        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
//        printf("%d,%d,%f\n", i, n, time_spent);
//    }
    
    // test powers of 2, from 2^0 to 2^30
    for (int j = 0; j < 31; j++) {
        int n_pow = (int)pow(2, j);
        start = clock();
//        int n = fib_iterative_mod(n_pow);
        unsigned int n = fib_matrix_mod(n_pow);
        end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d,%d,%f\n", n_pow, n, time_spent);
    }
    
    // try largest possible int value in C
    
//    start = clock();
////    int n = fib_iterative_mod(INT_MAX);
//    unsigned int n = fib_matrix_mod(INT_MAX);
//    end = clock();
//    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
//    printf("%d,%d,%f\n", INT_MAX, n, time_spent);
    
    return 0;
}
