// optimizing light guide length
// using helmuth spieler 
//
void lightguide()
{
  Double_t n = 1.495;  // Lucite index of refraction
  TF1 *f = new TF1("f","cos(asin(1.0/[0]) - x)",0,3.14);
  f->SetParameter(0,n);
  
  //f->Draw();

  // Attenuation Length
  //Double_t atten = 150.;  // cm
  Double_t atten = 200.;  // cm

  TF1 *f_atten = new TF1("f_atten","exp(-x/[0])",0,10);
  f_atten->SetParameter(0,atten);
  f_atten->DrawCopy();
  f_atten->SetParameter(0,150);
  f_atten->DrawCopy("same");
}

