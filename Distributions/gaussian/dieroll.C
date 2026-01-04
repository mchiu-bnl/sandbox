//
// Demonstrate the statistics of errors using the roll of a 6-sided die
//

void dieroll()
{
  TRandom3 *rand = new TRandom3(0);

  TH1 *h_results = new TH1F("h_results","Results from rolling die 600 times",6,0.5,6.5);
  const int NROLLS = 600;   // number of die rolls in one experiment

  const int NEXP = 1000;    // number of experiments
  TString name;
  TString title;
  TH1 *h_rolled[6];
  Int_t minbin = NROLLS/6 - 5*sqrt(NROLLS/6);
  Int_t maxbin = NROLLS/6 + 5*sqrt(NROLLS/6);
  for (int irolled=0; irolled<6; irolled++)
  {
    name = "h_rolled_"; name += (irolled+1);
    title = "num times "; title += (irolled+1); title += " is rolled";
    h_rolled[irolled] = new TH1F(name,title,maxbin-minbin,minbin,maxbin);
  }

  TCanvas *bc = new TCanvas("bc","bc",1000,1000);

  // Do NEXP experiments
  for (int iexp=0; iexp<NEXP; iexp++)
  {
    // Each experiment consists of NROLLS of the die
    for (int iroll=0; iroll<NROLLS; iroll++)
    {
      int result = static_cast<int>(rand->Rndm()*6.0) + 1;
      h_results->Fill( result );
    }

    h_results->Draw();
    /*
    gPad->Modified();
    gPad->Update();
    */

    for (int ibin=1; ibin<=6; ibin++)
    {
      Float_t nrolled = h_results->GetBinContent(ibin);
      h_rolled[ibin-1]->Fill( nrolled );
    }

    /*
    string junk;
    cin >> junk;
    */

    if ( iexp != NEXP-1 ) h_results->Reset();
  }

  // Plot the results, and fit to a gaussian
  TCanvas *ac = new TCanvas("ac","ac",1000,1000);
  ac->Divide(2,3);

  TF1 *gaus[6];
  for (int idie=0; idie<6; idie++)
  {
    ac->cd(idie+1);
    name = "gaus"; name += idie;
    gaus[idie] = new TF1(name,"gaus",minbin,maxbin);
    gaus[idie]->SetLineColor(kRed);
    h_rolled[idie]->Fit(gaus[idie]);
  }

}
