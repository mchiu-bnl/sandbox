void pseudorapidity()
{
  TF1 *f_eta = new TF1("f_eta","-log(tan(x/2))",0.1,3.1);
  f_eta->GetHistogram()->SetXTitle("#theta (radians)");
  f_eta->GetHistogram()->SetYTitle("#eta");

  f_eta->Draw();
}

