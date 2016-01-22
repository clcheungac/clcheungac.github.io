//: C05:FuncDef.cpp
#include <iostream>
using namespace std;

template<class T>
T sum(T* b, T* e, T init = T()) {
  while (b != e)
    init += *b++;
  return init;
}

int main() {
  int a[] = {1,2,3};
  cout << sum(a, a+sizeof a / sizeof a[0]) << endl; // 6
} ///:~
