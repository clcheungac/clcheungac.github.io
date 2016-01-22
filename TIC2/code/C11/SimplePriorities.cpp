//: C11:SimplePriorities.cpp
// Shows the use of thread priorities.
//{L} Zthread
#include <iostream>
#include <cmath>
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

class SimplePriorities : public Runnable {
  Thread& t; // The Thread that's running this task
  int countDown;
  volatile double d; // No optimization
  int id;
  static int threadCount;
public:
  SimplePriorities(Thread& th) : t(th),countDown(5),d(0.0){
    id = threadCount++;
  }
  ~SimplePriorities() throw() {
    cout << id << " completed" << endl;
  }
  friend ostream&
  operator<<(ostream& os, const SimplePriorities& sp) {
    return os << "#" << sp.id << " priority: " 
      << sp.t.getPriority() << " count: "<< sp.countDown;
  }
  void run() throw() {
    while(true) {
      // An expensive, interruptable operation:
      for(int i = 1; i < 100000; i++)
        d = d + (M_PI + M_E) / (double)i;
      cout << *this << endl;
      if(--countDown == 0) return;
    }
  }
};

int SimplePriorities::threadCount = 0;

int main() {
  try {
    Thread h;
    h.setPriority(High);
    h.run(new SimplePriorities(h));
    for(int i = 0; i < 5; i++) {
      Thread* t = new Thread;
      t->setPriority(Low);
      t->run(new SimplePriorities(*t));
    }
    h.join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
