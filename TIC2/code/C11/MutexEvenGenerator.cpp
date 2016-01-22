//: C11:MutexEvenGenerator.cpp
// Preventing thread collisions with mutexes.
//{L} EvenChecker Zthread
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class MutexEvenGenerator : 
public Generator, public Runnable {
  int currentEvenValue;
  Mutex lock;
public:
  MutexEvenGenerator() { currentEvenValue = 0; }
  ~MutexEvenGenerator() throw() {
    cout << "~MutexEvenGenerator" << endl;
  }
  int getValue() { 
    lock.acquire();
    int rval = currentEvenValue;
    lock.release();
    return rval;
  }
  void run() throw() {
    while(!isCanceled()) {
      lock.acquire();
      currentEvenValue++;
      Thread::yield();
      currentEvenValue++;
      lock.release();
    }
  }
};

int main() {
  try {
    ThreadedExecutor<Mutex> executor;
    MutexEvenGenerator* eg = new MutexEvenGenerator;
    executor.execute(eg);
    for(int i = 0; i < 10; i++)
      executor.execute(new EvenChecker(eg));
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
