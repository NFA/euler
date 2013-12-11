/**
 * projecteuler.net
 * Problem 29
 *
 * Surprisingly there are only three numbers that can be written as the sum of
 * fourth powers of their digits:
 *
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 * As 1 = 1^4 is not a sum it is not included.
 *
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 * Find the sum of all the numbers that can be written as the sum of fifth
 * powers of their digits.
 */
#include <iostream>
#include <vector>
#include <cmath>




std::vector<int> get_parts(int num) {
  std::vector<int> ret;
  while (num) {
    int digit = num % 10;
    ret.push_back(digit);
    num /= 10;
  }
  return ret;
}

int digit_fifth_power(int num) {
  int sum = 0;
  auto parts = get_parts(num);
  for (auto& part: parts) {
    sum += std::pow(part, 5);
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 2; i <= 1000000; ++i) {
    if (i == digit_fifth_power(i)) {
      std::cout << i << std::endl;
      sum += i;
    }
  }
  std::cout << "\nsum: " << sum << std::endl;
  return 0;
}
