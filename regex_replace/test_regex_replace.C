#include <string>
#include <regex>
#include <boost/algorithm/string/predicate.hpp>


using namespace std;

void test_regex_replace()
{
  string s("/aaa/bbc.calib");
  cout << s << endl;
  std::regex re("bbc.calib");
  string s2 = std::regex_replace(s,regex("bbc.calib"),"abc.calib");
  cout << s2 << endl;

  if (boost::algorithm::ends_with(s2, "calib"))
  {
    cout << "endswith calib" << endl;
  }

  gSystem->Exit(0);
}
