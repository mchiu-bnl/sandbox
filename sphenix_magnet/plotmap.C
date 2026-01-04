//
// Plot sPHENIX Field Map
//
void plotmap(const char *fname = "sPHENIX.2d.root")
{
  gStyle->SetOptStat(0);

  TFile *infile = new TFile(fname,"READ");
  TNtuple *fieldmap = (TNtuple*)infile->Get("fieldmap");

  //Double_t MAX_R = 320; //in cm, for bPHENIX.dp.root
  Int_t MAX_R = 300; //in cm, for sPHENIX.2d.root
  //Int_t MAX_R = 400; //in cm, for bPHENIX.plug.root

  //Double_t MAX_Z = 400; //in cm, for bPHENIX.dp.root
  Int_t MAX_Z = 400; //in cm, for sPHENIX.2d.root
  //Int_t MAX_Z = 800; //in cm, for bPHENIX.plug.root

  //TH2F *h2_smap_bz = new TH2F("h2_smap_bz","sPHENIX Bz map",2*MAX_Z+1,-MAX_Z-0.5,MAX_Z+0.5,MAX_R+1,-0.5,MAX_R+0.5);
  //TH2F *h2_smap_br = new TH2F("h2_smap_br","sPHENIX Br map",2*MAX_Z+1,-MAX_Z-0.5,MAX_Z+0.5,MAX_R+1,-0.5,MAX_R+0.5);
  //TH2F *h2_smap = new TH2F("h2_smap","sPHENIX B map",401,-MAX_Z-0.5,MAX_Z+0.5,MAX_R+1,-0.5,MAX_R+0.5);
 
  /*
  // bPHENIX.plug.root
  TH2F *h2_smap_bz = new TH2F("h2_smap_bz","sPHENIX Bz map",401,-802,802,101,-2,402);
  TH2F *h2_smap_br = new TH2F("h2_smap_br","sPHENIX Br map",401,-802,802,101,-2,402);
  TH2F *h2_smap_b = new TH2F("h2_smap","sPHENIX B map",401,-802,802,101,-2,402);
  */

  // sPHENIX.2d.root
  TH2F *h2_smap_bz = new TH2F("h2_smap_bz","sPHENIX Bz map",401,-401,401,151,-1,301);
  TH2F *h2_smap_br = new TH2F("h2_smap_br","sPHENIX Br map",401,-401,401,151,-1,301);
  TH2F *h2_smap_b = new TH2F("h2_smap_b","sPHENIX B map",401,-401,401,151,-1,301);


  TCanvas *sphx_bz = new TCanvas("sphx_bz","sPHENIX Bz",550,425);
  fieldmap->Draw("r:z>>h2_smap_bz","bz","colz");
  gPad->SaveAs(".png");
  TCanvas *sphx_br = new TCanvas("sphx_br","sPHENIX Br",550,425);
  fieldmap->Draw("r:z>>h2_smap_br","br","colz");
  gPad->SaveAs(".png");
  TCanvas *sphx_b = new TCanvas("sphx_b","sPHENIX B",550,425);
  fieldmap->Draw("r:z>>h2_smap_b","sqrt(br*br+bz*bz)","colz");
  gPad->SaveAs(".png");
}
