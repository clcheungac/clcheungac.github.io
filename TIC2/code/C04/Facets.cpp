//: C04:Facets.cpp
//{-bor}
//{-g++}
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main() {
  // Change to French/France
  locale loc("french");
  cout.imbue(loc);

  string currency =
    use_facet<moneypunct<char> >(loc).curr_symbol();
  char point =
    use_facet<moneypunct<char> >(loc).decimal_point();
  cout << "I made " << currency << 12.34 << " today!"
       << endl;
} ///:~
