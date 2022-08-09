#include <bits/stdc++.h>
using namespace std;

const int kINF = 0x3f3f3f3f;

struct Edge {
  int v;
  int cost;
  Edge(int v, int cost) : v(v), cost(cost) {}
};

vector<vector<Edge>> adj_list;
int N;
int E;
vector<int> dis;
vector<int> cnt;  // 记录最短路经过的边数，大于等于 N 则存在负环
vector<bool> vis;

void AddEdge(int u, int v, int cost) {
  adj_list[u].emplace_back(Edge(v, cost));
  adj_list[v].emplace_back(Edge(u, cost));
}

bool SPFA(int src) {
  dis[src] = 0;
  vis[src] = true;
  queue<int> que;  // 存储节点
  que.push(src);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = false;  // 出队则重置访问标记
    for (const auto &e : adj_list[u]) {
      int v = e.v;
      int w = e.cost;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] >= N) {
          cout << "Negtive Loop Detected!" << endl;
          return false;
        }
        if (!vis[v]) {
          que.push(v);
          vis[v] = true;
        }
      }
    }
  }
  return true;
}

int main() {
  cin >> N >> E;
  // 初始化
  adj_list.resize(N + 1);
  dis.assign(N + 1, kINF);
  cnt.assign(N + 1, 0);
  vis.assign(N + 1, false);

  for (int i = 0; i < E; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    AddEdge(u, v, cost);
  }

  if (SPFA(1)) {
    for (int v = 1; v <= N; ++v) {
      cout << dis[v] << endl;
    }
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

负环
5 7
1 2 -1
1 3 4
1 5 1
2 4 5
5 2 1
5 3 2
3 4 2
*/