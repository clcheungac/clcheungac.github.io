//: C07:Reversible.cpp
// Using reversible containers
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

int main() {
  ifstream in("Reversible.cpp");
  assure(in, "Reversible.cpp");
  string line;
  vector<string> lines;
  while(getline(in, line))
    lines.push_back(line);
  for(vector<string>::reverse_iterator r = lines.rbegin(); 
      r != lines.rend(); r++)
    cout << *r << endl;
} ///:~
