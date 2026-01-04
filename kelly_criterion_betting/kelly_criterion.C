//
// Kelly Criterion for how much to bet b (= fraction of stash), given
//
// p = probability of winning bet
// w = multiple won on bet b, ie, w = 2 means if you bet a penny, you get back the penny + another penny
// b = fraction of current stash to bet
//
// Note: when w>1, and p*w > 1, you are guaranteed to be able to win in the long run

double get_bestbetrange(const double p, const double w)
{
 const double step = 0.01;
 
 double b = step;
 double r = pow(1-b+b*w,p)*pow(1-b,1-p);
 while ( r > 1.0 )
 {
   b += step;
   r = pow(1-b+b*w,p)*pow(1-b,1-p);

   if ( r<1.0 )
   {
     return b;
   }

   if ( b>1.0 )
   {
     return 0.;
   }
 }

 return 0.;
}

void kelly_criterion()
{
  TF1 *R = new TF1("R","pow(1-x+[1]*x,[0])*pow(1-x,1-[0])",0,1);

  Double_t p = 0.505;
  Double_t w = 2.00;

  R->SetParameter(0,p);
  R->SetParameter(1,w);

  R->Draw();

  Double_t x_at_max = R->GetMaximumX();
  Double_t y_at_max = R->Eval(x_at_max);
  Double_t max = R->GetMaximum();
  cout << x_at_max << "\t" << y_at_max << "\t" << max << endl;

  Double_t b = (p*w-1)/(w-1);

  cout << "best bet = " << b << " for p = " << p << ", w = " << w << endl;
  cout << "R = " << R->Eval(b) << endl;
  //cout << R->Eval(0.01) << endl;


  // Now plot the value of b for each p,w
  //
  TCanvas *ac[100];
  int icv = 0;

  ac[icv] = new TCanvas("c_bestbet","best bet",1000,800);
  TF2 *f2_bestbet = new TF2("bestbet","(x*y-1)/(y-1)",0,1,1,10);
  f2_bestbet->Draw("surf");
  f2_bestbet->GetHistogram()->SetXTitle("P");
  f2_bestbet->GetHistogram()->SetYTitle("w");

  TH2 *h2_bestbet = new TH2F("h2_bestbet","best bet",50,0,1,50,1,10);
  TH2 *h2_betrange = new TH2F("h2_betrange","betrange",50,0,1,50,1,10);

  for (int ixbin=1; ixbin<=50; ixbin++)
  {
    double p = ((TAxis*)h2_bestbet->GetXaxis())->GetBinCenter(ixbin);
    for (int iybin=1; iybin<=50; iybin++)
    {
      double w = ((TAxis*)h2_bestbet->GetYaxis())->GetBinCenter(iybin); 

      double b = f2_bestbet->Eval(p,w);
      if ( b>0. && b<1. )
      {
        h2_bestbet->SetBinContent(ixbin,iybin,b);

        double range = get_bestbetrange(p,w);
        h2_betrange->SetBinContent(ixbin,iybin,range);
      }
    }
  }
  h2_bestbet->Draw("colz");

  // range of value of b that still is winning (R>1)
  ac[++icv] = new TCanvas("c_betrange","best range",1000,800);
  h2_betrange->Draw("colz");
}


