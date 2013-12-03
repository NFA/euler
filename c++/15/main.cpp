/**
 * projecteuler.net
 * Problem 15
 *
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

#include <iostream>
#include <map>

#define SIZE 20

class Lattice {
public:
  Lattice(int x_max, int y_max) : x_max(x_max), y_max(y_max) { }
  long count_paths() {
    return step(0, 1) + step(1, 0);
  }
  long step(int x, int y) {
    if (x > x_max) return 0;
    if (y > y_max) return 0;
    if (x == x_max && y == y_max) {
      return 1;
    }
    if (cache.find({x, y}) != cache.end()) {
      return cache[{x, y}];
    }
    else {
      long steps = step(x, y + 1) + step(x + 1, y);
      cache[{x, y}] = steps;
      return steps;
    }
  }
private:
  int x_max, y_max;
  std::map<std::pair<int, int>, long> cache;
};


int main(int argc, char *argv[]) {
  Lattice grid20(SIZE, SIZE);
  std::cout << grid20.count_paths() << std::endl;
  return 0;
}
