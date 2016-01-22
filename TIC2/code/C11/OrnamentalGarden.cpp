//: C11:OrnamentalGarden.cpp
//{L} Zthread
#include "zthread/Thread.h"
#include "zthread/Mutex.h"
#include "zthread/Guard.h"
#include "zthread/ThreadedExecutor.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace ZThread;
using namespace std;

class Count {
  Mutex lock;
  int value;
public:
  Count() : value(0) {
    srand(time(0)); // Seed the random number generator
  }
  int increment() {
    // Comment the following line to see counting fail:
    Guard<Mutex> g(lock);
    int temp = value;
    if(rand() < RAND_MAX/2) // Yield half the time
      Thread::yield();
    return (value = ++temp);
  }
  int operator()() { return value; }
};

class Entrance : public Runnable, public Cancelable {
  static Count count;
  int value;
  static vector<Entrance*> entrances;
  int id;
  static bool quitFlag;
  static Mutex lock, iolock;
  void show(int total) {
    // Lock on a static Mutex so multiple instances of
    // this task can't collide with each other over output:
    Guard<Mutex> g(iolock);
    cout << *this << " Total: " << total << endl;
  }
public:
  Entrance(int n) : value(0), id(n) {
    entrances.push_back(this);
  }
  static int total() { return count(); }
  static int sumOfEntrances() {
    int sum = 0;
    vector<Entrance*>::iterator it = entrances.begin();
    while(it != entrances.end()) {
      sum += (*it)->value;
      it++;
    }
    return sum;
  }
  void run() throw() {
    try {
      while(!isCanceled()) {
        value++;
        show(count.increment());
        Thread::sleep(100);
      }
    } catch(Synchronization_Exception& e) {
      Guard<Mutex> g(iolock);
      cerr << *this << ": " << e.what() << endl;
    }
    Guard<Mutex> g(iolock);
    cout << "Exiting " << *this << endl;
  }
  void cancel() {
    Guard<Mutex> g(lock);
    quitFlag = true;
  }
  bool isCanceled() {
    Guard<Mutex> g(lock);
    return quitFlag;
  }
  friend ostream&
  operator<<(ostream& os, const Entrance& e) {
    return os << "Entrance " << e.id << ": " << e.value;
  }
};

Count Entrance::count;
Mutex Entrance::lock, Entrance::iolock;
vector<Entrance*> Entrance::entrances;
bool Entrance::quitFlag = false;

int main() {
  cout << "Press <ENTER> to quit" << endl;
  Entrance* e[] = { new Entrance(1), new Entrance(2) };
  try {
    ThreadedExecutor<Mutex> executor;
    for(int i = 0; i < sizeof e/sizeof *e; i++)
      executor.execute(e[i]);
    cin.get();
    for(int i = 0; i < sizeof e/sizeof *e; i++)
      e[i]->cancel();
    cout << "Total: " << Entrance::total() << endl
      << "Sum of Entrances: " 
      << Entrance::sumOfEntrances() << endl;
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
