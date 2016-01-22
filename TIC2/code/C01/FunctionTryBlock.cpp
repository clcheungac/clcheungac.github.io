//: C01:FunctionTryBlock.cpp
// Function-level try blocks
//{-bor}
#include <iostream>
using namespace std;

int main() try {
  throw "main";
} catch(const char* msg) {
   cout << msg << endl;
   return 1;
} ///:~
