//: C09:Interfaces2.cpp
// Implicit interface inheritance via templates
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Able {
  int myData;
public:
  Able(int x) {
    myData = x;
  }
  void print(ostream& os) const {
    os << myData;
  }
  int toInt() const {
    return myData;
  }
  string toString() const {
    ostringstream os;
    os << myData;
    return os.str();
  }
};

template<class Printable>
void testPrintable(const Printable& p) {
  p.print(cout);
  cout << endl;
}
template<class Intable>
void testIntable(const Intable& n) {
  int i = n.toInt() + 1;
  cout << i << endl;
}
template<class Stringable>
void testStringable(const Stringable& s) {
  string buf = s.toString() + "th";
  cout << buf << endl;
}

int main() {
  Able a(7);
  testPrintable(a);
  testIntable(a);
  testStringable(a);
} ///:~
