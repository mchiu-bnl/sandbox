// calculate intensity from focused PiLAS
void pilas_intensity()
{

  const double h = 6.62607004e-34;      // m^2 kg/s
  const double c = 2.99792458e8;        // m/s
  const double j2ev = 6.242e18;         // Joules to eV

  // Laser Paramters
  const double lambda = 420.5e-9;      // m
  double power = 1.3e-9/50.;           // Watts (@100Hz,@1% full intensity)
  double rate = 100;                   // Hz

  double ephot_j = h*c/lambda;     // joules
  double ephot_ev = ephot_j*j2ev;  // joules
  cout << "e_phot " << ephot_j << " J" << endl;
  cout << "e_phot " << ephot_ev << " eV" << endl;

  double nphot_rate = power/ephot_j;
  cout << "nphotons/s " << nphot_rate << endl;

}

