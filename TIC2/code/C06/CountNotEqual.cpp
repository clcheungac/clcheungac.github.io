//: C06:CountNotEqual.cpp
// Count elements not equal to 20
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
using namespace std;
int main() {
  int a[] = {10, 20, 30};
  const size_t SIZE = sizeof a / sizeof a[0];
  cout << count_if(a, a + SIZE,
                   not1(bind1st(equal_to<int>(), 20)));// 2
} ///:~
