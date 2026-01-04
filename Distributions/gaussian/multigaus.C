
// par0 - ped ampl
// par1 - ped mean
// par2 - ped sigma
// par3 - 1p.e. ampl
// par4 - 1p.e. mean
// par5 - 1p.e. sigma (w/o electronics noise) 
Double_t ngaus(Double_t *x, Double_t *par)
{
   Double_t xx =x[0];
   Double_t f = TMath::Gaus(xx,par[0],par[1],par[2])
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+par[5]*par[5]))
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+2.0*par[5]*par[5]))
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+3.0*par[5]*par[5]))
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+4.0*par[5]*par[5]))
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+5.0*par[5]*par[5]))
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+6.0*par[5]*par[5]))
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+7.0*par[5]*par[5]))
     + TMath::Gaus(xx,par[3],par[4],sqrt(par[0]*par[0]+8.0*par[5]*par[5]));

   return f;
}


