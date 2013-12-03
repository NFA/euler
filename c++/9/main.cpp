/**
 * projecteuler.net
 * Problem 9
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c,
 * for which,
 *
 * a^2 + b^2 = c^2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <iostream>

bool is_pythagorean(int a, int b, int c) {
  return ((a * a) + (b * b)) == (c * c);
}

bool found_it(int a, int b, int c) {
  return (a + b + c) == 1000;
}

int main(int argc, char *argv[]) {
  int a, b, c;
  for ( c = 3; c <= 1000; c++) {
    for ( b = 2; b < c; b++) {
      for ( a = 1; a < b; a++) {
        if (is_pythagorean(a, b, c) && found_it(a, b, c)) {
          goto end;
        }
      }
    }
  }
end:
  std::cout << a*b*c << std::endl;
  return 0;
}
