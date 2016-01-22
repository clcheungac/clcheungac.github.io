//: C07:FileEditor.h
// File editor tool
#ifndef FILEEDITOR_H
#define FILEEDITOR_H
#include <iostream>
#include <string>
#include <vector>

class FileEditor : 
  public std::vector<std::string> {
public:
  void open(const char* filename);
  FileEditor(const char* filename) {
    open(filename);
  }
  FileEditor() {};
  void write(std::ostream& out = std::cout);
};
#endif // FILEEDITOR_H ///:~
