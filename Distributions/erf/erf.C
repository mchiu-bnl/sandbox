//
// What is erf?
//
Double_t TrigTurnOn(Double_t *x, Double_t *par)
{
  // par[0] is the amplitude (turn on max)
  // par[1] is the stretch (how long it takes to reach max)
  // par[2] is the offset (where it reaches max)
  // x[0] is the energy (or pt)
  Double_t y = 0.5*par[0]*TMath::Erfc(-(sqrt(2)/par[1])*(x[0]-par[2]));

  return y;
}

void erf()
{
  TF1 *erf = new TF1("erf","TMath::Erfc(-x)",-5,5);
  erf->Draw();

  TF1 *turnon = new TF1("turnon",TrigTurnOn,0,8,3);
  //turnon->SetParameters(1,1.0,3.5);
  turnon->SetParameters(1,2,4.0);
  turnon->SetLineColor(4);
  turnon->Draw();

  return;

  TF1 *gaussian = new TF1("gaussian","gaus",-100,100);
  gaussian->SetParameters(1.0/sqrt(2*3.14159),0,1);

  for (double sigma=1.0; sigma<=3.0; sigma += 0.1)
    {
      Double_t integ = gaussian->Integral(-sigma,sigma);
      cout << sigma << "\t" << integ << endl;
    }


  for (double sigma=0.0; sigma<=3.0; sigma += 0.1)
    {
      cout << sigma << "\t" << erf->Eval(sigma) << endl;
    }

cout << gaussian->Integral(-1.28,1.28) << endl;
}

