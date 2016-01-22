//: C11:TimedLocking.cpp
// Limited time locking.
//{L} Zthread
#include "zthread/Mutex.h"
#include "zthread/Thread.h"
using namespace ZThread;

class TimedLocking {
  Mutex lock;
public:
  void f() {
    Guard<Mutex, TimedLockedScope<500> > g(lock);
    // ...
  }
};

int main() {
  TimedLocking t;
  t.f();
} ///:~
