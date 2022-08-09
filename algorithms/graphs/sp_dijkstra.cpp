#include <bits/stdc++.h>
using namespace std;

const int kINF = 0x3f3f3f3f;

struct Edge {
  int v;
  int cost;
  Edge(int v, int cost) : v(v), cost(cost) {}
  bool operator>(const Edge &e) const { return cost > e.cost; }
};

int N;
int E;
vector<vector<Edge>> adj_list;
vector<int> dis;   // 保存单个源点 s 到任意节点的距离
vector<int> path;  // 保存单个源点 s 到任意节点的路径

void AddEdge(int u, int v, int cost) {
  adj_list[u].emplace_back(Edge(v, cost));
  adj_list[v].emplace_back(Edge(u, cost));
}

void Dijkstra(int src) {  // 单源最短路
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  dis[src] = 0;
  path[src] = 0;
  pq.push(Edge(src, 0));

  while (!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    int u = e.v;
    if (dis[u] < e.cost) continue;  // 剪枝

    for (const auto &nb : adj_list[u]) {
      if (dis[nb.v] > dis[u] + nb.cost) {
        dis[nb.v] = dis[u] + nb.cost;
        pq.push(Edge(nb.v, dis[nb.v]));
        path[nb.v] = u;
      }
    }
  }
}

// 输出路径必须从 1 开始标号，0 用作递归的终止，即
void PrintPath(int ed) {
  if (path[ed] != -1)
    PrintPath(path[ed]);
  else
    return;

  cout << ed << "(dis=" << dis[ed] << ")"
       << "->";
}

int main() {
  cin >> N >> E;
  adj_list.resize(N + 1);
  dis.assign(N + 1, kINF);
  path.assign(N + 1, -1);
  for (int i = 0; i < E; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    AddEdge(u, v, cost);
  }

  Dijkstra(1);
  for (int v = 1; v <= N; ++v) {
    PrintPath(v);
    cout << endl;
  }

  return 0;
}

/*
5 7
1 2 1
1 3 4
1 5 1
2 4 5
5 2 1
5 3 2
3 4 2
*/