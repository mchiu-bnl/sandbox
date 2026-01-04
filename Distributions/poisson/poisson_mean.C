// check if poisson mean is same as mu (poisson parameter)
void poisson_mean(double mean = 5.8)
{
  gStyle->SetOptStat(11111);
  gStyle->SetOptFit(11111);

  const double mu = 0.5;  // mean rate
  const int XMAX = 10;

  TF1 *pois = new TF1("pois","TMath::Poisson(x,[0])",0,XMAX);
  TF1 *poisI = new TF1("poisI","TMath::PoissonI(x,[0])",0,XMAX);
  poisI->SetParameter(0,mu);
  pois->SetParameter(0,mu);

  poisI->SetLineColor(2);

  //pois->Draw();
  poisI->Draw();
  pois->Draw("same");

  TH1 *hpoisI = new TH1F("hpoisI","poisI",XMAX,0,XMAX);
  hpoisI->SetLineColor(4);
  Int_t nbins = hpoisI->GetNbinsX();
  for (int ibin=0; ibin<nbins; ibin++)
  {
    hpoisI->Fill(ibin,poisI->Eval(ibin));
  }
  hpoisI->Draw("histsame");

  cout << "mu " << mu << "\t" << hpoisI->GetMean() << endl;
 // << "\t" << pois->GetMean() << endl;
 //
  Double_t sum = 0.;
  for (int ibin=0; ibin<nbins; ibin++)
  {
    cout << ibin << "\t" << hpoisI->GetBinContent(ibin+1) << endl;
    sum += ibin*hpoisI->GetBinContent(ibin+1);
  }
  cout << sum << endl;

}

