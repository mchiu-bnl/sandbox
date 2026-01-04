// testing THnSparse
//
void thnsparse()
{
  Int_t nbins[] = { 10, 20 };
  Double_t lowrange[] = { -10, 10 };
  Double_t highrange[] = { 0, 20 };
  THnSparse *hs = new THnSparseF("hs","hs",2,nbins,lowrange,highrange);

  Double_t fillvalues[] = { -5, 11 };
  hs->Fill( fillvalues );

  cout << hs->GetAxis(0)->GetNbins() << endl;
  hs->GetAxis(0)->SetRange(1,2);
  cout << hs->GetAxis(0)->GetNbins() << endl;

  TH2 *h = hs->Projection(1,0,"e");
  h->Draw("colz");
}
