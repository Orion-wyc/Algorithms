#include <iostream>
using namespace std;

// 第一个命名空间
namespace first_space {
void func() { cout << "Inside first_space" << endl; }
// 第二个命名空间
namespace second_space {
void func() { cout << "Inside second_space" << endl; }
}  // namespace second_space
}  // namespace first_space
using namespace first_space;

class Demo {
 public:
  Demo(int z = 123) : z(z) {}
  int z = 123;
  static int x;
  static const int y = 1000;
};
int Demo::x = 100;

// void func(Demo* d) {
//   d = new Demo(456);
//   cout << d->x << " " << d->y << " " << d->z << endl;
// }

void func(Demo* d) {
  d = new Demo(456);
  cout << d->x << " " << d->y << " " << d->z << endl;
}

int main() {
  // 调用第二个命名空间中的函数
  func();
  second_space::func();
  int c = 0;
  auto x = [](int n) { cout << n << endl; };
  c = 1234;
  int m = [](int x) { return [](int y) { return y * 2; }(x) + 6; }(5);

  x(123456);
  m;

  Demo demo;
  cout << demo.x << " " << demo.y << " " << demo.z << endl;

  Demo* d = new Demo(233);
  cout << d->x << " " << d->y << " " << d->z << endl;
  func(d);
  cout << -d->x << " " << d->y << " " << d->z << endl;

  return 0;
}
