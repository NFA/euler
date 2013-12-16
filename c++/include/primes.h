#ifndef __PRIME_GENERATOR_H__
#define __PRIME_GENERATOR_H__
#include <vector>
#include <map>

namespace euler {
// Prime generator based on the Sieve of Eratosthenes
// from:
// http://stackoverflow.com/questions/231381/is-this-prime-generator-inefficient-c
// starts from 3
template<typename T = int, typename M = std::map<T, T>>
class odd_prime_generator {
public:
  using prime_iterator = typename M::iterator;

  odd_prime_generator() : current(1), skips() { operator++(); }

  T operator*() { return current; }
  odd_prime_generator &operator++() {
    prime_iterator i;
    while ((i = skips.find(current += 2)) != skips.end()) {
      T skip = i->second, next = current + skip;
      skips.erase(i);
      for (prime_iterator j = skips.find(next);
           j != skips.end();
           j = skips.find(next += skip)) {}
      skips[next] = skip;
    }
    skips[current * current] = 2 * current;
    return *this;
  }
private:
  T current;
  M skips;
};


template<typename T = int, typename M = std::map<T, T>>
class prime_generator {
public:
  using prime_iterator = typename M::iterator;

  prime_generator() : current(1), skips(), base() {
    q = (*base) * (*base);
    operator++();
  }

  T operator*() { return current; }
  prime_generator &operator++() {
    while (true) {
      current += 2;
      if (current == q) {
        add_a_skip(current + 2 * (*base), 2 * (*base));
        ++base;
        q = (*base) * (*base);
        continue;
      }
      prime_iterator i = skips.find(current);
      if (i == skips.end()) {
        break;
      }
      T skip = i->second, next = current + skip;
      skips.erase(i);
      add_a_skip(next, skip);
    }
    return *this;
  }
  T show_base() { return *base; }
private:
  T current, q;
  M skips;
  odd_prime_generator<T> base;
  void add_a_skip(T next, T skip) {
    for (prime_iterator j = skips.find(next);
                        j != skips.end();
                        j = skips.find( next += skip)) {}
    skips[next] = skip;
  }
};

template <typename T>
std::vector<T> get_prime_factors(T number) {
  std::vector<T> factors;
  euler::prime_generator<T> primes;

  long mod;
  // Special case for 2
  do {
    mod = number % 2;
    if (mod == 0) {
      number = number / 2;
      factors.push_back(2);
    }
    else {
      break;
    }
  } while (true);

  // primes 3, 5, 7, ...
  do {
     mod = number % *primes;

    if (mod == 0) {
      number = number / (*primes);
      factors.push_back(*primes);
    } else {
      ++primes;
    }
  } while (number != 1);
  return factors;
}


bool check_prime(const std::vector<int> &primes, int number) {
  auto srch = find(std::begin(primes), std::end(primes), number);
  return srch != std::end(primes);
}

bool is_prime(int number) {
  static std::vector<int> prime_vector{2};
  static euler::prime_generator<int> primes;

  if (prime_vector.back() > number) {
    return check_prime(prime_vector, number);
  }
  int newp = 0;
  while (prime_vector.back() < number) {
    prime_vector.push_back(*primes);
    ++primes;
    ++newp;
  }
  return check_prime(prime_vector, number);
}

}
#endif

