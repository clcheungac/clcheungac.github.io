//: C09:Dominance2.cpp
#include <iostream>
using namespace std;

class A {
public:
   virtual void f() {cout << "A::f\n";}
};

class B : virtual public A {
public:
   void f() {cout << "B::f\n";}
};

class C : public B {};
class D : public C, virtual public A {};

int main()
{
   B* p = new D;
   p->f();  // calls B::f()
} ///:~
