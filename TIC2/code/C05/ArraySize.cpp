//: C05:ArraySize.cpp
#include <cstddef>
using std::size_t;

template<size_t R, size_t C, typename T>
void init1(T a[R][C]) {
  for (size_t i = 0; i < R; ++i)
    for (size_t j = 0; j < C; ++j)
      a[i][j] = T();
}

template<size_t R, size_t C, class T>
void init2(T (&a)[R][C]) {  // reference parameter
  for (size_t i = 0; i < R; ++i)
    for (size_t j = 0; j < C; ++j)
      a[i][j] = T();
}

int main() {
  int a[10][20];
  init1<10,20>(a);  // must specify
  init2(a);         // sizes deduced
} ///:~
