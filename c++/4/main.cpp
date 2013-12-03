/**
 * projecteuler.net
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <iostream>
#include <string>

bool is_palindrome(std::string arg) {
  std::string reversed(arg.rbegin(), arg.rend());
  return arg == reversed;
}

bool is_palindrome(int arg) {
  return is_palindrome(std::to_string(arg));
}

int brute_force() {
  int max = 0;
  for (int number_one = 100; number_one < 1000; number_one++) {
    for (int number_two = 100; number_two < 1000; number_two++) {
      int product = number_one * number_two;
      if (is_palindrome(product) && product > max)
        max = product;
    }
  }
  return max;
}


int main(int argc, char *argv[]) {

  std::cout << brute_force() << std::endl;
  return 0;
}
