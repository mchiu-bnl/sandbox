#include <iostream>

UInt_t hammingweight(UInt_t i)
{
  // Java: use >>> instead of >>
  // C or C++: use uint32_t
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);

  UInt_t n = (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
  cout << n << endl;

  return n;
}

