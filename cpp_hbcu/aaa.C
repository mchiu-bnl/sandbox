int a = 0;
while (a < 100)
{
  int b = 0;
  while (b < 100)
  {
    int c = 0;
    while (c < 100)
    {
      std::cout << "*";
      c++;
    }
    b++;
  }
  a++; 
}
std::cout << '\n';
