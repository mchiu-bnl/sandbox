void th1()
{
  TH1 *h = new TH1F("h","aa",3,0,3);
  TH1 *h2 = new TH1F("h2","bb",3,0,3);
  h2->SetLineColor(2);

  double w = 270.;
  h->Fill(2,w);

  //h->SetBinError(3,sqrt(w));
  //h->SetBinContent(3,w);
  h->Fill( -2, 2*w );
  h2->Fill( 2, 3*w );


  h->Sumw2();
  h->Draw("ehist");
  h2->Draw("same");
  double max1 = h->GetBinContent( h->GetMaximumBin() );
  double max2 = h2->GetBinContent( h2->GetMaximumBin() );
  cout << "max " << max1 << "\t" << max2 << endl;
}
