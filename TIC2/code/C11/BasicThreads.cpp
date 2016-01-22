//: C11:BasicThreads.cpp
// The most basic use of the Thread class.
//{L} Zthread
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

int main() {
  try {
    Thread t;
    t.run(new LiftOff(10));
    cout << "Waiting for LiftOff" << endl;
    t.join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
