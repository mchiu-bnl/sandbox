void stdarray()
{
  const std::array<double,3> a{1,2,3};

  //a[0] = 1;

  for ( auto i : a )
  {
    cout << i << endl;
  }
}
