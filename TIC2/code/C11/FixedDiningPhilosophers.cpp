//: C11:FixedDiningPhilosophers.cpp
// Dining Philosohophers w/o Deadlock
//{L} Zthread
#include "DiningPhilosophers.h"
using namespace ZThread;
using namespace std;

int main() {
  cout << "Press <ENTER> to quit" << endl;
  try {
    Thread t[PHILOSOPHERS];
    Chopstick c[PHILOSOPHERS];
    for(int i = 0; i < PHILOSOPHERS; i++) {
      int j = (i+1) > (PHILOSOPHERS-1) ? 0 : (i+1);
      if(i < (PHILOSOPHERS-1))
        t[i].run(new Philosopher(c[i], c[j], i));
      else
        t[i].run(new Philosopher(c[j], c[i], i));
    }
    // Wait for any key
    string s;
    getline(cin, s);
    for(int i = 0; i < PHILOSOPHERS; i++)
      t[i].interrupt();
    for(int i = 0; i < PHILOSOPHERS; i++)
      t[i].join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
