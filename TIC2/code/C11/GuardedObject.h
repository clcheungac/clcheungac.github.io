//: C11:GuardedObject.h
// Transferred Locking Scope, used to create a
// GuardedObject template. A GuardedObject will
// automatically lock and unlock an internal Lockable
// object as each member function invocation 
// begins and ends.
#ifndef GUARDEDOBJECT_H
#define GUARDEDOBJECT_H
#include "zthread/Mutex.h"
#include "zthread/Thread.h"

namespace ZThread {

template <class T, class LockType = Mutex>
class GuardedObject {
  LockType _lock;
  T _p;
  GuardedObject(const GuardedObject&);
  GuardedObject& operator=(const GuardedObject&);
public:
  class TransferedScope {
  public:
    template <class LockType1, class LockType2>
    static void shareScope(LockHolder<LockType1>& l1,
                           LockHolder<LockType2>& l2) {
      l1.disable();
      l2.getLock().acquire();
    }
    template <class LockType1>
    static void createScope(LockHolder<LockType1>& l) {
      // Don't acquire the lock when created
    }
    template <class LockType1>
    static void destroyScope(LockHolder<LockType1>& l) {
      l.getLock().release();
    }
  };

  class Proxy : Guard<LockType, TransferedScope> {
    T& _object;
  public:
    Proxy(LockType& lock, T& object)
     : Guard<LockType, TransferedScope>(lock),
       _object(object) { }
    T* operator->() { return &_object; }
  };

public:
  GuardedObject() {}
  Proxy operator->() {
    Proxy p(_lock, _p);
    return p;
  }
};

} // End of namespace
#endif // GUARDEDOBJECT_H ///:~
