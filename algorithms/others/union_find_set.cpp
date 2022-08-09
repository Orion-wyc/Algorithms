#include <bits/stdc++.h>

using namespace std;

const int kMAXN = 100;

int fa[kMAXN];

// 查找父亲的时候做路径压缩
int FindSet(int x) {
  if (x != fa[x])  // x 不是自身的父亲，即 x 不是该集合的代表
    fa[x] = FindSet(fa[x]);  // 查找 x 的祖先直到找到代表，于是顺手路径压缩
  return fa[x];
}

// 不带路径压缩的查找函数
int _FindSet(int x) {
  while (x != fa[x]) {
    x = fa[x];
  }
  return x;
}

// x 与 y 所在家族合并
void UnionSet(int x, int y) {
  x = FindSet(x);
  y = FindSet(y);
  fa[x] = y;  // 把 x 的祖先变成 y 的祖先的儿子
}

int main() {
  for (int i = 0; i < kMAXN; ++i) fa[i] = i;
  UnionSet(1, 2);
  UnionSet(2, 3);
  UnionSet(3, 4);
  UnionSet(5, 6);
  UnionSet(6, 7);
  for (int i = 0; i < 8; ++i) cout << FindSet(i) << endl;
}