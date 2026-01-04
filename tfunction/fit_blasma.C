// Blasma Class

class  BlasmaFunctions {
 public:
   Double_t  hipt_blasma() (Double_t *x, Double_t *p);
   Double_t  lopt_blasma() (Double_t *x, Double_t *p);
 private:
};

// hipt, inclusive photon pt
Double_t BlasmaFunctions::hipt_blasma() (Double_t *x, Double_t *par)
{
  Double_t pt = x[0];
  Double_t f = 0;

  if ( pt < 1.15 )
    {
      f = par[0]*pt;
    }
  else
    {
      f = par[0]*1.15;
    }

  return f;
}

// lopt, inclusive photon pt
Double_t BlasmaFunctions::lopt_blasma() (Double_t *x, Double_t *par)
{
  Double_t pt = x[0];
  Double_t f = 0;

  if ( pt < 1.15 )
    {
      f = par[0]*pt;
    }
  else
    {
      f = par[0]*1.15;
    }

  return f;
}

void fit_blasma()
{
  BlasmaFunctions *blasma_fcn = new BlasmaFunctions();
  TF1 *blasma = new TF1("blasma",blasma_fcn,0,10,1);
  blasma->SetParameter(0,2.0);
  blasma->SetParNames("constant");
  blasma->SetLineColor(4);

  // Create test histogram with blasma function
  TH1F *h1 = new TH1F("h1","test",100,0,10);
  h1->FillRandom("blasma",20000);

  // Test Fit
  blasma->SetParameter(0,1.0);
  h1->Fit("blasma");
}

