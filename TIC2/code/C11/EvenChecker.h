//: C11:EvenChecker.h
#ifndef EVENCHECKER_H
#define EVENCHECKER_H
#include "zthread/Thread.h"
#include "zthread/Cancelable.h"
#include <iostream>

class Generator : public ZThread::Cancelable {
  static bool quitFlag; // "true" means return from run()
public:
  virtual int getValue() = 0;
  virtual void cancel() { quitFlag = true; }
  virtual bool isCanceled() { return quitFlag; }
  virtual ~Generator() throw() {}
};

class EvenChecker : public ZThread::Runnable, 
public ZThread::Cancelable {
  Generator* generator;
  static int idCounter;
  int id;
  static bool quitFlag;
public:
  EvenChecker(Generator* g) : generator(g) {
    id = idCounter++;
  }
  ~EvenChecker() throw() {
    std::cout << "~EvenChecker " << id << std::endl;
  }
  void run() throw();
  virtual void cancel() { quitFlag = true; }
  virtual bool isCanceled() { return quitFlag; }
};
#endif // EVENCHECKER_H ///:~
