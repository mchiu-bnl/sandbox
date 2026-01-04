//void poisson(double mean = 5.8)
void p()
{
  gStyle->SetOptStat(11111);
  gStyle->SetOptFit(11111);

  //const Double_t MAX = 5;
  const Double_t MAX = 10;

  TF1 *poisI = new TF1("poisI","TMath::PoissonI(x,[0])",0,MAX);

  double mean = 0.03;

  poisI->SetParameter(0,mean);
  poisI->SetLineColor(2);

  //pois->Draw();
  poisI->Draw();

  poisI->Print("ALL");
  for (int i=0; i<10; i++)
  {
    cout << i << "\t" << poisI->Eval(i) << endl;
  }


}

