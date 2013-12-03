/**
 * projecteuler.net
 * Problem 20
 *
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 */
#include <iostream>
#include <string>
#include <deque>

std::string to_string(std::deque<int> number) {
  bool start = false;
  std::string ret;
  for (auto it = number.cbegin(); it != number.cend(); ++it) {
    if (!start && *it != 0) start = true;
    if (start)
      ret += std::to_string(*it);
  }
  return ret;
}


std::deque<int> factorial(int multiplier, std::deque<int> number = {0, 1}) {
  if (!multiplier) return number;

  int carryover = 0;

  // need to grow the deque to fit the numbers,
  int grow = 2;
  while (grow--)
    number.push_front(0);

  for (size_t idx = number.size() - 1; idx; --idx) {
    number[idx] = (number[idx] * multiplier) + carryover;
    carryover = number[idx] / 10;
    number[idx] %= 10;
  }
  return factorial(multiplier - 1, number);
}

int main(int argc, char *argv[]) {
  auto x = to_string(factorial(100));
  int sum = 0;
  for (const char& digit: x) {
    sum += digit - '0';
  }
  std::cout << sum << std::endl;

  return 0;
}
