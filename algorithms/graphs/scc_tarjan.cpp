#include <bits/stdc++.h>
using namespace std;

const int kINF = 0x3f3f3f3f;

// 邻接表
vector<list<int>> adj_list;
//
vector<int> dfn;
vector<int> low;
vector<bool> in_stack;
vector<vector<int>> scc_list;
stack<int> stk;

int dfn_cnt;
int N;
int E;

void AddEdge(int u, int v) { adj_list[u].push_back(v); }

void Tarjan(int u) {
  low[u] = dfn[u] = ++dfn_cnt;
  stk.push(u);
  in_stack[u] = true;

  for (const auto& v : adj_list[u]) {
    if (!dfn[v]) {
      Tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  // 相当则此时栈顶到 u 之间的节点构成一个 SCC
  if (dfn[u] == low[u]) {
    vector<int> scc;
    int v;
    do {
      v = stk.top();
      stk.pop();
      in_stack[v] = false;
      scc.push_back(v);
    } while (u != v);
    scc_list.push_back(scc);
  }
}

void GetAllSccs() {
  for (int i = 0; i < N; ++i) {
    if (!dfn[i]) Tarjan(i);
  }
}

void PrintSccs() {
  for (const auto& scc : scc_list) {
    for (const auto& u : scc) {
      cout << u << " ";
    }
    cout << "(size = " << scc.size() << ")" << endl;
  }
}

int main() {
  cin >> N >> E;
  // 初始化
  adj_list.resize(N);
  dfn.assign(N, 0);
  low.assign(N, 0);
  in_stack.assign(N, false);

  while (E--) {
    int u;
    int v;
    cin >> u >> v;
    AddEdge(u, v);
  }

  GetAllSccs();

  PrintSccs();

  return 0;
}

/*
10 15
0 1
0 4
1 0
1 8
2 1
2 4
2 7
3 4
4 3
5 0
5 6
7 9
7 4
8 5
9 2
*/