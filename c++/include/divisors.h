#include <vector>
#include <cmath>
#include "primes.h"

namespace euler {

template <typename T = int>
std::vector<T> get_proper_divisors(T number) {
  int limit = static_cast<int>(std::sqrt(number)) + 1;
  std::vector<T> divisors;
  std::vector<T> pair;

  for (T i = 1; i < limit; ++i) {
    if (number % i == 0) {
      divisors.push_back(i);
    }
  }

  for (const auto& num: divisors) {
    if (num != 1) {
      pair.push_back(number / num);
    }
  }

  if (limit * limit == number)
    divisors.push_back(limit);

  divisors.insert(end(divisors), begin(pair), end(pair));
  std::sort(begin(divisors), end(divisors));
  divisors.erase(std::unique(begin(divisors), end(divisors)), end(divisors));

  return divisors;
}

template <typename T = int>
std::vector<T> get_divisors(T number) {
  std::vector<T> divisors = get_proper_divisors<T>(number);
  divisors.push_back(number);
  return divisors;
}


} /* namespace euler*/
