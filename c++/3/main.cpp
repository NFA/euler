/**
 * projecteuler.net
 * Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <primes.h>

long max_prime_factor(long number) {
  int div = 2;
  while (number > 1) {
    if (0 == (number % div)) {
      number /= div;
      div--;
    }
    div++;
  }
  return div;
}

int main(int argc, char *argv[]) {
  long number = 600851475143;
  auto factors = euler::get_prime_factors<long>(number);
  auto max = factors.back();

  std::cout << max << std::endl;
  std::cout << max_prime_factor(number) << std::endl;
  return 0;
}
