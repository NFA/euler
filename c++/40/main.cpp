/**
 * projecteuler.net
 * Problem 40
 *
 * An irrational decimal fraction is created by concatenating the positive
 * integers:
 *
 * 0.123456789101112131415161718192021...
 *
 * It can be seen that the 12th digit of the fractional part is 1.
 *
 * If dn represents the nth digit of the fractional part, find the value of the
 * following expression.
 *
 * d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
 */

#include <iostream>
#include <string>
#include <sstream>

void brute_force() {
  std::stringstream ss;
  int i = 1;
  while (ss.tellp() <= 1000000) {
    ss << i;
    ++i;
  }
  std::string meh(ss.str());
  int product = 1;
  for (size_t n = 1; n <= 1000000; n*=10) {
    int number = meh[n - 1] - '0';
    std::cout << number << " ";
    product *= number;
  }
  std::cout << std::endl << product << std::endl;
}

int main(int argc, char *argv[]) {
  brute_force();
  return 0;
}
