//: C06:PrintSequence.h
// Prints the contents of any sequence
#ifndef PRINTSEQUENCE_H
#define PRINTSEQUENCE_H
#include <iostream>
#include <iterator>

template<typename InputIter>
void print(InputIter first, InputIter last,
  char* nm = "", char* sep = "\n", 
  std::ostream& os = std::cout) { 
  if(nm != 0 && *nm != '\0')
    os << nm << ": " << sep;
  while(first != last)
    os << *first++ << sep;
  os << std::endl;
}
#endif // PRINTSEQUENCE_H ///:~
