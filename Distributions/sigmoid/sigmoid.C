void sigmoid()
{
  TF1 *f_sigmoid = new TF1("f_sigmoid","1/(1+exp([0]*(x-[1])))",-10,10);

  f_sigmoid->SetParameter(1,4);
  f_sigmoid->SetParameter(0,1/3.);
  f_sigmoid->Draw();
  gPad->SetGridy(1);
  gPad->SetGridx(1);
}
