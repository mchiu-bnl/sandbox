//void poisson(double mean = 5.8)
void poisson()
{
  gStyle->SetOptStat(11111);
  gStyle->SetOptFit(11111);

  //const Double_t MAX = 5;
  const Double_t MAX = 20;
  TF1 *pois = new TF1("pois","TMath::Poisson(x,[0])",0,MAX);

  TF1 *poisI = new TF1("poisI","TMath::PoissonI(x,[0])",0,MAX);
  //const double mu = 0.1;  // mean rate
  //poisI->SetParameter(0,mu);

  //double mean = 0.20/(9.38*110./120.);
  //double mean = 15.00/(9.38*110./120.);
  //double mean = 0.001;

  //double mean = 50e3/(9.38e6*110./120.);
  //`double mean = 2.1;
  double mean = 100.;

  //mean = 53*7e3/9.38e6;
  mean = 53*7e3*106.5e-9;
  const double vtx_dphi = 0.8;
  const double vtx_eff = 0.375;
  //const double vtx_eff = 0.8;
  //mean = 3*2*0.8*0.375;	// number of hits in vtx, dn/dy*dy*dphi%*vtx_eff
  //mean = 3*2*vtx_dphi*vtx_eff;	// number of hits in vtx, dn/dy*dy*dphi%*vtx_eff
  //mean += 2*2.4*vtx_eff;
  //const double fvtx_eff = 0.8;
  //mean += 2*2.4*fvtx_eff;
  //mean = 0.5;	// ZDC
  //mean = 18.0;	// probability of prefire (expect 18 in 113.4 days)
  //mean = 1.*35./113.;	// probability of prefire (expect 1 in 113.4 days)
  //mean = 0.16*113.;	// probability of prefire (expect 1 in 113.4 days)
  //mean = (1.0/634)*35.;	// probability of prefire (expect 1 in 113.4 days)

//cout << mean << endl;
//cout << 1.0/634. << endl;

  //mean = 0.3;

  //mean = 1.0/200.;

  //mean = 17./700.;  // number of UPC J/Psi over total number of runs

  //mean = 9.;  // number of UPC J/Psi over total number of runs

  pois->SetParameter(0,mean);
  poisI->SetParameter(0,mean);
  poisI->SetLineColor(1);

  //pois->Draw();
  poisI->Draw();
  pois->Draw("same");

  double one_or_more = 1.0-poisI->Eval(0);
  double two_or_more = 1.0-poisI->Eval(0)-poisI->Eval(1);

  // Prob of an event in a crossing
  cout << "mu = " << mean << "\t1-P(0)\tP(1)\tP(>1)" << endl;
  cout << "\t" << one_or_more
       << "\t" << poisI->Eval(1)
       << "\t" << two_or_more
       << endl;
  cout << "Fraction multi-collisions: " << two_or_more/one_or_more << endl;

}

