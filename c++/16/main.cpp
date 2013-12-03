/**
 * projecteuler.net
 * Problem 16
 *
 * 2^215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 */

#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {
  double x = std::pow(2, 1000); // it fits
  int sum = 0;
  std::string number = std::to_string(x);
  for(const char& digit : number) {
    if (digit == '.') break;
    sum += digit - '0';
  }
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
