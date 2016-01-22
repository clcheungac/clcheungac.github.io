//: C11:Interrupting3.cpp
// General idiom for interrupting a task.
//{L} Zthread
#include "zthread/Thread.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace ZThread;
using namespace std;

class NeedsCleanup {
  int id;
public:
  NeedsCleanup(int ident) : id(ident) {
    cout << "NeedsCleanup " << id << endl;
  }
  ~NeedsCleanup() {
    cout << "~NeedsCleanup " << id << endl;
  }
};

class Blocked3 : public Runnable {
  volatile double d;
public:
  Blocked3() : d(0.0) {}
  void run() throw() {
    try {
      while(!Thread::interrupted()) {
        point1:
        NeedsCleanup n1(1);
        cout << "Sleeping" << endl;
        Thread::sleep(1000);
        point2:
        NeedsCleanup n2(2);
        cout << "Calculating" << endl;
        // A time-consuming, non-blocking operation:
        for(int i = 1; i < 100000; i++)
          d = d + (M_PI + M_E) / (double)i;
      }
      cout << "Exiting via while() test" << endl;
    } catch(Interrupted_Exception&) {
      cout << "Exiting via Interrupted_Exception" << endl; 
    } catch(Synchronization_Exception& e) {
      cerr << e.what() << endl;
    }
  }
};

int main(int argc, char* argv[]) {
  if(argc != 2) {
    cerr << "usage: " << argv[0] 
      << " delay-in-milliseconds" << endl;
    exit(1);
  }
  int delay = atoi(argv[1]);
  try {
    Thread t;
    t.run(new Blocked3);
    Thread::sleep(delay);
    t.interrupt();
    t.join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
