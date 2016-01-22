//: C01:Autoexcp.cpp
// No matching conversions
#include <iostream>
using namespace std;

class Except1 {};
class Except2 {
public:
  Except2(const Except1&) {}
};

void f() { throw Except1(); }

int main() {
  try { f();
  } catch (Except2&) {
    cout << "inside catch(Except2)" << endl;
  } catch (Except1&) {
    cout << "inside catch(Except1)" << endl;
  }
} ///:~
