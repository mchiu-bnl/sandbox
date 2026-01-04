// check what happens when one fits a cosine moduluation with free ampl and phase
// to a straight line.  Done to check the phase determination when A_N = 0.
#include <math.h>

const double M_PI = 3.14159265358979323846264338327950288;

void a()
{
  gStyle->SetOptFit(111111);

  TGraphErrors *g = new TGraphErrors();
  g->SetName("g");
  g->SetMarkerStyle(20);

  TGraphErrors *g_phase = new TGraphErrors();
  g_phase->SetName("g_phase");
  g_phase->SetMarkerStyle(20);
  

  TRandom3 *r3 = new TRandom3();
  const double mean = 0;
  //const double err = 0.02;
  const double err = 0.08;

  TCanvas *ac = new TCanvas("ac","ac",550,425);

  TF1 *f = new TF1("f","[0]*cos(x-[1])",0,2.0*M_PI);

  int verbose = 0;
  const int nevents = 100;
  for (int ievt=0; ievt<nevents; ievt++)
    {
      f->SetParameter(0,1.01);
      f->SetParameter(1,M_PI);

      for (int iphi=0; iphi<12; iphi++)
        {
          //Double_t phi = iphi*2.0*M_PI/12;
          Double_t phi = iphi*2.0*M_PI/12;
          Double_t val = r3->Gaus(mean,err);
          val += f->Eval(phi);
          g->SetPoint(iphi, phi, val);
          g->SetPointError(iphi, 0, err);
        }

      if ( verbose && ievt<4 )
        {
          g->Draw("ap");
        }

      //double mean_seed = 10;
      //double mean_seed = 1;
      //double mean_seed = 0;
      double mean_seed = 1; 
      //double phase_seed = 0;
      double phase_seed = M_PI/2;
      f->SetParameters(0,mean_seed);
      f->SetParameters(1,phase_seed);
      //f->FixParameter(0,mean_seed);
      //f->SetParLimits(1,0,2.0*M_PI);

      g->Fit(f,"Q");

      Double_t phase = f->GetParameter(1);
      Double_t phase_err = f->GetParError(1);

      if ( phase > 2.0*M_PI )
        {
cout << "aaa " << phase << endl;
          int a = phase/(2.0*M_PI);
cout << a << "\t" << phase/(2.0*M_PI) << endl;
          phase = phase - a*2.0*M_PI;
cout << phase << endl;
if ( phase>4.0 ) {
verbose = 1;
g->Draw("ap");
}
        }
      else if ( phase <= 0. )
        {
          int a = 1 - phase/(2.0*M_PI);
          phase = phase + a*2.0*M_PI;

        }

      Int_t n = g_phase->GetN();
      g_phase->SetPoint(n,ievt,phase);
      g_phase->SetPointError(n,0,phase_err);

      //if ( verbose && ievt<5 )
      if ( verbose )
        {
          ac->Modified();
          ac->Update();

	  string junk;
	  cin >> junk;
          if ( junk[0] == 's' )
            {
              ac->SaveAs("phase_iit.png");
            }
verbose = 0;
	}

      g->Clear();
    }

  TCanvas *bc = new TCanvas("bc","phase",550,425);
  g_phase->Draw("ap");
  g_phase->GetHistogram()->SetXTitle("run");
  g_phase->GetHistogram()->SetYTitle("phase");
  g_phase->Fit("pol0");


}

