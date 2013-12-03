/**
 * projecteuler.net
 * Problem 7
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <iostream>
#include "primes.h"

template<typename T>
T nth_prime(int n) {
  euler::prime_generator<T> primes;
  for(int i=1; i<(n-1); ++i) {
    ++primes;
  }
  return *primes;
}

int main(int argc, char *argv[]) {
  std::cout << nth_prime<long>(10001) << std::endl;
  return 0;
}
