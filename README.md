# Fibonacci Numbers

Program to compute the Fibonacci numbers, where F<sub>0</sub> = 0, F<sub>1</sub> = 1, and for all n >= 2, F<sub>n</sub> is defined as F<sub>n-1</sub> + F<sub>n-2</sub>.

The repo contains 3 algorithms to compute the Fibonacci numbers:
- `fib_recursive.cpp`: recursive implementation (non-memoized), runs in O(2<sup>n</sup>) time
- `fib_iterative.cpp`: iterative solution, runs in O(n) time and O(1) space
- `fib_matrix.cpp`: matrix solution, runs in O(log n) time

The algorithms each contain `mod` implementations where computations are done mod 65536 to prevent integer overflow.

Time calculations can be found in `Fibonacci_Times.ipynb`.
