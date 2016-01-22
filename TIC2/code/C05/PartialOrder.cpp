//: C05:PartialOrder.cpp
// Reveals Ordering of Function Templates
#include <iostream>
using namespace std;

template<class T>
void f(T) {
  cout << "T\n";
}

template<class T>
void f(T*) {
  cout << "T*\n";
}

template<class T>
void f(const T*) {
  cout << "const T*\n";
}

int main() {
  f(0);            // T
  int i = 0;
  f(&i);           // T*
  const int j = 0;
  f(&j);           // const T*
} ///:~
