#include <stdlib.h>

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TMap.h"
#include "TClonesArray.h"
#include "TObject.h"
#include "TH1.h"
#include "TString.h"

//______________________________________________________________________________
void x() {

   Int_t comp   = 1;       // by default file is compressed
   Int_t split  = 0;       // by default, split Event in sub branches
   Int_t write  = 1;       // by default the tree is filled

   Int_t testKey[] = {6,10,1,0};
   Int_t testType[] = {1,7,9,23};
   Float_t testE[] = {22.,1.,0.3,4.};

   Int_t nVal = 10;

   TFile *hfile;
   TTree *tree;

   // Fill event, header and tracks with some random numbers

   Int_t nb = 0;
   Int_t ev;
   Int_t bufsize;

/// This file is now becoming the current directory.

   hfile = new TFile("Event.root","RECREATE","TTree benchmark ROOT file");
   hfile->SetCompressionLevel(comp);

// Create a ROOT Tree and one superbranch

   tree = new TTree("T","An example of a ROOT tree");

   // create the map to be written out and an iterator for it

   TClonesArray *testClone = new TClonesArray("TH1F");
   TClonesArray &mcpart = *testClone;

   tree->Branch("testClone", "TClonesArray", &testClone, bufsize,split);

   TString name;
   for (Int_t i=0; i<nVal; ++i) {
     name = "th"; name += i;
   cout << "a " << testClone->GetLast()+1 << endl;
     new(mcpart[i]) TH1F(name,name,10,0,10);

   cout << "b " << testClone->GetLast()+1 << endl;
     printf("Particle type %s \n",((TH1F*)mcpart[i])->GetName());

     if ( i%2==0 ) continue;
     testClone->RemoveAt(i);
   cout << "c " << testClone->GetLast()+1 << endl;
   }

   cout << "d " << testClone->GetLast()+1 << endl;
   testClone->Compress();
   cout << "e " << testClone->GetLast()+1 << endl;

   
   for (Int_t i=0; i<testClone->GetLast()+1; ++i) {
     printf("Particle type %s \n",((TH1F*)mcpart[i])->GetName());
   }


return;

   if (write) {
      nb += tree->Fill();  //fill the tree
      printf(" tree filled with %i bytes \n",nb);

      hfile->Write();
      tree->Print();
   }
   hfile->Close();
   return;
}

