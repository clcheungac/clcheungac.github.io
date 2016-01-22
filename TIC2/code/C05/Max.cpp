//: C05:Max.cpp
#include <iostream>
using namespace std;

template<int n1, int n2>
struct Max {
   enum {val = n1 > n2 ? n1 : n2};
};
int main() {
   cout << Max<10, 20>::val << endl;  // 20
} ///:~
