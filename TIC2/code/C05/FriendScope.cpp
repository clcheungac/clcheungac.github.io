//: C05:FriendScope.cpp
#include <iostream>
using namespace std;

class Friendly {
  int i;
public:
  Friendly(int theInt) { i = theInt; }
  friend void f(const Friendly&); // needs global def.
  void g() { f(*this); }
};

void h() {
  f(Friendly(1));  // uses ADL
}

void f(const Friendly& fo) {  // definition of friend
  cout << fo.i << endl;
}

int main() {
  h();			// prints 1
  Friendly(2).g();	// prints 2
} ///:~
