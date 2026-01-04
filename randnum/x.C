//#include <TRandom3.h>
void x()
{
  TRandom3 frand;

  for (int i=0; i<10; i++)
   {
     //cout << gRandom->Gaus() << endl;
     cout << frand.Gaus() << endl;
   }
}
