//: C05:UsingTypename.cpp
// Using 'typename' in the template argument list

template<typename T> class X { }; 

int main() {
  X<int> x;
} ///:~
