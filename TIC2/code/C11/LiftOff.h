//: C11:LiftOff.h
// Demonstration of the Runnable interface.
#ifndef LIFTOFF_H
#define LIFTOFF_H
#include "zthread/Runnable.h"
#include <iostream>

class LiftOff : public ZThread::Runnable {
  int countDown;
  int id;
public:
  LiftOff(int count, int ident = 0) : 
    countDown(count), id(ident) {}
  ~LiftOff() throw() { 
    std::cout << id << " completed" << std::endl;
  }
  void run() throw() {
    while(countDown--)
      std::cout << id << ":" << countDown << std::endl;
    std::cout << "Liftoff!" << std::endl;
  }
};
#endif // LIFTOFF_H ///:~
