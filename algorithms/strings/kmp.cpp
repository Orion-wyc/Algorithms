#include <bits/stdc++.h>
using namespace std;

int GetNext(const string &target, const vector<int> &fail, int pos,
            const char ch) {
  pos = fail[pos];
  while (pos != -1 && target[pos] != ch) pos = fail[pos];

  return pos + 1;
}

vector<int> GetFail(const string &target) {
  int m = target.size();
  vector<int> fail(m + 1, 0);
  fail[0] = -1;
  for (int i = 1; i <= m; ++i) {
    fail[i] = GetNext(target, fail, i - 1, target[i - 1]);
  }

  return fail;
}

int KMP_Match(const string &source, const string &target) {
  int n = source.size();
  int m = target.size();
  // 看模式串target是否为空
  if (m == 0) return 0;

  int pos = -1;
  vector<int> fail = GetFail(target);

  for (int i : fail) cout << i << " ";
  cout << endl;

  for (int i = 0, j = 0; i < n; ++i) {
    if (source[i] == target[j]) {
      ++j;
      if (j == m) {
        pos = i - m + 1;
        break;
      }
    } else {
      j = GetNext(target, fail, j, source[i]);
    }
  }

  return pos;
}

int main() {
  string s = "aaabbababcdbcefgq";
  string t = "abeabf";
  cout << KMP_Match(s, t) << endl;

  return 0;
}