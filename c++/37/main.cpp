/**
 * projecteuler.net
 * Problem 36
 *
 * The number 3797 has an interesting property. Being prime itself, it is
 * possible to continuously remove digits from left to right, and remain prime
 * at each stage: 3797, 797, 97, and 7. Similarly we can work from right to
 * left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to
 * right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */
#include <iostream>
#include "primes.h"

bool trim_and_check_left(int number) {
  if (!euler::is_prime(number)) return false;

  if (number < 10) return true;

  std::string num(std::to_string(number));
  std::string new_num(std::begin(num) + 1, std::end(num));
  int next = std::stoi(new_num);
  return trim_and_check_left(next);

}

bool trim_and_check_right(int number) {
  if (!euler::is_prime(number)) return false;

  if (number < 10) return true;

  std::string num(std::to_string(number));
  std::string new_num(std::begin(num), std::end(num) - 1);
  int next = std::stoi(new_num);
  return trim_and_check_right(next);

}

bool is_truncatable_prime(int number) {
  return trim_and_check_left(number) && trim_and_check_right(number);
}

int main(int argc, char *argv[]) {
  int sum = 0;
  int n = 0;
  euler::prime_generator<int> primes;
  while (n < 11) {
    int one_digit = *primes % 10;
    if (*primes > 7 && (one_digit == 3 || one_digit == 7) && is_truncatable_prime(*primes)) {
      sum += *primes;
      n += 1;
      std::cout << *primes << " ";
    }
    ++primes;
  }
  std::cout << "\nsum: " << sum << std::endl;
  return 0;
}
