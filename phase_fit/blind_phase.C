void blind_phase()
{
  gStyle->SetOptStat(0);

  float pi=2.*acos(0);
  TRandom3 *rand = new TRandom3();

  int nevt=100000;
  int phi_bins=12;

  float e_step = 0.001;
  int e_bins = 50;
  
  TH1F* h = new TH1F("h","h",phi_bins,0,2.*pi);

  float epsilon=0.001;
  float phase=0.0;

  TH1F* h_asym = new TH1F("a","asymmetry;input asymmetry;fit result", e_bins,0,e_bins*e_step);
  TH1F* h_phase = new TH1F("p","phase;input asymmetry; fit result", e_bins,0,e_bins*e_step);

  TF1* f = new TF1("f","[0]*cos(x+[1])",0,2*pi);
  f->SetParLimits(1,-pi/2,pi/2);


  for(int j=0; j<e_bins; j++) {
    h->Reset();
    epsilon = (j+0.5)*e_step;
    epsilon = 0;
    f->SetParameter(0,epsilon);
    f->SetParameter(1,phase);

    float phi;
    for(int i=0; i<nevt; i++) {
      phi=rand->Rndm()*2.*pi-pi/2.;
      
      if(phi>pi/2. && rand->Rndm()<fabs(epsilon*cos(phi)))
	phi+=-pi;
      
      while(phi<0) phi+=2*pi;
      while(phi>2*pi) phi-=2*phi;
      
      h->Fill(phi);
    }

    h->Sumw2();
    h->Scale((float)phi_bins/nevt);
    for(int i=0; i<phi_bins; i++)
      h->SetBinContent( i+1, h->GetBinContent(i+1)-1. );
    
    //f->SetParameter(0,0.01);
    //f->SetParameter(1,1.5);
    f->SetParameter(0,0.0001);
    f->SetParameter(1,0.0001);
    //f->SetParameter(0,0.0);
    //f->SetParameter(1,0.0);
    h->Fit("f","R");
    
    h_asym->SetBinContent ( j+1, f->GetParameter(0) );
    h_asym->SetBinError   ( j+1, f->GetParError(0) );
    h_phase->SetBinContent( j+1, f->GetParameter(1) );
    h_phase->SetBinError  ( j+1, f->GetParError(1) );
  }

  TCanvas *c = new TCanvas("c","c",800,800);
  c->Divide(1,2);

  c->cd(1);
  h_asym->Draw();

  c->cd(2);
  h_phase->Draw();
  h_phase->Fit("pol0");

}
