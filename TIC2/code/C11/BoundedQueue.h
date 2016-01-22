//: C11:BoundedQueue.h
#ifndef BOUNDEDQUEUE_H
#define BOUNDEDQUEUE_H
#include "zthread/Thread.h"
#include "zthread/Condition.h"
#include "zthread/Mutex.h"
#include <deque>

template<class T> class BoundedQueue {
  ZThread::Mutex lock;
  ZThread::Condition cond;
  std::deque<T> data;
public:
  BoundedQueue() : cond(lock) {}
  void put(T item) {
    ZThread::Guard<ZThread::Mutex> g(lock);
    data.push_back(item);
    cond.signal();
  }
  T get() {
    ZThread::Guard<ZThread::Mutex> g(lock);
    while(data.empty())
      cond.wait();
    T returnVal = data.front();
    data.pop_front();
    return returnVal;
  }
};
#endif // BOUNDEDQUEUE_H ///:~
