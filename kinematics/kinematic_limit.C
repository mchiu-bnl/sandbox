// plot kinematic limit to pt
void kinematic_limit()
{
  TF1 *tf1 = new TF1("tf1","[0]*sin(2*atan(exp(-x)))",-5.5,5.5);
  tf1->SetParameter(0,100.);	// proton beam energy
  tf1->GetHistogram()->SetXTitle("pseudorapidity");
  tf1->GetHistogram()->SetYTitle("kinematic limit in pt");
  tf1->Draw();
}
