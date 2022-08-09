// 给定一组区间，判断该组区间是否重叠，重叠返回true，否则返回false
// 区间[1,2]和[2,4]重叠
// 区间[1,3]和[2,4]重叠
// 区间[1,2]和[3,4]不重叠

// 输入样例：
// intervals=[[1,2],[3,6],[8,10],[15,18]，返回false

// 输入样例：
// intervals=[[3,6],[1,4],[8,10],[15,18]，返回true

#include <bits/stdc++.h>
using namespace std;

struct Interval {
  int l;
  int r;
  Interval(int x, int y) : l(x), r(y) {}
  bool operator<(const Interval &b) const {
    if (l == b.l)
      return r < b.r;
    else
      return l < b.l;
  }
};

bool solve(vector<Interval> &intervals) {
  sort(intervals.begin(), intervals.end());
  for (int i = 0; i < intervals.size() - 1; ++i) {
    if (intervals[i].r >= intervals[i + 1].l) return true;
  }
  return false;
}

int main() {
  vector<Interval> intervals = {{1, 2}, {3, 6}, {15, 18}, {8, 10}};
  vector<Interval> intervals1 = {{3, 6}, {1, 4}, {15, 18}, {8, 10}};
  cout << boolalpha << solve(intervals) << endl;
  cout << boolalpha << solve(intervals1) << endl;
  return 0;
}