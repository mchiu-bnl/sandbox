//
// Acceptance change when moving back the south arm
//
void acceptance()
{
  gROOT->Reset();

  // points at inner and outer position of ncc and s.muon
  const double ncc_rmax = 19.0;
  const double ncc_rmin = 11.0;
  //const double ncc_rmin = 6.0;
  const double ncc_z = 220.947;

  // good zvertex range
  const double max_zvtx = 200;
  const double min_zvtx = -200;

  TF1 *eta_fn_ncc_max = new TF1("eta_fn_ncc_max","-log(tan(0.5*atan2([0],[1]-x)))",min_zvtx,max_zvtx);
  TF1 *eta_fn_ncc_min = new TF1("eta_fn_ncc_min","-log(tan(0.5*atan2([0],[1]-x)))",min_zvtx,max_zvtx);

  eta_fn_ncc_max->SetLineColor(2);
  eta_fn_ncc_min->SetLineColor(2);

  eta_fn_ncc_max->SetParameters(ncc_rmax,ncc_z);	// outer sncc
  eta_fn_ncc_min->SetParameters(ncc_rmin,ncc_z);	// inner sncc

  TCanvas *c_accept = new TCanvas("c_accept","MPC Acceptance w/ 4 VTX hits",550,425);
  //TPad *pad1 = new TPad("pad1","pad1",0.01,0.01,0.99,0.195,0,0,0);
//  TPad *pad1 = new TPad("pad1","pad1",0.01,0.01,0.99,0.295);
//  TPad *pad2 = new TPad("pad2","pad2",0.01,0.305,0.99,0.99,0,0,0);
  //pad1->SetFillColor(4);
//  pad1->Draw();
  //pad2->SetFillColor(2);
//  pad2->Draw();

//  pad2->cd();
  //Make dummy histogram;
  TH1 *h_dummy = new TH1F("h_dummy","",1,-200,200);
  gStyle->SetOptStat(0);
  h_dummy->SetMaximum(5.0);
  h_dummy->SetMinimum(0.5);
  h_dummy->SetTitle("MPC Acceptance");
  h_dummy->SetXTitle("zvertex (cm)");
  h_dummy->SetYTitle("pseudorapidity #eta");
  h_dummy->Draw();
/*
  TGraph *grshade = new TGraph(22);
  for (int i=0;i<=10;i++)
    {
      Double_t x1 = min_zvtx + i*2.0;
      Double_t y1 = eta_fn_ncc_max->Eval(x1);
      Double_t x2 = max_zvtx - i*2.0;
      Double_t y2 = eta_fn_ncc_min->Eval(x2);
      grshade->SetPoint(i,x1,y1);
      grshade->SetPoint(11+i,x2,y2);
    }
  grshade->SetFillStyle(3013);
  grshade->SetFillColor(2);
  grshade->Draw("f");
*/

  eta_fn_ncc_max->Draw("LCsame");
  eta_fn_ncc_min->Draw("LCsame");

/*
  // Now draw vertex gaussian
  pad1->cd();
  TF1 *vtx = new TF1("vtx","gaus",-40,40);
  vtx->SetParameters(0.5,0,22.0);
  TF1 *vtx_accepted = new TF1("vtx_accepted","gaus",min_zvtx,max_zvtx);
  vtx_accepted->SetParameters(0.5,0,22.0);
  vtx_accepted->SetFillColor(4);
  vtx_accepted->SetFillStyle(3144);

  vtx->Draw();
  vtx_accepted->Draw("same");
  pad1->Draw();
  Double_t all_events = vtx->Integral(-1000.,1000.);
  Double_t accepted_events = vtx->Integral(min_zvtx,max_zvtx);
  cout << "Taking " << accepted_events << " out of " << all_events
       << " " << accepted_events/all_events << endl;
*/

/*
  gPad->SetGridy(1);
  gPad->SetGridx(1);
  gPad->Modified();
  gPad->Update();
*/

  // Print eta acceptance vs rollback displacement
  //const double rollback = 0.;
  const double rollback = 50.;
  //const double rollback = 100.;
  //const double rollback = 150.;
  cout << "[" 
       << eta_fn_ncc_max->Eval(rollback) << ","
       << eta_fn_ncc_min->Eval(rollback)
       << "]" << endl;
}

