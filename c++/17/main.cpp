/**
 * projectuler.net
 * Problem 17
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 */



#include <iostream>

std::string ones(int number) {
  std::string ret;
  switch (number) {
    case 0: ret = ""; break;
    case 1: ret = "one"; break;
    case 2: ret = "two"; break;
    case 3: ret = "three"; break;
    case 4: ret = "four"; break;
    case 5: ret = "five"; break;
    case 6: ret = "six"; break;
    case 7: ret = "seven"; break;
    case 8: ret = "eight"; break;
    case 9: ret = "nine"; break;
  }
  return ret;
}

std::string tens(int number) {
  std::string ret;
  switch (number) {
    case 2: ret = "twenty"; break;
    case 3: ret = "thirty"; break;
    case 4: ret = "forty"; break;
    case 5: ret = "fifty"; break;
    case 6: ret = "sixty"; break;
    case 7: ret = "seventy"; break;
    case 8: ret = "eighty"; break;
    case 9: ret = "ninety"; break;
  }
  return ret;
}

std::string teenies(int number) {
  std::string ret;
  switch (number) {
    case 10: ret = "ten"; break;
    case 11: ret = "eleven"; break;
    case 12: ret = "twelve"; break;
    case 13: ret = "thirteen"; break;
    case 14: ret = "fourteen"; break;
    case 15: ret = "fifteen"; break;
    case 16: ret = "sixteen"; break;
    case 17: ret = "seventeen"; break;
    case 18: ret = "eighteen"; break;
    case 19: ret = "nineteen"; break;
  }
  return ret;
}

std::string add_and(bool flag) {
  return flag ? std::string("and") : std::string();
}

std::string integer_to_string(int number) {
  int tmp;
  std::string ret;
  bool add = false, init = false;
  if ((tmp = number / 1000)) {
    ret += ones(tmp) + std::string("thousand");
    number %= 1000;
    init = true;
  }
  if ((tmp = number / 100)) {
    ret += ones(tmp) + std::string("hundred");
    number %= 100;
    init = true;
  } else {
    add = true;
  }
  if ((tmp = number / 10)) {
    //std::cout << "10: " << tmp << std::endl;
    if (tmp == 1) {
      ret += add_and(init) + teenies(number);
      number = 0;
      init = true;
    } else {
      ret += add_and(init) + tens(tmp);
      init = true;
    }
    number %= 10;
    add = false;
  } else {
    add = true;
  }
  if (number) {
    ret += add_and(add & init) + ones(number % 10);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 1; i <= 1000; ++i) {
    sum += integer_to_string(i).size();
  }
  std::cout << "sum: " << sum << std::endl;
  return 0;
}
