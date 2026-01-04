void weibull()
{
  TF1 *f_weibull = new TF1("f_weibull","[0]*[1]*([0]*x)^([1]-1)*exp(-([0]*x)^[1])",0,20);
  f_weibull->SetParameters(0.1,4);
  f_weibull->Draw();
}
