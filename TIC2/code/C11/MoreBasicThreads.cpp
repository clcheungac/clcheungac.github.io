//: C11:MoreBasicThreads.cpp
// Adding more threads.
//{L} Zthread
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

int main() {
  const int sz = 5;
  try {
    Thread t[sz];
    for(int i = 0; i < sz; i++)
      t[i].run(new LiftOff(10, i));
    cout << "Waiting for LiftOff" << endl;
    for(int i = 0; i < sz; i++)
      t[i].join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
