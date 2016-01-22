//: C05:TempTemp4.cpp
//{-bor}
//{-msc}
// Passes standard sequences as template arguments
#include <iostream>
#include <list>
#include <memory>  // declares allocator<T>
#include <vector>
using namespace std;

template<class T, template<class U, class = allocator<U> >   
                  class Seq>
class Container {
  Seq<T> seq; // default of allocator<T> applied implicitly
public:
  void push_back(const T& t) { seq.push_back(t); }
  typename Seq<T>::iterator begin() { return seq.begin(); }
  typename Seq<T>::iterator end() { return seq.end(); }
};

int main() {
  // Use a vector
  Container<int, vector> theData;
  theData.push_back(1);
  theData.push_back(2);
 
  for (vector<int>::iterator p = theData.begin();
       p != theData.end(); ++p) {
    cout << *p << endl;
  }
  // Use a list
  Container<int, list> theOtherData;
  theOtherData.push_back(3);
  theOtherData.push_back(4);
  
  for (list<int>::iterator p2 = theOtherData.begin();
       p2 != theOtherData.end(); ++p2) {
    cout << *p2 << endl;
  }
} ///:~
