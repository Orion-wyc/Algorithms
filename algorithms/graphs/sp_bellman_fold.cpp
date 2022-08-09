#include <bits/stdc++.h>
using namespace std;

const int kINF = 0x3f3f3f3f;

struct Edge {
  int v;
  int cost;
  Edge(int v, int cost) : v(v), cost(cost) {}
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

// 基于动态规划思想的松弛操作
bool RelaxEdge(int u, int v, int cost) {
  bool relaxed = false;
  if (dis[v] > dis[u] + cost) {
    dis[v] = dis[u] + cost;
    path[v] = u;  // 更新前驱节点
    relaxed = true;
  }

  return relaxed;
}

// 单源最短路
bool BellmanFord(int src) {
  dis[src] = 0;  // 初始化 src 的距离
  path[src] = src;  // 这里前驱节点设置为 自身 表示路径递归输出返回条件

  // 执行松弛操作累计 N-1 次
  for (int i = 1; i <= N - 1; ++i) {
    // 遍历所有边，进行松弛操作
    for (int u = 1; u <= N; ++u) {
      // 距离为无穷大的点，加减常数依旧无穷大，所以剪枝
      if (dis[u] == kINF) continue;

      for (const auto &e : adj_list[u]) {
        RelaxEdge(u, e.v, e.cost);
      }
    }
  }

  bool neg_loop = false;
  for (int u = 1; u <= N; ++u) {
    for (const auto &e : adj_list[u]) {
      if (RelaxEdge(u, e.v, e.cost)) {
        neg_loop = true;
        break;
      }
    }
  }

  if (neg_loop) {
    cout << "Negtive Loop Detected!" << endl;
    return false;
  }
  return true;
}

// 输出路径必须从 1 开始标号，0 用作递归的终止，即
// void PrintPath(int ed) {
//   if (path[ed] != ed)
//     PrintPath(path[ed]);
//   else
//     return;

//   cout << ed << "(dis=" << dis[ed] << ")"
//        << "->";
// }

void PrintPath(int ed) {
  if (path[ed] == kINF) {
    cout << "Node Unreachable!" << endl;
  } else {
    while (path[ed] != ed) {
      cout << ed << "<-";
      ed = path[ed];
    }
    cout << ed;
  }
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

  if (BellmanFord(1)) {
    for (int v = 1; v <= N; ++v) {
      PrintPath(v);
      cout << endl;
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