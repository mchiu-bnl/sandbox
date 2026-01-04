//
// evaluate height at minimum with gaussian
//
void gaus_harmonic()
{
  const char *c[] = {
    "exp(-0.5*((x-3.14159)/[1])^2)",
    "exp(-0.5*((x+3.14159)/[1])^2)",
    "exp(-0.5*((x-3*3.14159)/[1])^2)",
    "exp(-0.5*((x+3*3.14159)/[1])^2)",
    "exp(-0.5*((x-5*3.14159)/[1])^2)",
    "exp(-0.5*((x+5*3.14159)/[1])^2)",
    "exp(-0.5*((x-7*3.14159)/[1])^2)"
  };

  TString ngaus_txt = "[0]*(";
  ngaus_txt += c[0]; ngaus_txt += "+";
  ngaus_txt += c[1]; ngaus_txt += "+";
  ngaus_txt += c[2]; ngaus_txt += "+";
  ngaus_txt += c[3]; ngaus_txt += "+";
  ngaus_txt += c[4]; ngaus_txt += "+";
  ngaus_txt += c[5]; ngaus_txt += "+";
  ngaus_txt += c[6]; ngaus_txt += ")";
  cout << ngaus_txt << endl;
  TF1 *gaus_harmonic = new TF1("gaus_harmonic",ngaus_txt.Data(),0,2*3.14159);
  //TF1 *gaus_harmonic = new TF1("gaus_harmonic",ngaus_txt.Data(),-20,20);

  Int_t nsteps = 0;
  Float_t sigma[1000] = {0};
  Float_t bkg[1000] = {0};
  Float_t ampl[1000] = {0};	// This is the apparent amplitude, after subtracting a flat part
  Float_t fraction[1000] = {0};	// This is the fraction in area of "gaussian part" over total

  gaus_harmonic->SetParameter(0,1);
  for (float wid=0.5; wid<2.0; wid += 0.1)
    {
      sigma[nsteps] = wid;
      gaus_harmonic->SetParameter(1,wid);

      bkg[nsteps] = gaus_harmonic->Eval(0);
      Float_t temp_ampl = gaus_harmonic->Eval(3.14159);
      ampl[nsteps] = temp_ampl - bkg[nsteps];

      fraction[nsteps] = bkg[nsteps]*2*3.14159/gaus_harmonic->Integral(0,2*3.14159);
      cout << wid << "\t" << ampl[nsteps] << "\t" << fraction[nsteps] << endl;

      ++nsteps;
    }

  TGraph *g = new TGraph(nsteps,sigma,fraction);
  g->SetName("harmonic_gaussian_error");
  g->GetHistogram()->SetXTitle("gaussian sigma");
  g->GetHistogram()->SetYTitle("Fraction of Area Lost");
  g->GetHistogram()->SetTitle("");
  g->Draw("la");
  c1->SaveAs("periodic_gaussian_fraction_lost.gif");

  gaus_harmonic->SetParameter(1,1.5);
  gaus_harmonic->GetHistogram()->SetMinimum(0);
  gaus_harmonic->Draw();
  c1->SaveAs("gauss_wid_1.5_in_periodic_space.gif");
}

