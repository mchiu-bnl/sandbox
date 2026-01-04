Double_t nbd(Double_t *x, Double_t *par)
{
  Double_t n = x[0];
  Double_t mu = par[0];
  Double_t k = par[1];

  Double_t F, f;

  if (n+k > 100.0) {
    // log method for handling large numbers
    F  = TMath::LnGamma(n + k)- TMath::LnGamma(n + 1.)- TMath::LnGamma(k);
    f  = n * TMath::Log(mu/k) - (n + k) * TMath::Log(1.0 + mu/k);
    F = F+f;
    F = TMath::Exp(F);
  } else {
    F  = TMath::Gamma(n + k) / ( TMath::Gamma(n + 1.) * TMath::Gamma(k) );
    f  = n * TMath::Log(mu/k) - (n + k) * TMath::Log(1.0 + mu/k);
    f  = TMath::Exp(f);
    F *= f;
  }

  return F;  

}

void plotnbd(const char *fname = "/direct/phenix+hhj/chiu/dAu_glauber/offline/analysis/glauber_mc/glauber_calc00.root")
{

  TF1 *fnbd = new TF1("fnbd",nbd,0,200,2);
  fnbd->SetParNames("mu","k");	// k
  Double_t npart = 15;
  fnbd->SetParameter(0,3.038*npart);	// mu
  fnbd->SetParameter(1,0.464*npart);	// k

  fnbd->Draw();
  for (int inpart=1; inpart<20; inpart++)
    {
      fnbd->SetParameter(0,3.038*inpart);	// mu
      fnbd->SetParameter(1,0.464*inpart);	// k
      cout << inpart << "\t" << fnbd->Integral(0,200) << endl;
    }

  // open Glauber ntuple
  TFile* f = new TFile(fname);
  TTree* gl = (TTree*) f->Get("gl");

  // make ntuple variables known
  Int_t nHitsNBD;
  Int_t npartproj;
  Int_t nparttarg;
  Int_t ncoll;
  Double_t b;
  Double_t eccentr;
  Double_t area;

  gl->SetBranchAddress("nHitsNBD", &nHitsNBD);
  gl->SetBranchAddress("npartproj", &npartproj);
  gl->SetBranchAddress("nparttarg", &nparttarg);
  gl->SetBranchAddress("ncoll", &ncoll);
  gl->SetBranchAddress("b", &b);
  gl->SetBranchAddress("eccentr", &eccentr);
  gl->SetBranchAddress("area", &area);

  TH1 *hbbc = new TH1D("hbbc","BBC.S NBD dist",1000,0,200);
  TH1 *hbbc_temp = hbbc->Clone("hbbc_temp");
  TH1 *hnparttarg = new TH1D("hnparttarg","hnparttarg",200,0,200);

  // BBC efficiency (vs nbd dist)
  TF1 *f_bbceff = new TF1("f_bbceff","1-[0]*exp(-[1]*x)",0,200);
  f_bbceff->SetParameters(0.897,0.612);
  //f_bbceff->Draw();
  //return;
  int maxeffbin = hbbc->FindBin(10);	// max bin we need to apply to the eff
  
  int nentries = gl->GetEntries();
  for (int ientry=0; ientry<nentries; ientry++)
    {
      gl->GetEntry(ientry);

      if ( nparttarg==0 ) continue;

      fnbd->SetParameter(0,3.038*nparttarg);	// mu
      fnbd->SetParameter(1,0.464*nparttarg);	// k

      hbbc_temp->Reset();
      hbbc_temp->Add( fnbd );
      for (int ibin=1; ibin<maxeffbin; ibin++)
        {
          Double_t y = hbbc_temp->GetBinContent(ibin);
          if (y>0.)
            {
              Double_t x = hbbc_temp->GetBinCenter(ibin);
              Double_t eff = f_bbceff->Eval( x );
              hbbc_temp->SetBinContent(ibin,y*eff);
            }
        }

      hbbc->Add( hbbc_temp );

      hnparttarg->Fill( nparttarg );
      if ( ientry==1000 ) break;
    }

  hbbc->Draw();
  gPad->SetLogy(1);
  gPad->SetGridx(1);
  gPad->SetGridy(1);

  hbbc->Draw();
}
