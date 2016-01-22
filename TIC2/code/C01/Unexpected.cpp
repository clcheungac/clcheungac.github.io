//: C01:Unexpected.cpp
// Exception specifications & unexpected()
//{-msc} Doesn't terminate properly
#include <exception>
#include <iostream>
#include <cstdlib>
using namespace std;

class Up {};
class Fit {};
void g();

void f(int i) throw (Up, Fit) {
  switch(i) {
    case 1: throw Up();
    case 2: throw Fit();
  }
  g();
}

// void g() {} // Version 1
void g() { throw 47; } // Version 2

void my_unexpected() {
  cout << "unexpected exception thrown" << endl;
  exit(0);
}

int main() {
  set_unexpected(my_unexpected);
  // (ignores return value)
  for(int i = 1; i <=3; i++)
    try {
      f(i);
    } catch(Up) {
      cout << "Up caught" << endl;
    } catch(Fit) {
      cout << "Fit caught" << endl;
    }
} ///:~
