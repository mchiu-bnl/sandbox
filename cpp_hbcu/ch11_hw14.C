// return the number of even integers in v
int count_evens(const std::vector<int>& v)
{
  int n_even = 0;

  // Loop over elements of v (value of each element v[] is iv)
  // This is valid syntax since C++11
  // google "c++ for loop vector" to find other ways to loop over a vector
  for (auto& itr : v )
  {
    //cout << itr << endl;
    if ( itr%2 == 0 )  // Check if iv is even
    {
      // Found an even number
      n_even++;
    }
  }

  return n_even;
}


void ch11_hw14()
{
  vector<int> vec{ 3, 5, 4, -1, 0 };

  // get number of evens in vec
  int n_evens = count_evens( vec );

  cout << "There were " << n_evens << " even numbers" << endl;

}
