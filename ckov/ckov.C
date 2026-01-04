// Calculate number of ckov photons
//
#include <cmath>

// thickness - radiator thickness in cm
// lambda_min,max - min and max of wavelength ranges
double ckov(const double thickness = 1.0, double lambda_min = 300, double lambda_max = 700)
{
  const double alpha_em = 1.0/137.;

  const double n = 1.458;
  double Z = 1.0;  // charge of particle


  const double theta_c = acos(1.0/n);
  const double sin_theta_c = sin(theta_c);
  cout << "theta_c\t" << theta_c << "\t" << theta_c*180/M_PI << endl;
  cout << "sin(theta_c)\t" << sin_theta_c << "\t" << sin_theta_c*sin_theta_c << endl;

  // convert lambda from nm to cm
  lambda_min *= 1e-7;
  lambda_max *= 1e-7;

  double nckov = 2*M_PI*Z*Z*alpha_em*sin_theta_c*sin_theta_c*(1.0/lambda_min - 1.0/lambda_max)*thickness;

  cout << "nckov = " << nckov << endl;

  return nckov;
}
