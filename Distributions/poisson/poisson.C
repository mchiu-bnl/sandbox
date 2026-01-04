void poisson(double mean = 5.8)
{
  gStyle->SetOptStat(11111);
  gStyle->SetOptFit(11111);
  TF1 *pois = new TF1("pois","TMath::Poisson(x,[0])",0,5);

  TF1 *poisI = new TF1("poisI","TMath::PoissonI(x,[0])",0,5);

  mean = 7e3/9.38e6;
  //mean = 11e3/9.38e6;
  const double vtx_dphi = 0.8;
  const double vtx_eff = 0.375;
  //const double vtx_eff = 0.8;
  //mean = 3*2*0.8*0.375;	// number of hits in vtx, dn/dy*dy*dphi%*vtx_eff
  //mean = 3*2*vtx_dphi*vtx_eff;	// number of hits in vtx, dn/dy*dy*dphi%*vtx_eff
  //mean += 2*2.4*vtx_eff;
  //const double fvtx_eff = 0.8;
  //mean += 2*2.4*fvtx_eff;
  //mean = 0.5;	// ZDC
  //mean = 12/9.38;	// 12MHz

  //mean = 50e3*0.5e-6;  // nexo 40kHz photons, in 1 microsecond

  cout << mean << endl;

  //mean = 0.3;

  pois->SetParameter(0,mean);
  poisI->SetParameter(0,mean);
  poisI->SetLineColor(2);

  //pois->Draw();
  poisI->Draw();
  pois->Draw("same");

  double p0 = poisI->Eval(0);
  double p1 = poisI->Eval(1);
  cout << "P0 P1 " << p0 << "\t" << p1 << endl;
  double n2plus = 1-p0-p1;
  cout << "n>1 " << n2plus << endl;

  // Probability of an event having pileup
  cout << "n>1/n>0 " << n2plus/(1-p0) << endl;

}

