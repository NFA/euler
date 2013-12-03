/**
 * projecteuler.net
 * Problem 6
 *
 * The sum of the squares of the first ten natural numbers is,
 *
 * 1^2 + 2^2 + ... + 102 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 *
 * (1 + 2 + ... + 10)^2 = 552 = 3025
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */
#include <iostream>

template <int N>
constexpr int sum_of_square() {
 return N*N + sum_of_square<N-1>();
}

template <>
constexpr int sum_of_square<1>() {
 return 1;
}

template <int N>
constexpr int sum() {
 return N + sum<N-1>();
}

template <>
constexpr int sum<1>() {
 return 1;
}

template <int N>
constexpr int square_of_sum() {
  return sum<N>() * sum<N>();
}

template <int N>
constexpr int compile_time() {
  return square_of_sum<N>() - sum_of_square<N>();
}

int run_time(int num) {
  // from formulas of (sum of i from 1 to n)^2 and
  //                  (sum of i^2 from 1 to n)
  return (num * (3 * num + 2) * (num * num - 1)) / 12;
}

int main(int argc, char *argv[]) {
  std::cout << compile_time<100>() << std::endl;
  std::cout << run_time(100) << std::endl;
  return 0;
}
