//
// maximize the size of plots in TCanvas divides
//
void gpadsize()
{
  TCanvas *ac = new TCanvas("ac","ac",425,550);
  //ac->Divide(1,2,0.00005,0.00005);
  ac->Divide(1,2,-1,-1);

  TF1 *f1 = new TF1("f1","x*x",-10,10);
  TF1 *f2 = new TF1("f2","-x*x",-10,10);
  ac->cd(1);
  f1->Draw();
  //gPad->SetPad(0,0,1,1);
  ac->cd(2);
  f2->Draw();
}
