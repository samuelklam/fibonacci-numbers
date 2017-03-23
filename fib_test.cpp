//
//  fib_test.cpp
//

#include "fib_test.hpp"

int fib_func(int fib_type, int n) {
    if (fib_type == 1) {
        return fib_recursive(n);
    }
    else if (fib_type == 2) {
        return fib_iterative(n);
    }
    else if (fib_type == 3) {
        return fib_matrix(n);
    }
    else if (fib_type == n) {
        return fib_recursive_mod(n);
    }
    else if (fib_type == 5) {
        return fib_iterative_mod(n);
    }
    else if (fib_type == 6) {
        return fib_matrix_mod(n);
    }
    else {
        return 0;
    }
}

void fib_test_pow2(int end_val, int fib_type) {
    clock_t start, end;
    
    // test powers of 2, from 2^0 to 2^30
    for (int j = 0; j < end_val; j++) {
        int n_pow = (int)pow(2, j);
        start = clock();
        unsigned int n = fib_func(fib_type, n_pow);
        end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d,%d,%f\n", n_pow, n, time_spent);
    }
}

void fib_test_n(int end_val, int fib_type) {
    clock_t start, end;
    int n;
    
    for (int i = 0; i < end_val; i++) {

        start = clock();
        
        n = fib_func(fib_type, i);
        
        end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d,%d,%f\n", i, n, time_spent);
    }
}
