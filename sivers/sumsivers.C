void sumsivers()
{
  const double M_PI = 3.14159265358979323846;

  TFile *f = new TFile("plotyields_trig2.25_20.0.root","READ");

  TH1F *yield[4] = {0};
  yield[1] = (TH1F*)f->Get("yieldchgampydphi0_10p1");
  yield[2] = (TH1F*)f->Get("yieldchgampydphi0_10p2");
  yield[3] = (TH1F*)f->Get("yieldchgampydphi0_10p3");

  TFile *savefile = new TFile("sumsivers.root","RECREATE");

  double newlowedge = -M_PI+10*M_PI/15;
  double newhighedge = M_PI+10*M_PI/15;
  TH1F *sum = new TH1F("sum","sum",30,newlowedge,newhighedge);

  // get sum of p1, p2, p3 dists, and also rotate the axis so
  // that the dphi range is (-pi/2,3pi/2)
  int nbinsx = yield[3]->GetNbinsX();
  for (int ibin=1; ibin<=nbinsx; ibin++)
    {
      double temp_sum = 0.;
      for (int ipt=1; ipt<4; ipt++)
	{
	  temp_sum += yield[ipt]->GetBinContent(ibin);
	}
      double dphi = yield[3]->GetBinCenter(ibin);
      if ( dphi<newlowedge )
	{
	  dphi += 2.0*M_PI;
	}
cout << ibin << " " << dphi << " " << temp_sum << endl;
      sum->Fill(dphi,temp_sum);
    }
  sum->Sumw2();

  double nevt = yield[3]->GetBinContent(0);
  sum->Scale(1.0/nevt);
  sum->SetMarkerStyle(20);
  sum->SetMarkerColor(2);
  sum->SetLineColor(2);
  sum->SetMarkerSize(0.5);
  sum->SetXTitle("#Delta#phi");
  sum->SetYTitle("1/N_{trig}dN/d#Delta#phi");
  sum->Draw("ehist");

  const char *flatgaustxt = "[0]*exp(-0.5*(x/[1])^2) + [2]*(exp(-0.5*((x-3.14159)/[3])^2) + exp(-0.5*((x+3.14159)/[3])^2)) + [4]";
  TF1 *flat2gaus = new TF1("flat2gaus",flatgaustxt,newlowedge,newhighedge);
  flat2gaus->SetParameters(0.2,0.2,0.2,0.3,0.1);

  sum->Fit(flat2gaus,"R");

  // now subtract the flat contribution, and convert error bar into percentage
  TH1F *sum2 = (TH1F*)sum->Clone("sum2");
  sum2->Reset();
  sum2->SetYTitle("%");
  int nbinsx = sum->GetNbinsX();
  for (int ibin=1; ibin<=nbinsx; ibin++)
    {


    }

//  savefile->Write();
//  savefile->Close();

}

