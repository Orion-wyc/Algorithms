#include <bits/stdc++.h>
using namespace std;

// 694. Number of Distinct Islands 不同岛屿的数量, 假设 1 是岛屿 0 是海水

class Solution {
 public:
  vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int numDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    unordered_set<string> hash_table;
    // 岛屿遍历顺序 - 序列化
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        string seq = "";
        dfs(grid, i, j, seq, 9);
        hash_table.insert(seq);
      }
    }
    return hash_table.size();
  }
  
  void dfs(vector<vector<int>> &grid, int x, int y, string &seq, int op) {
    int n = grid.size();
    int m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
      return;
    }
    grid[x][y] = 1;
    seq.push_back('a' + op);
    for (int i = 0; i < dirs.size(); ++i) {
      dfs(grid, x + dirs[i][0], y + dirs[i][1], seq, i);
    }
    seq.push_back('A' + op);
  }
};