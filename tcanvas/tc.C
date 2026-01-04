// change title of TCanvas window on the fly
//
#include <iostream>

void tc()
{
  TH1 *h = new TH1F("h","h",10,0,10);
  h->Fill( 5 );

  TCanvas *ac = new TCanvas("ac","ac",550,425);
  h->Draw();
  gPad->Modified();
  gPad->Update();

  string junk;
  cin >> junk;

  ac->SetTitle("bbb");
  h->Draw();
}

