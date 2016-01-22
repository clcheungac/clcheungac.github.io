//: C05:TempTemp3.cpp
//{-bor}
//{-msc}
// Combining template template parameters and
// default arguments
#include <cstddef>
#include <iostream>
using namespace std;

template<class T, size_t N = 10>  // a default argument
class Array {
  T data[N];
  size_t count;
public:
  Array() { count = 0; }
  void push_back(const T& t) {
    if (count < N)
      data[count++] = t;
  }
  void pop_back() {
    if (count > 0)
      --count;
  }
  T* begin() { return data; }
  T* end() { return data + count; }
};

template<class T, template<class, size_t = 10> class Seq>
class Container {
  Seq<T> seq;  // default used
public:
  void append(const T& t) { seq.push_back(t); }
  T* begin() { return seq.begin(); }
  T* end() { return seq.end(); }
};

int main() {
  Container<int, Array> theData;
  theData.append(1);
  theData.append(2);
  int* p = theData.begin();
  while (p != theData.end())
    cout << *p++ << endl;
} ///:~
