// 增加判环功能，并且使用list实现
#include <bits/stdc++.h>
using namespace std;

vector<list<int>> adj_list;  // 简易邻接表，不带权重
int E;
int N;

void AddEdge(int u, int v) {
  // 添加从 u --> v 的边
  adj_list[u].push_back(v);
}

bool dfs(int u, vector<int> &visited, stack<int> &results) {
  visited[u] = -1;  // -1代表当前正在访问
  for (const auto &v : adj_list[u]) {
    if (visited[v] == -1) {
      return false;  // 存在环路
    } else if (visited[v] == 0) {
      if (!dfs(v, visited, results)) return false;
    }
  }
  visited[u] = 1;
  results.push(u);
  return true;
}

bool TopologicalSort() {
  stack<int> results;   // 记录排序结果
  vector<int> visited;  // 记录是否被访问
  visited.resize(N + 1, 0);

  for (int u = 1; u <= N; ++u) {
    if (!visited[u] && !dfs(u, visited, results)) {
      cout << "Loop Detected! Topological Sort Failed!" << endl;
      return false;
    }
  }

  // 输出结果
  cout << "Topological sort results = ";
  while (!results.empty()) {
    cout << results.top() << ", ";
    results.pop();
  }
  cout << endl;

  return true;
}

int main() {
  cin >> E >> N;
  adj_list.resize(N + 1);

  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    AddEdge(u, v);
  }

  // 带返回值，true表示无环路，拓扑排序成功
  TopologicalSort();

  return 0;
}

/*
6 6
6 3
6 1
5 1
5 2
3 4
4 2
*/