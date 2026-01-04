void ast()
{
  int count = 0;

  int a = 0;
  while (a < 100)
  {


    // 2nd loop do 100 times
    int b = 0;
    while (b < 100)
    {


      // print out 100 asterisks
      int c = 0;
      while (c < 100)
      {
        std::cout << "*";
        count++;
        c++;
      }


      b++;
    } // b-loop


    a++; 
  }
  std::cout << '\n';


  cout << count << endl;

}
