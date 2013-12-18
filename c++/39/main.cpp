/**
 * projecteuler.net
 * Problem 39
 *
 * If p is the perimeter of a right angle triangle with integral length sides,
 * {a,b,c}, there are exactly three solutions for p = 120.
 *
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p ≤ 1000, is the number of solutions maximised?
 */
#include <iostream>
#include <utility>

int triangle_perimeter(int p, bool print = false) {
  int solutions = 0;
  for (int a = 1; a <= p/2; ++a) {
    for (int b = 1; b <= p/2; ++b) {
      int c = p - a - b;
      if ((a *a + b * b) == (c * c)) {
          solutions += 1;
          if (print) std::cout << "{" << a << "," << b << "," << c << "}" << std::endl;
      }
    }
  }
  return solutions / 2;
}

int main(int argc, char *argv[]) {
  std::pair<int, int> max_solutions;
  for (int p = 12; p <= 1000; ++p) {
    int val = triangle_perimeter(p);
    if (max_solutions.first < val) {
      max_solutions = { val, p };
    }
  }
  std::cout << "p = " << max_solutions.second << " is the maximum with ";
  std::cout << max_solutions.first << " solutions." << std::endl;
  return 0;
}
