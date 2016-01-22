//: C11:YieldingTask.cpp
// Suggesting when to switch threads with yield().
//{L} Zthread
#include <iostream>
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

class YieldingTask : public Runnable {
  int countDown;
  int id;
  static int threadCount;
public:
  YieldingTask() : countDown(5) {
    id = threadCount++;
  }
  ~YieldingTask() throw() {
    cout << id << " completed" << endl;
  }
  friend ostream&
  operator<<(ostream& os, const YieldingTask& yt) {
    return os << "#" << yt.id << ": " << yt.countDown;
  }
  void run() throw() {
    while(true) {
      cout << *this << endl;
      if(--countDown == 0) return;
      Thread::yield();
    }
  }
};

int YieldingTask::threadCount = 0;

int main() {
  try {
    ThreadedExecutor<Mutex> executor;
    for(int i = 0; i < 5; i++)
      executor.execute(new YieldingTask);
    executor.cancel();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
