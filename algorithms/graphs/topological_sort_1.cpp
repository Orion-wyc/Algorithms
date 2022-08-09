// 该版本无法判环，应当确保输入的数据满足 DAG

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int cost;  // 在拓扑排序中无用
  Edge(int to, int cost = 0) : to(to), cost(cost) {}
};

vector<vector<Edge>> adj_list;
int E;
int N;

void dfs(int u, vector<bool> &visited, stack<int> &res) {
  visited[u] = true;
  for (auto const &e : adj_list[u]) {
    if (!visited[e.to]) dfs(e.to, visited, res);
  }
  res.push(u);
}

void TopologicalSort() {
  stack<int> results;    // 记录排序结果
  vector<bool> visited;  // 记录是否被访问
  visited.resize(N + 1, false);

  for (int u = 1; u <= N; ++u) {
    if (!visited[u]) dfs(u, visited, results);
  }

  // 输出结果
  cout << "Topological sort results = ";
  while (!results.empty()) {
    cout << results.top() << ", ";
    results.pop();
  }
  cout << endl;
}

int main() {
  cin >> E >> N;
  adj_list.resize(N + 1);

  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    // 无向图
    adj_list[u].emplace_back(Edge(v));
  }

  TopologicalSort();

  return 0;
}