// test namespaces
void t()
{
  gSystem->Load("x_C.so");


  // needs namespace qualifier
  //xxx::x = 1;
  //xxx::px();
 
  // using namespace works? yes it does
  using namespace xxx;
  int x = 2;  // testing local variables.. these do override the namespace
  px();
  cout << x << endl;
  
}
