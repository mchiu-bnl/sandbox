const double M_PION   = 0.13957;
const double M_KAON   = 0.49367;
const double M_PROTON = 0.93827;
const double C = 2.99792458e8;
const double M_PI = 3.14159265358979323846;

void ephenix_performance()
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

  // eHENIX 
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

  TGraph *gReach_piK = new TGraph();
  TGraph *gReach_Kp = new TGraph();
  gReach_piK->SetName("gReach_piK");
  gReach_Kp->SetName("gReach_Kp");

  double istep = 0.01;
  // hadron endcap
  for (double itheta=0; itheta<M_PI*(45./180.); itheta+=istep)
    {
      double len = 300/cos(itheta);

      piK_mom->SetParameter(1,M_PION);
      piK_mom->SetParameter(2,M_KAON);
      double reach = piK_mom->Eval(len);
      gReach_piK->SetPoint(gReach_piK->GetN(),itheta,reach);

      piK_mom->SetParameter(1,M_KAON);
      piK_mom->SetParameter(2,M_PROTON);
      reach = piK_mom->Eval(len);
      gReach_Kp->SetPoint(gReach_Kp->GetN(),itheta,reach);
    }
  // barrel
  for (double itheta=M_PI*(45./180.); itheta<M_PI*(135./180.); itheta+=istep)
    {
      double len = 80/sin(itheta);

      piK_mom->SetParameter(1,M_PION);
      piK_mom->SetParameter(2,M_KAON);
      double reach = piK_mom->Eval(len);
      gReach_piK->SetPoint(gReach_piK->GetN(),itheta,reach);

      piK_mom->SetParameter(1,M_KAON);
      piK_mom->SetParameter(2,M_PROTON);
      reach = piK_mom->Eval(len);
      gReach_Kp->SetPoint(gReach_Kp->GetN(),itheta,reach);
    }
  // electron endcap
  for (double itheta=M_PI*(135./180.); itheta<M_PI; itheta+=istep)
    {
      double len = -100/cos(itheta);

      piK_mom->SetParameter(1,M_PION);
      piK_mom->SetParameter(2,M_KAON);
      double reach = piK_mom->Eval(len);
      gReach_piK->SetPoint(gReach_piK->GetN(),itheta,reach);

      piK_mom->SetParameter(1,M_KAON);
      piK_mom->SetParameter(2,M_PROTON);
      reach = piK_mom->Eval(len);
      gReach_Kp->SetPoint(gReach_Kp->GetN(),itheta,reach);
    }

  gReach_Kp->SetLineColor(1);
  gReach_Kp->SetLineWidth(2);
  gReach_Kp->GetHistogram()->SetXTitle("#theta (rad)");
  gReach_Kp->GetHistogram()->SetYTitle("p(#Deltat=3#sigma) (GeV)");
  gReach_Kp->SetMinimum(0);
  gReach_Kp->Draw("al");

  gReach_piK->SetLineColor(4);
  gReach_piK->SetLineWidth(2);
  gReach_piK->GetHistogram()->SetXTitle("#theta (rad)");
  gReach_piK->GetHistogram()->SetYTitle("p(#Deltat=3#sigma) (GeV)");
  gReach_piK->SetMinimum(0);
  gReach_piK->Draw("l");

  
  TLegend* leg = new TLegend(0.6, 0.6, .8, .8);
  leg->AddEntry(gReach_piK,"#pi/K","l");
  leg->AddEntry(gReach_Kp,"K/p","l");
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->Draw();

  /*
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
  */

}
