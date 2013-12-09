

namespace euler {

template <typename T>
class fibonacci_generator {
public:
  fibonacci_generator() : current(T(1)) {
    fibonacci[0] = T(0);
    fibonacci[1] = T(1);
  }
  T operator*() { return current; }
  fibonacci_generator &operator++() {
    current = fibonacci[0] + fibonacci[1];
    fibonacci[0] = fibonacci[1];
    fibonacci[1] = current;

    return *this;
  }

private:
  T current;
  T fibonacci[2];
};

} /* namespace euler */
