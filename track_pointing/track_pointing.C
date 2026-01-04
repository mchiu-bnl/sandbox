// pointing resolution of a track in the middle between two tracking chambers

void track_pointing()
{
  const int verbose = 0;      // whether to plot fits

  const double sigma = 0.050; // resolution in mm of trackers
  const int NPOINTS = 2;
  const Double_t XPOS[] = { -100., 100. };  // positions of tracker

  /*
  const int NPOINTS = 10;
  const Double_t XPOS[] = { -100., -95., -90., -85., -80., 80., 85., 90., 95., 100. };  // positions of tracker
  */

  TString name;
  TRandom3 rand3;

  TH1 *h_x[NPOINTS];
  for (int ix=0; ix<NPOINTS; ix++)
  {
    name = "h_x"; name += ix;
    h_x[ix] = new TH1F(name,name,200,-1,1);
  }
  TH1 *h_proj = new TH1F("h_proj","projection",200,-1,1);

  TGraphErrors *g_points = new TGraphErrors(NPOINTS);
  g_points->SetMarkerStyle(20);
  TF1 *poly1 = new TF1("poly1","[0]+[1]*x",XPOS[0]-10.,XPOS[NPOINTS-1]+10.);
  poly1->SetLineColor(4);

  string junk;
  TCanvas *ac = new TCanvas("ac","fits",800,600);
  int nevents = 1000;
  Double_t xerr[NPOINTS];
  Double_t proj;
  for (int ievt=0; ievt<nevents; ievt++)
  {
    for (int ix=0; ix<NPOINTS; ix++)
    {
      xerr[ix] = rand3->Gaus(0.,sigma);
      h_x[ix]->Fill(xerr[ix]);
      g_points->SetPoint(ix,XPOS[ix],xerr[ix]);
      g_points->SetPointError(ix,0.,sigma);
    }

    poly1->SetParameters(0,0);
    g_points->Fit(poly1);

    if ( verbose )
    {
      g_points->Draw("ap");
      ac->Modified();
      ac->Update();
      cin >> junk;
    }

    proj = poly1->Eval(110.); // projection to detector

    h_proj->Fill(proj);
  }

  h_proj->Draw();
}

