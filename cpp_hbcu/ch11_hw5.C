int proc(int arr[])
{
  int len = *(&arr + 1) - arr;
  //int len = sizeof(arr)/sizeof(arr[0]);
  //int len = std::begin(arr) - std::end(arr[0]);


  cout << "The length of the array is: " << len << endl;

  return len;
}

void ch11_hw5()
{
  int aaa[] = { 1, 2, 3, 5, 7, 11 };

  proc(aaa);
}

