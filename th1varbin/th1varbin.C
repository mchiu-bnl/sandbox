void th1varbin()
{
  Int_t nbins = 8;
  Float_t xedges[] = { -3.0, -2.0, -1.5, -0.5, 0.,0.5,1.5,2.0,3.0 };
  TH1 *h = new TH1F("h","test hist",nbins,xedges);
  //TH1 *h = new TH1F("h","test hist",nbins,-3,3);

  //h->FillRandom("gaus",100);
  Double_t values[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  h->SetContent(values);

  h->Draw();
  h->ShowPeaks(1.0,"nobackground",0.05);

  h->Print("all");
  /*
  TSpectrum *s = new TSpectrum();
  s->Search(h,1.0,"nobackground");
  */
}
