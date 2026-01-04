#include <iostream>

using namespace std;

int fun1(int n) {
  // n=5
  int result = 0;
  while ( n ) {
    result += n;
    //1st: 5
    //2nd: result= 5+4+3+2+1
    n--; 
    // n=3
  }
  return result;
}

void fun2(int stars) {
  for (int i = 0; i < stars; i++)
    std::cout << "*";
  std::cout << '\n';
}

double fun3(double x, double y) {
  return 2*x*x + 3*y;
}

bool fun4(char ch) {
  return ch >='A' && ch <= 'Z';
}

bool fun5(int a, int b, int c) {
  return (a <= b) ? (b <= c) : false;
}

int fun6() {
  return rand() % 2;
}

int main()
{
  int a = fun1(5); 
  cout << a << endl;

  return 0;
}

