#include <iostream>

int max(int n) {
  return n;
}

int max(int m, int n) {
  return (m >= n)? m : n;
}

int max(int m, int n, int r) {
  int x = m;
  if (n > x)
    x = n;
  if (r > x)
    x = r;
  return x; 
}

void hw10_p3() {
  std::cout << max(4) << '\n';
  std::cout << max(4, 5) << '\n';
  std::cout << max(5, 4) << '\n';
  std::cout << max(1, 2, 3) << '\n';
  std::cout << max(2, 1, 3) << '\n';
  std::cout << max(2, 1, 2) << '\n';
}

