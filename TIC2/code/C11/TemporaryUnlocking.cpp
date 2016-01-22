//: C11:TemporaryUnlocking.cpp
// Temporarily unlocking another guard.
//{L} Zthread
#include "zthread/Mutex.h"
#include "zthread/Thread.h"
using namespace ZThread;

class TemporaryUnlocking {
  Mutex lock;
public:
  void f() {
    Guard<Mutex> g(lock);
    // lock is acquired
    // ...
    {
      Guard<Mutex, UnlockedScope> h(g);
      // lock is released
      // ...
      // lock is acquired
    }
    // ...
    // lock is released
  }
};

int main() {
  TemporaryUnlocking t;
  t.f();
} ///:~
