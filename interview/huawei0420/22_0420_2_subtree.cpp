// 75%
#include <bits/stdc++.h>
using namespace std;

vector<int> tree1;
vector<int> path;
vector<int> tree2;
vector<int> ans;

void process(string s1, string s2, string s3) {
  // 处理根子树
  s1 = s1.substr(1, s1.size() - 2);
  stringstream ss1(s1);
  string s;
  while (getline(ss1, s, ',')) {
    tree1.push_back(stoi(s));
  }
  // 处理路径
  s2 = s2.substr(1);
  stringstream ss2(s2);
  while (getline(ss2, s, '/')) {
    path.push_back(stoi(s));
  }
  // 处理替换的树
  s3 = s3.substr(1, s3.size() - 2);
  stringstream ss3(s3);
  while (getline(ss3, s, ',')) {
    tree2.push_back(stoi(s));
  }
  // for (int n : tree1) cout << n << " ";
  // cout << endl;
  // for (int n : path) cout << n << " ";
  // cout << endl;
  // for (int n : tree2) cout << n << " ";
  // cout << endl;
}

int find_root() {
  int path_len = path.size();
  if (path_len == 0) return -1;

  int root_idx = 0;

  for (int i = 1; i < path_len; ++i) {
    int l = 2 * root_idx + 1;
    int r = 2 * root_idx + 2;
    if (l < tree1.size() && path[i] == tree1[l]) {
      root_idx = l;
    } else if (r < tree1.size() && path[i] == tree1[r]) {
      root_idx = r;
    }
    // cout << l <<" " << r << " " << root_idx <<endl;
  }
  return root_idx;
}

void dfs(int root1, int root2) {
  int len1 = tree1.size();
  int len2 = tree2.size();
  if (root1 >= len1) {
    if (root2 < len2) {
      tree1.insert(tree1.end(), tree2.begin() + root2, tree2.end());
    }
    return;
  }
  if (root2 >= len2) {
    tree1[root1] = 0;
  } else {
    tree1[root1] = tree2[root2];
  }
  dfs(2 * root1 + 1, 2 * root2 + 1);
  dfs(2 * root1 + 2, 2 * root2 + 2);
}

void print_result() {
  // 输出样例[1,1,5,3]
  cout << '[';
  for (int i = 0; i < ans.size(); ++i) {
    if (i == ans.size() - 1) {
      cout << ans.back();
    } else {
      cout << ans[i] << ",";
    }
  }
  cout << ']' << endl;
}

int main() {
  string s1, s2, s3;
  getline(cin, s1);
  getline(cin, s2);
  getline(cin, s3);
  process(s1, s2, s3);
  int root_idx = find_root();
  // tree2为空，直接返回处理后的数组
  // 这里写得有点问题，当时没看懂子树替换的第二个条件
  // if (root_idx == -1) {
  //   for (int n : tree1) {
  //     if (n != 0) ans.push_back(n);
  //   }
  // } else {
  if (root_idx != -1) {
    dfs(root_idx, 0);
  }
  for (int n : tree1) {
    if (n != 0) ans.push_back(n);
  }

  // 输出结果
  print_result();

  return 0;
}