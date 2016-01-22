//: C05:Power.cpp
#include <iostream>
using namespace std;

template<int N, int P>
struct Power {
  enum {val = N * Power<N, P-1>::val};
};
template<int N>
struct Power<N, 0> {
  enum {val = 1};
};
int main() {
  cout << Power<2, 5>::val << endl;  // 32
} ///:~
