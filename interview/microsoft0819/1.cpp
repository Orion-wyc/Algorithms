#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &X, vector<int> &Y, int W) {
  // write your code in C++ (C++14 (g++ 6.2.0))
  set<int> points;
  for (int x : X) {
    points.insert(x);
  }

  // 已排序
  vector<int> nums(points.begin(), points.end());
  int ans = 0;
  int pos = -1;
  for (int i = 0; i < nums.size(); ++i) {
    if (pos < nums[i]) {
      ++ans;
      pos = nums[i] + W;
    }
  }
  return ans;
}

int main() {
  vector<int> x = {1, 1};

  cout << solution(x, x, 1) << endl;

  return 0;
}