//: C08:CheckedCast2.cpp
// Uses RTTI's dynamic_cast
#include <iostream>
#include <vector>
#include "../purge.h"
using namespace std;

class Security {
public:
  virtual ~Security(){}
};
class Stock : public Security {};
class Bond : public Security {};
class Investment : public Security {
public:
  void special() {
    cout << "special Investment function\n";
  }
};
class Metal : public Investment {};

int main() {
  vector<Security*> portfolio;
  portfolio.push_back(new Metal);
  portfolio.push_back(new Investment);
  portfolio.push_back(new Bond);
  portfolio.push_back(new Stock);
  for (vector<Security*>::iterator it = 
                                   portfolio.begin();
       it != portfolio.end(); ++it) {
    Investment* cm = dynamic_cast<Investment*>(*it);
    if(cm)
      cm->special();
    else
      cout << "not a Investment" << endl;
  }
  cout << "cast from intermediate pointer:\n";
  Security* sp = new Metal;
  Investment* cp = dynamic_cast<Investment*>(sp);
  if(cp) cout << "  it's an Investment\n";
  Metal* mp = dynamic_cast<Metal*>(sp);
  if(mp) cout << "  it's a Metal too!\n";
  purge(portfolio);
} ///:~
