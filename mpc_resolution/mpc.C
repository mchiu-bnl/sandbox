//
// Plot the energy resolution versus energy or pt
//
void mpc()
{
  TF1 *dE = new TF1("dE","sqrt( [0]*[0]*x + [1]*[1]*x*x )",0,100);
  dE->SetParameter(0,0.13); // stochastic term
  dE->SetParameter(1,0.05); // constant term

  TF1 *dE_bad = new TF1("dE_bad","[0]*x",0,100);
  dE_bad->SetParameter(0,0.13); // bad constant term
  dE_bad->SetLineColor(2);

  dE->Draw();
  dE_bad->SetLineColor(2);
  dE_bad->Draw("same");
}

