//: C05:Conditionals.cpp
// Uses compile-time conditions to choose code
#include <iostream>
using namespace std;

template<bool cond>
struct Select {};

template<>
struct Select<true> {
  static inline void f() { statement1(); }
private:
  static inline void statement1() {
    cout << "This is";
    cout << " statement1 executing\n";
  }
};
template<>
struct Select<false> {
  static inline void f() { statement2(); }
private:
  static inline void statement2() {
    cout << "This is";
    cout << " statement2 executing\n";
  }
};
template<bool cond>
void execute() {
  Select<cond>::f();
}

int main() {
  execute<sizeof int == 4>();
} ///:~
