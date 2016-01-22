//: C05:Sorted.cpp
// Testing template specialization
#include <cstddef>
#include <iostream>
#include "Sorted.h"
#include "Urand.h"
using namespace std;

#define asz(a) (sizeof a / sizeof a[0])

char* words[] = {
  "is", "running", "big", "dog", "a",
};
char* words2[] = {
  "this", "that", "theother",
};

int main() {
  Sorted<int> is;
  Urand<47> rand;
  for(size_t i = 0; i < 15; i++)
    is.push_back(rand());
  for(size_t l = 0; l < is.size(); l++)
    cout << is[l] << ' ';
  cout << endl;
  is.sort();
  for(size_t l = 0; l < is.size(); l++)
    cout << is[l] << ' ';
  cout << endl;

  // Uses the template partial specialization:
  Sorted<string*> ss;
  for(size_t i = 0; i < asz(words); i++)
    ss.push_back(new string(words[i]));
  for(size_t i = 0; i < ss.size(); i++)
    cout << *ss[i] << ' ';
  cout << endl;
  ss.sort();
  for(size_t i = 0; i < ss.size(); i++)
    cout << *ss[i] << ' ';
  cout << endl;
  
  // Uses the full char* specialization:
  Sorted<char*> scp;
  for(size_t i = 0; i < asz(words2); i++)
    scp.push_back(words2[i]);
  for(size_t i = 0; i < scp.size(); i++)
    cout << scp[i] << ' ';
  cout << endl;
  scp.sort();
  for(size_t i = 0; i < scp.size(); i++)
    cout << scp[i] << ' ';
  cout << endl;
} ///:~
