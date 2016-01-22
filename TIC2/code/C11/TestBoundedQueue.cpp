//: C11:TestBoundedQueue.cpp
//{L} Zthread
#include <string>
#include <iostream>
#include "BoundedQueue.h"
using namespace ZThread;
using namespace std;

int main() {
  BoundedQueue<string> stringQueue;
  stringQueue.put("Hello, ");
  stringQueue.put("world!");
  cout << stringQueue.get();
  cout << stringQueue.get();
} ///:~
