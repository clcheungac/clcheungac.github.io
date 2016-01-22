//: C07:WordCount.cpp
// Count occurrences of words using a map
#include "../require.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

typedef map<string, int> WordMap;
typedef WordMap::iterator WMIter;

int main(int argc, char* argv[]) {
  char* fname = "WordCount.cpp";
  if(argc > 1) fname = argv[1];
  ifstream in(fname);
  assure(in, fname);
  WordMap wordmap;
  string word;
  while(in >> word)
    wordmap[word]++;
  for(WMIter w = wordmap.begin(); w != wordmap.end(); w++)
    cout << w->first << ": "
      << w->second << endl;
} ///:~
