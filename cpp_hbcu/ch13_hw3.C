#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

bool palindrome(const string& s)
{
  int i, len;
  bool _flag = true;

  //len = strlen(s.c_str()); // strlen to calculate the length of a string s and len indicate  the length
  len = s.size(); // for C++ string, you use the string::size() method

 
  for(i = 0; i < len; i++)
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


void ch13_hw3()
{
  std::srand( static_cast<unsigned int>(std::time(nullptr)) ); 


  bool found_palindrome = false;
  string s;

  // loop to generate numbers until we find a palindrome 
  do
  {
    // generates random integers
    int r = rand();

    // converts the integer to a string
    s = to_string( r );

    // Checks if the integer string is a palindrome
    found_palindrome = palindrome( s );

  } while ( found_palindrome == false );

  // If it is a palindrome, print it out and end program
  cout << s << endl;


}
