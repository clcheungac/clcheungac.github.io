//: C11:PoolExecutor.cpp
//{L} Zthread
#include "zthread/PoolExecutor.h"
#include "zthread/Mutex.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

int main() {
  try {
    // Constructor argument is minimum number of threads:
    PoolExecutor<Mutex> executor(5);
    for(int i = 0; i < 5; i++)
      executor.execute(new LiftOff(10, i));
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
