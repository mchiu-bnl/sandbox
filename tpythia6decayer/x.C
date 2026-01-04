void x()
{
  gSystem->Load("libPhysics.so");
  gSystem->Load("libPhysics.so");

  TPythia6Decayer* decayer = TPythia6Decayer::Instance();
	// The following just tells pythia6 to not decay particles only to
	// certain channels.
  decayer->SetForceDecay(TPythia6Decayer::kAll);
  decayer->Init();
}
