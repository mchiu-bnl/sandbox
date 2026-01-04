// check size of TClonesArray
#include <TH1F.h>

void tclones()
{
  TClonesArray ca("TH1F",1000);
  Int_t n = ca.GetEntries();
  cout << "n " << n << endl;
  int i = 0;
  TH1 *th1 = (TH1F*)ca.ConstructedAt(i);
  n = ca.GetEntries();
  cout << "n " << n << endl;
}
