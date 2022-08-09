#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u;
  int v;
  int cost;
  Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
  bool operator<(const Edge &e) const { return cost < e.cost; }
};

vector<Edge> edges;
int E, N;

// 并查集
vector<int> fa;

int FindSet(int x) {
  if (x != fa[x]) {
    fa[x] = FindSet(fa[x]);
  }
  return fa[x];
}

void UnionSet(int a, int b) {
  a = FindSet(a);
  b = FindSet(b);
  fa[a] = b;
}

void MstKruskal() {
  // 初始化并查集
  fa.resize(N + 1);
  for (int i = 0; i <= N; ++i) fa[i] = i;

  // 边按照代价升序排序
  sort(edges.begin(), edges.end());

  // 保存被选取的边的索引
  int total_cost = 0;
  vector<int> edge_indices;
  for (int i = 0; i < E; ++i) {
    if (edge_indices.size() == N - 1) break;
    const Edge &e = edges[i];
    if (FindSet(e.u) != FindSet(e.v)) {
      total_cost += e.cost;
      edge_indices.push_back(i);
      UnionSet(e.u, e.v);
    }
  }

  cout << "MST Kruskal Total Cost = " << total_cost << endl;
}

int main() {
  cin >> E >> N;
  for (int i = 0; i < E; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    edges.emplace_back(Edge(u, v, cost));
  }

  // 求最小生成树
  MstKruskal();

  return 0;
}

/*
// 边数 节点数
// 节点 节点 代价
11 7
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 11
5 7 9
*/