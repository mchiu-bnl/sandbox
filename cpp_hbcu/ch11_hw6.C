int collection[100][200];


void ch11_hw6()
{
  for (int row =0; row < 100; row++)
  {
    for(int col =0; col<200; col++)
    {
      std::cout<< collection[row][col]<<"   ";
    }
    std::cout<<'\n'; 
  }
}

