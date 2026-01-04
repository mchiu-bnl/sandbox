// pointing resolution of a track after two tracking chambers
// Based on MWPCs used in FTBF, ie, 1 mm pitch

const int MAX_CHAMBERS = 4; // max possible chambers
const int NPOINTS = 2;      // actual num chambers used

TH1 *h_z[NPOINTS];
TH1 *h_proj;
TH1 *h_diff;

void track_projection()
{
  const int verbose = 0;      // whether to plot fits

  const double sigma = 1.050; // resolution in mm of trackers

  // positions in mm, from FNAL Survey (2018)
  const Double_t chamber_z[MAX_CHAMBERS] = { 1988., 4750., 7589., 15345.};	//mm
  const Double_t chamber_x[MAX_CHAMBERS] = { 3.62, 4.98, 4.5, 4.8 };
  const Double_t chamber_y[MAX_CHAMBERS] = { 4.4, 4.9, 4.1, 4.2 };
  const Double_t d2mcp = 390.;  // dist in z from 2nd chamber to mcp


  TString name;
  TRandom3 rand3;

  for (int iz=0; iz<NPOINTS; iz++)
  {
    name = "h_z"; name += iz;
    h_z[iz] = new TH1F(name,name,200,-10,10);
  }
  h_proj = new TH1F("h_proj","projection",200,-10,10);
  h_diff = new TH1F("h_diff","true vs projection",200,-10,10);

  TGraphErrors *g_points = new TGraphErrors(NPOINTS);
  g_points->SetMarkerStyle(20);
  /*
  TF1 *poly1 = new TF1("poly1","[0]+[1]*x",XPOS[0]-10.,XPOS[NPOINTS-1]+10.);
  poly1->SetLineColor(4);
  */

  string junk;
  TCanvas *ac = new TCanvas("ac","fits",800,600);
  int nevents = 1000;
  Double_t xtrue[NPOINTS];  // True incoming location, in global coordinates
  Double_t xwire[NPOINTS];  // Which wire it hits
  Double_t xproj;
  for (int ievt=0; ievt<nevents; ievt++)
  {
    // Get the true locations
    xtrue[0] = (rand3.Rndm()-0.5)*8.0;
    for (int iz=0; iz<NPOINTS; iz++)
    {
      //xerr[iz] = rand3->Gaus(0.,sigma);
      xwire[iz] = xtrue[0] - chamber_x[iz];
      h_z[iz]->Fill(xwire[iz]);
      //g_points->SetPoint(iz,XPOS[iz],xerr[iz]);
      //g_points->SetPointError(iz,0.,sigma);
    }

    /*
    poly1->SetParameters(0,0);
    g_points->Fit(poly1);

    if ( verbose )
    {
      g_points->Draw("ap");
      ac->Modified();
      ac->Update();
      cin >> junk;
    }
    */

    //proj = poly1->Eval(110.); // projection to detector
    // Projection of two points
    Double_t dx = (TMath::Nint(xwire[1]) + chamber_x[1]) - (TMath::Nint(xwire[0]) + chamber_x[0]);
    const Double_t dz = chamber_z[1] - chamber_z[0];
    xproj = dx*((dz+d2mcp)/dz) + xwire[0];

    h_proj->Fill(xproj);
    h_diff->Fill(xproj-xtrue[0]);

  }

  TCanvas *bc = new TCanvas("bc","bc",800,600);
  bc->Divide(2,2);
  bc->cd(1);
  h_z[0]->Draw();
  bc->cd(2);
  h_z[1]->Draw();
  bc->cd(3);
  h_proj->Draw();
  bc->cd(4);
  h_diff->Draw();

}

