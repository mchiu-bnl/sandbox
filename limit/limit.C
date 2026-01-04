#include <iomanip.h>

void limit()
{
  double eps = 1.;
  double one = 0.;
  for (int i=0; i<100000; i++)
    {
      eps /= 2.;
      one = 1. + eps;
      cout << i << "\t" << setprecision(20) << one << "\t" << eps << endl;
      //if ( one == 1. ) break;
    }
}
