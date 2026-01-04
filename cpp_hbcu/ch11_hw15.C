using namespace std;

void ch11_hw15()
{

  const char *fname = "files.txt";

  ifstream infile( fname );

  string tfilename[1000];

  int nfile = 0;

  while ( infile >> tfilename[nfile] )
  {
    cout<< "processing " << tfilename[nfile] << endl;

    nfile++;

  }

  cout << "Processed " << nfile << " files" << endl;

}

