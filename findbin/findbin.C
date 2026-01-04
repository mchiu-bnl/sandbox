// which bin does FindBin select when the bin is on the edge?
void findbin()
{
  TH1F *h = new TH1F("h","h",4,0,4);

  cout << h->FindBin(2) << endl;
  cout << h->FindBin(3) << endl;
}
