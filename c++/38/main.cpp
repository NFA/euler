/**
 * projecteuler.net
 * Problem 38
 *
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We
 * will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
 * and 5, giving the pandigital, 918273645, which is the concatenated product of
 * 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 * the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */
#include <iostream>
#include <sstream>
#include "pandigital.h"

int multiply_with_n_and_concat(int number, int n) {
  std::stringstream ss;
  int ret;

  for (int i = 1; i <= n; ++i) {
    ss << (number * i);
  }
  ss >> ret;

  return ret;
}

int max_number(int n)
{
  static int num[8] = { 99999, 9999, 999, 9, 9, 9, 1, 1 };
  return num[n - 2];
}

int main(int argc, char *argv[]) {
  int max = 0;
  const int max_pan = 987654321;
  for (int n = 2; n < 10; ++n) {
    int loop_max = max_number(n);

    for (int val = 1; val <= loop_max; ++val) {
      int number = multiply_with_n_and_concat(val, n);
      if (number < max_pan && euler::is_pandigital(number)) {
        max = std::max(number, max);
      }
    }
  }
  std::cout << "max: " << max << std::endl;
  return 0;
}
