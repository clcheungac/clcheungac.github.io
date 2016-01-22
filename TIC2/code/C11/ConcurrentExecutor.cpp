//: C11:ConcurrentExecutor.cpp
//{L} Zthread
#include "zthread/ConcurrentExecutor.h"
#include "zthread/Mutex.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

int main() {
  try {
    ConcurrentExecutor<Mutex> executor;
    for(int i = 0; i < 5; i++)
      executor.execute(new LiftOff(10, i));
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
