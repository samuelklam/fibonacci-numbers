//
//  main.cpp
//
//  Driver function to run fibonacci time tests
//

#include <stdio.h>
#include "fib_test.hpp"

int main(int argc, const char * argv[]) {
    printf("Fib_number,Fib_value,Time_spent\n");
    fib_test_n(10, 3);
    fib_test_pow2(10, 3);
    return 0;
}
