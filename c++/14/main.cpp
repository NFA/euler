/**
 * projecteuler.net
 * Problem 14
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class Collatz {
public:
  Collatz() : node(1), chain({1}) {
  }
  Collatz(long i) : node(i) {
    chain.push_back(i);
    do {
      next_collatz_term();
      chain.push_back(node);
    } while(node != 1);
  }
  size_t chain_size() const { return chain.size(); }
  bool operator<(const Collatz& other) const {
    return chain_size() < other.chain_size();
  }
private:
  long node;
  std::vector<long> chain;
  friend std::ostream & operator<<(std::ostream& out, const Collatz& col);
  void next_collatz_term() {
    if (node % 2 == 0) {
      node = node / 2;
    } else {
      node = 3 * node + 1;
    }
  }

};

std::ostream& operator<<(std::ostream& out, const Collatz& col) {
    out << "Size(" << col.chain_size() << "): ";
    for (const auto& term: col.chain) {
      if (term != 1)
        out << term <<" -> ";
      else
        out << term;
    }
    out << std::endl;
    return out;
}

int main(int argc, char *argv[]) {
  Collatz max {};
  for (int i = 1;i < 1000000; ++i) {
    Collatz tmp(i);
    max = std::max(max, tmp);
  }
  std::cout << max << std::endl;
  return 0;
}
