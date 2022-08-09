#include <iostream>
using namespace std;

extern const int a = 100;

extern "C" void solve(int i) {
  static int cnt = 0;
  ++cnt;
  cout << "SUCCESS" << i << " " << cnt << endl;
}