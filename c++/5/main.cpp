/**
 * projecteuler.net
 * Problem 5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */
#include <iostream>

template<int N>
bool is_divisible(int num) {
  if (num % N == 0) {
    return is_divisible<N-1>(num);
  } else {
    return false;
  }
}

template<>
bool is_divisible<1>(int num) {
  return true;
}

int my_solution() {
  int num = 1;
  while(!is_divisible<20>(num)) {
    num++;
  }
  return num;
}

int main(int argc, char *argv[]) {

  std::cout << my_solution() << std::endl;
  return 0;
}
