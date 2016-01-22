//: C05:TempTemp2.cpp
// A multi-variate template template parameter
#include <cstddef>
#include <iostream>
using namespace std;

template<class T, size_t N>
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

template<class T,size_t N,template<class,size_t> class Seq>
class Container {
  Seq<T,N> seq;
public:
  void append(const T& t) { seq.push_back(t); }
  T* begin() { return seq.begin(); }
  T* end() { return seq.end(); }
};

int main() {
  const size_t N = 10;
  Container<int, N, Array> theData;
  theData.append(1);
  theData.append(2);
  int* p = theData.begin();
  while (p != theData.end())
    cout << *p++ << endl;
} ///:~
