// check if changing data using pointer to data changes TGraph
// and it does, so this means TGraph doesn't copy the data
void tgraph()
{
  double x[3] = { 0, 1, 2 };
  double y[3] = { 1, 2, 3 };

  TGraph *g = new TGraph(3,x,y);
  //g->Draw("ap");

  double *ynew = g->GetY();
  ynew[1] = 0;
  g->Draw("ap");

}
