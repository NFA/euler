/**
 * projecteuler.net
 * Problem 31
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the
 * digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1
 * through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity
 * can be written as a 1 through 9 pandigital.
 *
 * HINT: Some products can be obtained in more than one way so be sure to only
 * include it once in your sum.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <numeric>

// Reduce number space.
// Observations from different permutations of 9 numbers
// a * b = cdefghi [max = 9*8 = 72] - not possible
// ab * c = defghi [max = 87*9 = 783] - not possible
// abc * d = efghi [max = 876*9 = 7884] - not possible
// abcd * e = fghi [max = 8765*9 = 78885, min = 2345*1 = 2345] some are possible
// abcde * f = ghi [min = 23456*1 = 23456 ] - not possible
// ...
// ab * cd = efghi [min= 13*24 = 312, max = 96*87 = 8352] not possible
// abc * def = ghi [min = 135*246 = 33210] not possible
// ...
// ab * cde = fghi [min = 13*245=3185, max = 97*865 = 83905] some are possible
// ab * cdef = ghi [min = 13*2456= 31928] not possible
//
// ergo, space can be reduced to numbers of the form:
//   abcd * e = fghi (subspace 1)
//   ab * cde = fghi (subspace 2)

bool contains0(int x) {
  while (x) {
    if (x % 10 == 0) {
      return true;
    }
    x /= 10;
  }
  return false;
}

bool pandigital(int a, int b, int c) {
  if (c > 9871 || contains0(a) || contains0(b) || contains0(c)) {
    return false;
  }

  std::stringstream ss;
  std::string num_str;
  ss << a << b << c;
  num_str  = ss.str();


  std::vector<char> numbers(std::begin(num_str), std::end(num_str));
  std::sort(std::begin(numbers), std::end(numbers));
  numbers.erase(std::unique(std::begin(numbers), std::end(numbers)), std::end(numbers));

  return numbers.size() == 9;
}

int main(int argc, char *argv[]) {
  std::map<int, std::pair<int, int>> products;

  auto add_product = [&products](int a, int b) {
    int result = a * b;
      if (pandigital(a, b, result)) {
        if (products.find(result) == std::end(products)) {
          std::cout << a << " * " << b << " = " << result << std::endl;
          products[result] = {a, b};
        }
      }
  };


  // space 1
  for (int a = 1234; a <= 9876; ++a) {
    for (int b = 1; b <= 9; ++b) {
      add_product(a, b);
    }
  }

  // space 2
  for (int a = 12; a <= 98; ++a) {
    for (int b = 123; b <= 987; ++b) {
      add_product(a, b);
    }
  }

  int sum = std::accumulate(std::begin(products), std::end(products), 0,
    [](int total, const decltype(products)::value_type& data) {
      return total + data.first;
    });

  std::cout << "#unique pandigital identities =  " << products.size() << std::endl;
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
