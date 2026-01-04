#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Tests of getting random number generator seeds
int main()
{
/*
  timeval x;

  int a = gettimeofday(&x,NULL);
  long c = (x.tv_sec << 12) + (x.tv_usec&0xfff);
  cout << hex << x.tv_sec << "\t" << x.tv_usec << "\t" << c << endl;
sleep(1);
  int b = gettimeofday(&x,NULL);
  c = (x.tv_sec << 12) + (x.tv_usec&0xfff);
  cout << hex << x.tv_sec << "\t" << x.tv_usec << "\t" << c << endl;
*/

  int seed;
/*
  FILE *devrandom = fopen("/dev/random", "r");
  fread(&seed, sizeof(seed), 1 , devrandom);
*/
  ifstream devrandom;
  devrandom.open("/dev/random",ios::binary);

  devrandom.read((char*)&seed,sizeof(seed) );

  cout << seed << endl;
  

  return 0;
}
