// test various options on TGraph
void tg()
{
  gStyle->SetTitleFontSize(0.08);

  Double_t x[] = { 0, 1, 2, 3};
  Double_t y[] = { 0, 2, 4, 6};

  TGraph *g[4];

  TCanvas *ac = new TCanvas("ac","ac",840,640);
  ac->Divide(2,2);
  //TString title;
  char title[1000];

  for (int ich=0; ich<4; ich++)
  {
    g[ich] = new TGraph(4, x, y);

    /*
    title = "ch "; title += ich;
    */

    sprintf( title, "ch %d", ich );
    cout << "title = " << title << endl;

    g[ich]->SetTitle(title);
    g[ich]->SetMarkerSize(2);
    g[ich]->SetMarkerStyle(20);


    g[ich]->GetXaxis()->SetLabelSize(0.08);

    ac->cd(ich+1);


    g[ich]->SetMaximum(10);
    g[ich]->SetMinimum(-10);
    g[ich]->Draw("ap");

  }

}
