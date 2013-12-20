/**
 * projecteuler.net
 * Problem 42
 *
 * The nth term of the sequence of triangle numbers is given by, tn = (n(n+1))/2;
 * so the first ten triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its alpha-
 * betical position and adding these values we form a word value. For example,
 * the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a
 * triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
 * containing nearly two-thousand common English words, how many are triangle
 * words?
 */

#include <iostream>
#include <cctype>
#include "triangle.h"
#include "file.h"

int word_value(std::string word) {
  int sum = 0;
  for (auto& letter : word) {
    sum += letter - 'A' + 1;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int count = 0;
  euler::triangle_generator<int> triangles;
  std::vector<std::string> file = euler::open_file("../words.txt");

  for (const auto& word : file) {
    if (triangles.is_triangle(word_value(word))) {
      count += 1;
    }
  }
  std::cout << "\ncount: " << count << std::endl;
  return 0;
}
