/**
 * projecteuler.net
 * Problem 35
 *
 * The number, 197, is called a circular prime because all rotations of the
 * digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37,
 * 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "euler.h"
#include "primes.h"

bool is_primes(std::vector<int> numbers) {
  for(const auto& num: numbers) {
    if (!euler::is_prime(num)) return false;
  }
  return true;
}

std::vector<int> get_rotations(int number) {
  std::vector<int> ret {};
  std::string rot(std::to_string(number));
  auto len = static_cast<std::string::difference_type>(rot.length());

  while (len--) {
    std::rotate(std::begin(rot), std::begin(rot) + 1, std::end(rot));
    ret.push_back(std::stoi(rot));
  }
  return ret;
}

int main(int argc, char *argv[]) {
  euler::prime_generator<int> primes;
  int num = 1; // 2 is circular but not yielded by generator

  while (*primes < 1000000) {
    if (is_primes(get_rotations(*primes))) {
      std::cout << *primes << " ";
      num += 1;
    }
    ++primes;
  }
  std::cout << "\n#circular primes: " << num << std::endl;
  return 0;
}
