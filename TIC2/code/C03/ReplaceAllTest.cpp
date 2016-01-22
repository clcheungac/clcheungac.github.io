//: C03:ReplaceAllTest.cpp
//{-msc}
//{L} ReplaceAll
#include <iostream>
#include <cassert>
using namespace std;

string& replaceAll(string& context, const string& from,
  const string& to);

int main() {
  string text = "a man, a plan, a canal, panama";
  replaceAll(text, "an", "XXX");
  assert(text == "a mXXX, a plXXX, a cXXXal, pXXXama");
} ///:~
