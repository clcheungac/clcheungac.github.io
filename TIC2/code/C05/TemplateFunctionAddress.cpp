//: C05:TemplateFunctionAddress.cpp
// Taking the address of a function generated
// from a template.

template <typename T> void f(T*) {}

void h(void (*pf)(int*)) {}

template <typename T> 
  void g(void (*pf)(T*)) {}

int main() {
  // Full type specification:
  h(&f<int>);
  // Type deduction:
  h(&f);
  // Full type specification:
  g<int>(&f<int>);
  // Type deduction:
  g(&f<int>);
  // Partial (but sufficient) specification
  g<int>(&f);
} ///:~
