/**
 * projecteuler.net
 * Problem 36
 *
 * The decimal number, 585 = 1001001001v2 (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in
 * base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include
 * leading zeros.)
 */
#include <iostream>

bool is_binary_palindrome(unsigned int num) {
  unsigned int tmp = 0;

  for (unsigned int i = num; i; i >>= 1) {
    tmp = ( tmp << 1) | ( i & 1);
  }

  return tmp == num;
}

bool is_integer_palindrome(unsigned int num) {
  std::string number(std::to_string(num));
  std::string num_reverse(number);

  std::reverse(std::begin(num_reverse), std::end(num_reverse));

  return number == num_reverse;
}

int main(int argc, char *argv[]) {
  unsigned int sum = 0;

  for (unsigned int i = 0; i < 1000000; ++i) {
    if (is_binary_palindrome(i) && is_integer_palindrome(i)) {
      std::cout << i << " ";
      sum += i;
    }
  }
  std::cout << "\nsum: " << sum << std::endl;
  return 0;
}
