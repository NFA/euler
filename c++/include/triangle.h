#include <vector>

namespace euler {

/**
 * The nth term of the sequence of triangle numbers is given by, t(n) = (n(n+1))/2;
 * so the first ten triangle numbers are:
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55,
 */
template <typename T>
T nth(T ordinal) {
    return (ordinal * (ordinal + T(1)) ) / T(2);
}

template <typename T>
class triangle_generator {
public:
  triangle_generator() : current(T(1)), count(1) {
    triangles.push_back(current);
  }
  T operator*() { return current; }
  triangle_generator &operator++() {
    current = nth<T>(++count);
    triangles.push_back(current);
    return *this;
  }
  bool is_triangle(T test) {
    if (current == test) {
      return true;
    }
    if (current > test) {
      return check_triangle(test);
    }

    do {
      this->operator++();
    } while (current < test);

    if (triangles.back() == test) {
      return true;
    }
    return false;
  }


private:
  T current;
  int count;
  std::vector<T> triangles;
  bool check_triangle(T test) {
    auto srch = find(std::begin(triangles), std::end(triangles), test);
    return srch != std::end(triangles);
  }
};

} /* namespace euler */
