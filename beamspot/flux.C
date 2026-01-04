// calculate flux from a 2-d gaussian, for different radii from the center
void flux()
{
  TF2 *gaus2d = new TF2("gaus2d","[0]/(6.283*[1]*[2])*exp(-0.5*(x/[1])*(x/[1]) - 0.5*(y/[2])*(y/[2]))",-2,2,-2,2);
  gaus2d->SetParameters(36.5/4,0.187/2.35,0.457/2.35);

  // Limits of integration
  Double_t xmin = -0.187/2;
  Double_t xmax = 0.187/2;
  Double_t ymin = -0.457/2;
  Double_t ymax = 0.457/2;
  Double_t area = (xmax-xmin)*(ymax-ymin);

  Double_t total = gaus2d->Integral(xmin,xmax,ymin,ymax);

  cout << total << "\t" << area << "\t" << total/area << endl;

}

