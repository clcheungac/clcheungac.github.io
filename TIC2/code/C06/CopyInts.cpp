//: C06:CopyInts.cpp
// Copies ints without an explicit loop
#include <algorithm>
#include <cassert>
#include <cstddef>  // For size_t
using namespace std;

int main() {
  int a[] = {10, 20, 30};
  const size_t SIZE = sizeof a / sizeof a[0];
  int b[SIZE];
  copy(a, a + SIZE, b);
  for (int i = 0; i < SIZE; ++i)
    assert(a[i] == b[i]);
} ///:~
