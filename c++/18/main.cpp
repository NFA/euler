/**
 * projecteuler.net
 * Problem 18
 *
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 *
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 * <cut and added to data structure below>
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by
 * trying every route. However, Problem 67, is the same challenge with a
 * triangle containing one-hundred rows; it cannot be solved by brute force, and
 * requires a clever method! ;o)
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> triangle =
{
                              { 75 },
                            { 95, 64 },
                          { 17, 47, 82 },
                        { 18, 35, 87, 10 },
                      { 20, 04, 82, 47, 65 },
                    { 19,  1, 23, 75,  3, 34 },
                  { 88,  2, 77, 73,  7, 63, 67 },
                { 99, 65,  4, 28,  6, 16, 70, 92 },
              { 41, 41, 26, 56, 83, 40, 80, 70, 33 },
            { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 },
          { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 },
        { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 },
      { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 },
    { 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 },
  {  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60, 04, 23 },
};

int maximum_sum_path(size_t x, size_t y) {
  // Two legal directions, down and down-right
  if (y < triangle.size() - 1) {
    int a = maximum_sum_path(x, y + 1);
    int b = maximum_sum_path(x + 1, y + 1);

    return std::max(a, b) + triangle[y][x];
  } else {
    return triangle[y][x];
  }
}

int main(int argc, char *argv[]) {
  //std::cout << triangle.size() << std::endl;
  std::cout << "max:" << maximum_sum_path(0, 0) << std::endl;
  return 0;
}
