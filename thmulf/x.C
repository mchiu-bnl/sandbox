void x()
{
  const double M_PI=3.14;
  //gSystem->AddIncludePath("-I${OFFLINE_MAIN}/include"); // In order to find THMulf.h
  gSystem->Load("libTHmul.so"); // In order to load the code for the class, including the dictionary

  THmulf *mpc_ch_mulf = new THmulf("mpc_ch_mulf","mpc-charged correlations");
  //mpc_ch_mulf->AddAxis("ptm", "mpc pt", 20, 0., 10.);
  //mpc_ch_mulf->AddAxis("ptc", "central track pt", 8, 0., 4.);
  mpc_ch_mulf->AddAxis("dphi", "cent-mpc dphi", 60, -M_PI, M_PI);
  double eta_edges[42] = {0.};
cout << "eta_edges" << endl;
  for (int ibin=0; ibin<21; ibin++) { eta_edges[ibin] = -4.5 + 0.1*ibin; cout << eta_edges[ibin] << endl; }
  for (int ibin=21; ibin<42; ibin++) { eta_edges[ibin] = 2.5 + 0.1*(ibin-21); cout << eta_edges[ibin] << endl; }

  mpc_ch_mulf->AddAxis("deta", "cent-mpc deta", 41, eta_edges);
  mpc_ch_mulf->AddAxis("cent", "centrality", 20, 0, 100);
  //mpc_ch_mulf->AddAxis("vtx", "zvtx", 20, -30, 30);

  for (float ieta=-4.45; ieta<4.5; ieta += 0.1)
    {
      mpc_ch_mulf->Fill( fabs(ieta), ieta/2., ieta, 1 );
    }

  gStyle->SetPalette(1);
  //mpc_ch_mulf->Draw("deta","");
  mpc_ch_mulf->Draw("dphi:deta","","colz");
}

