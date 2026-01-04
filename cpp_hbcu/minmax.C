#include <iostream>
#include <climits>

using namespace std;

void minmax()
{
  cout << "Please enter 5 numbers (hit enter after each one)" << endl;
  
  int n1, n2, n3, n4, n5;

  cin >> n1 >> n2 >> n3 >> n4 >> n5;

  int min = INT_MAX;
  int max = INT_MIN;

  if ( n1 > max ) max = n1;
  if ( n1 < min ) min = n1;

  if ( n2 > max ) max = n2;
  if ( n2 < min ) min = n2;

  if ( n3 > max ) max = n3;
  if ( n3 < min ) min = n3;

  if ( n4 > max ) max = n4;
  if ( n4 < min ) min = n4;

  if ( n5 > max ) max = n5;
  if ( n5 < min ) min = n5;


  cout << "You entered " << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
  cout << "min = " << min << endl;
  cout << "max = " << max << endl;

}
