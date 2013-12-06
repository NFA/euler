#include <iostream>

namespace euler {

template <typename T>
void print(std::vector<T> vec, std::ostream& out = std::cout, bool fold = false) {
  out << "{ ";
  if (!fold) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(out, " "));
  } else {
    std::copy(vec.begin(), vec.begin() + 5, std::ostream_iterator<T>(out, " "));
    out << " ... ";
    std::copy(vec.end() - 5, vec.end(), std::ostream_iterator<T>(out, " "));
  }
  out << "}";
}

} /* namespace euler */
