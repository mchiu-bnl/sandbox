// Converting photon energy to wavelength, and vice-versa, and counts

const double h = 6.62607015e-34;  // J.s
const double C = 2.99792458e8; // m/s

void photon_energy()
{
  // wavelength to energy [nm -> eV]
  TF1 *lambda2e = new TF1("lambda2e","1.2398e3/x",100,1500);
  lambda2e->GetHistogram()->SetXTitle("#lambda (nm)");
  lambda2e->GetHistogram()->SetYTitle("#E (eV)");

  // wavelength to Joules [nm -> J]
  TF1 *lambda2j = new TF1("lambda2j","1.98645e-16/x",100,1500);
  lambda2j->GetHistogram()->SetXTitle("#lambda (nm)");
  lambda2j->GetHistogram()->SetYTitle("E (Joules)");

  //lambda2j->Draw();

  // Calculate the number of photons/pulse in the PiLas 405nm
  double power = 160e-3;  //W (J/s)
  double pulse_width = 45e-12;  // s, FWHM

  double energy_per_pulse = power*pulse_width; //J
  double photon_energy = lambda2j->Eval(405);     //J

  double photons_per_pulse = energy_per_pulse/photon_energy;

  cout << "Photons per pulse " << photons_per_pulse << endl;

}
