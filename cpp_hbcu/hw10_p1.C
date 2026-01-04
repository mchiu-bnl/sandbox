#include <iostream>

int sum1(int n) {
  int s = 0;
  while (n > 0) {
    s++;
    n--; 
  }
  return s; 
}

int input;

int sum2() {
  int s = 0;
  while (input > 0) {
    s++;
    input--;
  }
  return s;
}

int sum3() {
  int s = 0;
  for (int i = input; i > 0; i--)
    s++;
  return s;
}
  
void hw10_p1()
{
            input = 5;
            std::cout << sum2() << '\n';
            std::cout << sum1(input) << '\n';
            std::cout << sum3() << '\n';
}  
