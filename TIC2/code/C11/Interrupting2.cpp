//: C11:Interrupting2.cpp
// Interrupting a thread blocked 
// with a synchronization guard.
//{L} Zthread
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class BlockedMutex {
  Mutex lock;
public:
  BlockedMutex() {
    lock.acquire();
  }
  void f() {
    Guard<Mutex> g(lock);
    // This will never be available
  }
};

class Blocked2 : public Runnable {
  BlockedMutex blocked;
public:
  void run() throw() {
    try {
      cout << "Waiting for f() in BlockedMutex" << endl;
      blocked.f();
    } catch(Interrupted_Exception& e) {
      cerr << e.what() << endl;
      // Exit the task
    }
  }
};

int main(int argc, char* argv[]) {
  try {
    Thread t;
    t.run(new Blocked2);
    t.interrupt();
    t.join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
