// how to plot black on TH2
//
void th2()
{
  TH2 *h2 = new TH2F("h2","h2",3,0,3,3,0,3);

  h2->Fill(2,2.,-100);

  h2->Draw("0colz");
}
