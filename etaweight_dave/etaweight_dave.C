//
// demonstrating of weighting in two variables, pt and eta
// we consider eta from 3-4 and pt from 0-10
//
void etaweight_dave()
{
  // use a gaussian eta distribution for dn/deta
  TF1 *dndeta = new TF1("dndeta","gaus",-5,5);
  dndeta->SetParameters(5,0,3);
  dndeta->Draw();
  Double_t n_particles = dndeta->Integral(3,4); // the total number of particles
  cout << "N = " << n_particles << endl;


  // use an exponential for dn/dpt
  TF1 *dndpt = new TF1("dndpt","[0]*exp([1]*x)",0,10);
  dndpt->SetParameters(1,-1.5);
  Double_t integ = dndpt->Integral(0,10);
  //cout << "integral dndpt = " << integ << endl;   // should be same as n_particles
  dndpt->SetParameter(0,n_particles/integ);
  integ = dndpt->Integral(0,10);
  cout << "integral dndpt = " << integ << endl;   // should be same as n_particles
  //dndpt->Draw();
  //gPad->SetLogy(1);

  // Two dimensional distribution d2n/dpdeta
  // The integral of this has to be n_particles
  TF2 *d2ndptdeta = new TF2("d2ndpdeta","gaus*exp([3]*y)",-5,5,0,10);
  d2ndptdeta->SetParameters(1,0,3,-1.5);
  integ = d2ndptdeta->Integral(3,4,0,10);
  //cout << "\integral d2ndptdeta = " << integ << endl;
  d2ndptdeta->SetParameter(0,n_particles/integ);
  integ = d2ndptdeta->Integral(0,10,3,4);
  cout << "\integral d2ndptdeta = " << integ << endl;

  // Now generate a flat distribution in eta and pt
  TRandom3 r;
  Double_t r_eta;     // randomly selected eta (flat dist)
  Double_t r_pt;      // randomly selected pt (flat dist)
  Double_t w;         // weight to use
  Double_t wpt, weta; // weight to use, method 2

  // normalize the dn/deta histogram to 1
  integ = dndeta->Integral(3,4);
  dndeta->SetParameter(0,5.0/integ);
  integ = dndeta->Integral(3,4);
  cout << "integral dndeta = " << integ << endl;   // should be 1

  // evaluation histograms
  TH2 *h2_thrown_pteta = new TH2F("h2_thrown_pteta","thrown pt,eta",10,3,4,100,0,10);
  TH2 *h2_weight_pteta = new TH2F("h2_weight_pteta","weight pt,eta",10,3,4,100,0,10);
  TH2 *h2_weight_pteta_2 = new TH2F("h2_weight_pteta_2","weight pt,eta, 2nd method",10,3,4,100,0,10);

  const int ntries = 10000000;
  for (int itry=0; itry<ntries; itry++)
    {
      r_eta = r.Rndm()+3.0;    // 3 < eta < 4
      r_pt = r.Rndm()*10;      // 0 < pt < 10

      h2_thrown_pteta->Fill(r_eta,r_pt);

      // now weight by 2-dim d2n/dptdeta distribution
      w = d2ndptdeta->Eval(r_eta,r_pt);
      h2_weight_pteta->Fill(r_eta,r_pt,w);

      // now weight by two 1-dim dn/dpt, dn/deta distributions
      // this only works if d2n/dptdeta is separable
      wpt = dndpt->Eval(r_pt);
      weta = dndeta->Eval(r_eta);
      h2_weight_pteta_2->Fill(r_eta,r_pt,wpt*weta);
    }
  h2_thrown_pteta->Scale(1.0/ntries);
  h2_weight_pteta->Scale(1.0/ntries);
  h2_weight_pteta_2->Scale(1.0/ntries);

  // scale by bin widths to make d2n/dptdeta
  Float_t dpt = 0.01;
  Float_t deta = 0.1;
  h2_thrown_pteta->Scale(1.0/(dpt*deta));
  h2_weight_pteta->Scale(1.0/(dpt*deta));
  h2_weight_pteta_2->Scale(1.0/(dpt*deta));

  TCanvas *bc = new TCanvas("bc","eval weighting",800,800);
  bc->Divide(2,2);
  bc->cd(1);
  h2_thrown_pteta->Draw("lego2");
  bc->cd(2);
  d2ndptdeta->SetRange(3,4);
  d2ndptdeta->Draw("lego2");
  d2ndptdeta->GetHistogram()->SetXTitle("pt");
  d2ndptdeta->GetHistogram()->SetYTitle("eta");
  bc->cd(3);
  h2_weight_pteta->Draw("lego2");
  bc->cd(4);
  h2_weight_pteta_2->Draw("lego2");
}

