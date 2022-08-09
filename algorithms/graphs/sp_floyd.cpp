#include <bits/stdc++.h>
using namespace std;

const int kINF = 0x3f3f3f3f;

vector<vector<int>> dis;
int N;
int E;

void Floyd() {
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (dis[i][j] > dis[i][k] + dis[k][j]) {
          dis[i][j] = dis[i][k] + dis[k][j];
        }
      }
    }
  }
}

int main() {
  cin >> N >> E;
  dis.assign(N + 1, vector<int>(N + 1));
  //初始化
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i == j)
        dis[i][j] = 0;
      else
        dis[i][j] = kINF;
    }
  }

  for (int i = 0; i < E; ++i) {
    int u;
    int v;
    int cost;
    cin >> u >> v >> cost;
    dis[u][v] = cost;
    dis[v][u] = cost;
  }

  Floyd();

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << dis[i][j] << " ";
    }
    cout << endl;
  }
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