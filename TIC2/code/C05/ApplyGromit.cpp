//: C05:ApplyGromit.cpp
// Test ApplySequence.h
#include <cstddef>
#include <iostream>
#include <vector>
#include "applySequence.h"
#include "Gromit.h"
using namespace std;

int main() {
  vector<Gromit*> dogs;
  for(size_t i = 0; i < 5; i++)
    dogs.push_back(new Gromit(i));
  apply(dogs, &Gromit::speak, 1);
  apply(dogs, &Gromit::eat, 2.0f);
  apply(dogs, &Gromit::sleep, 'z', 3.0);
  apply(dogs, &Gromit::sit);
  for (size_t i = 0; i < dogs.size(); ++i)
    delete dogs[i];
} ///:~
