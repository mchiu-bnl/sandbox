
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void stlmap2()
{
  std::map <int, std::string> trig_list;

  trig_list[0] = "A";
  trig_list[1] = "B";
  trig_list[2] = "C";
  trig_list[3] = "D";

  //cout << trig_list[5] << endl;

  map<int,std::string>::iterator it;
  for( map<int, string>::iterator ii=trig_list.begin(); ii!=trig_list.end(); ++ii)
   {
     cout << (*ii).first << ": " << (*ii).second << endl;
     if ( (*ii).second == "A" ) cout << (*ii).second << endl;
   }
}
