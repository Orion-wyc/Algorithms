#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> c;
int n;

// C++ Version
int lowbit(int x) {
  // x 的二进制表示中，最低位的 1 的位置。
  // lowbit(0b10110000) == 0b00010000
  //          ~~~^~~~~
  // lowbit(0b11100100) == 0b00000100
  //          ~~~~~^~~
  return x & (-x);
}

// C++ Version
void add(int x, int k) {
  while (x <= n) {  // 不能越界
    c[x] = c[x] + k;
    x = x + lowbit(x);
  }
}

// C++ Version
int getsum(int x) {  // a[1]..a[x]的和
  int ans = 0;
  while (x >= 1) {
    ans += c[x];
    x -= lowbit(x);
  }
  return ans;
}

// C++ Version
void init() {
  for (int i = 1; i <= n; ++i) {
    c[i] += a[i];
    int j = i + lowbit(i);
    if (j <= n) c[j] += c[i];
  }
}

int main() {
  n = 10;
  c.resize(n + 1);
  a.resize(n + 1);
  vector<int> arr = {2, 4, -10, 8, 222, 4, 6, 2, 67, 8};
  for (int i = 1; i <= n; ++i) {
    a[i] = i;
  }
  // 建树
  init();
  for (int i = 1; i <= n; ++i) {
    cout << getsum(i) << " ";
  }
  cout << endl;
  add(5, 1000);
  for (int i = 1; i <= n; ++i) {
    cout << getsum(i) << " ";
  }
  cout << endl;

  cout << getsum(4) - getsum(2) << endl; // 求[3, 4]区间和
  return 0;
}