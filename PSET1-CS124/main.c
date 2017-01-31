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
    if (n == 0 | n == 1) return n;
    else return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_iterative(int n) {
    int f0 = 0;
    int f1 = 1;
    int tmp;
    
    if (n == 0 | n == 1) return n;
    
    for (int i = 1; i < n; i++) {
        tmp = f1;
        f1 += f0;
        f0 = tmp;
    }
    
    return f1;
}

//int fib_matrix(int n) {
//    
//}

int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    start = clock();
    
    int fib_val = 3;
    
//    int n0 = fib_recursive(fib_val);
    int n1 = fib_iterative(fib_val);
    
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f\n", time_spent);
    printf("Fib (%d) = %d\n", fib_val, n1);
    
    return 0;
}
