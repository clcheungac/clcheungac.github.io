//: C09:BreakTie.cpp
class Top {};

class Left : virtual public Top {
public:
   void f(){}
};

class Right : virtual public Top {
public:
   void f(){}
};

class Bottom : public Left, public Right {
public:
  using Left::f;
};

int main() {
   Bottom b;
   b.f();     // calls Left::f()
} ///:~
