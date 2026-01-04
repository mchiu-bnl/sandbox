// model how long it takes for gas to be replaced in a container

void gas_replace()
{
  Double_t V0 = 35000.; // cc
  Double_t flow = 300.; // ccm

  // do steps in minutes
  Int_t tot_time = 60*24; // 24 hours

  TGraph *g_newgas = new TGraph(tot_time);

  Double_t Vnew = 0;   // volume of new gas inside, in cc
  Double_t Vold = V0;
  Double_t frac_loss = flow/V0;
  for (int istep=0; istep<60*24; istep++)
  {
    g_newgas->SetPoint(istep, istep/60., Vnew);

    // take out gas, add in gas
    Vnew = Vnew*(1.0-frac_loss) + flow;
    Vold = Vold*(1.0-frac_loss);

    if (istep%60==0 ) cout << Vnew+Vold << endl;
  }

  g_newgas->Draw("ap");
  gPad->SetGridy(1);
}

