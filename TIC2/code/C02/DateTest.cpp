//: C02:DateTest.cpp
// Automated Testing (with a Framework)
//{L} Date ../TestSuite/Test
#include <iostream>
#include "DateTest.h"
using namespace std;

int main() {
  DateTest test;
  test.run();
  return test.report();
}
/* Output:
Test "DateTest":
        Passed: 21,      Failed: 0
*/ ///:~
