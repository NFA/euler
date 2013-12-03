/**
 * projecteuler.net
 * Problem 1
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>

 int return_if_multiple_of_3_5(int num) {
  return (num % 3 == 0 || num % 5 == 0) ? num : 0;
 }

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i=0; i< 1000; i++) {
    sum += return_if_multiple_of_3_5(i);
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
