//: C05:Lookup2.cpp
//{-bor}
//{-g++}
// Microsoft: use option -Za (ANSI mode)
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;

void g() { cout << "global g()\n"; }

template <class T>
class Y {
public:
  void g() { cout << "Y<" << typeid(T).name()
                  << ">::g()\n"; }
  void h() { cout << "Y<" << typeid(T).name()
                  << ">::h()\n"; }
  typedef int E;
};

typedef double E;

template<class T>
void swap(T& t1, T& t2) {
  cout << "global swap\n";
  T temp = t1;
  t1 = t2;
  t2 = temp;
}

template<class T>
class X : public Y<T> {
public:
  E f() {
    g();
    this->h();
    T t1 = T(), t2 = T(1);
    cout << t1 << endl;
    swap(t1, t2);
    std::swap(t1, t2);
    cout << typeid(E).name() << endl;
    return E(t2);
  }
};

int main() {
  X<int> x;
  cout << x.f() << endl;
} ///:~
