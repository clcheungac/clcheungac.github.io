//: C05:FriendScope3.cpp
//{-bor}
// Microsoft: use the -Za (ANSI-compliant) option
#include <iostream>
using namespace std;

template<class T>
class Friendly {
  T t;
public:
  Friendly(const T& theT) : t(theT) {}
  friend void f(const Friendly<T>& fo) {
    cout << fo.t << endl;
}
  void g() { f(*this); }
};

void h() {
  f(Friendly<int>(1));
}

int main() {
  h();
  Friendly<int>(2).g();
} ///:~
