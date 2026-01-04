// test of a vector in ttree
#include <vector>

void x()
{
  Int_t evt;
  std::vector< std::vector<double> > data;
  Int_t len;
  Float_t data2[100];

  TFile *f = new TFile("x.root","RECREATE");
  TTree *t = new TTree("t","test STL");
  t->Branch("evt",&evt,"evt/I");
  t->Branch("data",&data);
  t->Branch("len",&len,"len/I");
  t->Branch("data2",data2,"data2[len]/F");

  for (int ievt=0; ievt<10; ievt++)
    {
      evt = ievt;

      data.clear();
      data.resize(4);
      for (int j=0; j<4; j++)
        {
          data[j].resize(10);
        }

      for (int ich=0; ich<4; ich++)
        for (int j=0; j<=ievt; j++)
          {
            data[ich][j] = ievt*j;
          }

      len = ievt;
      for (int ilen=0; ilen<len; ilen++)
        {
          data2[ilen] = ievt*ilen;
        }

      t->Fill();
    }


  for (int ievt=0; ievt<10; ievt++)
    {
      t->GetEntry(ievt);
      cout << evt << endl;
      for (int ilen=0; ilen<len; ilen++)
        {
          cout << data2[ilen] << "\t";
        }
      cout << endl;
    }
 
  f->Write();
}

