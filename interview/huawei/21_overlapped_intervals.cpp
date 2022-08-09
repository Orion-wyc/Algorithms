/* 题目：给定一组区间，判断区间是否存在重叠
 * 区间排序即可
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
  int low;
  int high;
  Interval(int l, int r) : low(l), high(r) {}
  bool operator<(const Interval &b) {
    if (low == b.low) {
      return high < b.high;
    } else {
      return low < b.low;
    }
  }
};

bool check_overlap(vector<Interval> &intervals) {
  int len = intervals.size();

  sort(intervals.begin(), intervals.end());
  // 检查区间重叠
  bool overlapped = false;
  for (int i = 1; i < len; ++i) {
    if (intervals[i - 1].high > intervals[i].low) {
      overlapped = true;
      break;
    }
  }

  return overlapped;
}

int main() {
  vector<Interval> intervals = {{3, 6}, {15, 18}, {1, 3}, {8, 11}};
  // intervals.emplace_back(Interval{3, 6});
  // intervals.emplace_back(Interval{15, 18});
  // intervals.emplace_back(Interval{1, 3});
  // intervals.emplace_back(Interval{8, 11});

  cout << boolalpha << "Intervals overlapped = " << check_overlap(intervals)
       << endl;

  return 0;
}