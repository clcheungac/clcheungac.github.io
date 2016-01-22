//: C02:SimpleDateTest.cpp
//{L} Date
// You'll need the full Date.h from the Appendix:
#include "Date.h"
#include <iostream>
using namespace std;

// Test machinery
int nPass = 0, nFail = 0;
void test(bool t) {
  if(t) nPass++; else nFail++;
}

int main() {
  Date mybday(1951, 10, 1);
  test(mybday.getYear() == 1951);
  test(mybday.getMonth() == 10);
  test(mybday.getDay() == 1);
  cout << "Passed: " << nPass << ", Failed: "
       << nFail << endl;
}
/* Expected output:
Passed: 3, Failed: 0
*/ ///:~
