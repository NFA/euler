/**
 * projeteuler.net
 * Problem 41
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is
 * also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 */
#include <iostream>
#include <algorithm>
#include "primes.h"
#include "pandigital.h"

template <typename T>
int digits(T num) {
  int digits = 0;
  while (num) {
    num /= 10;
    digits++;
  }
  return digits;
}

template <typename T>
int get_hex(T num) {
  int ret = 0;
  int dig = digits(num);
  while (dig--) {
    ret = ret | (1 << dig);
  }
  return ret;
}


int main(int argc, char *argv[]) {
  euler::prime_generator<long> primes;
  long max = 0;
  while (*primes < 9876543) {
    if (euler::is_pandigital(*primes, get_hex(*primes)))
      max = std::max(max, *primes);
    ++primes;
  }
  std::cout << "max: " << max << std::endl;
  return 0;
}
