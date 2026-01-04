void tform()
{
  TString t = Form("%3d",10);
  //cout << t << endl;
  TString t2(" 10     xxxxx");

  if ( t2.BeginsWith( t ) )
  {
    cout << t2 << endl;
  }
}
