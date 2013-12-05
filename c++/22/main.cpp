/**
 * projectuler.net
 * Problem 21
 *
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
 * containing over five-thousand first names, begin by sorting it into alpha-
 * betical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name
 * score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is
 * worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */
#include <iostream>
#include <fstream>
#include <vector>
#include "euler.h"

int word_points(std::string name) {
  int sum = 0;
  for (const char& letter: name) {
    sum += letter - 'A' + 1;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  std::ifstream file("../names.txt");
  std::vector<std::string> names;
  int score = 0;

  if (!file.is_open()) {
    std::cerr << "Couldn't find names.txt." << std::endl;
    return 0;
  }

  while (file) {
    std::string name;
    file.ignore(256, '"'); //  "
    std::getline(file, name, '"'); // name until "
    names.push_back(name);
    file.ignore(256, ','); // ",
   }

  file.close();

  std::sort(begin(names), end(names));

  for (size_t i = 0; i < names.size(); ++i) {
    score += static_cast<int>(i) * word_points(names[i]);

  }
  std::cout << "sum: " << score << std::endl;
  return 0;
}
