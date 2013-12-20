/**
 * projecteuler.net
 * Problem 43
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up
 * of each of the digits 0 to 9 in some order, but it also has a rather
 * interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note
 * the following:
 *
 * d2d3d4=406 is divisible by 2
 * d3d4d5=063 is divisible by 3
 * d4d5d6=635 is divisible by 5
 * d5d6d7=357 is divisible by 7
 * d6d7d8=572 is divisible by 11
 * d7d8d9=728 is divisible by 13
 * d8d9d10=289 is divisible by 17
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

#include "primes.h"

template <typename T, class ForwardIterator>
const T get_value(ForwardIterator first, ForwardIterator last) {
  T ret;
  std::stringstream ss;
  for (auto it = first; it != last; ++it ) {
    ss << *it;
  }
  ss >> ret;
  return ret;
}

bool unnamed_property(std::vector<int> digits) {
  auto start = std::begin(digits) + 1;
  auto end = start + 3;
  euler::prime_generator<int> primes;

  // special case
  if (get_value<int>(start++, end++) % 2 != 0) return false;

  for (; end <= std::end(digits); ++start, ++end) {
    int value = get_value<int>(start, end);
    if (value % *primes != 0) return false;
    ++primes;
  }

  return true;
}

int main(int argc, char *argv[]) {
  long sum = 0;
  std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  do {
    if (unnamed_property(digits)) {
      sum += get_value<long>(std::begin(digits), std::end(digits));
    }
  } while (std::next_permutation(std::begin(digits), std::end(digits)));

  std::cout << "\nsum: " << sum << std::endl;
  return 0;
}
