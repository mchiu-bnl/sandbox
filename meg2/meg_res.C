#include <TMath.h>

// par0 - ped ampl
// par1 - ped mean
// par2 - ped sigma
// par3 - 1p.e. ampl
// par4 - 1p.e. mean
// par5 - 1p.e. sigma (w/o electronics noise) 
// par6 - 2p.e. ampl
// par7 - 3p.e. ampl
// par8 - 4p.e. ampl
// par9 - 5p.e. ampl
// par10 - 6p.e. ampl
// par11 - 7p.e. ampl
// par12 - 8p.e. ampl
// Note: Should make the ampl par's consecutive,
//       eg, 1pe ampl = par5, 2pe ampl = par6, etc
const int npeaks = 7;
Double_t ngaus(Double_t *x, Double_t *par)
{
   Double_t xx =x[0];
   Double_t f = par[0]*TMath::Gaus(xx,par[1],par[2])
     + par[3]*TMath::Gaus(xx,par[4]+par[1],sqrt(par[2]*par[2]+par[5]*par[5]))
     + par[6]*TMath::Gaus(xx,2.0*par[4]+par[1],sqrt(par[2]*par[2]+2.0*par[5]*par[5]))
     + par[7]*TMath::Gaus(xx,3.0*par[4]+par[1],sqrt(par[2]*par[2]+3.0*par[5]*par[5]))
     + par[8]*TMath::Gaus(xx,4.0*par[4]+par[1],sqrt(par[2]*par[2]+4.0*par[5]*par[5]))
     + par[9]*TMath::Gaus(xx,5.0*par[4]+par[1],sqrt(par[2]*par[2]+5.0*par[5]*par[5]))
     + par[10]*TMath::Gaus(xx,6.0*par[4]+par[1],sqrt(par[2]*par[2]+6.0*par[5]*par[5]))
     + par[11]*TMath::Gaus(xx,7.0*par[4]+par[1],sqrt(par[2]*par[2]+7.0*par[5]*par[5]));
     //+ par[12]*TMath::Gaus(xx,8.0*par[4]+par[1],sqrt(par[2]*par[2]+8.0*par[5]*par[5]));

   //cout << xx << "\t" << f << endl;
   return f;
}


void meg_res()
{
  TGraph *g_spec_read = new TGraph("spe_resolution.csv","%lg,%lg");
  //g_spec_read->Print("all");
 
  Double_t *x = g_spec_read->GetX();
  Double_t *y = g_spec_read->GetY();

  int n = g_spec_read->GetN();
  Double_t *yerr = new Double_t[n];

  for (int ip=0; ip<n; ip++)
  {
    yerr[ip] = sqrt( y[ip] );
  }
  TGraphErrors *g_spec = new TGraphErrors(n,x,y,0,yerr);

  TF1 *f_ngaus = new TF1("ngaus",ngaus,-0.029,0.14,npeaks+5);
  f_ngaus->SetParameter(0,500);    // par0 - ped ampl
  f_ngaus->SetParameter(1,0.);     // par1 - ped mean
  f_ngaus->SetParameter(2,0.005);  // par2 - ped sigma
  f_ngaus->SetParameter(3,600.);   // par3 - 1p.e. ampl
  f_ngaus->SetParameter(4,0.01);   // par4 - 1p.e. mean
  f_ngaus->SetParameter(5,0.0015); // par5 - 1p.e. sigma (w/o electronics noise) 
  f_ngaus->SetParameter(6,500);    // par6 - 2p.e. ampl
  f_ngaus->SetParameter(7,400);    // par7 - 3p.e. ampl
  f_ngaus->SetParameter(8,300);    // par8 - 4p.e. ampl
  f_ngaus->SetParameter(9,200);    // par9 - 5p.e. ampl
  f_ngaus->SetParameter(10,100);   // par10 - 6p.e. ampl
  f_ngaus->SetParameter(11,50);    // par11 - 7p.e. ampl
  f_ngaus->SetParameter(12,50);     // par12 - 8p.e. ampl
  f_ngaus->FixParameter(12,100);
  //f_ngaus->SetParameter(13,1);     // par13 - 9p.e. ampl
  f_ngaus->SetLineColor(2);
  //f_ngaus->Draw();

  f_ngaus->SetParName(0,  "ped ampl");
  f_ngaus->SetParName(1,  "ped mean");
  f_ngaus->SetParName(2,  "e noise");
  f_ngaus->SetParName(3,  "1pe ampl");
  f_ngaus->SetParName(4,  "1pe mean-ped");
  f_ngaus->SetParName(5,  "pe noise");
  f_ngaus->SetParName(6,  "2pe ampl");
  f_ngaus->SetParName(7,  "3pe ampl");
  f_ngaus->SetParName(8,  "4pe ampl");
  f_ngaus->SetParName(9,  "5pe ampl");
  f_ngaus->SetParName(10, "6pe ampl");
  f_ngaus->SetParName(11, "7pe ampl");

  g_spec->Draw("ap");
  g_spec->SetTitle("MEGII SiPM Calibration");
  g_spec->Fit(f_ngaus,"R");

  TF1 *gaussians[100] = {0};
  TString name;
  for (int ig=0; ig<npeaks+1; ig++)
  {
    name = "gaussian"; name += ig;
    cout << name << endl;
    gaussians[ig] = new TF1(name,"gaus",-0.029,1.0);
  }
  gaussians[0]->SetParameter( 0, f_ngaus->GetParameter(0) );
  gaussians[0]->SetParameter( 1, f_ngaus->GetParameter(1) );
  gaussians[0]->SetParameter( 2, f_ngaus->GetParameter(2) );
  gaussians[0]->SetLineColor( 3 );
  gaussians[0]->Draw("same");

  Double_t enoise_mean = f_ngaus->GetParameter(1);
  Double_t enoise_sigma = f_ngaus->GetParameter(2);
  Double_t pe_mean = f_ngaus->GetParameter(4);
  Double_t pe_sigma = f_ngaus->GetParameter(5);

  gaussians[1]->SetParameter( 0, f_ngaus->GetParameter(3) );
  gaussians[1]->SetParameter( 1, pe_mean+enoise_mean );
  gaussians[1]->SetParameter( 2, sqrt(pe_sigma*pe_sigma+enoise_sigma*enoise_sigma) );
  gaussians[1]->SetLineColor( 4 );
  gaussians[1]->Draw("same");

  for (int ipe=2; ipe<npeaks+1; ipe++)
  {
    cout << "xxx " << ipe << "\t" <<  f_ngaus->GetParameter(ipe+4) << endl;
    gaussians[ipe]->SetParameter( 0, f_ngaus->GetParameter(ipe+4) );
    gaussians[ipe]->SetParameter( 1, ipe*pe_mean+enoise_mean );
    gaussians[ipe]->SetParameter( 2, sqrt(ipe*pe_sigma*pe_sigma+enoise_sigma*enoise_sigma) );
    gaussians[ipe]->SetLineColor( ipe+3 );
    gaussians[ipe]->Draw("same");
  }

  f_ngaus->Draw("same");

  cout << "S/N " << (pe_mean+enoise_mean)/sqrt(pe_sigma*pe_sigma+enoise_sigma*enoise_sigma) << endl;

}

