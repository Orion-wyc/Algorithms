#include <iostream>
// #include "base.h"
extern std::string a;
int main() {
  // std::string a;
  // extern std::string a;
  void print(std::string s);
  // std::string a = "demo";
  print(a);
  a = "1233";
  print(a);
  return 0;
}

//g++ -o main  main.cpp base.cpp