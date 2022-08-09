#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <bitset>
#include <vector>

using namespace std;
static int num = 10;

struct Node {
  int x;
  int y;
};

Node nodes[2] = {{1, 1}, {2, 2}};

void print_element(int (*arr)[3]) { cout << arr[1][1] << endl; }

int main() {
  //测试基本用法
  // enum color { red, blue, purple };
  // color c = red;
  // int a = 0;
  // int b;
  // cin >> b;
  // cout << a << " " << b << " " << num << endl;
  // num = 100;
  // cout << a << " " << b << " " << num << endl;
  // cout << c << int(0b1111) << endl;
  char st[] = "http://www.ibegroup.com/";
  cout << uppercase << st << endl;

  // 测试位运算
  cout << ~(1 << 31) << endl;

  //测试流输出控制
  cout << setprecision(4) << log(M_E) << endl;

  string str = "Hello";
  vector<std::string> v;
  v.push_back(str);
  std::cout << "After copy, str is \\ " << str << "\n";
  //输出结果为 After copy, str is "Hello"

  v.push_back(std::move(str));
  std::cout << "After move, str is " << str << "\n";
  //输出结果为 After move, str is ""

  // int *arr = new int[2];
  // arr[0] = arr[1] = 1;
  // cout << *arr << endl;
  // delete[] arr;

  // 测试数组
  // int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
  // int(*p)[3] = arr;
  // int *q = *arr + 2;
  // cout << sizeof(arr) << " " << sizeof(p) << " " << sizeof(*p) << endl;
  // cout << *q << " " << sizeof(q) << " " << sizeof(*q) << endl;

  // 多维数组传参
  // print_element(arr);

  // int arr3[2][2][3] = {{{1, 2, 3}, {1, 2, 3}}, {{1, 2, 3}, {1, 2, 3}}};
  // int(*d)[3] = *arr3;
  // cout << d << " " << *d << " " << **d << endl;

  // cout << nodes[1].x << " " << nodes[0].y << endl;

  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  auto it = vec.begin();
  cout << *it << " " << *next(it) << " " << *next(it, 2) << " " << *next(it, 4)
       << endl;

  auto func = [](auto x, auto y) {return x + y;};
  cout << func(2, 3) <<endl;
  
  // 尝试移动语义
  cout << &vec[0] << " " << vec[0] << endl;
  vector<int> v2(move(vec));
  cout << &v2[0] << " " << v2[0] << endl;
  copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
  
  //const ptr
  int a = 4;
  int b = -4;
  const int *ptr = &a;
  ptr = &b;
  cout<< *ptr << endl;

  int * const cptr = &a;
  *cptr = b;
  cout<< a<<endl;
  
  // bitset
  bitset<100> bset;
  cout << bset.size() <<endl;

  constexpr int N = 5;
  int arr[N];

  return 0;
}
