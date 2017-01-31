//
//  main.c
//  PSET1-CS124
//
//  Created by Samuel K. Lam on 1/30/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int fib_recursive(int n) {
    if (n == 0 || n == 1) return n;
    else return fib_recursive(n - 1) + fib_recursive(n - 2);
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

// recursive implementation
void matrix_power(int M[2][2], int n) {
    
    if (n == 0 || n == 1) return;
    int N[2][2] = {{1, 1}, {1, 0}};
    
    matrix_power(M, n/2);
    matrix_mult(M, M);
    
    if (n % 2 != 0) matrix_mult(M, N);
}

int fib_matrix(int n) {
    if (n == 0 || n == 1) return n;
    int M[2][2] = {{1, 1}, {1, 0}};
    matrix_power(M, n-1);
    return M[0][0];
}

int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    start = clock();
    
    int fib_val = 9;
    
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    
    printf("Fib Recursive: (%d) = %d\n", fib_val, fib_recursive(fib_val));
    printf("Fib Iterative: (%d) = %d\n", fib_val, fib_iterative(fib_val));
    printf("Fib Matrix: (%d) = %d\n", fib_val, fib_matrix(fib_val));

    return 0;
}
