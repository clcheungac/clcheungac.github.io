//: C11:TestGuardedObjectTemplate.cpp
//{L} Zthread
#include "GuardedObject.h"
using namespace ZThread;

class MyClass {
public:
  void func1() {}
  void func2() {}
};

int main() {
  MyClass a;
  a.func1(); // not synchronized
  a.func2(); // not synchronized
  GuardedObject<MyClass> b;
  b->func1(); // synchronized, only one thread at a time
  b->func2(); // synchronized, only one thread at a time
} ///:~
