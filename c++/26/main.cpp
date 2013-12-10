/**
 * projecteuler.net
 * Problem 26
 *
 * A unit fraction contains 1 in the numerator. The decimal representation of
 * the unit fractions with denominators 2 to 10 are given:
 *
 * 1/2 =   0.5
 * 1/3 =   0.(3)
 * 1/4 =   0.25
 * 1/5 =   0.2
 * 1/6 =   0.1(6)
 * 1/7 =   0.(142857)
 * 1/8 =   0.125
 * 1/9 =   0.(1)
 * 1/10  =   0.1
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be
 * seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle
 * in its decimal fraction part.
 */
#include <iostream>
#include <bitset>

// find max #-digit recurring cycle in 1 / den
unsigned int drc(unsigned int den) {
  bool* seen = new bool[den]{};
  unsigned int cycles = 0;
  unsigned int numerator = 1;

  for(;;) {
    unsigned int remain;
    remain = numerator % den;
    if (seen[remain])
      break;

    seen[remain] = true;
    numerator = remain * 10;
    ++cycles;
    if (cycles > (den-1))
      break;
  }
  delete[] seen;
  return cycles;
}

int main(int argc, char *argv[]) {
  unsigned int max = 0, max_d;
  for (unsigned int d = 1000; d > 0; --d) {
    if (max > (d-1))
      break;

    unsigned int digits = drc(d);
    if ( digits > max) {
      max_d = d;
      max = digits;
    }
  }
  std::cout << "1/" << max_d << " has " << max << " recurring digits." << std::endl;
  return 0;
}
