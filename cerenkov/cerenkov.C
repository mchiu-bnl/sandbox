void cerenkov()
{
  TF1 *Ncerenkov = new TF1("Ncerenkov","(6.28/137.)*[0]*(1/[1]-1/[2])*(1-1/(x*x))",1.0,2.0);
  //Ncerenkov->SetParameter(0,1);		// length traversed in cm
  //Ncerenkov->SetParameter(1,200e-7);	// 200 nm in terms of cm
  //Ncerenkov->SetParameter(2,650e-7);

  Ncerenkov->SetParameter(0,0.1);	// length traversed in cm
  Ncerenkov->SetParameter(1,400e-7);	// 200 nm in terms of cm
  Ncerenkov->SetParameter(2,600e-7);

  Ncerenkov->Draw();
}
