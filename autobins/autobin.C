// check how to make a histogram keep autobinning, even after reset
//#include <TH1.h>

void autobin()
{
  TH1 *h = new TH1F("h","h",1000,0,-1);
  cout << "extend? " << h->CanExtendAllAxes() << endl;
  h->SetCanExtend(TH1::kAllAxes);
  for (int i=0; i<1010; i++)
  {
    h->Fill(i);
  }

  cout << h->GetMean() << endl;
  h->Draw();
  h->Reset();

  cout << "extend? " << h->CanExtendAllAxes() << endl;

  for (int i=2000; i<3000; i++)
  {
    h->Fill(i);
  }

  cout << h->GetMean() << endl;
  h->Draw();
}
