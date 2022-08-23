#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int x1, int y1, int x2, int y2, int d1, int d2) {
  if (abs(x1 - a) + abs(y1 - b) != d1) return false;
  if (abs(x2 - a) + abs(y2 - b) != d2) return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  int d1, d2, d3;
  cin >> d1 >> d2 >> d3;
  if (d2 < d1) {
    swap(x1, x2);
    swap(y1, y2);
    swap(d1, d2);
  }
  if (d3 < d1) {
    swap(x1, x3);
    swap(y1, y3);
    swap(d1, d3);
  }
  // cout << x1 << y1 << x2 << y2 << x3 << y3 << d1 << d2 << d3 << endl;
  vector<vector<int>> dirs{
      {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};  // 确保字典序最小

  set<pair<int, int>> ans;
  for (int i = d1; i >= 0; --i) {
    int j = d1 - i;
    for (auto d : dirs) {
      int x = x1 + d[0] * i;
      int y = y1 + d[1] * j;
      if (x >= 1 && x <= n && y >= 1 && y <= n &&
          check(x, y, x2, y2, x3, y3, d2, d3)) {
        ans.insert(make_pair(x, y));
      }
    }
  }

  auto node = *ans.begin();
  cout << node.first << " " << node.second << endl;

  return 0;
}