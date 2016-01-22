//: C04:Unitbuf.cpp
#include <cstdlib>  // For abort()
#include <fstream>
using namespace std;

int main() {
  ofstream out("log.txt");
  out.setf(ios::unitbuf);
  out << "one\n";
  out << "two\n";
  abort();
} ///:~
