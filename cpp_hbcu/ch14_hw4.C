
#include <cmath>

using namespace std;

// Models a mathematical rational number
class Circle
{
  double _x; // x of center
  double _y; // y of center
  double _r; // radius

  public:
  // Constructor of a Circle object
  Circle(double x_center, double y_center, double radius):
    _x(x_center), _y(y_center), _r(radius)
  {
    if (_r < 0)
    {
      // Display error message
      std::cout << "Radius must be greater than or equal to 0" << std::endl;
      exit(1);   // Exit the program

      // Note: We could have decided to not allow r=0, but here we do
      // since mathematically it is valid.
    }
  }

  // The default constructor makes a unit circle at the origin
  Circle(): _x(0), _y(1), _r(1.0) {}

  // Allows a client to reassign the numerator
  void set_center(double x, double y) 
  {
    _x = x;
    _y = y;
  }

  void set_radius(double r) 
  {
    if (r >= 0)
    {
      _r = r;
    }  
    else {
      std::cout << "Radius must be greater than or equal to 0" << std::endl;
      exit(1);   // Exit the program
    }

  }

  double circumference()
  {
    double circ = 2.0*M_PI*_r;

    return circ;
  }

  double area()
  {
    double area = M_PI*_r*_r;

    return area;
  }

  void print()
  {
    cout << "Circle with radius " << _r << endl;
    cout << "Area = " << area() << endl;
    cout << "Circumference = " << circumference() << endl;
  }

};


void ch14_hw4()
{
  Circle c(0,0,1);

  c.print();

}

