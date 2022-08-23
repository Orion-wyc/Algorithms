// strings and c-strings
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

struct Node {
  int a;
  char *str = new char[10];
};

void InputInt(int* num) { cout << *num << endl; }
int main() {
  const int constant = 21;
  // InputInt(constant); //error C2664: “InputInt”: 不能将参数 1 从“const
  // int”转换为“int *”
  InputInt(const_cast<int*>(&constant));

  cout << sizeof(Node) << endl;
  Node node;
  cout << sizeof node << endl;
  delete node.str;

  system("pause");
}