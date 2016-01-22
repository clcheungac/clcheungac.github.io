//: C05:ToLower2.cpp
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

template<class charT>
charT strTolower(charT c) {
  return tolower(c);  // one-arg version called
}

int main() {
  string s("LOWER");
  transform(s.begin(),s.end(),s.begin(),&strTolower<char>);
  cout << s << endl;
} ///:~
