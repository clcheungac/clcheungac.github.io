//: C05:Factorial.cpp
// Compile-time computation!
#include <iostream>
using namespace std;

template<int n>
struct Factorial
{
   enum {val = Factorial<n-1>::val * n};
};
template<>
struct Factorial<0>
{
   enum {val = 1};
};

int main()
{
   cout << Factorial<12>::val << endl; // 479001600
} ///:~
