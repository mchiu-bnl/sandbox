// testing stl maps
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void stlmap3()
{
  /*
  map<float,float> a;

  a[1.2] = 567.2;
  a[0.3] = 2222.2;

  cout << "Map size: " << a.size() << endl;
  cout << "a[1.2] = " << a[1.2] << endl;
  cout << "a[0.3] = " << a[0.3] << endl;

  for( map<float,float>::iterator ii=a.begin(); ii!=a.end(); ++ii)
  {
    cout << (*ii).first << " : " << (*ii).second << endl;
  }
  */

  map<int,int> b;

  int run_number = 330455;
  b[run_number] = 138;
  b[330456] = 223432;
  b[run_number] += 1;
  b[111] += 1;

  cout << "b[330455] = " << b[run_number] << endl;
  cout << "b[330456] = " << b[330456] << endl;
  cout << "b[111] = " << b[111] << endl;
}

