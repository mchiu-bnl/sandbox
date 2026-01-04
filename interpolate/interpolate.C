void interpolate()
{
  float x[] = { 0, 1, 2, 3, 4 };
  float y[] = { 0, 1, 4, 9, 16 };

  TGraph *gr = new TGraph(5,x,y);

  gr->Draw("ac");

  // Does the smooth curve specified with c match a real parabola?
  TF1 *parabola = new TF1("parabola","pol2",0,4);
  parabola->SetParameters(0,0,1);
  parabola->SetLineColor(2);
  parabola->Draw("same");
  
  Double_t ix = 2.5;
  Double_t iy = gr->Eval(ix,0,"S");
  cout << ix << "\t" << iy << endl;
}
