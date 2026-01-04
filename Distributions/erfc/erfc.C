#include <TMath.h>

void erfc()
{
  TF1 *ferfc = new TF1("ferfc","TMath::Erf(x/sqrt(2))",0,3);
  ferfc->Draw();

  for (double val=1; val<5; val+=1.0)
  {
    cout << TMath::Erf(val/sqrt(2)) << endl;
  }
}
