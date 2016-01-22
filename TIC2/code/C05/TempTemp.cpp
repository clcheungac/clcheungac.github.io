//: C05:TempTemp.cpp
// Illustrates a template template parameter
#include <cstddef>
#include <iostream>
using namespace std;

template<class T>
class Array { // A simple, expandable sequence
  enum {INIT = 10};
  T *data;
  size_t capacity;
  size_t count;
public:
  Array() {
    count = 0;
    data = new T[capacity = INIT];
  }
  void push_back(const T& t) {
    if (count == capacity) {
      // Grow underlying array
      size_t newCap = 2*capacity;
      T* newData = new T[newCap];
      for (size_t i = 0; i < count; ++i)
        newData[i] = data[i];
      delete data;
      data = newData;
      capacity = newCap;
    }
    data[count++] = t;
  }
  void pop_back() {
    if (count > 0)
      --count;
  }
  T* begin() {
    return data;
  }
  T* end() {
    return data + count;
  }
};

template<class T, template<class> class Seq>
class Container {
  Seq<T> seq;
public:
  void append(const T& t) {
    seq.push_back(t);
  }
  T* begin() {
    return seq.begin();
  }
  T* end() {
    return seq.end();
  }
};

int main() {
  Container<int, Array> theData;
  theData.append(1);
  theData.append(2);
  int* p = theData.begin();
  while (p != theData.end())
    cout << *p++ << endl;
} ///:~
