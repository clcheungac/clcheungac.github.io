//: C06:CopyInts3.cpp
// Uses an output stream iterator
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
using namespace std;
bool gt15(int x) {
  return 15 < x;
}
int main() {
  int a[] = {10, 20, 30};
  const size_t SIZE = sizeof a / sizeof a[0];
  remove_copy_if(a, a + SIZE,
                 ostream_iterator<int>(cout, "\n"), gt15);
} ///:~
