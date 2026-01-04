void minuit()
{

  TF1 *gaussian = new TF1("gaussian","gaus",-3,3);
  gaussian->SetParameters(1/sqrt(2*3.14),0,1);

  TH1F *h_gaus = new TH1F("h_gaus","gaus",60,-3,3);

  for (int isample=0; isample<1000; isample++)
    {
      Double_t x = gaussian->GetRandom();
      h_gaus->Fill(x);
    }

  TF1 *fit_gaussian = new TF1("fit_gaussian","gaus",-3,3);
  fit_gaussian->SetParameters(1,0,0.2);

  TF1 *fit_poly1 = new TF1("fit_poly1","pol1",-3,3);
  fit_poly1->SetParameters(0,1,1);

  Double_t fmin;
  Double_t fedm;
  Double_t errdef;
  Int_t npari;
  Int_t nparx;
  Int_t istat;

  TF1 *fit_fcn = fit_gaussian;
  h_gaus->Fit(fit_fcn,"R");		// gaussian works

  gMinuit->mnstat(fmin, fedm, errdef, npari, nparx, istat);

  cout << "minuit status "
       << fmin << "\t"
       << fedm << "\t"
       << errdef << "\t"
       << npari << "\t"
       << nparx << "\t"
       << istat << endl;

  fit_fcn = fit_poly1;
  h_gaus->Fit(fit_fcn,"RF");	// poly1 doesn't work, "F" is needed to get Minuit for polynomials

  gMinuit->mnstat(fmin, fedm, errdef, npari, nparx, istat);

  cout << "minuit status "
       << fmin << "\t"
       << fedm << "\t"
       << errdef << "\t"
       << npari << "\t"
       << nparx << "\t"
       << istat << endl;

/*
void mnstat(Double_t& fmin, Double_t& fedm, Double_t& errdef, Int_t& npari, Int_t& nparx, Int_t& istat)

Returns concerning the current status of the minimization
*-*      =========================================================
*-*       User-called
*-*          Namely, it returns:
*-*        FMIN: the best function value found so far
*-*        FEDM: the estimated vertical distance remaining to minimum
*-*        ERRDEF: the value of UP defining parameter uncertainties
*-*        NPARI: the number of currently variable parameters
*-*        NPARX: the highest (external) parameter number defined by user
*-*        ISTAT: a status integer indicating how good is the covariance
*-*           matrix:  0= not calculated at all
*-*                    1= approximation only, not accurate
*-*                    2= full matrix, but forced positive-definite
*-*                    3= full accurate covariance matrix
*
*/


}
