/**
 * projecteuler.net
 * Problem 23
 *
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than
 * n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However, this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 */
#include <iostream>
#include <numeric>
#include <iterator>
#include <vector>
#include "divisors.h"
#include "euler.h"

bool is_abundant(int num) {
  auto div = euler::get_proper_divisors(num);
  int sum = std::accumulate(begin(div), end(div), 0);

  return sum > num;
}

std::vector<int> get_abundant_numbers(int max) {
  std::vector<int> ret;
  for (int i = 1; i <= max; ++i) {
    if (is_abundant(i))
      ret.push_back(i);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  std::vector<int> abundant_numbers = get_abundant_numbers(28123);
  std::vector<int> abundant_sums;
  std::vector<int> result;

  int sum;

  // 1. generate all abundant numbers up to 28123
  // 2. generate all sums of abundant numbers where the result < 28123
  // 3. sort and remove duplicates.
  // 4. check each n from 1...28123 if they exist in container from (2)
  //    a) if no, add to result vector
  // 5. sum result vector

  for (auto outer = begin(abundant_numbers); outer != end(abundant_numbers); ++outer) {
    for (auto inner = outer; inner != end(abundant_numbers); ++inner) {
      int tmp = *outer + *inner;
      if (tmp > 28123) {
        break;
      } else {
        abundant_sums.push_back(tmp);
      }
    }
  }

  std::sort(begin(abundant_sums), end(abundant_sums));
  abundant_sums.erase(std::unique(begin(abundant_sums), end(abundant_sums)), end(abundant_sums));

  auto start = begin(abundant_sums);
  for (int i = 1; i <= 28123; ++i) {
    auto it = std::find(start, end(abundant_sums), i);
    if (it == end(abundant_sums)) {
      result.push_back(i);
    } else {
      start = it;
    }
  }

  sum = std::accumulate(begin(result), end(result), 0);
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
