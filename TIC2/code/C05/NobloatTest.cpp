//: C05:NobloatTest.cpp
#include <iostream>
#include <string>
#include "Nobloat.h"
using namespace std;

template<class StackType>
void emptyStack(StackType& stk) {
  while (stk.size() > 0) {
    cout << stk.top() << endl;
    stk.pop();
  }
}
// An overload for emptyStack (not a specialization!)
template<class T>
void emptyStack(Stack<T*>& stk) {
  while (stk.size() > 0) {
    cout << *stk.top() << endl;
    stk.pop();
  }
}

int main() {
  Stack<int> s1;
  s1.push(1);
  s1.push(2);
  emptyStack(s1);

  Stack<int *> s2;
  int i = 3;
  int j = 4;
  s2.push(&i);
  s2.push(&j);
  emptyStack(s2);
} ///:~
