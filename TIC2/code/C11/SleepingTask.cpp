//: C11:SleepingTask.cpp
// Calling sleep() to pause for awhile.
//{L} Zthread
#include <iostream>
//#include <string>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class SleepingTask : public Runnable {
  int countDown;
  static int threadCount;
  int id;
public:
  SleepingTask() : countDown(5) {
    id = threadCount++;
  }
  ~SleepingTask() throw() {
    cout << id << " completed" << endl;
  }
  friend ostream&
  operator<<(ostream& os, const SleepingTask& st) {
    return os << "#" << st.id << ": " << st.countDown;
  }
  void run() throw() {
    while(true) {
      try {
        cout << *this << endl;
        if(--countDown == 0) return;
        Thread::sleep(100);
      } catch(Interrupted_Exception& e) {
        cerr << e.what() << endl;
      }
    }
  }
};

int SleepingTask::threadCount = 0;

int main() {
  try {
    ThreadedExecutor<Mutex> executor;
    for(int i = 0; i < 5; i++)
      executor.execute(new SleepingTask);
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
