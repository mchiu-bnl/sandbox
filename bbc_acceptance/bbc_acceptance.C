double eta(const double r, const double z = 250.)
{
  return -log(tan(0.5*atan2(r,z)));
}

void bbc_acceptance()
{
  // phenix acceptance
  double ph_etamin = eta( 15., 144.);
  double ph_etamax = eta( 5., 144.);

  // sphenix acceptance
  double sph_etamin = eta( 15., 250.);
  double sph_etamax = eta( 5., 250.);

  // sphenix acceptance, z = +10 cm
  double sph_etamin_p10 = eta( 15., 240.);
  double sph_etamax_p10 = eta( 5., 240.);

  // sphenix acceptance, z = -10 cm
  double sph_etamin_m10 = eta( 15., 260.);
  double sph_etamax_m10 = eta( 5., 260.);

  cout << "BBC (rmin,rmax) = (5,15) cm" << endl;
  cout << "PHENIX Acceptance, z=144\t" << ph_etamin << "\t" << ph_etamax << endl;
  cout << "SPHENIX Acceptance, z=250\t" << sph_etamin << "\t" << sph_etamax << endl;
  cout << "SPHENIX Acceptance, z_vtx = +10 cm\t" << sph_etamin_p10 << "\t" << sph_etamax_p10 << endl;
  cout << "SPHENIX Acceptance, z_vtx = -10 cm\t" << sph_etamin_m10 << "\t" << sph_etamax_m10 << endl;
}
