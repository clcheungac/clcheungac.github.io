//: C09:Countable.h
// A "mixin" class
#ifndef COUNTABLE_H
#define COUNTABLE_H
#include <cassert>

class Countable {
public:
  long attach() { return ++count; }
  long detach() {
    return (--count > 0) ? count : (delete this, 0);
  }
  long refCount() const { return count; }
protected:
  Countable() { count = 0; }
  virtual ~Countable() { assert(count == 0); }
private:
  long count;
};
#endif ///:~
