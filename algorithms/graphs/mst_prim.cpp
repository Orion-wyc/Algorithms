#include <bits/stdc++.h>
using namespace std;

const int kINF = 0x3f3f3f3f;
struct Edge {
  int to;
  int cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};

// 下标从1开始
vector<vector<Edge>> adj_list;
int E;  // 边的数量
int N;  // 节点数量

int MstPrim() {
  int total_cost = 0;
  // 记录当前节点是都已经存在生成树节点集合 U 中
  vector<bool> vis(N + 1, false);
  // 存储当前生成树节集合U到其它顶点的最短距离
  vector<int> dis(N + 1, kINF);
  dis[1] = 0;

  for (int i = 1; i <= N; ++i) {
    // 寻找与 U 中节点距离最小节点 v
    int u = -1;
    int min_dis = kINF;
    for (int j = 1; j <= N; ++j) {
      if (vis[j] == false && dis[j] < min_dis) {
        min_dis = dis[j];
        u = j;
      }
    }

    //找不到小于 kINF 的 dis[u]，则剩下的顶点与集合 U 不连通
    if (u == -1) {
      return -1;
    }

    vis[u] = true;
    total_cost += dis[u];
    // 更新 dis 数组，即剩下节点到 U 中节点的最小距离
    for (int j = 0; j < adj_list[u].size(); ++j) {
      int v = adj_list[u][j].to;
      if (vis[v] == false && adj_list[u][j].cost < dis[v]) {
        dis[v] = adj_list[u][j].cost;
      }
    }
  }

  return total_cost;
}

int main() {
  cin >> E >> N;
  adj_list.resize(N + 1);
  for (int i = 0; i < E; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    // 无向图
    adj_list[u].emplace_back(Edge(v, cost));
    adj_list[v].emplace_back(Edge(u, cost));
  }
  cout << "MST Prim total cost = " << MstPrim() << endl;

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