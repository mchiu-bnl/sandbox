//
// study of geometric acceptance for decays in mpc
// 
const Double_t M_PI = 3.14159265358979323846;

void mpc_pi0decay()
{
  TGenPhaseSpace gendecay;
  TRandom3 rand(0);

  TLorentzVector pi0;
  const Double_t pi0_mass = 0.1349766;
  Double_t masses[] = { 0, 0 };
  
  TH1 *heta = new TH1D("heta","eta of decay photons",120,-6,6);
  //TH1 *htheta = new TH1D("htheta","theta of decay photons",120,-6,6);
  TH1 *hphi = new TH1D("hphi","phi of decay photons",360,-M_PI,M_PI);

  TVector3 boost;
  Double_t pi0_e = 10.;	// energy in GeV
  Double_t pi0_eta = 1.;
  Double_t pi0_theta = 2.0*atan(exp(-pi0_eta));
cout << "theta\t" << pi0_theta*180/M_PI << endl;
  Double_t pi0_v = 0;
  if ( pi0_e>0. )
    {
      pi0_v = sqrt( 1.0 - (pi0_mass/pi0_e)*(pi0_mass/pi0_e) );
    }

  for (int ievt=0; ievt<1000; ievt++)
    {
      Double_t pi0_phi = 2.0*M_PI*(rand.Rndm()-0.5);
      boost.SetMagThetaPhi(pi0_v,pi0_theta,pi0_phi);
      pi0.SetPxPyPzE(0,0,0,pi0_mass);
      pi0.Boost( boost );
      gendecay.SetDecay(pi0,2,masses);

      gendecay.Generate();
      for (int idecay=0; idecay<2; idecay++)
        {
          TLorentzVector *gam = gendecay.GetDecay(idecay);
          Double_t eta = gam->Eta();
          Double_t phi = gam->Phi();
          heta->Fill( eta );
          hphi->Fill( phi );
        }
    }
    
  TCanvas *ac = new TCanvas("ac","ac",1000,500);
  ac->Divide(1,2);
  ac->cd(1);
  heta->Draw();
  ac->cd(2);
  hphi->Draw();

}

