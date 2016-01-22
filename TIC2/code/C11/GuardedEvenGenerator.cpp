//: C11:GuardedEvenGenerator.cpp
// Simplifying mutexes with the Guard template.
//{L} EvenChecker Zthread
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class GuardedEvenGenerator : 
public Generator, public Runnable {
  int currentEvenValue;
  Mutex lock;
public:
  GuardedEvenGenerator() { currentEvenValue = 0; }
  ~GuardedEvenGenerator() throw() {
    cout << "~GuardedEvenGenerator" << endl;
  }
  int getValue() { 
    Guard<Mutex> g(lock);
    return currentEvenValue;
  }
  void run() throw() {
    while(!isCanceled()) {
      Guard<Mutex> g(lock);
      currentEvenValue++;
      Thread::yield();
      currentEvenValue++;
    }
  }
};

int main() {
  try {
    ThreadedExecutor<Mutex> executor;
    GuardedEvenGenerator* eg = new GuardedEvenGenerator;
    executor.execute(eg);
    for(int i = 0; i < 10; i++)
      executor.execute(new EvenChecker(eg));
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
