// get the number of lines in a txt file
//

int getlines2(const std::string& fname = "getlines.C")
{
  TString cmd = "wc -l "; cmd += fname; cmd += "| awk '{print $1}'";
  TString retval = gSystem->GetFromPipe( cmd );
  int nlines = retval.Atoi();
  cout << nlines << endl;

  return nlines;
}

int getlines(const std::string& fname = "getlines.C")
{
  ifstream infile(fname);

  int nlines = 0;

  string line;
  while ( getline(infile,line) )
  {
    nlines++;
  }
  // return pointer to beginning of file
  infile.clear();
  infile.seekg( 0, ios::beg );
  cout << nlines << endl;

  return nlines;
}

