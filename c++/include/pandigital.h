namespace euler {

bool is_pandigital(int number) {
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
  return (seen & 0x1FF) == 0x1FF;
}

} /* namspace euler */
