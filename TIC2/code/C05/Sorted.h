//: C05:Sorted.h
// Template specialization
#ifndef SORTED_H
#define SORTED_H
#include <string>
#include <vector>

template<class T>
class Sorted : public std::vector<T> {
public:
  void sort();
};

template<class T>
void Sorted<T>::sort() { // A simple sort
  for(int i = size(); i > 0; i--)
    for(int j = 1; j < i; j++)
      if(at(j-1) > at(j)) {
        T t = at(j-1);
        at(j-1) = at(j);
        at(j) = t;
      }
}

// Partial specialization for pointers:
template<class T>
class Sorted<T*> : public std::vector<T*> {
public:
  void sort();
};

template<class T>
void Sorted<T*>::sort() {
  for(int i = size(); i > 0; i--)
    for(int j = 1; j < i; j++)
      if(*at(j-1) > *at(j)) {
        T* t = at(j-1);
        at(j-1) = at(j);
        at(j) = t;
      }
}

// Full specialization for char*:
template<>
void Sorted<char*>::sort() {
  for(int i = size(); i > 0; i--)
    for(int j = 1; j < i; j++)
      if(std::strcmp(at(j-1), at(j)) > 0) {
        char* t = at(j-1);
        at(j-1) = at(j);
        at(j) = t;
      }
}
#endif // SORTED_H ///:~
