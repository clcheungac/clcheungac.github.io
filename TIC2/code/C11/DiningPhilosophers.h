//: C11:DiningPhilosophers.h
// Classes for Dining Philosohophers
#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H
//#include "Random.h"
#include "zthread/Condition.h"
#include "zthread/Guard.h"
#include "zthread/Mutex.h"
#include "zthread/Singleton.h"
#include "zthread/Thread.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

static const int PHILOSOPHERS = 5;

class Philosopher;

class Display {
  ZThread::Mutex lock;
public:
  void thinking(const Philosopher& p);
  void eating(const Philosopher& p);
  void left(const Philosopher& p);
  void right(const Philosopher& p);
};

class Chopstick {
  ZThread::Mutex lock;
  ZThread::Condition notTaken;
  bool taken;
public:
  Chopstick() : notTaken(lock), taken(false) {}
  void take() {
    ZThread::Guard<ZThread::Mutex> g(lock);
    while(taken)
      notTaken.wait();
    taken = true;
  }
  void drop() {
    ZThread::Guard<ZThread::Mutex> g(lock);
    taken = false;
    notTaken.signal();
  }
};

class Philosopher : public ZThread::Runnable {
  Chopstick& left;
  Chopstick& right;
  int id; 
  //Random random;
public:
  Philosopher(Chopstick& l, Chopstick& r, int ident) 
    : left(l), right(r), id(ident) {
    srand(time(0));
  }
  virtual ~Philosopher() throw() {}
  static int randSleepTime() {
    return rand()/(RAND_MAX/5)*1000;
  }
  virtual void run() throw() {
    try {
      while(!ZThread::Thread::interrupted()) {
        ZThread::Singleton<Display>::
          instance()->thinking(*this);
        ZThread::Thread::sleep(randSleepTime());
        // Hungry
        ZThread::Singleton<Display>::
          instance()->right(*this);
        right.take();
        ZThread::Singleton<Display>::
          instance()->left(*this);
        left.take();        
        // Eating
        ZThread::Singleton<Display>::
          instance()->eating(*this);
        ZThread::Thread::sleep(randSleepTime());     
        right.drop();
        left.drop();
      }
    } catch(ZThread::Synchronization_Exception& e) {
      std::cerr << *this << e.what() << std::endl;
    }
  }
  int identity() const { return id; }
  friend std::ostream& 
  operator<<(std::ostream& os, const Philosopher& p) {
    return os << "Philosopher " << p.identity();
  }
};

inline void Display::thinking(const Philosopher& p) {
  ZThread::Guard<ZThread::Mutex> g(lock);
  std::cout << p << " thinking" << std::endl;
}

inline void Display::eating(const Philosopher& p) {
  ZThread::Guard<ZThread::Mutex> g(lock);
  std::cout << p << " eating" << std::endl;
}

inline void Display::left(const Philosopher& p) {
  ZThread::Guard<ZThread::Mutex> g(lock);
  std::cout << p << " grabbing left" << std::endl;
}

inline void Display::right(const Philosopher& p) {
  ZThread::Guard<ZThread::Mutex> g(lock);
  std::cout << p << " grabbing right" << std::endl;
}
#endif // DININGPHILOSOPHERS_H ///:~
