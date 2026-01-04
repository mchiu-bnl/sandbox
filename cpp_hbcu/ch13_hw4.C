#include <iostream>
#include <fstream>
#include <string>

void ch13_hw4()
{
  std::string w;
  std::ifstream x("results");
  while (x >> w)
    std::cout << '[' << w << "]\n";
}

