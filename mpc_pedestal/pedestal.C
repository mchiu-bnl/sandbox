// Study the effect of the zero suppression on the pedestal
void pedestal()
{
  TRandom3 *trand3 = new TRandom3();

  TH1 *h_ped = new TH1F("h_ped","pedestal",20,-10.,10.);
  Double_t mean = 0;
  Double_t sigma = 1.5;   // sigma in adc counts

  for (int ievt=0; ievt<100000; ievt++)
    {
      Double_t ped0 = trand3->Gaus(mean,sigma);
      Double_t ped6 = trand3->Gaus(mean,sigma);

      if ( (int(ped6)-int(ped0)) > 0 )
        {
          h_ped->Fill(ped0);
        }
    }

  h_ped->Draw();
}

