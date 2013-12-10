#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>

#include "euler.h"

namespace euler {
// TODO: add in rest of the arithmetic
class BigNum {
public:
  BigNum(std::string number) : bignum(number) {
    std::reverse(std::begin(bignum), std::end(bignum));
    std::transform(std::begin(bignum), std::end(bignum), std::begin(bignum),
      [](char i) { return i - '0'; });
  }

  BigNum(int number) : BigNum(std::to_string(number)) { }
  BigNum() : BigNum(0) { }
  BigNum& operator+=(const BigNum& rhs) {
    //this->bignum
    return *this;
  }
  int digits() {
    std::stringstream ss;
    ss << *this;
    return static_cast<int>(ss.str().size());
  }
private:
  std::string bignum;
  enum sign { PLUS, MINUS};
  friend inline BigNum operator+(const BigNum& lhs, const BigNum& rhs);
  friend std::ostream& operator<<(std::ostream& out, const BigNum& bignum);
};

void zero_pad(std::string& str, size_t padding) {
  size_t to_add = padding - str.size();
  if (to_add == 0) return;

  str = str + std::string(padding, static_cast<char>(0));
}

inline BigNum operator+(const BigNum& BN_lhs, const BigNum& BN_rhs) {
  int carry = 0;

  std::string left  = BN_lhs.bignum;
  std::string right = BN_rhs.bignum;
  size_t padding = std::max(BN_lhs.bignum.size(), BN_rhs.bignum.size()) + 1;

  zero_pad(left, padding);
  zero_pad(right, padding);

  std::string result(padding, static_cast<char>(0));

  //check signs and do subtraction if +/- or -/+

  for (size_t i = 0; i < padding; i++) {
    result[i] = (carry + left[i] + right[i]) % 10;
    carry     = (carry + left[i] + right[i]) / 10;
  }

  BigNum ret;
  ret.bignum = result;

  return ret;
}


std::ostream& operator<<(std::ostream& out, const BigNum& number) {
  std::string copy(number.bignum);
  std::reverse(std::begin(copy), std::end(copy));
  size_t start = copy.find_first_not_of(static_cast<char>(0));
  start = start == std::string::npos ? 0 : start;
  std::transform(std::begin(copy), std::end(copy), std::begin(copy),
      [](char i) { return i + '0'; });
  out << copy.substr(start, std::string::npos);
  return out;
}

} /* namspace euler */

