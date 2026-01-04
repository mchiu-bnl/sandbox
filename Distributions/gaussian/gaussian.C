//Get Gaussian Integrals
#include <TF1.h>

void gaussian(const double min = -1.5, const double max = 1.5)
{
  TF1 *g = new TF1("g","gaus",-10,10);
  double sigma = 0.1;
  g->SetParameters(1,0,sigma);

  g->Draw();

  Double_t total = g->Integral(-100*sigma,100*sigma);
  Double_t integ = g->Integral(min,max);
  cout << integ << "\t" << total << endl;
  cout << "trig_percentage " << integ/total << endl;

  // Calcuate trig rate for nexo
  Double_t trig_percentage = integ/total;
  cout << "nexo trig rate (Hz) " << 2e6*trig_percentage << endl;

  TF1 *erfc = new TF1("erfc","0.5*TMath::Erfc(x/sqrt(2))",-10,10);
  erfc->SetNpx(1000);
  cout << erfc->Eval(0.5/sigma)*2e6 << endl;

  cout << erfc->Eval(1.0) << endl;
  cout << erfc->Eval(2) << endl;
  cout << erfc->Eval(3) << endl;
  erfc->Draw();
}
