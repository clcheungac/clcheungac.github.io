//: C05:Urand.h
//{-bor}
// Unique random number generator
#ifndef URAND_H
#define URAND_H
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>
using std::size_t;
using std::bitset;

template<size_t upperBound>
class Urand {
  bitset<upperBound> used;
public:
  Urand() {
    srand(time(0));  // randomize
  }
  size_t operator()(); // The "generator" function
};

template<size_t upperBound>
inline size_t Urand<upperBound>::operator()() {
  if(used.count() == upperBound)
    used.reset();  // start over (clear bitset)
  size_t newval;
  while(used[newval = rand() % upperBound])
    ; // Until unique value is found
  used[newval] = true;
  return newval;
}
#endif // URAND_H ///:~
