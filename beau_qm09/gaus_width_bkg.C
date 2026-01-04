//
// study what happens if we don't correct the corr width for the combinatoric bkg
//
void gaus_width_bkg()
{
  const double M_PI = 3.14159265358979323846;  /* pi */

  const char *signal_gaus_txt = "([0]/sqrt(2*3.14159*[1]))*exp(-0.5*(x/[1])^2)";
  const char *bkg_gaus_txt = "([0]/sqrt(2*3.14159*[1]))*exp(-0.5*(x/[1])^2)";
  TF1 *gaus_signal = new TF1("gaus_signal",signal_gaus_txt,-M_PI,M_PI);
  TF1 *gaus_bkg = new TF1("gaus_bkg",bkg_gaus_txt,-M_PI,M_PI);

  // summed gaussian (signal + combinatoric background)
  const char *sum_gaus_txt = "[4]+([0]/sqrt(2*3.14159*[1]))*exp(-0.5*(x/[1])^2)+([2]/sqrt(2*3.14159*[3]))*exp(-0.5*(x/[3])^2)";
  TF1 *gaus_sum = new TF1("gaus_sum",sum_gaus_txt,-M_PI,M_PI);

  // fit function attempts
  const char *zyam_txt = "[2]+([0]/sqrt(2*3.14159*[1]))*exp(-0.5*(x/[1])^2)";
  TF1 *zyam = new TF1("zyam",zyam_txt,-M_PI,M_PI);
  zyam->SetLineColor(2);

  TString gaus5_txt = "[2]+([0]/(sqrt(2*3.14159)*[1]))*exp(-0.5*(x/[1])^2)";
  gaus5_txt += "+([0]/(sqrt(2*3.14159)*[1]))*exp(-0.5*((x-2*3.14159)/[1])^2)";
  gaus5_txt += "+([0]/(sqrt(2*3.14159)*[1]))*exp(-0.5*((x+2*3.14159)/[1])^2)";
  gaus5_txt += "+([0]/(sqrt(2*3.14159)*[1]))*exp(-0.5*((x-4*3.14159)/[1])^2)";
  gaus5_txt += "+([0]/(sqrt(2*3.14159)*[1]))*exp(-0.5*((x+4*3.14159)/[1])^2)";

  cout << gaus5_txt << endl;
  TF1 *gaus5 = new TF1("gaus5",gaus5_txt.Data(),-M_PI,M_PI);
  gaus5->SetLineColor(4);

  Int_t nsteps = 0;
  Float_t sigma[1000] = {0};
  Float_t bkg[1000] = {0};
  Float_t ampl[1000] = {0};	// This is the apparent amplitude, after subtracting a flat part
  //Float_t fraction[1000] = {0};	// This is the fraction in area of "gaussian part" over total

  string junk;

  Float_t signal_width = 1.2;

  cout << "B/S" << "\t" << "B_sigma/S_sigma" << "\t" << "ZYAM_sigma" << "\t" << "gaus5_sigma" << endl;
  for (float fraction=0.1; fraction<=1.0; fraction += 0.1) // fraction = background fraction relative to signal, ie B/S
    {

      for (float width_fraction=0.8; width_fraction<=1.2; width_fraction += 0.1)
        {
          gaus_sum->SetParameters(1,signal_width,fraction,width_fraction*signal_width,30.);

          TH1 *hist = gaus_sum->GetHistogram();
          hist->Draw();
          
          zyam->SetParameter(0,1);
          zyam->SetParameter(1,signal_width);
          zyam->FixParameter(2,hist->GetBinContent(1));
          hist->Fit(zyam,"wq");

          gPad->Modified();
          gPad->Update();
          //cin >> junk;

          gaus5->SetParameter(0,1);
          gaus5->SetParameter(1,signal_width);
          gaus5->SetParameter(2,hist->GetBinContent(1));
          hist->Fit(gaus5,"wq");

          gPad->Modified();
          gPad->Update();
          //cin >> junk;

          cout << fraction << "\t" << width_fraction << "\t" << zyam->GetParameter(1) << "\t" << gaus5->GetParameter(1) << endl;

          ++nsteps;
        }
    }

/*
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
*/
}

