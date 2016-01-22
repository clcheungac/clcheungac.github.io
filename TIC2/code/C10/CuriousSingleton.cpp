//: C10:CuriousSingleton.cpp
// Separates a class from its singleton-ness (almost)
#include <iostream>
using namespace std;

template<class T>
class Singleton {
public:
  static T& instance() {
    static T theInstance;
    return theInstance;
  }
protected:
  Singleton(){}
  virtual ~Singleton(){}
private:
  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);
};
// A sample class to be made into a Singleton
class MyClass : public Singleton<MyClass> {
  int x;
protected:
  friend class Singleton<MyClass>;
  MyClass(){x = 0;}
public:
  void setValue(int n) { x = n; }
  int getValue() const { return x; }
};

int main() {
  MyClass& m = MyClass::instance();
  cout << m.getValue() << endl;
  m.setValue(1);
  cout << m.getValue() << endl;
} ///:~
