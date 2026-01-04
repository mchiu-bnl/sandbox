// testing stl maps
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef map<int,int> RTMap;	// run to trig mapping

void stlmap()
{
  //map<string,map<int,int>> a;
  map<int,int> a[10];

  (a[0])[1] = 2;
  (a[0])[4] = 3;

  //a.insert( make_pair(0,Z) );
  //a[1111].insert( make_pair(111111,10) );

/*
  a["aaa"] = make_pair(1111,10);
  a["bbb"] = make_pair(1111,20);
  a["ccc"] = make_pair(1111,30);
*/

  cout << "Map size: " << (a[0]).size() << endl;
  cout << "XXX " << a[0][2] << endl;
  cout << "XXX " << a[0][1] << endl;

   for( map<int,int>::iterator ii=(a[0]).begin(); ii!=(a[0]).end(); ++ii)
   {
       cout << (*ii).first << " : " << (*ii).second << endl;
   }
}
/*
	typedef map<int, string> Map1;
	typedef map<double, Map1> Map2;

	Map2 m;
	m.insert (make_pair (1.2, Map1 ()));
	m[1.2].insert (make_pair (3, "three"));
	m[1.2].insert (make_pair (5, "five"));

	m.insert (make_pair (.5, Map1 ()));
	m[.5].insert (make_pair (5, "five"));
	m[.5].insert (make_pair (1, "one"));
	m[.5].insert (make_pair (9, "nine"));

	cout << m << endl;
*/

