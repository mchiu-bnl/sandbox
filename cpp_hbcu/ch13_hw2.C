#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool palindrome(const string& s)
{
  bool _flag = true;

  int len = s.size(); // for C++ string, you use the string::size() method

  for(int i = 0; i < len; i++)
  {
    // convert str to lower case and then compare
    if ( tolower( s[i] ) != tolower( s[len - i - 1] ) )
    {
      _flag = false; // use as a signal in programming to let the program know that a certain condition has met.
      break;
    }
  }

  return _flag;
}

int ch13_hw2()
{

  string str;
  cout << ("\n Please Enter any String :  ");
  cin >> str;

  bool flag = palindrome(str);

  if ( flag == true )
  {
    cout << str << " is a Palindrome String" << endl;
  }
  else
  {
    cout << str << " is Not a Palindrome String" << endl;
  }

  return 0;
}

