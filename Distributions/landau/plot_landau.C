#include <TF1.h>

void plot_landau()
{
  TH1 *h_landau = new TH1F("h_landau" , "Landau Dist" , 400, 0, 400);
  TF1 *landau = new TF1("landau","landau",0,400);
  landau->SetParameters(10000,120,10);
  landau->Draw(); 
  cout << landau->Integral(0,400) << endl;

  h_landau->FillRandom( "landau", 10000 );
  h_landau->Draw(); 
  h_landau->Fit(landau); 
}
