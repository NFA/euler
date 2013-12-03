/**
 * projecteuler.net
 * Problem 10
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */
#include <iostream>
#include "primes.h"

int main(int argc, char *argv[]) {
  euler::prime_generator<int> primes;
  long sum = 2;
  do  {
    sum += *primes;
  } while (*(++primes) < 2000000);

  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
