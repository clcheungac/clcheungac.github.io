//: C05:PoohCorner2.cpp
// Illustrates policy classes
#include <iostream>
using namespace std;

// Item classes:
class Water {
public:
  friend ostream& operator<<(ostream& os, const Water&) {
    return os << "Water";
  }
};
class Milk {
public:
  friend ostream& operator<<(ostream& os, const Milk&) {
    return os << "Milk";
  }
};
class Honey {
public:
  friend ostream& operator<<(ostream& os, const Honey&) {
    return os << "Honey";
  }
};
class Cookies {
public:
  friend ostream& operator<<(ostream& os, const Cookies&) {
    return os << "Cookies";
  }
};

// Guest classes:
class Bear {
public:
  friend ostream& operator<<(ostream& os, const Bear&) {
    return os << "Pooh";
  }
};
class Boy {
public:
  friend ostream& operator<<(ostream& os, const Boy&) {
    return os << "Christopher Robin";
  }
};

// Traits template
template<class Guest>
class GuestTraits;

// Traits specializations for Guest types
template<>
class GuestTraits<Bear> {
public:
  typedef Water beverage_type;
  typedef Honey snack_type;
};
template<>
class GuestTraits<Boy> {
public:
  typedef Milk beverage_type;
  typedef Cookies snack_type;
};

// Policy classes (require a static doAction() function)
class Feed {
public:
  static const char* doAction() {
    return "Feeding";
  }
};
class Stuff {
public:
  static const char* doAction() {
    return "Stuffing";
  }
};

// The Guest template (uses a policy and a traits class)
template< class Guest, class Action, class traits = 
                                     GuestTraits<Guest> >
class PoohCorner {
  Guest theGuest;
  typedef typename traits::beverage_type beverage_type;
  typedef typename traits::snack_type snack_type;
  beverage_type bev;
  snack_type snack;
public:
  PoohCorner(const Guest& g)
    : theGuest(g), bev(beverage_type()), snack(snack_type()) {}
  void entertain() {
    cout << Action::doAction() << " " << theGuest
         << " with " << bev
         << " and " << snack << endl;
  }
};

int main() {
  Boy cr;
  PoohCorner<Boy, Feed> pc1(cr);
  pc1.entertain();
  Bear pb;
  PoohCorner<Bear, Stuff> pc2(pb);
  pc2.entertain();
} ///:~
