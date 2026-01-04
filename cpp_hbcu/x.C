#include <iostream>

void x()
{
   const char *str_1 = "abc";

   char str_array[] = { 'a', 'b', 'c', '\0' };
//   'a', 'b', 'c', ?, ?, ?, '\0'
   const char *str_2 = &str_array[1];

   int number = 12323;
   int *p_number = &number;

   cout << str_1 << endl;
   //cout << str_2 << endl;
   cout << str_2 << endl;
   cout << *p_number << endl;


   string s("abc");
   string s = "abc";

}



Classes join functions with the data to do related activities.

string    int length
          char array[];




