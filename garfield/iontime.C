// make plot of ion start time from Garfield++ Drift Tube example
void iontime()
{
  double p0 =  1.49880e-13;   
  double p1 =  2.09250e+02;
  double p2 =  2.61998e+02;
  double p3 = -1.24766e+02;

  TF1 *iontiming = new TF1("iontiming","pol3",0,2);
  iontiming->SetParameter(0,p0);
  iontiming->SetParameter(1,p1);
  iontiming->SetParameter(2,p2);
  iontiming->SetParameter(3,p3);

  iontiming->Draw();
}
