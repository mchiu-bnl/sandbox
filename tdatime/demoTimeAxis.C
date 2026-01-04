void demoTimeAxis()
{

  TTimeStamp startTime(2010,07,21,13,0,0, 0, kTRUE);
  TTimeStamp stopTime (2010,07,21,15,0,0, 0, kTRUE);

  TH1F *h1  = new TH1F("h1" ,"h1",100, startTime.GetSec(), stopTime.GetSec() );

  gStyle->SetTimeOffset(startTime);

  //h1->GetXaxis()->SetTimeOffset(0,"gmt");
  h1->GetXaxis()->SetTimeFormat("%Hh%M %d/%m/%Y");
  h1->GetXaxis()->SetTimeDisplay(1);

  h1->GetXaxis()->SetLabelOffset(0.048);
  h1->GetXaxis()->SetLabelSize(0.02);
  h1->GetXaxis()->SetNdivisions(-507);
  h1->Draw();
}
