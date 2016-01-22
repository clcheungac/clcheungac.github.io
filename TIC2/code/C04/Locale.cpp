//: C04:Locale.cpp
//{-g++}
//{-bor}
//{-edg}
// Illustrates effects of locales
#include <iostream>
#include <locale>
using namespace std;
int main() {
  locale def;
  cout << def.name() << endl;
  locale current = cout.getloc();
  cout << current.name() << endl;
  float val = 1234.56;
  cout << val << endl;
  // Change to French/France
  cout.imbue(locale("french"));
  current = cout.getloc();
  cout << current.name() << endl;
  cout << val << endl;

  cout << "Enter the literal 7890,12: ";
  cin.imbue(cout.getloc());
  cin >> val;
  cout << val << endl;
  cout.imbue(def);
  cout << val << endl;
} ///:~
