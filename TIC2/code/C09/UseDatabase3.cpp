//: C09:UseDatabase3.cpp
// Tests a parameterized "mixin" class
#include <cassert>
#include "Countable.h"
#include "DBConnection2.h"

class DBClient {
public:
  DBClient(DBConnection<Countable>* dbCon) {
    db = dbCon;
    db->attach();
  }
  ~DBClient() {
    db->detach();
  }
private:
  DBConnection<Countable>* db;
};

int main() {
  DBConnection<Countable>* db = 
    DBConnection<Countable>::create("MyDatabase");
  assert(db->refCount() == 1);
  DBClient c1(db);
  assert(db->refCount() == 2);
  DBClient c2(db);
  assert(db->refCount() == 3);
  db->detach();
  assert(db->refCount() == 2);
} ///:~
