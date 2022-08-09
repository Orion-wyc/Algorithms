

#include <bits/stdc++.h>
using namespace std;

template <typename T, typename... Ts>
std::unique_ptr<T> MakeUnique(Ts&&... params) {
  return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}

struct Node {
  int a;
  int b;
  int c;
  Node(int x, int y, int z) : a(x), b(y), c(z) {}
};

class Foo {
 public:
  Foo(int x, bool y) : a(x), flag(y) { cout << "Hello" << endl; }
  ~Foo();

  bool operator!() const { return !flag; }

 private:
  int a;
  bool flag;
};

Foo::~Foo() { cout << "Bye Bye" << endl; }

void demo(Node node) { node.a += 100; }

int main() {
  unique_ptr<Node> up = MakeUnique<Node>(99, 0, 0);
  cout << up->a << up->b << up->c << endl;

  shared_ptr<Node> p(new Node(1, 2, 3));
  cout << p->a << p->b << p->c << endl;
  cout << "use count of p = " << p.use_count() << endl;
  {
    shared_ptr<Node> p_tmp = p;
    cout << "use count of p = " << p.use_count() << endl;
    cout << "use count of p_tmp = " << p_tmp.use_count() << endl;
    Foo foo(1, false);
    cout << boolalpha << !foo << endl;
  }
  cout << "use count of p = " << p.use_count() << endl;

  weak_ptr<Node> wp(p);
  cout << "use count of p = " << p.use_count() << endl;
  cout << wp.use_count() << endl;

  {
    tuple<int, int, string> info(1, 2, "www");
    cout << get<2>(info) << endl;
  }

  return 0;
}