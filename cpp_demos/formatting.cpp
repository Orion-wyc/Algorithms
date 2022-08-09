// strings and c-strings
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

struct Node {
  int a;
  double b;
  float c;
};

class A {
  Node a;
};

class B {
  Node *b;
};

int main() {
  cout << sizeof(A) << sizeof(B) << endl;
  return 0;
}