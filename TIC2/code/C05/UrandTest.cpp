//: C05:UrandTest.cpp
//{-bor}
#include <iostream>
#include "Urand.h"
using namespace std;

int main() {
  Urand<10> u;
  for (int i = 0; i < 20; ++i)
    cout << u() << ' ';
} ///:~
