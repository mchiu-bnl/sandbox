
void tttimestamp()
{
  TTimeStamp *tt = new TTimeStamp();

  TString ttext = "";
  ttext += tt->GetDate(kFALSE);
  ttext += tt->GetTime(kFALSE);

  cout << ttext << endl;
}
