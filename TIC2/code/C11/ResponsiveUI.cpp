//: C11:ResponsiveUI.cpp
// Changed to create a responsive interface
//{L} Zthread
#include "zthread/Thread.h"
#include <iostream>
#include <fstream>
using namespace ZThread;
using namespace std;

class DisplayTask : public Runnable {
  ifstream in;
  static const int SZ = 100;
  char buf[SZ];
  bool quitFlag;
public:
  DisplayTask(const string& file) : quitFlag(false) {
    in.open(file.c_str());
  }
  ~DisplayTask() throw() { in.close(); }
  void run() throw() {
    while(in.getline(buf, SZ) && !quitFlag) {
      cout << buf << endl;
      Thread::sleep(1000);
    }
  }
  void stop() { quitFlag = true; }
};

int main() {
  try {
    Thread t;
    cout << "Press <Enter> to quit:" << endl;
    DisplayTask* dt = new DisplayTask("ResponsiveUI.cpp");
    t.run(dt);
    cin.get();
    dt->stop();
    t.join();
  } catch(Synchronization_Exception& e) {
    cerr << e.what() << endl;
  }
  cout << "Shutting down..." << endl;
} ///:~
