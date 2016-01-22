//: C11:SynchronousExecutor.cpp
//{L} Zthread
#include "zthread/SynchronousExecutor.h"
#include "zthread/Mutex.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

int main() {
  try {
    SynchronousExecutor<Mutex> executor;
    for(int i = 0; i < 5; i++)
      executor.execute(new LiftOff(10, i));
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
