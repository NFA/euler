#include <iostream>

namespace euler {

template <typename T>
void print(std::vector<T> vec, std::ostream& out = std::cout) {
  out << "{ ";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(out, " "));
  out << "}";
}

} /* namespace euler */
