//: C11:SleepingBarber.cpp
// The Sleeping Barber problem.
//{L} Zthread
#include "zthread/CountingSemaphore.h"
#include "zthread/Semaphore.h"
#include "zthread/Thread.h"
#include "zthread/Singleton.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class Display {
  Mutex lock;
public:
  void barberSleep() {
    Guard<Mutex> g(lock);
    cout << "Barber sleeping..." << endl;
  }
  void barberAwake() {
    Guard<Mutex> g(lock);
    cout << "Barber awakened, cutting hair" << endl;
  }
  void barberDone() {
    Guard<Mutex> g(lock);
    cout << "Barber finished cutting hair" << endl;
  }
  void shopEnter(int id) {
    Guard<Mutex> g(lock);
    cout << "Customer " << id
    << " entering shop, waiting for barber." << endl;
  }
  void shopExit(int id) {
    Guard<Mutex> g(lock);
    cout << "Customer " << id
      << " woke up, leaving shop." << endl;
  }
  void shopFull(int id) {
    Guard<Mutex> g(lock);
    cout << "Barber shop full!, Customer " << id
      << " leaving." << endl;
  }
  void shopHaircut(int id) {
    Guard<Mutex> g(lock);
    cout << "Customer " << id
      << " getting haircut." << endl;
  }
};

class Generator {
  Mutex lock;
  int id;
public:
  Generator() : id(0) {}
  int next() {
    Guard<Mutex> g(lock);
    return ++id;
  }
};

class BarberShop {
  //! Customers waiting for a haircut
  CountingSemaphore customer;
  //! Haircut completed
  CountingSemaphore barber;
  //! Keep track of when a customer is done
  Semaphore complete;
  //! Serialize data access
  Semaphore mutex;
  //! Number of seats in the shop
  int seats;
  int waiting;
public:
  BarberShop(int n = 3)
  : customer(0), barber(0), complete(0), mutex(1) {
    waiting = 0;
    seats = n;
  }
  void waitForHaircut(int id) {
    mutex.wait();
    // Leave if the shop is full
    if(waiting < seats) {
      waiting++;
      Singleton<Display>::instance()->shopEnter(id);
      // Let the barber know someone is waiting
      customer.post();
      mutex.post();
      // Wait for the barber to wake up or to
      // finish with someone's hair
      barber.wait();
      Singleton<Display>::instance()->shopHaircut(id);
      // Let the barber know the customer woke up
      complete.post();
      Singleton<Display>::instance()->shopExit(id);
    } else {
      Singleton<Display>::instance()->shopFull(id);
      mutex.post();
    }
  }
  void waitForCustomer() {
    Singleton<Display>::instance()->barberSleep();
    // Wait for a customer to show up
    customer.wait();
    Singleton<Display>::instance()->barberAwake();
    // Serialize access to the waiting variable
    mutex.wait();
    // Update the waiter count
    waiting--;
    barber.post();
    mutex.post();
    // Wait for the customer to wake up
    complete.wait();
    Singleton<Display>::instance()->barberDone();
  }
};

class Customer : public Runnable {
  BarberShop& shop;
  int id;
public:
  Customer(BarberShop& bs) : shop(bs) {
    id = Singleton<Generator>::instance()->next();
  }
  virtual ~Customer() throw() {}
  virtual void run() throw() {
    try {
      // Precondition based on interruption
      while(!Thread::interrupted()) {
        shop.waitForHaircut(id);
        // Pause before trying again:
        Thread::sleep(2000);
      }
    } catch(Interrupted_Exception&) {
      // Signal to quit
    } catch(Synchronization_Exception& e) {
      cerr << e.what() << endl;
    }
  }
};

class Barber : public Runnable {
  BarberShop& shop;
public:
  Barber(BarberShop& bs) : shop(bs) {}
  virtual ~Barber() throw() {}
  virtual void run() throw() {
    try {
      // Precondition based on interruption
      while(!Thread::interrupted())
        shop.waitForCustomer();
    } catch(Interrupted_Exception&) {
      // Signal to quit
    } catch(Synchronization_Exception& e) {
      cerr << e.what() << endl;
    }
  }
};

int main() {
  try {
    Thread t[8];
    BarberShop shop;
    t[7].run(new Barber(shop));
    for(int i = 0; i < 7; i++)
      t[i].run(new Customer(shop));
    // Run for 10 seconds
    Thread::sleep(10000);
    // Communicate with any running tasks
    for(int i = 0; i < 8; i++)
      t[i].interrupt();
    // Join instead of using daemon threads. These
    // tasks are all sharing that BarberShop object
    // which lives on the stack and we need to be
    // sure that object will not be deleted before
    // the threads are all done
    for(int i = 0; i < 8; i++)
      t[i].join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
