/**
 * projecteuler.net
 * Problem 34
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <iostream>

// restriction 1-9
int factorial (int number) {
  switch (number) {
    case 0: return 1;
    case 1: return 1;
    case 2: return 2;
    case 3: return 6;
    case 4: return 24;
    case 5: return 120;
    case 6: return 720;
    case 7: return 5040;
    case 8: return 40320;
    case 9: return 362880;
    default: return -1;
  }
}


int factorial_sum(int number) {
  int sum = 0;
  int n = number;
  while (n) {
    sum += factorial(n % 10);
    n /= 10;
  }
  return sum;
}

// w/o space reduction you get all results in this loop
int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 10; i <= 10000000; ++i) {
    if (factorial_sum(i) == i) {
      sum += i;
      std::cout << i << " ";
    }
  }
  std::cout << "\nsum: " << sum << std::endl;
  return 0;
}
