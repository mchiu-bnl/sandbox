const double M_PION   = 0.13957;
const double M_KAON   = 0.49367;
const double M_PROTON = 0.93827;
const double C = 2.99792458e8;
void tof_performance()
{
  TF1 *dt = new TF1("dt","[0]*(1.0e12/(2*[3]))*([2]*[2]-[1]*[1])/(x*x)/[4]",0,10);
  dt->SetParameter(0,100);    // L (flight path)
  dt->SetParameter(1,M_PION);
  dt->SetParameter(2,M_KAON);
  dt->SetParameter(3,C*100);  // in cm/s
  dt->SetParameter(4,10);     // sigma_t in ps
  cout << dt->Eval(1) << endl;

  dt->Draw();
  dt->GetYaxis()->SetRangeUser(0.,5.);
  dt->GetXaxis()->SetRangeUser(0.,5.);
  gPad->SetGridx(1);
  gPad->SetGridy(1);
  dt->DrawCopy("same");

  dt->SetLineColor(2);
  dt->SetParameter(1,M_KAON);
  dt->SetParameter(2,M_PROTON);
  dt->DrawCopy("same");

  // PHENIX BES
  TCanvas *ac = new TCanvas("ac","ac",550,425);
  // momentum where pi/K TOF is seperated by N sigma, as a function of L
  TF1 *piK_mom = new TF1("dt","sqrt(x*(1.0e12/(2*[3]))*([2]*[2]-[1]*[1])/([4]*[0]))",0,800);
  piK_mom->GetHistogram()->SetXTitle("flight length (cm)");
  piK_mom->GetHistogram()->SetYTitle("3 sigma separation (GeV)");
  piK_mom->GetHistogram()->SetTitle("");
  piK_mom->SetParameter(0,3);        // 3 sigma separation
  piK_mom->SetParameter(1,M_PION);
  piK_mom->SetParameter(2,M_KAON);
  piK_mom->SetParameter(3,C*100);  // in cm/s
  //piK_mom->SetParameter(4,6);     // sigma_t in ps
  piK_mom->SetParameter(4,10);     // sigma_t in ps
  piK_mom->DrawCopy();

  gPad->SetGridx(1);
  gPad->SetGridy(1);

  piK_mom->SetLineColor(2);
  piK_mom->SetParameter(1,M_KAON);
  piK_mom->SetParameter(2,M_PROTON);
  piK_mom->DrawCopy("same");

  piK_mom->SetLineStyle(2);
  piK_mom->SetLineColor(1);
  piK_mom->SetParameter(1,M_PION);
  piK_mom->SetParameter(2,M_KAON);
  piK_mom->SetParameter(4,100);     // sigma_t in ps
  piK_mom->DrawCopy("same");

  piK_mom->SetLineColor(2);
  piK_mom->SetParameter(1,M_KAON);
  piK_mom->SetParameter(2,M_PROTON);
  piK_mom->DrawCopy("same");

  TCanvas *bc = new TCanvas("bc","bc",550,425);
  // theta as fn of eta
  TF1 *ftheta = new TF1("ftheta","(180/3.14159)*atan(2.*exp(-x))",0,4);
  ftheta->Draw();

  // eta at radius x, z=[0]
  TF1 *feta = new TF1("feta","-log(tan(0.5*atan2(x,[0])))",0,4);
  feta->SetParameter(0,100);    // z location

  const double RAD2DEG = 180/3.14159;
  const double DEG2RAD = 3.14159/180;

  const int NETA = 4;
  float eta[4] = { 1.2, 1.6, 2.0, 2.4 };
  for (int ieta=0; ieta<NETA; ieta++)
    {
      cout << eta[ieta] << "\t" << ftheta->Eval(eta[ieta])
        << "\t" << sin(DEG2RAD*ftheta->Eval(eta[ieta]))
        << "\t" << 3.5*sin(DEG2RAD*ftheta->Eval(eta[ieta]))
        << "\t" << 6*sin(DEG2RAD*ftheta->Eval(eta[ieta]))
        << "\t" << feta->Eval(100*tan(DEG2RAD*ftheta->Eval(eta[ieta]))+10)
        << "\t" << feta->Eval(100*tan(DEG2RAD*ftheta->Eval(eta[ieta]))-10)
        << endl;
    }
}

