/**
 * projecteuler.net
 * Problem 44
 *
 * Pentagonal numbers are generated by the formula, P(n)=n(3n−1)/2. The first ten
 * pentagonal numbers are:
 *
 * 1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...
 *
 * It can be seen that P(4) + P(7) = 22 + 70 = 92 = P(8). However, their difference,
 * 70 − 22 = 48, is not pentagonal.
 *
 * Find the pair of pentagonal numbers, P(j) and P(k), for which their sum and
 * difference are pentagonal and D = |P(k) − P(j)| is minimised; what is the value
 * of D?
 */

#include <iostream>
#include <cmath>
#include <numeric>
#include "pentagonal.h"

bool is_penta(int num) {
  double result = (std::sqrt(24 * num + 1) + 1.0) / 6.0;
  return std::floor(result) == result;
}



int main(int argc, char *argv[]) {
  int global_min = std::numeric_limits<int>::max();
  euler::pentagonal_generator<int> pentagons;
  for (int i = 0; i <= 10000; ++i) {
    ++pentagons;
  }
  std::cout << "Generated 10000 pentagonal numbers." << std::endl;

  size_t sz = pentagons.size();

  for (size_t j = 0; j < sz; ++j) {
    for (size_t k = j; k < sz; ++k) {

      int max = std::max(pentagons[k], pentagons[j]);
      int min = std::min(pentagons[k], pentagons[j]);
      int diff = max - min;
      if (!is_penta(max + min)) continue;
      if (!is_penta(diff)) continue;

      if (diff < global_min) {
        global_min = min;
        std::cout << "Found new global minumum for P(" << j << ") = " << pentagons[j];
        std::cout << " and P(" << k << ") = " << pentagons[k];
        std::cout << ", D = " << max - min << std::endl;
      }

    }

  }

  return 0;
}




