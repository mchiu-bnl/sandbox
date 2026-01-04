// fixed length array in ttree
void t()
{
  Float_t a[5];
  for (int i=0; i<5; i++)
    {
      a[i] = i;
    }
  TFile *savefile = new TFile("s.root","RECREATE");
  TTree *t = new TTree("t","t");
  t->Branch("a",a,"a[5]/F");

  t->Fill();
  savefile->Write();

}

