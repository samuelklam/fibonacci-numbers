//
//  fib_test.hpp
//
//  Created by Samuel K. Lam on 3/22/17.
//  Copyright © 2017 Samuel K. Lam. All rights reserved.
//

#ifndef fib_test_hpp
#define fib_test_hpp

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "fib_recursive.hpp"
#include "fib_iterative.hpp"
#include "fib_matrix.hpp"

/*
 * Calls appropriate fibonacci function and calculates fib value
 * @param fib_type : 1, 2, 3, 4, 5, 6 denotes recursive, iterative, matrix, rec_mod, it_mod, matrix_mod respectively
 * @param n : fibonacci # to compute
 * @return fibonacci value for fibonacci #
 */
int fib_func(int fib_type, int n);

/*
 * Computes the time spent to calculate fibonacci by power of 2s from 1 to end_val
 * @param end_val : end fibonacci # to test up to
 * @param fib_type : the appropriate fibonacci function to call from [1, 6]
 */
void fib_test_pow2(int end_val, int fib_type);

/*
 * Computes the time spent to calculate fibonacci from [1, end_val]
 * @param end_val : end fibonacci # to compute up to
 * @param fib_type : the appropriate fibonacci function to call from [1, 6]
 */
void fib_test_n(int end_val, int fib_type);

#endif /* fib_test_hpp */
