#include <iostream>
int c()
{
  double C, r;
  const double PI = 3.14159;

  // Get the radius from the user
  cout << "Please enter the circle's radius: ";
  cin >> r;

  // Formula for the area of a circle given its radius
  C = 2*PI*r;

  // Print the circumference
  std::cout << "Circumference is " << C << '\n';


  if ( true )
  {
    cout << "L1" << endl;
    if (false)
    {
      cout << "L2" << endl;
    }
  }


  return 0;
}

