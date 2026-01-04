// Test reset of THStack
void thstack()
{
  TCanvas *ac = new TCanvas("ac","thstack",550,425);
  THStack *hs = new THStack("hs","");

  TH1 *ha = new TH1F("ha","ha",10,0,10);
  TH1 *hb = new TH1F("hb","hb",10,0,10);
  hb->SetLineColor(2);

  // Fill hists and add to stack, and Draw
  ha->Fill(1);
  hb->Fill(2);
  hs->Add(ha);
  hs->Add(hb);
  hs->Draw("nostack");

  gPad->Modified();
  gPad->Update();

  // pause
  string junk;
  cout << "? ";
  cin >> junk;

  hs->ls();
  //hs->GetHists()->Clear();
  //cout << "hs->GetHists()->Clear() done" << endl;
  hs->ls();

  //hs->Clear();
  ha->Reset();
  hb->Reset();
  ha->Fill(5);
  hb->Fill(6);

  //hs->Add(ha);
  //hs->Add(hb);
  hs->Draw("nostack");

}
