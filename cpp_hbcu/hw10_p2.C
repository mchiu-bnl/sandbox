#include <iostream>

int next_int1() {
  static int cnt = 0;
  cnt++;
  return cnt;
}

int next_int2() {
  int cnt = 0;
  cnt++;
  return cnt; 
}

int global_count = 0;

int next_int3() {
  global_count++;
  return global_count;
}

void hw10_p2()
{
  for (int i = 0; i < 5; i++)
    std::cout << next_int1() << " " << next_int2() << " " << next_int3() << '\n';
}

