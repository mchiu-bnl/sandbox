// calculate gamma for a beam particle

#include <math.h>

void beam()
{
  const double mass = 0.938272046;  // proton

  const double plab = 200.;  // E704

  double Elab = sqrt(plab*plab+mass*mass);

  double beta = plab/Elab;

  double gamma = 1.0/sqrt(1.0-beta*beta);

  double beam_rapidity = TMath::ATanH(beta);

  double sqrts = sqrt(2.0*mass*mass + 2*Elab*mass);
  double cm_gamma = (0.5*sqrts)/mass;

  cout << plab << "\t" << Elab << "\t" << beta << "\t" << gamma << endl;
  cout << "sqrt(s)\t" << sqrts << "\t" << cm_gamma << endl;
  cout << "beam_rapidity\t" << beam_rapidity << endl;
}
