//
// calculate the number of events in a vertex
//
void vertex()
{
  TF1 *gaussian = new TF1("gaussian","gaus",-250,250);
  gaussian->SetParameters(1,0,22);
  gaussian->Draw();
  Double_t total = gaussian->Integral(-250,250);
  Double_t incut = gaussian->Integral(-30,30);
  cout << incut << "\t" << total << "\t" << incut/total << endl;
}
