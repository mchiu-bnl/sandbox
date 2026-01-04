// add at TF2 to a TH2
void x()
{
/*
  TF2 *f2 = new TF2("f2","[0]*TMath::Gaus(x,[1],[2])*TMath::Gaus(y,[3],[4])/(2*TMath::Pi()*[2]*[4])",-10,10,-10,10);
  f2->SetParameters(1,0,1,0,2);
  cout << f2->Integral(-10,10,-10,10) << endl;

  TH2 *h2 = new TH2D("h2","h2",200,-10,10,200,-10,10);
  h2->Add(f2);
  h2->Draw("lego2");
*/

  TRandom3 rand3;
  TF1 *f1 = new TF1("f1","[0]*TMath::Gaus(x,[1],[2])/(sqrt(2*TMath::Pi())*[2])",-10,10);

  TString name = "h1";
  TH1 *hvtx_wcm = new TH1F(name,name,400,-200,200);
  
  for (int i=0; i<10000; i++)
    {
      double mean = rand3.Gaus(0,3);
      f1->SetParameters(1,mean,2);
      double xmin = mean - 2*8;
      double xmax = mean + 2*8;
      int minbin = hvtx_wcm->FindBin(xmin);
      int maxbin = hvtx_wcm->FindBin(xmax);
      if ( minbin<1 ) continue;
      if ( maxbin>400 ) continue;
      //for (int ibin=minbin; ibin<=maxbin; ibin++)
      for (int ibin=1; ibin<=400; ibin++)
        {
          double x = hvtx_wcm->GetBinCenter(ibin);
          double y = f1->Eval(x);
          hvtx_wcm->Fill(x,y);
        }
    }

  hvtx_wcm->Draw();

}

