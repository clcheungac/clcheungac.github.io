//: C11:EvenGenerator.cpp
// When threads collide.
//{L} EvenChecker Zthread
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
#include "zthread/Mutex.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class EvenGenerator : public Generator, public Runnable {
  int currentEvenValue;
public:
  EvenGenerator() { currentEvenValue = 0; }
  ~EvenGenerator() throw() {
    cout << "~EvenGenerator" << endl;
  }
  int getValue() { return currentEvenValue; }
  void run() throw() {
    while(!isCanceled()) {
      currentEvenValue++; // Danger point here!
      currentEvenValue++;
    }
  }
};

int main() {
  try {
    ThreadedExecutor<Mutex> executor;
    EvenGenerator* eg = new EvenGenerator;
    executor.execute(eg);
    for(int i = 0; i < 10; i++)
      executor.execute(new EvenChecker(eg));
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
