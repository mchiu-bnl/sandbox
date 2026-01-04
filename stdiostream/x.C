void x()
{
  string FullLine;
  string label;

  double value;

  ifstream infile("a.cfg");
  // get one line first 
  getline(infile, FullLine);
  while ( !infile.eof() )
  {
    
    // skip lines that begin with #, or "//"
    if ( FullLine[0]=='#' || FullLine.substr(0, 2) == "//" )
    {
      getline(infile,FullLine);
      continue;
    }
    
    // make FullLine an istringstream
    istringstream line( FullLine.c_str() );
    
    // get label
    line >> label;
    
    // to lower case
    //std::transform(label.begin(), label.end(), label.begin(), (int(*)(int)) std::tolower);
    
    // based on label, fill correct item
    if ( label == "nevents" )
    {
      line >> _nevents;
      cout << "nevents\t" << _nevents << endl;
    }
    else if ( label == "p1" )
      {
        char a[10000];
        strcpy(a,FullLine.c_str());
        char *sptr = strtok(a," \t");
        sptr = strtok(NULL," \t");
        while ( sptr != NULL )
          {
            cout << "tok\t" << sptr << endl;
            sptr = strtok(NULL," \t");
          }
      }

    getline( infile, FullLine );

  }
}
