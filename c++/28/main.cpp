/**
 * projecteuler.net
 * Problem 28
 *
 * Starting with the number 1 and moving to the right in a clockwise direction a
 * 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way?
 */
#include <iostream>
#include <map>
#include <utility>

#define SIZE 1001

typedef std::map<std::pair<int, int>, int> grid_t;

std::pair<int, int> origo() {
  return std::make_pair<int, int>(SIZE / 2, SIZE / 2);
}

int diag_sum(grid_t& grid) {
  int sum = -1; // counting middle twice
  for (int x = 0, y = 0; x < SIZE && y < SIZE; ++x, ++y) {
    sum += grid[{x, y}];
  }
  for (int x = SIZE - 1, y = 0; x >= 0 && y < SIZE; --x, ++y) {
    sum += grid[{x, y}];
  }
  return sum;
}


int main(int argc, char *argv[]) {
  grid_t grid;

  int seq_ptr = 1;
  // A block is a movement of right, down, left, up
  // a full grid is x blocks + 1 right
  int blocks = SIZE / 2;
  // how many steps in each movement direction
  // follows pattern:
  //  1, 1, 2, 2, 3, 3, 4, 4, 5, 5, ...
  int steps = 0;
  auto coord = origo();

  grid[coord] = 1;

  while (blocks--) {
    // right
    ++steps;
    for (int n = 1; n <= steps; ++n) {
      coord.first  += 1;
      coord.second += 0;
      grid[coord]  = ++seq_ptr;
    }
    // down
    for (int n = 1; n <= steps; ++n) {
      coord.first  += 0;
      coord.second += 1;
      grid[coord]  = ++seq_ptr;
    }
    ++steps;

    // left
    for (int n = 1; n <= steps; ++n) {
      coord.first  += -1;
      coord.second += 0;
      grid[coord]  = ++seq_ptr;
    }
    // up
    for (int n = 1; n <= steps; ++n) {
      coord.first  += 0;
      coord.second += -1;
      grid[coord] = ++seq_ptr;
    }
  }
  // last right to finish
  for (int n = 1; n <= steps; ++n) {
    coord.first  += 1;
    coord.second += 0;
    grid[coord] = ++seq_ptr;
  }

  std::cout << "diag_sum = " << diag_sum(grid) << std::endl;
  return 0;
}
