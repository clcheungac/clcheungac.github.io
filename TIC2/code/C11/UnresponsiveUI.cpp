//: C11:UnresponsiveUI.cpp
// Lack of threading produces an unresponsive UI.
//{L} Zthread
#include "zthread/Thread.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace ZThread;

int main() {
  const int SZ = 100; // Buffer size;
  char buf[SZ];
  cout << "Press <Enter> to quit:" << endl;
  ifstream file("UnresponsiveUI.cpp");
  while(file.getline(buf, SZ)) {
    cout << buf << endl;
    Thread::sleep(1000); // Time in milliseconds
  }
  // Read input from the console
  cin.get();
  cout << "Shutting down..." << endl;
} ///:~
