

// Returns angle of E-field in lab frame from angle in rest frame
// par[0] = gamma
Double_t lorentz_angle(Double_t *x, Double_t *par)
{
   //Double_t v = par[0]; // relative velocity between frames
   //Double_t gamma = 1.0/sqrt(1-v*v);
   Double_t gamma = par[0];

   Double_t rest_angle = x[0];  // angle in rest frame

   // Need to correct ambiguity in tan() when it reaches pi/2
   Double_t tan_sign = fabs(rest_angle) > TMath::Pi()/2 ? -1.0 : 1.0; 

   Double_t lab_angle = atan( gamma * tan_sign * tan(rest_angle) );

   return lab_angle;
}

void field_lines_transform()
{
  // Create TF1
  TF1 *boosted_angle = new TF1("boosted_angle",lorentz_angle,-TMath::Pi(),TMath::Pi(),1);
  boosted_angle->SetParameter(0,100); // gamma = 100
  boosted_angle->GetHistogram()->SetXTitle("E-field angle in rest frame");
  boosted_angle->GetHistogram()->SetYTitle("E-field angle in lab frame");

  boosted_angle->Draw();

  const double DEG2RAD = TMath::Pi()/180.;

  Double_t rest_angle[] = { 10, 15, 30, 45, 60, 75, 90 };

  for (int iangle=0; iangle<7; iangle++)
  {
  cout << rest_angle[iangle] << "\t" << boosted_angle->Eval(rest_angle[iangle]*DEG2RAD)/DEG2RAD << endl;
  }

}

