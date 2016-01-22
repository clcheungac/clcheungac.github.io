//: C01:Cleanup.cpp
// Exceptions clean up complete objects only
#include <iostream>
using namespace std;

class Trace {
  static int counter;
  int objid;
public:
  Trace() {
    objid = counter++;
    cout << "constructing Trace #" << objid << endl;
    if(objid == 3) throw 3;
  }
  ~Trace() {
    cout << "destructing Trace #" << objid << endl;
  }
};

int Trace::counter = 0;

int main() {
  try {
    Trace n1;
    // Throws exception:
    Trace array[5];
    Trace n2;  // won't get here
  } catch(int i) {
    cout << "caught " << i << endl;
  }
} ///:~
