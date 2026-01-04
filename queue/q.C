#include <iostream>
#include <queue>

void q()
{
  queue<int> test;

  test.push(1);
  test.push(2);
  test.push(3);
  cout << test.size() << endl;
  cout << test.front() << endl;;
  cout << test.back() << endl;;
  cout << test.pop() << endl;;
  cout << test.front() << endl;;
  cout << test.back() << endl;;

  int *a = test.data();
  cout << a[1] << endl;

}

