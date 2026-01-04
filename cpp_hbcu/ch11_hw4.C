// Array a with length n
// Returns the sum of the even numbers in array a
int sum_evens(const int *a, int n) {
  // Add your code...

    int sum = 0;

    for(int n = 0; n<5; n++)
    {
      if ( a[n]%2 == 0 )  // check if even
        sum += a[n];
    }

    //sum_evens("%d, sum");   // this function argument is a STRING when sum_evens ONLY takes (int*, int) as the arguments

    //std::cout<<"sum at a " << sum <<'\n';

    return sum;

    // function never gets to here!!!!
}

/*
int len(int a[])
{
  return sizeof( a );
}
*/

void ch11_hw4()
{ 
  int a[5] = { -1, 2, 2, 3, 5 };

  int n=5;

       const char *word = "abcde";


  //int even_sum = sum_evens( a, n );

  //cout << even_sum << "\t" << sizeof( a ) << endl;

  cout << "AAAA " << *word << endl;
}


