//
// study my winning percentage in pigskin pick-em
//
void results()
{
  ifstream resultsfile("espn.txt");

  float nwin[100];
  float ngames[100];
  float total_nwin = 0.;
  float total_ngames = 0.;
  float percent[100];
  float week[100];
  int n = 0;
  while ( resultsfile >> nwin[n] >> ngames[n] )
    {
      week[n] = n;
      percent[n] = nwin[n]/ngames[n];

      total_nwin += nwin[n];
      total_ngames += ngames[n];

      n++;
    }

  
  TGraph *gwin = new TGraph(n,week,percent);
  gwin->SetMarkerStyle(20);
  gwin->SetMarkerSize(1.0);
  gwin->SetMarkerColor(2);

  gwin->GetHistogram()->SetXTitle("week");
  gwin->GetHistogram()->SetYTitle("win %");
  gwin->Draw("ap");


  cout << "wins games percentage " << total_nwin << "\t" << total_ngames << "\t" << total_nwin/total_ngames << endl;
}
