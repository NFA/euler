/**
 * projecteuler.net
 *
 * What is the first term in the Fibonacci sequence to contain 1000 digits?
 */
#include <iostream>
#include "fibonacci.h"
#include "bignum.h"

int main(int argc, char *argv[]) {
  euler::fibonacci_generator<euler::BigNum> fib;
  int stop = 1000, nth = 1;
  while ((*fib).digits() < stop) {
    ++fib;
    ++nth;
  }
  std::cout <<"\nNumber " << nth << " contains " << (*fib).digits() << " digits. " << std::endl;
  return 0;
}
