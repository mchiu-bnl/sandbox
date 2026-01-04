// calculate rate for a given halflife and quantity of material
//

const double Avogadro = 6.02e23;  // Avogadro's number

double thalf = 4.4e14;            // yrs, 115In
double weight = 10;               // grams
double atomic_weight = 114.9;     // g/mol
double abundance = 0.96;


void halflife()
{
  double N0 = (weight/atomic_weight)*Avogadro*abundance;  // N atoms at t=0

  // rate = dN/dt = N0*thalf/log(0.5);
  const double secs_per_year = 60.*60.*24.*365.;
  double thalf_secs = thalf*secs_per_year;
  double rate = N0*log(0.5)/thalf_secs;

  cout << rate << endl;
}
