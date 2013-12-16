/**
 * projecteuler.net
 * Problem 33
 *
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician
 * in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
 * is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less
 * than one in value, and containing two digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms,
 * find the value of the denominator.
 */

#include <iostream>
#include <vector>
#include <sstream>

bool is_invalid(int numerator, int denominator) {
    if (numerator > denominator) return true;
    if (numerator > 99 || denominator > 99) return true;
    if (numerator < 10 || denominator < 10) return true;
    if (numerator % 10 == 0 && denominator % 10 == 0) return true;
    return false;
}

bool is_curious_fraction(int numerator, int denominator) {
  if (is_invalid(numerator, denominator)) return false;

  char num[2], den[2];
  num[0] = static_cast<char>(numerator   / 10 + '0');
  num[1] = static_cast<char>(numerator   % 10 + '0');
  den[0] = static_cast<char>(denominator / 10 + '0');
  den[1] = static_cast<char>(denominator % 10 + '0');

  int numerator2, denominator2;

  if (num[0] == den[0]) {
    numerator2 = num[1] - '0';
    denominator2 = den[1] - '0';
  }
  else if (num[1] == den[0]) {
    numerator2 = num[0] - '0';
    denominator2 = den[1] - '0';
  }
  else if (num[0] == den[1]) {
    numerator2 = num[1] - '0';
    denominator2 = den[0] - '0';
  }
  else if (num[1] == den[1]) {
    numerator2 = num[0] - '0';
    denominator2 = den[0] - '0';
  }
  else {
    return false;
  }
  if (numerator2 == 0 || denominator2 == 0) return false;

  double result, cresult;
  result = (static_cast<double>(numerator) / denominator);
  cresult = (static_cast<double>(numerator2) / denominator2);

  bool is_curious = result == cresult;
  if (is_curious) {
    std::cout << numerator << "/" << denominator << " (" << result << ") ";
    std::cout << " = ";
    std::cout << numerator2 << "/" << denominator2 << " (" << cresult << ") ";
    std::cout << std::endl;
  }
  return is_curious;
}

int main(int argc, char *argv[]) {
  int denominator = 1, numerator = 1;
  for (int n = 10; n <= 99; ++n) {
    for (int d = 10; d <= 99; ++d) {
      if (n == d) continue;

      if (is_curious_fraction(n, d)) {
        numerator *= n;
        denominator *= d;
      }
    }
  }
  std::cout << numerator << " / " << denominator;
  std::cout << " = ";
  std::cout << static_cast<double>(numerator)/denominator;
  std::cout << std::endl;
  std::cout << "value of denominator = ";
  std::cout << 1L/(static_cast<double>(numerator)/denominator);
  std::cout << std::endl;
  return 0;
}
