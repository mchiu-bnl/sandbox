{
  //-* headlight effect
  const Double_t PI = 3.14159;
  TF1 *headlight = new TF1("headlight","acos((cos(x)+[0])/(1+[0]*cos(x)))",0.,PI);
  headlight->SetParameter(0, -.7);

  //-* separation d between two photons from pi0 decay, impinging on emcal
  TF1 *sep = new TF1("sep","2*[0]*[1]*sqrt(1-cos(x)^2)*sqrt(1-[1]^2)/([1]^2-cos(x)^2)",0.,PI);

  sep->SetMaximum(100);
  sep->SetMinimum(0);
  const double mpi0 = .140;	// mass of pi0, in GeV
  const int color = 1;
  for (double ipt=1.; ipt<=10.; ipt += 1.0)
    {
      double pmsqr = ipt*ipt/(mpi0*mpi0);
      double v = sqrt( pmsqr/(1 + pmsqr) );
      cout << "pt = " << ipt << ", v = " << v << endl;
      sep->SetParameters(500., v);
      sep->SetLineColor(color++);
      if (ipt==1.) sep->DrawCopy();
      else         sep->DrawCopy("same");
    }
}
