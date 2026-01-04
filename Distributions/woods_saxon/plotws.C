//
// Plot Woods-Saxon Dist
//
void plotws()
{
  Double_t ws_radius = 6.38;
  Double_t ws_diff = 0.54;
  TF1 *ws = new TF1("ws","1/(1+exp((x-[0])/[1]))",0.,12.);
  ws->SetParameters(ws_radius,ws_diff);

  ws->SetLineColor(4);
  ws->Draw();
  ws->GetHistogram()->SetXTitle("radius (fm)");
  ws->GetHistogram()->SetTitle("Au radial profile (Woods-Saxon)");
}
