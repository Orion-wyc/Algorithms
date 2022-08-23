// 工单系统 贪心
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int time;
  int val;
  Node(int t, int v) : time(t), val(v) {}
  bool operator<(const Node& node) const {
    if (val == node.val)
      return time < node.time;
    else
      return val > node.val;
  }
};

int N;
vector<Node> vec;
int max_time = -1;

int solve() {
  int ans = 0;
  vector<bool> vis(max_time + 1, false); // 这里可能会有问题
  sort(vec.begin(), vec.end());
  
  // for (auto n : vec) {
  //   cout << n.val << " " << n.time << endl;
  // }

  for (int i = 0; i < N; ++i) {
    for (int t = vec[i].time; t > 0; --t) {
      if (!vis[t]) {
        vis[t] = true;
        ans += vec[i].val;
        break;
      }
    }
  }
  return ans;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int t, v;
    cin >> t >> v;
    vec.emplace_back(Node(t, v));
    max_time = max(max_time, t);
  }

  cout << solve() << endl;

  return 0;
}


/*
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1
*/