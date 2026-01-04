// Christian Holm Christensen

// The following is a skeleton for a macro that can be executed in
// CINT and compiled. 

// ----------------------------------------------------------------------
#ifndef __CINT__ 
// Include all needed headers here 
#endif 

void foo() 
{ 
  // Put your function body here. 
  
} 

#ifndef __CINT__ 
int main(int argc, char** argv) 
{ 
  // If you need graphics, uncomment the next line 
  // TApplication fooApp("fooApp", &argc, argv); 
  
  // Call you script function 
  foo(); 

  // If you need graphics, uncomment the next line 
  // fooApp.Run();

  return 0;
}
#endif 
// ----------------------------------------------------------------------

//  This file can used with interactive ROOT as: 
//
//    Root> .x foo.C 
//
//  or you can compile it to a program with 
//
//    g++ -g -O2 -Wall `root-config --cflags --libs` foo.C -o foo 
//
//  and execute it as 
//  
//    ./foo 
//

