#include <TMath.h>

Double_t gaus2(Double_t *x, Double_t *par)
{
   Float_t xx =x[0];
   Double_t f = par[0]*TMath::Gaus(xx,par[1],par[2]) + par[3]*TMath::Gaus(xx,2.0*par[1],sqrt(2)*par[2]); 
   return f;
}

Double_t landaugaus(Double_t *x, Double_t *par)
{
   Float_t xx =x[0];
   Double_t f = par[0]*TMath::Landau(xx,par[1],par[2]) + par[3]*TMath::Gaus(xx,2.0*par[1],sqrt(2)*par[2]); 
   return f;
}

void two_mips(double mean = 1.0, double sigma = 0.1)
{
   //TF1 *f_2mips = new TF1("2mips",gaus2,0,4,4);
   TF1 *f_2mips = new TF1("2mips",landaugaus,0,4,4);
   f_2mips->SetParameters(10,mean,sigma,5);
   f_2mips->Draw();
}
