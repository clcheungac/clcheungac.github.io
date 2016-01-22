//: C01:StdExcept.cpp
// Derives an exception class from std::runtime_error
#include <stdexcept>
#include <iostream>
using namespace std;

class MyError : public runtime_error {
public:
  MyError(const string& msg = "") : runtime_error(msg) {}
};

int main() {
  try {
    throw MyError("my message");
  }
  catch (MyError& x) {
    cout << x.what() << endl;
  }
} ///:~
