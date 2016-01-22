//: C10:UseLog2.cpp
//{L} LogFile UseLog1
#include "UseLog1.h"
#include "LogFile.h"
using namespace std;

void g() {
  logfile() << __FILE__ << endl;
} 

int main() {
  f();
  g();
} ///:~
