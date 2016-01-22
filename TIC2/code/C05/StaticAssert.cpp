//: C05:StaticAssert.cpp
//{-g++}
#include <iostream>
using namespace std;

// A template and a specialization
template<bool>
struct StaticCheck {
   StaticCheck(...);
};
template<>
struct StaticCheck<false>{};

// The macro (generates a local class)
#define STATIC_CHECK(expr, msg) {              \
   class Error_##msg{};                        \
   sizeof((StaticCheck<expr>(Error_##msg()))); \
}

// Detects narrowing conversions
template<class To, class From>
To safe_cast(From from) {
   STATIC_CHECK(sizeof(From) <= sizeof(To), 
                NarrowingConversion);
   return reinterpret_cast<To>(from);
}

int main() {
   void* p = 0;
   int i = safe_cast<int>(p);
   cout << "int cast okay\n";
//!   char c = safe_cast<char>(p);
} ///:~
