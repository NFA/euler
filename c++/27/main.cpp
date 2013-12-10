/**
 * projecteuler.net
 * Problem 27
 *
 * Euler discovered the remarkable quadratic formula:
 *
 * n² + n + 41
 *
 * It turns out that the formula will produce 40 primes for the consecutive
 * values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is
 * divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible
 * by 41.
 *
 * The incredible formula  n² − 79n + 1601 was discovered, which produces 80
 * primes for the consecutive values n = 0 to 79. The product of the coefficients,
 * −79 and 1601, is −126479.
 *
 * Considering quadratics of the form:
 *
 * n² + an + b, where |a| < 1000 and |b| < 1000
 *
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |−4| = 4
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes for consecutive values of n,
 * starting with n = 0.
 */

#include <iostream>
#include <vector>

#include "primes.h"

bool check_prime(const std::vector<int> &primes, int number) {
  auto srch = find(std::begin(primes), std::end(primes), number);
  return srch != std::end(primes);
}

bool is_prime(int number) {
  static std::vector<int> prime_vector{2};
  static euler::prime_generator<int> primes;

  if (prime_vector.back() > number) {
    return check_prime(prime_vector, number);
  }
  int newp = 0;
  while (prime_vector.back() < number) {
    prime_vector.push_back(*primes);
    ++primes;
    ++newp;
  }
  return check_prime(prime_vector, number);
}

int count_primes(int a, int b) {
  int n;

  for (n = 0; ; ++n) {
    int number = n*n + a*n + b;

    if (!is_prime(number))
      break;
  }
  return n;
}

int main(int argc, char *argv[]) {
  int max = 0;
  std::pair<int, int> max_ab{0,0};

  //#pragma omp parallel for
  for (int a = -999; a < 1000; ++a) {
    for (int b = -999; b < 1000; ++b) {
      int num_primes = count_primes(a, b);

      if (num_primes > max) {
        max_ab = {a, b};
        max = num_primes;
      }
    }
  }
  std::cout << "(a = " << max_ab.first << ", b = " << max_ab.second
    << ") generated " << max << " primes." << std::endl;
  std::cout << "a * b = " << max_ab.first * max_ab.second << std::endl;
  return 0;
}
