#include <TROOT.h>
#include <TSystem.h>
#include <TSystemDirectory.h>
#include <TSystemFile.h>
//
// get list of system directory contents
//
void x()
{
  //gSystem->Load();
  gSystem->Exec("pwd");
  const char *current_dir = gSystem->Getenv("PWD");
  cout << "pwd " << current_dir << endl;

  TSystemDirectory sysdir("/phenix/u/chiu/","/phenix/u/chiu/sandbox");
  gSystem->Exec("pwd");
  TList *flist = sysdir.GetListOfFiles();

  gSystem->Exec("pwd");

  //GetListOfPrimitives()->R__FOR_EACH(TObject,Paint)(option);
  TIter next(flist);
  TSystemFile *f;
  while ( f = (TSystemFile*)next() )
    {
      cout << f->GetName() << endl;
    }

  gSystem->Exec("pwd");

  delete flist;

  //TSystemDirectory origdir("origdir",current_dir);
  sysdir.SetDirectory(current_dir);
  flist = sysdir.GetListOfFiles();
  delete flist;

  gSystem->Exec("pwd");
  
}
