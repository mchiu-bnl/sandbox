// Example code to test how loops work
#include <TGraph.h>
#include <iostream>

using namespace std;

TGraph *gr {nullptr};

void loop(const int nloops = 10)
{
  cout << "Begin loop" << endl;
  int nfiles = 0;

  TGraph gr;
  //gr = new TGraph();
  //cout << "gr mem address " << (unsigned long)gr << endl;

  for (int iloop=0; iloop<nloops; iloop++)
  {
    cout << iloop  << "-th iteration of loop" << endl;
    //gr->SetPoint(nfiles,iloop,iloop*2);
    gr.SetPoint(nfiles,iloop,iloop*2);

    nfiles++; // nfiles = nfiles + 1;
  }

  gr.DrawClone("ap");
  cout << "iloop end, nfiles " << nfiles << endl;
}
