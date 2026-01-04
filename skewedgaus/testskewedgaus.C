// testSkewedgauss.C

double new_skewedgauss(double * x, double *p) {
  double ampl = p[0];
  double mean = p[1];
  double sigma = p[2];
  double alpha = p[3];
  double delta = alpha/sqrt(1+alpha*alpha);

  double omega = sqrt(sigma*sigma/(1-2*delta*delta/M_PI));
  double xi = mean - omega*delta*sqrt(2/M_PI);
  //double arg = (x[0] - xi) / omega;
  double arg = (x[0] - mean) / sigma;
  double smallphi = TMath::Gaus(arg, 0.0, 1.0, true);
  double bigphi = 0.5 * (1 + std::erf(alpha * arg/std::sqrt(2)));

  return ampl * (2./omega) * smallphi * bigphi;
}

void new_testskewedgaus()
{
  TString name = "skgaus";
  TF1 *f = new TF1(name, new_skewedgauss,0, 4000, 4);
  f->SetParameters(600,200,60,0.5);
  f->SetNpx(1000);
  f->Draw();
  gPad->SetGridx(1);
  gPad->SetGridy(1);
  double mean = f->GetHistogram()->GetMean();
  double rms = f->GetHistogram()->GetRMS();
  cout << mean << "\t" << rms << endl;
}

double skewedgauss(double * x, double *p) {
    double xi = p[0];
    double omega = p[1];
    double alpha = p[2];
    double arg = (x[0] - xi) / omega;
    double smallphi = TMath::Gaus(arg, 0.0, 1.0, true);
    double bigphi = 0.5 * (1 + std::erf(alpha * arg/std::sqrt(2)));
    return 2./omega * smallphi * bigphi;
}

void testskewedgaus()
{
   //std::vector<double> shapes{-4.0, -1.0, 0.0, 1.0, 4.0};
   std::vector<double> shapes{0.0, 0.4};
   std::vector<int> colors{kCyan, kGreen, kPink, kOrange, kBlue};

   auto c1 = new TCanvas();
   auto legend = new TLegend(0.15,0.65,0.28,0.85);
   legend->SetBorderSize(0);

   for(std::size_t i = 0; i < shapes.size(); ++i) {
      std::string name = "f" + std::to_string(i);
      TF1 *f = new TF1(name.c_str(), skewedgauss,0, 1000, 3);
      f->SetTitle(";x;Density");
      f->SetParNames("location","scale","shape");
      f->SetLineColor(colors[i]);
      f->SetNpx(1000);
      f->SetParameters(200.0, 60.0, shapes[i]);

      f->Draw(i == 0 ? "" : "SAME");
      auto label = "#alpha = " + std::to_string(shapes[i]);
      legend->AddEntry(name.c_str(),label.c_str(),"l");

      double mean = f->GetHistogram()->GetMean();
      double rms = f->GetHistogram()->GetRMS();
      cout << mean << "\t" << rms << endl;

      double xi = f->GetParameter(0);
      double omega = f->GetParameter(1);
      double alpha = f->GetParameter(2);
      double delta = alpha/sqrt(1+alpha*alpha);

      double sigma = omega*sqrt(1-2*delta*delta/M_PI);
      mean = xi + omega*delta*sqrt(2/M_PI);
      cout << "xx " << mean << "\t" << sigma << endl;
   }

   TF1 *f2 = new TF1("f2", new_skewedgauss,0, 1000, 4);
   f2->SetParameters(1,200,60,0.4);
   f2->SetNpx(1000);
   f2->Draw("same");
   double mean = f2->GetHistogram()->GetMean();
   double rms = f2->GetHistogram()->GetRMS();
   cout << mean << "\t" << rms << endl;

   legend->Draw();
   c1->Draw();
   gPad->SetGridx(1);
   gPad->SetGridy(1);

   c1->SaveAs("skewedgauss.png");
}
