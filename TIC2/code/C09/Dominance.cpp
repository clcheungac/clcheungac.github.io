//: C09:Dominance.cpp
class Top {
public:
  virtual void f() {}
};

class Left : virtual public Top {
public:
   void f(){}
};

class Right : virtual public Top {
};

class Bottom : public Left, public Right {};

int main() {
   Bottom b;
   b.f(); // calls Left::f()
} ///:~
