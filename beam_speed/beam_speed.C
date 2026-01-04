// calculate beam speed at RHIC, and also the difference in revolution time at different energies
void beam_speed()
{
  TF1 *speed = new TF1("speed","sqrt((x*x)/([0]*[0]+x*x))",8,102);
  speed->SetParameter(0,0.938);
  speed->Draw();

  cout << "root-s\tbeta\tdelta-T" << endl;
  cout << 19.6 << "\t" << speed->Eval(9.8) << "\t" << -12779.4*(1.0-1.0/speed->Eval(9.8)) << endl;
  cout << 39.0 << "\t" << speed->Eval(19.5) << "\t" << -12779.4*(1.0-1.0/speed->Eval(19.5)) << endl;
  cout << 62.4 << "\t" << speed->Eval(31.2) << "\t" << -12779.4*(1.0-1.0/speed->Eval(31.2)) << endl;
  cout << 200.0 << "\t" << speed->Eval(100.0) << "\t" << 0 << endl;
}
