// 可判环，注意节点从 0 开始标号

#include <bits/stdc++.h>
using namespace std;

vector<list<int>> adj_list;  // 邻接表，节点从 0 开始计数
vector<int> in_degrees;      // 保存每个节点的入度
priority_queue<int> pq;      // 保存当前入度为 0 的节点编号 大顶堆字典序最大 5 4 2 3 1 0
priority_queue<int, vector<int>, greater<int>> pq;      // 小顶堆字典序最小 4 5 0 2 3 1 

void CreatGraph() {
  int n, m, v1, v2;
  cin >> m >> n;
  adj_list.assign(n, list<int>());
  in_degrees.assign(n, 0);
  while (m--) {
    cin >> v1 >> v2;
    adj_list[v1].push_back(v2);
    in_degrees[v2]++;
  }
  // 入度为 0 的点入栈
  for (int i = 0; i < n; i++)
    if (in_degrees[i] == 0) pq.push(i);
}

void TopologicalSort() {
  vector<int> vec;
  int v;
  while (!pq.empty()) {
    v = pq.top();
    pq.pop();
    // in_degrees[v] = -1;
    //遍历与节点v相连的节点
    for (const auto &u : adj_list[v]) {
      --in_degrees[u];
      if (in_degrees[u] == 0) pq.push(u);
    }
    vec.push_back(v);
  }

  if (vec.size() != in_degrees.size()) {
    cout << "Loop Detected! Topological Sort Failed!\n";
    return;
  }

  for (auto item : vec) cout << item << " ";
  cout << endl;
}

int main() {
  CreatGraph();
  TopologicalSort();

  return 0;
}

/*
6 6
5 2
5 0
4 0
4 1
2 3
3 1
*/