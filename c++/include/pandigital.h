namespace euler {

template <typename T>
bool is_pandigital(T number, int N=0x1FF) {
  int seen = 0;

  while (number > 0) {
    int digit = number % 10;
    if (digit == 0) {
      return false;
    }

    int bit = 1 << (digit - 1);
    if (seen & bit) return false;
    seen |= bit;

    number /= 10;
  }
  // 1FF = 0b111111111
  return (seen & N) == N;
}

} /* namspace euler */
