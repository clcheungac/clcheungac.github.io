//: C11:Interrupting.cpp
// Interrupting a blocked thread.
//{L} Zthread
#include "zthread/Thread.h"
#include <iostream>
using namespace ZThread;
using namespace std;

class Blocked : public Runnable {
public:
  void run() throw() {
    try {
      Thread::sleep(1000);
      cout << "Waiting for get() in run():";
      cin.get();
    } catch(Interrupted_Exception&) {
      cout << "Caught Interrupted_Exception" << endl; 
      // Exit the task
    } catch(Synchronization_Exception& e) {
      cerr << e.what() << endl;
    }
  }
};

int main(int argc, char* argv[]) {
  try {
    Thread t;
    t.run(new Blocked);
    if(argc > 1)
      Thread::sleep(1100);
    t.interrupt();
    t.join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
} ///:~
