/**
 * projecteuler.net
 * Problem 21
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and
 * each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#include <numeric>
#include "divisors.h"
#include "euler.h"

bool amicable(int number) {
  auto div_a = euler::get_proper_divisors(number);
  int d_a = std::accumulate(begin(div_a), end(div_a), 0);

  auto div_b = euler::get_proper_divisors(d_a);
  int d_b = std::accumulate(begin(div_b), end(div_b), 0);

  bool amicable = (d_b == number && d_a != d_b);

  return amicable;
}

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 1; i < 10000; ++i) {
    if (amicable(i)) {
      sum += i;
    }
  }
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
