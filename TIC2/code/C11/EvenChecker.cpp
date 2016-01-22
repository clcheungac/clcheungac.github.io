//: C11:EvenChecker.cpp {O}
#include "EvenChecker.h"
#include <iostream>
using namespace std;

void EvenChecker::run() throw() {
  while(!isCanceled()) {
    int val = generator->getValue();
    if(val % 2 != 0) {
      cout << val << " not even!" << endl;
      generator->cancel();
      cancel(); // Cancel all EvenCheckers
    }
  }
}

bool Generator::quitFlag = false;
bool EvenChecker::quitFlag = false;
int EvenChecker::idCounter = 0;
///:~
