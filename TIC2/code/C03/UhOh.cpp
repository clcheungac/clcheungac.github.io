//: C03:UhOh.cpp
#include <string>
#include <cassert>
using namespace std;

int main() {
  // Error: no single char inits
  //! string nothingDoing1('a');
  // Error: no integer inits
  //! string nothingDoing2(0x37);
  // The following is legal:
  string okay(5, 'a');
  assert(okay == string("aaaaa"));
} ///:~
