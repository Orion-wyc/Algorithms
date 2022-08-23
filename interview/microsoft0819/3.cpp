#include <bits/stdc++.h>
using namespace std;

const int kSEATS = 5;

struct Edge {
  int v;
  int cost;
  Edge(int v, int cost = 1) : v(v), cost(cost) {}
};

// 邻接表
vector<vector<Edge>> adj_list;
vector<bool> visited;
int total = 0;

// adj_list
void BuildGraph(const vector<int> &A, const vector<int> &B) {
  int N = A.size();
  adj_list.resize(N + 1);
  visited.assign(N + 1, false);
  for (int i = 0; i < N; ++i) {
    adj_list[A[i]].push_back(Edge(B[i]));
    adj_list[B[i]].push_back(Edge(A[i]));
  }
}

int dfs(int u) {
  int population = 1;
  visited[u] = true;
  for (int i = 0; i < adj_list[u].size(); ++i) {
    int v = adj_list[u][i].v;
    if (visited[v] == false) {
      int num_children = dfs(v);
      // 此处计算油耗
      total += num_children / kSEATS;
      if (num_children % kSEATS != 0) total += 1;
      population += num_children;
    }
  }
  return population;
}

int solution(vector<int> &A, vector<int> &B) {
  BuildGraph(A, B);
  dfs(0);
  return total;
}

int main() {
  vector<int> A = {0,0,0,0,0,1,1,1,1,1};
  vector<int> B = {1,2,3,4,5,6,7,8,9,10};
  cout << solution(A, B) << endl;

  return 0;
}