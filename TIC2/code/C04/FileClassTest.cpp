//: C04:FileClassTest.cpp
// Tests FileClass
//{L} FileClass
#include <cstdlib>
#include <iostream>
#include "FileClass.h"
using namespace std;

int main() {
  try {
    FileClass f("FileClassTest.cpp");  
    const int BSIZE = 100;
    char buf[BSIZE];
    while(fgets(buf, BSIZE, f.fp()))
      fputs(buf, stdout);
  }
  catch(FileClass::FileClassError& e) {
    cout << e.what() << endl;
    return EXIT_FAILURE;    
  }
  return EXIT_SUCCESS;
} // File automatically closed by destructor
///:~
