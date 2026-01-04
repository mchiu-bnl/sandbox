//
// plot of diffraction pattern for light
//
#include <TMath.h>

Double_t sinc(Double_t x)
{
  return sin(x)/x;
}

// Fraunhofer diffraction eqn for slits
Double_t fraunhofer(Double_t *x, Double_t *par)
{
  Double_t theta = x[0];
  Double_t ampl = par[0];
  Double_t d = par[1];
  Double_t lambda = par[2];

  return ampl*sinc( (d*TMath::Pi()/lambda)*sin(theta) );
}

// Airy fcn for pinholes
Double_t airy(Double_t *x, Double_t *par)
{
  Double_t theta = x[0];
  Double_t ampl = par[0];   // I_0
  Double_t a = par[1];      // radius of disk
  Double_t lambda = par[2]; // wavelength of light

  Double_t k = 2*TMath::Pi()/lambda;
  Double_t kast = k*a*sin(theta);

  return ampl*pow(2*TMath::BesselJ1(kast)/kast, 2.0);
}

// Airy fcn for pinholes, x = distance on screen
Double_t airy_d(Double_t *x, Double_t *par)
{
  Double_t d = x[0];
  Double_t ampl = par[0];   // I_0
  Double_t a = par[1];      // radius of disk
  Double_t lambda = par[2]; // wavelength of light
  Double_t D = par[3];      // distance to screen

  Double_t theta = atan2(d,D);
  Double_t k = 2*TMath::Pi()/lambda;
  Double_t kast = k*a*sin(theta);

  return ampl*pow(2*TMath::BesselJ1(kast)/kast, 2.0);
}

void diff_patt()
{
  Double_t r = 50.;        // pinhole radius
  Double_t lambda = 0.405;  // wavelength
  Double_t D = 3000.;       // distance to screen [um]

  auto ac = new TCanvas("ac", "ac", 600,500);

  TF1 *f_diffpatt = new TF1("f_diffpatt",airy_d,-50,50,4);
  f_diffpatt->SetParameter(0,1);
  f_diffpatt->SetParameter(1,r);
  f_diffpatt->SetParameter(2,lambda);
  f_diffpatt->SetParameter(3,D);
  f_diffpatt->GetHistogram()->SetXTitle("x (um)");
  f_diffpatt->Draw();

  r = 0.5;
  TF1 *f_diffpatt0 = new TF1("f_diffpatt0",airy_d,-50,50,4);
  f_diffpatt0->SetLineColor(2);
  f_diffpatt0->SetParameter(0,1);
  f_diffpatt0->SetParameter(1,r);
  f_diffpatt0->SetParameter(2,lambda);
  f_diffpatt0->SetParameter(3,D);
  f_diffpatt0->Draw("same");

  r = 20;
  TF1 *f_diffpatt1 = new TF1("f_diffpatt1",airy_d,-50,50,4);
  f_diffpatt1->SetLineColor(4);
  f_diffpatt1->SetParameter(0,1);
  f_diffpatt1->SetParameter(1,r);
  f_diffpatt1->SetParameter(2,lambda);
  f_diffpatt1->SetParameter(3,D);
  f_diffpatt1->Draw("same");

  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->AddEntry(f_diffpatt0,"1 um","l");
  legend->AddEntry(f_diffpatt1,"40 um","l");
  legend->AddEntry(f_diffpatt,"100 um","l");
  legend->Draw();
}

