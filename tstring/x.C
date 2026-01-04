void x()
{
  TString s("/a/b/c/dst.root");
  //TString s("dst.root");
  cout << s << endl;
  int index = s.Last("dst");
  cout << index << endl;
  if ( index>=0 ) s.Remove(0,index+1);
  cout << s << endl;
}
